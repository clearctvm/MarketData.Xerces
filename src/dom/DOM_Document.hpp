/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2000 The Apache Software Foundation.  All rights
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
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log$
 * Revision 1.12  2000/04/25 20:29:33  aruna1
 * DOM_XMLDecl type node introduced to get the information of the
 * XML Declaration in a document and store it part of the tree
 *
 * Revision 1.11  2000/03/24 21:24:50  abagchi
 * Added getElementById() from patch submitted by Jeff Lewis
 *
 * Revision 1.10  2000/03/02 19:53:55  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.9  2000/02/24 20:11:27  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.8  2000/02/17 17:47:24  andyh
 * Update Doc++ API comments
 * NameSpace update to track W3C
 * Changes were made by Chih Hsiang Chou
 *
 * Revision 1.7  2000/02/10 19:41:16  abagchi
 * Added docs for createNodeIterator and createTreeWalker
 *
 * Revision 1.6  2000/02/06 07:47:28  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.5  2000/02/04 01:49:28  aruna1
 * TreeWalker and NodeIterator changes
 *
 * Revision 1.4  2000/01/22 01:38:29  andyh
 * Remove compiler warnings in DOM impl classes
 *
 * Revision 1.3  2000/01/05 01:16:07  andyh
 * DOM Level 2 core, namespace support added.
 *
 * Revision 1.2  1999/12/21 07:47:06  robweir
 * Patches to support Xalan, where we need to create a
 * "special" DOM with subclassed Nodes.
 *
 * 1. Export the NodeImpl-derived classes
 * 2. Ensure that their constructors have at least protected access
 *
 * Revision 1.1.1.1  1999/11/09 01:08:51  twl
 * Initial checkin
 *
 * Revision 1.4  1999/11/08 20:44:15  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
*/

#ifndef DOM_Document_HEADER_GUARD_
#define DOM_Document_HEADER_GUARD_

#include <util/XercesDefs.hpp>
#include <dom/DOM_DocumentType.hpp>
#include <dom/DOM_DOMImplementation.hpp>
#include <dom/DOM_Element.hpp>
#include <dom/DOM_DocumentFragment.hpp>
#include <dom/DOM_Comment.hpp>
#include <dom/DOM_CDATASection.hpp>
#include <dom/DOM_ProcessingInstruction.hpp>
#include <dom/DOM_Attr.hpp>
#include <dom/DOM_Entity.hpp>
#include <dom/DOM_EntityReference.hpp>
#include <dom/DOM_NodeList.hpp>
#include <dom/DOM_Notation.hpp>
#include <dom/DOM_Text.hpp>
#include <dom/DOM_Node.hpp>
#include <dom/DOM_NodeIterator.hpp>
#include <dom/DOM_TreeWalker.hpp>
#include <dom/DOM_XMLDecl.hpp>

class DocumentImpl;
class NodeIteratorImpl;


/**
* Class to refer to XML Document nodes in the DOM.
*
* Conceptually, a DOM document node is the root of the document tree, and provides
* the  primary access to the document's data.
* <p>Since elements, text nodes, comments, processing instructions, etc.
* cannot exist outside the context of a <code>Document</code>, the
* <code>Document</code> interface also contains the factory methods needed
* to create these objects.  The <code>Node</code> objects created have a
* <code>ownerDocument</code> attribute which associates them with the
* <code>Document</code> within whose  context they were created.
*/
class CDOM_EXPORT DOM_Document: public DOM_Node {

public:
    /** @name Constructors and assignment operators */
    //@{
    /**
     * The default constructor for DOM_Document creates a null
     * DOM_Document object that refers to no document.  It may subsequently be
     * assigned to refer to an actual Document node.
     *
     * To create a new document, use the static method
     *   <code> DOM_Document::createDocument(). </code>
     *
     */
    DOM_Document();

    /**
      * Copy constructor.  Creates a new <code>DOM_Document</code> that refers to the
      * same underlying actual document as the original.
      *
      * @param other The object to be copied
      */
    DOM_Document(const DOM_Document &other);
    /**
      * Assignment operator
      *
      * @param other The object to be copied
      */
    DOM_Document & operator = (const DOM_Document &other);

