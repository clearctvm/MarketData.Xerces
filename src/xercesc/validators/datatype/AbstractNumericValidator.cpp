/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id$
 * $Log$
 * Revision 1.1  2002/02/01 22:22:39  peiyongz
 * Initial revision
 *
 * Revision 1.2  2001/10/09 21:16:31  peiyongz
 * . macro to simplify code
 *
 * Revision 1.1  2001/10/01 16:13:56  peiyongz
 * DTV Reorganization:new classes: AbstractNumericFactValidator/ AbstractNumericValidator
 *
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/validators/datatype/AbstractNumericValidator.hpp>
#include <xercesc/validators/datatype/InvalidDatatypeValueException.hpp>

#define  REPORT_VALUE_ERROR(val1, val2, except_code)    \
  XMLCh* value1 = (val1)->toString();                   \
  ArrayJanitor<XMLCh> jan1(value1);                     \
  XMLCh* value2 = (val2)->toString();                   \
  ArrayJanitor<XMLCh> jan2(value2);                     \
  ThrowXML2(InvalidDatatypeValueException               \
          , except_code                                 \
          , value1                                      \
          , value2);                            

// ---------------------------------------------------------------------------
//  Constructors and Destructor
// ---------------------------------------------------------------------------
AbstractNumericValidator::~AbstractNumericValidator()
{}

AbstractNumericValidator::AbstractNumericValidator(
                          DatatypeValidator*            const baseValidator
                        , RefHashTableOf<KVStringPair>* const facets
                        , const int                           finalSet
                        , const ValidatorType                 type)
:AbstractNumericFacetValidator(baseValidator, facets, finalSet, type)
{
    //do not invoke init() here !!!
}

void AbstractNumericValidator::validate(const XMLCh* const content)
{
    checkContent(content, false);
}

void AbstractNumericValidator::boundsCheck(const XMLNumber* const theData)
{
    int thisFacetsDefined = getFacetsDefined();
    int result;

    try 
    {

        // must be < MaxExclusive       
        if ( (thisFacetsDefined & DatatypeValidator::FACET_MAXEXCLUSIVE) != 0 )
        {
            result = compareValues(theData, getMaxExclusive());
            if ( result != -1)
            {
                REPORT_VALUE_ERROR(theData
                                 , getMaxExclusive()
                                 , XMLExcepts::VALUE_exceed_maxExcl)
            }
        } 	

        // must be <= MaxInclusive
        if ( (thisFacetsDefined & DatatypeValidator::FACET_MAXINCLUSIVE) != 0 )
        {
            result = compareValues(theData, getMaxInclusive());
            if (result == 1)
            {
                REPORT_VALUE_ERROR(theData
                                 , getMaxInclusive()
                                 , XMLExcepts::VALUE_exceed_maxIncl)
            }
        }

        // must be >= MinInclusive
        if ( (thisFacetsDefined & DatatypeValidator::FACET_MININCLUSIVE) != 0 )
        {
            result = compareValues(theData, getMinInclusive());
            if (result == -1)
            {
                REPORT_VALUE_ERROR(theData
                                 , getMinInclusive()
                                 , XMLExcepts::VALUE_exceed_minIncl)
            }
        }

        // must be > MinExclusive
        if ( (thisFacetsDefined & DatatypeValidator::FACET_MINEXCLUSIVE) != 0 )
        {
            result = compareValues(theData, getMinExclusive());
            if (result != 1)
            {
                REPORT_VALUE_ERROR(theData
                                 , getMinExclusive()
                                 , XMLExcepts::VALUE_exceed_minExcl)
            }
        }
    }
    catch (XMLException &e)
    {
       ThrowXML1(InvalidDatatypeValueException, XMLExcepts::RethrowError, e.getMessage());
    }

}

/**
  * End of file AbstractNumericValidator::cpp
  */