    /**
      * Assignment operator.  This overloaded variant is provided for
      *   the sole purpose of setting a DOM_Node reference variable to
      *   zero.  Nulling out a reference variable in this way will decrement
      *   the reference count on the underlying Node object that the variable
      *   formerly referenced.  This effect is normally obtained when reference
      *   variable goes out of scope, but zeroing them can be useful for
      *   global instances, or for local instances that will remain in scope
      *   for an extended time,  when the storage belonging to the underlying
      *   node needs to be reclaimed.
      *
      * @param val.  Only a value of 0, or null, is allowed.
      */
    DOM_Document & operator = (const DOM_NullPtr *val);



	//@}
  /** @name Destructor */
  //@{
	
  /**
    * Destructor.  The object being destroyed is the reference
    * object, not the underlying Document itself.
    *
    * <p>The reference counting memory management will
    *  delete the underlying document itself if this
    * DOM_Document is the last remaining to refer to the Document,
    * and if there are no remaining references to any of the nodes
    * within the document tree.  If other live references do remain,
    * the underlying document itself remains also.
    *
    */
    ~DOM_Document();

  //@}
  /** @name Factory methods to create new nodes for the Document */
  //@{

    /**
    *   Create a new empty document.
    *
    *   This differs from the <code> DOM_Document </code> default
    *   constructor, which creates
    *   a null reference only, not an actual document.
    *
    *   <p>This function is an extension to the DOM API, which
    *   lacks any mechanism for the creation of new documents.
    *   @return A new <code>DOM_Document</code>, which may then
    *   be populated using the DOM API calls.
    */
    static DOM_Document   createDocument();

    /**
    *  Create a new entity.
    *
    *  Non-standard extension.
    * @param name The name of the entity to instantiate
    *
    */
    DOM_Entity     createEntity(const DOMString &name);

    /**
    * Creates an element of the type specified.
    *
    * Note that the instance returned
    * implements the Element interface, so attributes can be specified
    * directly  on the returned object.
    * @param tagName The name of the element type to instantiate.
    * @return A <code>DOM_Element</code> that reference the new element.
    * @exception DOMException
    *   INVALID_CHARACTER_ERR: Raised if the specified name contains an
    *   illegal character.
    */
    DOM_Element     createElement(const DOMString &tagName);

    /**
    * Creates an element of the type specified.
    * This non-standard overload of createElement, with the name specified as
    * raw Unicode string, is intended for use from XML parsers,
    * and is the best performing way to create elements.  The name
    * string is not checked for conformance to the XML rules for valid
    * element names.
    *
    *
    * @param tagName The name of the element type to instantiate, as
    *    a null-terminated unicode string.
    * @return A new <CODE>DOM_Element</CODE> 
    *        object with the <CODE>nodeName</CODE> attribute set to 
    *        <CODE>tagName</CODE>, and <CODE>localName</CODE>, 
    *        <CODE>prefix</CODE>, and <CODE>namespaceURI</CODE> set to 
    *        <CODE>null</CODE>.
    */
    DOM_Element     createElement(const XMLCh *tagName);


    /**
    * Creates an empty DocumentFragment object.
    *
    * @return A <code>DOM_DocumentFragment</code> that references the newly
    * created document fragment.
    */
    DOM_DocumentFragment   createDocumentFragment();

    /**
    * Creates a Text node given the specified string.
    *
    * @param data The data for the node.
    * @return A <code>DOM_Text</code> object that references the newly
    *  created text node.
    */
    DOM_Text         createTextNode(const DOMString &data);

    /**
    * Creates a Comment node given the specified string.
    *
    * @param data The data for the comment.
    * @return A <code>DOM_Comment</code> that references the newly
    *  created comment node.
    */
    DOM_Comment      createComment(const DOMString &data);

    /**
    * Creates a CDATASection node whose value  is the specified
    * string.
    *
    * @param data The data for the <code>DOM_CDATASection</code> contents.
    * @return A <code>DOM_CDATASection</code> object.
    * @exception DOMException
    *   NOT_SUPPORTED_ERR: Raised if this document is an HTML document.
    */
    DOM_CDATASection   createCDATASection(const DOMString &data);

    /**
    *  Create a DocumentType node.  Non-standard extension.
    *
    * @return A <code>DOM_DocumentType</code> that references the newly
    *  created DocumentType node.
    *
    */
    DOM_DocumentType createDocumentType(const DOMString &name);


    /**
    *  Create a Notation.
    *
    *  Non-standard extension.
    *
    *  @param name The name of the notation to instantiate
    * @return A <code>DOM_Notation</code> that references the newly
    *  created Notation node.
    */
    DOM_Notation createNotation(const DOMString &name);


    /**
    * Creates a ProcessingInstruction node given the specified
    * name and data strings.
    *
    * @param target The target part of the processing instruction.
    * @param data The data for the node.
    * @return A <code>DOM_ProcessingInstruction</code> that references the newly
    *  created PI node.
    * @exception DOMException
    *   INVALID_CHARACTER_ERR: Raised if an illegal character is specified.
    */
    DOM_ProcessingInstruction createProcessingInstruction(const DOMString &target,
        const DOMString &data);


    /**
     * Creates an Attr of the given name.
     *
     * Note that the
     * <code>Attr</code> instance can then be attached to an Element
     * using the <code>DOMElement::setAttribute()</code> method.
     * @param name The name of the attribute.
     * @return A new <CODE>DOM_Attr</CODE> 
     *       object with the <CODE>nodeName</CODE> attribute set to 
     *       <CODE>name</CODE>, and <CODE>localName</CODE>, <CODE>prefix</CODE>, 
     *       and <CODE>namespaceURI</CODE> set to 
     *       <CODE>null</CODE>.
     * @exception DOMException
     *   INVALID_CHARACTER_ERR: Raised if the specified name contains an
     *   illegal character.
     */
    DOM_Attr     createAttribute(const DOMString &name);


    /**
     * Creates an EntityReference object.
     *
     * @param name The name of the entity to reference.
     * @return A <code>DOM_EntityReference</code> that references the newly
     *  created EntityReference node.
     * @exception DOMException
     *   INVALID_CHARACTER_ERR: Raised if the specified name contains an
     *   illegal character.
     */
    DOM_EntityReference    createEntityReference(const DOMString &name);


    /**
     * Creates a NodeIterator object.   (DOM2)
     *
     * NodeIterators are used to step through a set of nodes, e.g. the set of nodes in a NodeList, the
     * document subtree governed by a particular node, the results of a query, or any other set of nodes.
     * The set of nodes to be iterated is determined by the implementation of the NodeIterator. DOM Level 2
     * specifies a single NodeIterator implementation for document-order traversal of a document subtree.
     * Instances of these iterators are created by calling <code>DocumentTraversal.createNodeIterator()</code>. 
     *
     * To produce a view of the document that has entity references expanded and does not
     * expose the entity reference node itself, use the <code>whatToShow</code> flags to hide the entity
     * reference node and set expandEntityReferences to true when creating the iterator. To
     * produce a view of the document that has entity reference nodes but no entity expansion,
     * use the <code>whatToShow</code> flags to show the entity reference node and set
     * expandEntityReferences to false.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param root The root node of the DOM tree
     * @param whatToShow This attribute determines which node types are presented via the iterator.
     * @param filter The filter used to screen nodes
     * @param entityReferenceExpansion The value of this flag determines whether the children of entity reference nodes are
     *                   visible to the iterator. If false, they will be skipped over.
     */

    DOM_NodeIterator createNodeIterator(DOM_Node root, 
                                        unsigned long whatToShow, 
                                        DOM_NodeFilter*  filter, 
                                        bool entityReferenceExpansion);
     /**
     * Creates a TreeWalker object.   (DOM2)
     *
     * TreeWalker objects are used to navigate a document tree or subtree using the view of the document defined
     * by its whatToShow flags and any filters that are defined for the TreeWalker. Any function which performs
     * navigation using a TreeWalker will automatically support any view defined by a TreeWalker.
     *
     * Omitting nodes from the logical view of a subtree can result in a structure that is substantially different from
     * the same subtree in the complete, unfiltered document. Nodes that are siblings in the TreeWalker view may
     * be children of different, widely separated nodes in the original view. For instance, consider a Filter that skips
     * all nodes except for Text nodes and the root node of a document. In the logical view that results, all text
     * nodes will be siblings and appear as direct children of the root node, no matter how deeply nested the
     * structure of the original document.
     *
     * To produce a view of the document that has entity references expanded
     * and does not expose the entity reference node itself, use the whatToShow
     * flags to hide the entity reference node and set <code>expandEntityReferences</code> to
     * true when creating the TreeWalker. To produce a view of the document
     * that has entity reference nodes but no entity expansion, use the
     * <code>whatToShow</code> flags to show the entity reference node and set
     * <code>expandEntityReferences</code> to false
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param root The root node of the DOM tree
     * @param whatToShow This attribute determines which node types are presented via the tree-walker.
     * @param filter The filter used to screen nodes
     * @param entityReferenceExpansion The value of this flag determines whether the children of entity reference nodes are
     *                   visible to the tree-walker. If false, they will be skipped over.
     */

    DOM_TreeWalker  createTreeWalker(DOM_Node root, 
                                     unsigned long whatToShow, 
                                     DOM_NodeFilter*  filter, 
                                     bool entityReferenceExpansion);

    /**
     * Creates a XMLDecl type Node .   Non-Standard (an extension to xerces)
     *
     * XMLDecl Nodes are created to get  version, encoding and standalone information in a document tree
     *
     * This node if created gets attached to a document object or an entity node. There can be no child
     * to this type of node.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param version The version data of the document. Currently possible value is 1.0
     * @param encoding The encoding type specified in the document
     * @param standalone The information whether the document is standalone or not
     */

    DOM_XMLDecl createXMLDecl(const DOMString& version,
                            const DOMString& encoding,
                            const DOMString& standalone);

    //@}
    /** @name Getter functions */
    //@{
    /**
     * Get Document Type Declaration (see <code>DOM_DocumentType</code>) associated
     * with  this document.
     *
     * For documents without
     * a document type declaration this returns <code>null</code> reference object. The DOM Level
     *  1 does not support editing the Document Type Declaration, therefore
     * <code>docType</code> cannot be altered in any way.
     */
    DOM_DocumentType       getDoctype() const;



    /**
     * Return the <code>DOMImplementation</code> object that handles this document.
     */
    DOM_DOMImplementation  &getImplementation() const;


    /**
     * Return a reference to the root element of the document.
     */
    DOM_Element     getDocumentElement() const;

    /**
     * Returns a <code>DOM_NodeList</code> of all the elements with a
     * given tag name.  The returned node list is "live", in that changes
     * to the document tree made after a nodelist was initially
     * returned will be immediately reflected in the node list.
     *
     * The elements in the node list are ordered in the same order in which they
     * would be encountered in a
     * preorder traversal of the <code>Document</code> tree.
     * @param tagname The name of the tag to match on. The special value "*"
     *   matches all tags.
     * @return A reference to a NodeList containing all the matched
     *   <code>Element</code>s.
     */
    DOM_NodeList           getElementsByTagName(const DOMString &tagname) const;

    //@}
    /** @name Functions introduced in DOM Level 2. */
    //@{

    /**
     * Imports a node from another document to this document. 
     * The returned node has no parent (<CODE>parentNode</CODE> is 
     * <CODE>null</CODE>). The source node is not altered or removed from the 
     * original document; this method creates a new copy of the source 
     * node.<BR>For all nodes, importing a node creates a node object owned by 
     * the importing document, with attribute values identical to the source 
     * node's <CODE>nodeName</CODE> and <CODE>nodeType</CODE>, plus the 
     * attributes related to namespaces (prefix and namespaces URI).
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param importedNode The node to import.
     * @param deep If <CODE>true</CODE>, recursively import the subtree under the 
     *      specified node; if <CODE>false</CODE>, import only the node itself, 
     *      as explained above. This does not apply to <CODE>DOM_Attr</CODE>, 
     *      <CODE>DOM_EntityReference</CODE>, and <CODE>DOM_Notation</CODE> nodes.
     * @return The imported node that belongs to this <CODE>DOM_Document</CODE>.
     * @exception DOMException
     *   NOT_SUPPORTED_ERR: Raised if the type of node being imported is 
     *                      not supported.
     */
    DOM_Node            importNode(const DOM_Node &importedNode, bool deep);

    /**
     * Creates an element of the given qualified name and 
     * namespace URI.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param namespaceURI The <em>namespace URI</em> of
     *   the element to create.
     * @param qualifiedName The <em>qualified name</em>
     *   of the element type to instantiate.
     * @return A new <code>DOM_Element</code> object.
     * @exception DOMException
     *   INVALID_CHARACTER_ERR: Raised if the specified qualified name contains
     *                          an illegal character.
     * <br>
     *   NAMESPACE_ERR: Raised if the <CODE>qualifiedName</CODE> is 
     *      malformed, if the <CODE>qualifiedName</CODE> has a prefix and the 
     *      <CODE>namespaceURI</CODE> is <CODE>null</CODE> or an empty string, 
     *      or if the <CODE>qualifiedName</CODE> has a prefix that is "xml" and 
     *      the <CODE>namespaceURI</CODE> is different from 
     *      "http://www.w3.org/XML/1998/namespace".
     */
    DOM_Element         createElementNS(const DOMString &namespaceURI,
	const DOMString &qualifiedName);

    /**
     * Creates an attribute of the given qualified name and namespace
     * URI.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param namespaceURI The <em>namespace URI</em> of
     *   the attribute to create.
     * @param qualifiedName The <em>qualified name</em>
     *   of the attribute to instantiate.
     * @return A new <code>DOM_Attr</code> object.
     * @exception DOMException
     *   INVALID_CHARACTER_ERR: Raised if the specified qualified name contains
     *                          an illegal character.
     * <br>
     *   NAMESPACE_ERR: Raised if the <CODE>qualifiedName</CODE> is 
     *      malformed, if the <CODE>qualifiedName</CODE> has a prefix and the 
     *      <CODE>namespaceURI</CODE> is <CODE>null</CODE> or an empty string, 
     *      if the <CODE>qualifiedName</CODE> has a prefix that is "xml" and the 
     *      <CODE>namespaceURI</CODE> is different from 
     *      "http://www.w3.org/XML/1998/namespace", if the 
     *      <CODE>qualifiedName</CODE> has a prefix that is "xmlns" and the 
     *      <CODE>namespaceURI</CODE> is different from 
     *      "http://www.w3.org/2000/xmlns/", or if the 
     *      <CODE>qualifiedName</CODE> is "xmlns" and the 
     *      <CODE>namespaceURI</CODE> is different from 
     *      "http://www.w3.org/2000/xmlns/".
     */
    DOM_Attr            createAttributeNS(const DOMString &namespaceURI,
	const DOMString &qualifiedName);

    /**
     * Returns a <code>DOM_NodeList</code> of all the <code>DOM_Element</code>s
     * with a given <em>local name</em> and
     * namespace URI in the order in which they would be encountered in a
     * preorder traversal of the <code>DOM_Document</code> tree.
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param namespaceURI The <em>namespace URI</em> of
     *   the elements to match on. The special value "*" matches all
     *   namespaces.
     * @param localName The <em>local name</em> of the
     *   elements to match on. The special value "*" matches all local names.
     * @return A new <code>DOM_NodeList</code> object containing all the matched
     *  <code>DOM_Element</code>s.
     */
    DOM_NodeList        getElementsByTagNameNS(const DOMString &namespaceURI,
	const DOMString &localName) const;

    /**
     * Returns the <code>DOM_Element</code> whose ID is given by <code>elementId</code>.
     * If no such element exists, returns <code>null</code>.
     * Behavior is not defined if more than one element has this <code>ID</code>.
     * <P><B>Note:</B> The DOM implementation must have information that says 
     * which attributes are of type ID. Attributes with the name "ID" are not of 
     * type ID unless so defined. Implementations that do not know whether 
     * attributes are of type ID or not are expected to return 
     * <CODE>null</CODE>.</P>
     *
     * <p><b>"Experimental - subject to change"</b></p>
     *
     * @param elementId The unique <code>id</code> value for an element.
     * @return The matching element.
     */
    DOM_Element         getElementById(const DOMString &elementId);

    //@}

    /** @name Non-standard accessory functions */
    //@{

	/**
	 * Registers an identifier name with a specified element node.
	 * If the identifier is already registered, the new element
	 * node replaces the previous node. If the specified element
	 * node is null, removeIdentifier() is called.
	 *
     * @param elementId The unique <code>id</code> value for an element.
     * @param ele The <code>Element</code> unique <code>id</code> value for an element.
     */
    void		         putIdentifier(const DOMString &elementId, const DOM_Element &ele);

	//@}
protected:
    DOM_Document (DocumentImpl *impl);

    friend class DOM_Node;
    friend class NodeIteratorImpl;
    friend class DOM_DOMImplementation;

};


#endif
