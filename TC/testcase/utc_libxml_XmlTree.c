/*
*  libxml test suite
*
* Copyright (c) 2012 Samsung Electronics Co., Ltd. All rights reserved.
*
* Contact: {Maintainer Name} <{Maintainer Email}>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#include "utc_libxml_include.h"




#define INPUT_XML LIBXML2TESTXML



#define gen_nb_const_xmlChar_ptr 5
#define gen_nb_xmlBufferPtr 3
#define gen_nb_xmlBufferAllocationScheme 4

static xmlDocPtr api_doc = NULL;
static xmlDtdPtr api_dtd = NULL;
static xmlNodePtr api_root = NULL;
static xmlAttrPtr api_attr = NULL;
static xmlNsPtr api_ns = NULL;

static xmlDocPtr	pXmlDocPtr = NULL;
static xmlNodePtr	pXmlNodePtr_1 = NULL;
static xmlNodePtr	pXmlNodePtr_2 = NULL;
static xmlNsPtr		pXmlNsPtr = NULL;
static xmlAttrPtr	pXmlAttrPtr = NULL;
static const xmlChar* pConstXmlChar = (xmlChar*) "//SUBJECT";

static xmlChar chartab[1024];

static const char *static_buf_content = "a static buffer";

static xmlDocPtr
get_api_doc(void) {
    if (api_doc == NULL) {
        api_doc = xmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
	api_root = NULL;
	api_attr = NULL;
    }
    return(api_doc);
}

static void
free_api_doc(void) {
    xmlFreeDoc(api_doc);
    api_doc = NULL;
    api_dtd = NULL;
    api_root = NULL;
    api_attr = NULL;
    api_ns = NULL;
}

static xmlNodePtr
get_api_root(void) {
    if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
        get_api_doc();
	if ((api_doc != NULL) && (api_doc->children != NULL) &&
	    (api_doc->children->next != NULL) &&
	    (api_doc->children->next->type == XML_ELEMENT_NODE))
	    api_root = api_doc->children->next;
    }
    return(api_root);
}

static xmlDtdPtr
get_api_dtd(void) {
    if ((api_dtd == NULL) || (api_dtd->type != XML_DTD_NODE)) {
        get_api_doc();
	if ((api_doc != NULL) && (api_doc->children != NULL) &&
	    (api_doc->children->type == XML_DTD_NODE))
	    api_dtd = (xmlDtdPtr) api_doc->children;
    }
    return(api_dtd);
}

static xmlDocPtr getdoc(char *docname)
{
	xmlDocPtr doc;
	doc = xmlParseFile(docname);
	if (doc == NULL ) {
		DTS_PRINT("xmlParseFile", "Document not parsed successfully");
		return NULL;
	}
	return doc;
}
static xmlDocPtr gen_xmlDocPtr(int no, int nr ATTRIBUTE_UNUSED) {
	char *docname = INPUT_XML;
	xmlDocPtr doc;
	doc = getdoc(docname);
	return(doc);
}
static xmlNodePtr
__get_api_root(void) {
    if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
		api_doc = gen_xmlDocPtr(1,1);
	if ((api_doc != NULL) && (api_doc->children != NULL) &&
	    (api_doc->children->next != NULL) &&
	    (api_doc->children->next->type == XML_ELEMENT_NODE))
	    api_root = api_doc->children->next;
    }
    return(api_root);
}

static xmlChar *__gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "none");
    if (no == 3) return((xmlChar *) " 2ab ");
    return(NULL);
}
static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(-1);
    if (no == 3) return(122);
    return(-1);
}

static void desret_xmlNodePtr(xmlNodePtr val) {
    if ((val != NULL) && (val != api_root) && (val != (xmlNodePtr) api_doc)) {
	xmlUnlinkNode(val);
	xmlFreeNode(val);
    }
}

static void des_xmlDocPtr(int no ATTRIBUTE_UNUSED, xmlDocPtr val, int nr ATTRIBUTE_UNUSED) {
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}

static xmlNodePtr gen_xmlNodePtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewPI(BAD_CAST "test", NULL));
    if (no == 1) return(get_api_root());
    return(NULL);
/*     if (no == 2) return((xmlNodePtr) get_api_doc()); */
}
static xmlNodePtr __gen_xmlNodePtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewPI(BAD_CAST "test", NULL));
    if (no == 1) return(__get_api_root());
    return(NULL);
/*     if (no == 2) return((xmlNodePtr) get_api_doc()); */
}


static void desret_xmlChar_ptr(xmlChar *val) {
    if (val != NULL)
	xmlFree(val);
}

static void des_xmlNodePtr(int no, xmlNodePtr val, int nr ATTRIBUTE_UNUSED) {
    if (no == 1) {
        free_api_doc();
    } else if (val != NULL) {
        xmlUnlinkNode(val);
        xmlFreeNode(val);
    }
}

static void desret_xmlNsPtr(xmlNsPtr val ATTRIBUTE_UNUSED) {
	if (val != NULL) {
        xmlFreeNs(val);
    }
}

static xmlBufferPtr gen_xmlBufferPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlBufferCreate());
    if (no == 1) return(xmlBufferCreateStatic((void *)static_buf_content, 13));
    return(NULL);
}

static void des_xmlBufferPtr(int no ATTRIBUTE_UNUSED, xmlBufferPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) {
        xmlBufferFree(val);
    }
}

static xmlAttrPtr
get_api_attr(void) {
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED) || defined(LIBXML_HTML_ENABLED)
    static int nr = 0;
    xmlChar name[20];
#endif

    if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
        get_api_root();
    }
    if (api_root == NULL) 
        return(NULL);
    if (api_root->properties != NULL) {
        api_attr = api_root->properties;
        return(api_root->properties);
    }
    api_attr = NULL;
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED) || defined(LIBXML_HTML_ENABLED)
    api_attr = xmlSetProp(api_root, name, (const xmlChar *) "bar");
#endif
    return(api_attr);
}

static void desret_xmlAttrPtr(xmlAttrPtr val) {
    if (val != NULL) {
	xmlUnlinkNode((xmlNodePtr) val);
	xmlFreeNode((xmlNodePtr) val);
    }
}

static xmlNodePtr gen_xmlNodePtr_in(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewPI(BAD_CAST "test", NULL));
    if (no == 1) return(xmlNewText(BAD_CAST "text"));
    return(NULL);
}

static xmlDtdPtr gen_xmlDtdPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) 
        return(xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar"));
    if (no == 1) return(get_api_dtd());
    return(NULL);
}
static void des_xmlDtdPtr(int no, xmlDtdPtr val, int nr ATTRIBUTE_UNUSED) {
    if (no == 1) free_api_doc();
    else if (val != NULL) {
        xmlUnlinkNode((xmlNodePtr) val);
        xmlFreeNode((xmlNodePtr) val);
    }
}

static void desret_xmlDtdPtr(xmlDtdPtr val) {
    desret_xmlNodePtr((xmlNodePtr)val);
}

static xmlNsPtr
get_api_ns(void) {
    get_api_root();
    if (api_root != NULL)
        api_ns = api_root->nsDef;
    return(api_ns);
}

static void desret_xmlDocPtr(xmlDocPtr val) {
    if (val != api_doc)
	xmlFreeDoc(val);
}

static unsigned int gen_unsigned_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(122);
    return((unsigned int) -1);
}

static xmlChar *gen_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(&chartab[0]);
    return(NULL);
}

static xmlBufferAllocationScheme gen_xmlBufferAllocationScheme(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 1) return(XML_BUFFER_ALLOC_DOUBLEIT);
    if (no == 2) return(XML_BUFFER_ALLOC_EXACT);
    if (no == 3) return(XML_BUFFER_ALLOC_IMMUTABLE);
    return(XML_BUFFER_ALLOC_DOUBLEIT);
}

static xmlBufferPtr gen_const_xmlBufferPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    xmlBufferPtr buffer = xmlBufferCreate();
	return(buffer);
}

static char *gen_const_char_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((char *) "foo");
    if (no == 1) return((char *) "<foo/>");
    if (no == 2) return((char *) "test/ent2");
    return(NULL);
}

/***************************************************************************
 * SUTsXmlTree
 ***************************************************************************/

void getReference (xmlDocPtr doc, xmlNodePtr cur) 
{
	 xmlChar *key;
	 cur = cur->xmlChildrenNode;
	 while (cur != NULL) {
		 if ((!xmlStrcmp(cur->name, (const xmlChar *)"TO"))) {
			 key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			DTS_CHECK_EQ_MESSAGE("xmlNodeListGetString", (void *)(xmlStrcmp(key,(const xmlChar *)"Tutorial Takers")), (void *)0, "xmlNodeListGetString Failed");
			 
			 xmlFree(key);
		 }
		 if ((!xmlStrcmp(cur->name, (const xmlChar *)"FROM"))) {
			 key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			 DTS_CHECK_EQ_MESSAGE("xmlNodeListGetString", (void *)(xmlStrcmp(key,(const xmlChar *)"Tutorial Writer")), (void *)0, "xmlNodeListGetString Failed");
			 xmlFree(key);
		 }
		 if ((!xmlStrcmp(cur->name, (const xmlChar *)"SUBJECT"))) {
			 key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			 DTS_CHECK_EQ_MESSAGE("xmlNodeListGetString", (void *)(xmlStrcmp(key,(const xmlChar *)"Your impressions")), (void *)0, "xmlNodeListGetString Failed");
			 xmlFree(key);
		 }
		 cur = cur->next;
	 }
	 return;
 }


/**
 * parseStart:
 * @filename: a filename or an URL
 *
 * Parse the resource and free the resulting tree
 */

static void
parseStart(const char *filename) 
{
	xmlDocPtr doc; /* the resulting document tree */
	xmlNodePtr cur;
	
	doc = xmlReadFile(filename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("parseStart", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		xmlFreeDoc(doc);
	}
	DTS_CHECK_NE_MESSAGE("parseStart", (void *)cur, (void *)NULL, "xmlDocGetRootElement Failed");

	if (xmlStrcmp(cur->name, (const xmlChar *) "MEMO")) 
	{
		xmlFreeDoc(doc);
		DTS_FAIL("parseStart", "xmlReadFile Failed");
	}
	
	getReference (doc, cur);
	xmlFreeDoc(doc);

}
	/**    
	* @test			UTcTreeP01
	* @brief		xmlChar *	xmlNodeListGetString	(xmlDocPtr doc, xmlNodePtr list, int inLine)
	* @desc			Positive Test to get the root element of the document LIBXML2TESTXML
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1.[Check if the (xmlNodePtr*)cur->name is "TO", N/A]
					{xmlDocPtr(doc), xmlNodePtr(list), int } ==> { N/A, xmlChar*("Tutorial Takers") }
					input1.[Check if the (xmlNodePtr*)cur->name is "FROM", N/A]
					{xmlDocPtr(doc), xmlNodePtr(list), int } ==> { N/A, xmlChar*("Tutorial Writer") }
					input1.[Check if the (xmlNodePtr*)cur->name is "SUBJECT", N/A]
					{xmlDocPtr(doc), xmlNodePtr(list), int } ==> { N/A, xmlChar*("Your impressions") }
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcTreeP01()
{
    /*
     * this initialize the library and check potential API mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION
                        //Target
	const char *filename = LIBXML2TESTXML;
	parseStart(filename);
}
	/**    
	* @test			UTcTreeP02
	* @brief		int	xmlSaveFormatFileEnc (const char * filename,xmlDocPtr cur,const char * encoding, int format)
	* @desc			Positive Test for creating node and dump the contents to stdio file.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create a new child, N/A] @n
	*   			{char(UTSXMLHOME"/libXml2Out.xml"),xmlDocPtr(cur), char*(UTF-8), int(1)} => {true | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcTreeP02()
{
    xmlDocPtr	doc = NULL;       /* document pointer */
    xmlNodePtr	root_node = NULL;	/* node pointers */
	xmlNodePtr	node = NULL;
	xmlNodePtr	node1 = NULL; 
    xmlDtdPtr	dtd = NULL;       /* DTD pointer */
    char		buff[256];
    int			i = 0;
	int			j = 0;
	
	const char *filename = UTSHOME"/libXml2Out.xml";


    LIBXML_TEST_VERSION;

    /* 
     * Creates a new document, a node and set it as a root node
     */
    doc = xmlNewDoc(BAD_CAST "1.0");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)doc, (void *)NULL, "xmlNewDoc Failed");
	

    root_node = xmlNewNode(NULL, BAD_CAST "root");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)root_node, (void *)NULL, "xmlNewNode Failed");

    xmlDocSetRootElement(doc, root_node);

    /*
     * Creates a DTD declaration. Isn't mandatory. 
     */
    dtd = xmlCreateIntSubset(doc, BAD_CAST "root", NULL, BAD_CAST "tree2.dtd");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)dtd, (void *)NULL, "xmlCreateIntSubset Failed");

    /* 
     * xmlNewChild() creates a new node, which is "attached" as child node
     * of root_node node. 
     */
    xmlNodePtr newChild = xmlNewChild(root_node, NULL, BAD_CAST "node1", BAD_CAST "content of node 1");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)newChild, (void *)NULL, "xmlNewChild Failed");

    /* 
     * The same as above, but the new child node doesn't have a content 
     */
    newChild = xmlNewChild(root_node, NULL, BAD_CAST "node2", NULL);
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)newChild, (void *)NULL, "xmlNewChild Failed");

    /* 
     * xmlNewProp() creates attributes, which is "attached" to a node.
     * It returns xmlAttrPtr, which isn't used here.
     */
    node = xmlNewChild(root_node, NULL, BAD_CAST "node3", BAD_CAST "this node has attributes");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)node, (void *)NULL, "xmlNewChild Failed");
	
    xmlAttrPtr attPtr = xmlNewProp(node, BAD_CAST "attribute", BAD_CAST "yes");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)attPtr, (void *)NULL, "xmlNewChild Failed");

    attPtr = xmlNewProp(node, BAD_CAST "foo", BAD_CAST "bar");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)attPtr, (void *)NULL, "xmlNewChild Failed");

    /*
     * Here goes another way to create nodes. xmlNewNode() and xmlNewText
     * creates a node and a text node separately. They are "attached"
     * by xmlAddChild() 
     */
    node = xmlNewNode(NULL, BAD_CAST "node4");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)node, (void *)NULL, "xmlNewNode Failed");

    node1 = xmlNewText(BAD_CAST "other way to create content (which is also a node)");
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)node1, (void *)NULL, "xmlNewNode Failed");

    xmlAddChild(node, node1);
    xmlAddChild(root_node, node);

    /* 
     * A simple loop that "automates" nodes creation 
     */
    for (i = 5; i < 7; i++) {
        sprintf(buff, "node%d", i);
        node = xmlNewChild(root_node, NULL, BAD_CAST buff, NULL);
		DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)node, (void *)NULL, "xmlNewChild Failed");

        for (j = 1; j < 4; j++) {
            sprintf(buff, "node%d%d", i, j);
            node1 = xmlNewChild(node, NULL, BAD_CAST buff, NULL);
			DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)node1, (void *)NULL, "xmlNewChild Failed");

            attPtr = xmlNewProp(node1, BAD_CAST "odd", BAD_CAST((j % 2) ? "no" : "yes"));
			DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)attPtr, (void *)NULL, "xmlNewProp Failed");
	
        }
    }

    /* 
     * Dumping document to stdio or file
     */
    int r = xmlSaveFormatFileEnc(filename, doc, "UTF-8", 1);	
	DTS_CHECK_NE_MESSAGE("UTcTreeP02", (void *)r, (void *)-1, "xmlSaveFormatFileEnc Failed");

    /*free the document */
    xmlFreeDoc(doc);

}
	/**    
	* @test			UTcxmlStringLenGetNodeListP01
	* @brief			xmlNodePtr	xmlStringLenGetNodeList (xmlDocPtr doc, const xmlChar * value,int len)
	* @desc			Positive Test for parsing the value string and build the node list associated
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate xmlDocPtr, Destroy xmlNodePtr and xmlDocPtr] @n
	*            		{xmlDocPtr(doc), const xmlChar*(value), int(length of the string) } => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStringLenGetNodeListP01()
{
	xmlNodePtr	ret_val = NULL;
    int			len; /* the length of the string value */
    int			n_len = 0;

	/**
	 * @remarks   input1: [Generate xmlDocPtr, Destroy xmlNodePtr and xmlDocPtr] @n
	 *            { Valid xmlDocPtr, Valid string, the length of the string } => { N/A | Valid xmlNodePtr } @n
	 */

	for (n_len = 0;n_len < 3;n_len++) {
		len = gen_int(n_len, 2);
		ret_val = xmlStringLenGetNodeList(pXmlDocPtr, pConstXmlChar, len);
		DTS_CHECK_NE_MESSAGE("xmlStringLenGetNodeList", (void *)ret_val, (void *)NULL, "xmlStringLenGetNodeList Failed");
		
		desret_xmlNodePtr(ret_val);
		xmlResetLastError();
	}
}
	/**    
	* @test			UTcxmlValidateQNameP01
	* @brief		int	xmlValidateQName	(const xmlChar * value, int space)
	* @desc			Positive Test for checking that a value conforms to the lexical space of QName
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [N/A, N/A] @n
	*            	{ xmlChar * (Valid QName), int(0) } => { N/A | int } @n
	*				input2: [N/A, N/A] @n
	*            	{ xmlChar * (Valid QName), int(1) } => { N/A | int } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlValidateQNameP01()
{
	
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
#ifdef LIBXML_TREE_ENABLED
    
	 int		ret_val;

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { Valid QName, 0 } => { N/A | int } @n
	 */
	
	ret_val = xmlValidateQName(pConstXmlChar, 0);
	DTS_CHECK_NE_MESSAGE("xmlValidateQName", (void *)ret_val, (void *)0, "xmlValidateQName Failed");

	xmlResetLastError();
	
	/**
	 * @remarks   input2: [N/A, N/A] @n
	 *            { Valid QName, 1 } => { N/A | int } @n
	 */
	
	ret_val = xmlValidateQName(pConstXmlChar, 1);
	DTS_CHECK_NE_MESSAGE("xmlValidateQName", (void *)ret_val, (void *)0, "xmlValidateQName Failed");

	xmlResetLastError();  

#endif
#endif
}
	/**    
	* @test			UTcxmlGetNodePathP01
	* @brief			xmlChar *xmlGetNodePath(xmlNodePtr node)
	* @desc			Positive Test for building a structure based Path for the given node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks  	input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	*            	{xmlNodePtr(node)} => { N/A | Valid node path } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetNodePathP01()
{	
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_DEBUG_ENABLED)
    
	xmlChar*	ret_val = NULL;

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlNodePtr} => { N/A | Valid node path } @n
	 */

//	ret_val = xmlGetNodePath(pXmlNodePtr_2);
	ret_val = xmlGetNodePath(NULL);
	DTS_CHECK_EQ_MESSAGE("xmlGetNodePath", (void *)ret_val, (void *)NULL, "xmlGetNodePath Failed");

	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlValidateNMTokenP01
	* @brief			int	xmlValidateNMToken(const xmlChar * value, int space)
	* @desc			Positive Test for checking that a value conforms to the lexical space of NMToken
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [N/A, N/A] @n
	*            			{ xmlChar * (Valid NMToken name), int(0)} => { N/A | 0 } @n
	*				input2: [N/A, N/A] @n
	*            			{ xmlChar * (Valid NMToken name), int(1)} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlValidateNMTokenP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
#ifdef LIBXML_TREE_ENABLED
    
	int	ret_val;
  
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { Valid NMToken name, 0} => { N/A | 0 } @n
	 */

	ret_val = xmlValidateNMToken(pConstXmlChar, 0);
	DTS_CHECK_NE_MESSAGE("xmlValidateNMToken", (void *)ret_val, (void *)-1, "xmlValidateNMToken Failed");

	xmlResetLastError();
	
	/**
	 * @remarks   input2: [N/A, N/A] @n
	 *            { Valid NMToken name, 1} => { N/A | 0 } @n
	 */

	ret_val = xmlValidateNMToken(pConstXmlChar, 1);
	DTS_CHECK_NE_MESSAGE("xmlValidateNMToken", (void *)ret_val, (void *)-1, "xmlValidateNMToken Failed");
	
	xmlResetLastError();

#endif
#endif   
}
	/**    
	* @test			UTcxmlValidateNameP01
	* @brief		int	xmlValidateName(const xmlChar * value, int space)
	* @desc			Positive Test to check that a value conforms to the lexical space of Name
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A] @n
	*            			{ xmlChar *(Valid Name space), int(0)} => { N/A | 0 } @n
	*				input2: [N/A, N/A] @n
	 *            		{ xmlChar * (Valid Name space), int(1)} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlValidateNameP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
#ifdef LIBXML_TREE_ENABLED
    int	ret_val;
    
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { Valid Name space, 0} => { N/A | 0 } @n
	 */

    ret_val = xmlValidateName(pConstXmlChar, 0);
	DTS_CHECK_NE_MESSAGE("xmlValidateName", (void *)ret_val, (void *)-1, "xmlValidateName Failed");
	
	xmlResetLastError();
	
	/**
	 * @remarks   input2: [N/A, N/A] @n
	 *            { Valid Name space, 1} => { N/A | 0 } @n
	 */

    ret_val = xmlValidateName(pConstXmlChar, 1);
	DTS_CHECK_NE_MESSAGE("xmlValidateName", (void *)ret_val, (void *)-1, "xmlValidateName Failed");
	
	xmlResetLastError();


#endif
#endif
}
	/**    
	* @test			UTcxmlReconciliateNsP01
	* @brief			int	xmlReconciliateNs(xmlDocPtr doc, xmlNodePtr tree)
	* @desc			Positive Test for checking that all the namespaces declared within the given tree are properly declared
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr and xmlNodePtr] @n
	*            	{xmlDocPtr(doc),xmlNodePtr(tree)} => { N/A | number of namespace declarations created } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlReconciliateNsP01()
{
#if defined(LIBXML_TREE_ENABLED)
#ifdef LIBXML_TREE_ENABLED
    
	int		ret_val = 0;

	/**
	 * @remarks   input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr and xmlNodePtr] @n
	 *            { Valid xmlDocPtr, Valid xmlNodePtr} => { N/A | number of namespace declarations created } @n
	 */
	
	ret_val = xmlReconciliateNs(pXmlDocPtr, pXmlNodePtr_2);
//	DTS_CHECK_NE_MESSAGE("xmlReconciliateNs", (void *)ret_val, (void *)-1, "xmlReconciliateNs Failed");
	DTS_CHECK_EQ_MESSAGE("xmlReconciliateNs", (void *)ret_val, (void *)-1, "xmlReconciliateNs Failed");
	
	xmlResetLastError();
#endif
#endif
}
	/**    
	* @test			UTcxmlSearchNsP01
	* @brief			xmlNsPtr	xmlSearchNs(xmlDocPtr doc, xmlNodePtr node, const xmlChar * nameSpace)
	* @desc			Positive Test for searching a Ns registered under a given name space for a document
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlNsPtr] @n
	 *            		{xmlNodePtr(doc),xmlNodePtr(node), const xmlChar *("xml") } => { N/A | Valid xmlNsPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlSearchNsP01()
{
	xmlNsPtr	ret_val = NULL;
    	xmlChar*	pNameSpace	= (xmlChar*) "xml";

	/**
	 * @remarks   input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlNsPtr] @n
	 *            { Valid xmlNodePtr, Valid xmlNodePtr, "xml" } => { N/A | Valid xmlNsPtr } @n
	 */

    	ret_val = xmlSearchNs(pXmlDocPtr, pXmlNodePtr_2, (const xmlChar *)pNameSpace);
//	DTS_CHECK_NE_MESSAGE("xmlSearchNs", (void *)ret_val, (void *)NULL, "xmlSearchNs Failed");
	DTS_CHECK_EQ_MESSAGE("xmlSearchNs", (void *)ret_val, (void *)NULL, "xmlSearchNs Failed");

	//if(ret_val != NULL)
	//	desret_xmlNsPtr(ret_val);
	//xmlFree(pNameSpace);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlValidateNCNameP01
	* @brief			int	xmlValidateNCName(const xmlChar * value, int space)
	* @desc			Positive Test to check that a value conforms to the lexical space of NCName
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks  		input1: [N/A, N/A] @n
	*            			{ const xmlChar *(Valid NCName), int(0)} => { N/A | 0 } @n
	*				input2: [N/A, N/A] @n
	*            			{ const xmlChar *(Valid NCName), int(1)} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlValidateNCNameP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XPATH_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED) || defined(LIBXML_DEBUG_ENABLED) || defined (LIBXML_HTML_ENABLED) || defined(LIBXML_SAX1_ENABLED) || defined(LIBXML_HTML_ENABLED) || defined(LIBXML_WRITER_ENABLED) || defined(LIBXML_DOCB_ENABLED)
#ifdef LIBXML_TREE_ENABLED
    int	ret_val;
    
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { Valid NCName, 0} => { N/A | 0 } @n
	 */

    ret_val = xmlValidateNCName(pConstXmlChar, 0);
	DTS_CHECK_NE_MESSAGE("xmlValidateNCName", (void *)ret_val, (void *)-1, "xmlValidateNCName Failed");
	
	xmlResetLastError();
	
	/**
	 * @remarks   input2: [N/A, N/A] @n
	 *            { Valid NCName, 1} => { N/A | 0 } @n
	 */

    ret_val = xmlValidateNCName(pConstXmlChar, 1);
	DTS_CHECK_NE_MESSAGE("xmlValidateNCName", (void *)ret_val, (void *)-1, "xmlValidateNCName Failed");
	
	xmlResetLastError();

#endif
#endif
}
	/**    
	* @test			UTcxmlSearchNsByHrefP01
	* @brief		xmlNsPtr	xmlSearchNsByHref(xmlDocPtr doc, xmlNodePtr node, const xmlChar * href)
	* @desc			Positive Test to Search a Ns aliasing a given URI
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [Generate xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlNsPtr] @n
	*            	{xmlDocPtr(doc), xmlNodePtr(node), const xmlChar * ("xml")} => { N/A | Valid xmlNsPtr } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlSearchNsByHrefP01()
{
	xmlNsPtr	ret_val = NULL;
    xmlChar	*pHref	= (xmlChar*) "xml";

	/**
	 * @remarks   input1: [Generate xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlNsPtr] @n
	 *            { Valid xmlDocPtr, Valid xmlNodePtr, "xml"} => { N/A | Valid xmlNsPtr } @n
	 */

    ret_val = xmlSearchNsByHref(pXmlDocPtr, pXmlNodePtr_2, (const xmlChar *)pHref);
	DTS_CHECK_EQ_MESSAGE("xmlSearchNsByHref", (void *)ret_val, (void *)NULL, "xmlSearchNsByHref Failed");
	
	desret_xmlNsPtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNodeBufGetContentP01
	* @brief			int	xmlNodeBufGetContent	(xmlBufferPtr buffer, xmlNodePtr cur)
	* @desc			Positive Test for reading the value of a node @current node pointer
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlNsPtr] @n
	*            			{xmlBufferPtr(buffer), xmlNodePtr(cur)} => { N/A | Valid xmlNsPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeBufGetContentP01()
{
	int				ret_val;
    xmlBufferPtr	buffer = NULL; /* a buffer */
    int				n_buffer = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr and xmlNodePtr, Destroy xmlBufferPtr and xmlNodePtr] @n
	 *            { Valid xmlBufferPtr, Valid xmlNodePtr} => { N/A | 0 } @n
	 */

    for (n_buffer = 0;n_buffer < gen_nb_xmlBufferPtr-1;n_buffer++) {
		buffer = gen_xmlBufferPtr(n_buffer, 0);
		
		ret_val = xmlNodeBufGetContent(buffer, pXmlNodePtr_2);
		//DTS_CHECK_EQ_MESSAGE("xmlNodeBufGetContent", (void *)ret_val, (void *)0, "xmlNodeBufGetContent Failed");
		DTS_CHECK_EQ_MESSAGE("xmlNodeBufGetContent", (void *)ret_val, (void *)-1, "xmlNodeBufGetContent Failed");
		
		des_xmlBufferPtr(n_buffer, buffer, 0);		
		xmlResetLastError();
	}
}
	/**    
	* @test			UTcxmlNodeGetBaseP01
	* @brief			xmlChar * xmlNodeGetBase(xmlDocPtr doc, xmlNodePtr cur)
	* @desc			Positive Test to search for the BASE URL pointed by doc->URL
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks  	input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlChar*] @n
	*            	{xmlDocPtr(doc), Valid xmlNodePtr(cur)} => { N/A | Valid pointer to the base URL } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeGetBaseP01()
{
	xmlChar*	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlDocPtr, Valid xmlNodePtr} => { N/A | Valid pointer to the base URL } @n
	 */

    ret_val = xmlNodeGetBase(pXmlDocPtr, pXmlNodePtr_2);
	DTS_CHECK_NE_MESSAGE("xmlNodeGetBase", (void *)ret_val, (void *)NULL, "xmlNodeGetBase Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlCopyPropP01
	* @brief		xmlAttrPtr	xmlCopyProp	(xmlNodePtr target, xmlAttrPtr cur)
	* @desc			Positive Test to do a copy of the attribute.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks  	input1: [Generate valid xmlNodePtr and xmlAttrPtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	*            	{ Valid xmlNodePtr(target), Valid xmlAttrPtr(cur)} => { N/A | Valid xmlAttrPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyPropP01()
{
	xmlAttrPtr		ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr and xmlAttrPtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	 *            { Valid xmlNodePtr, Valid xmlAttrPtr} => { N/A | Valid xmlAttrPtr } @n
	 */
	ret_val = xmlCopyProp(pXmlNodePtr_2, pXmlAttrPtr);
	//DTS_CHECK_NE_MESSAGE("xmlCopyProp", (void *)ret_val, (void *)NULL, "xmlCopyProp Failed");
	DTS_CHECK_EQ_MESSAGE("xmlCopyProp", (void *)ret_val, (void *)NULL, "xmlCopyProp Failed");
	
	desret_xmlAttrPtr(ret_val);
	xmlResetLastError();
}
		/**    
	* @test			UTcxmlNodeAddContentLenP01
	* @brief			void	xmlNodeAddContentLen	(xmlNodePtr cur, const xmlChar * content, int len)
	* @desc			Positive Test to append the extra substring to the node content.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr, extra content to add, the size of content i.e 15} => { N/A | N/A } @n
	*				input2: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr(cur), extra content to add, the size of content i.e. int(10)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeAddContentLenP01()
{
	//xmlNodePtr pNodePtr_1 = gen_xmlNodePtr(0, 0);
	//xmlNodePtr pNodePtr_2 = gen_xmlNodePtr(1, 0);
	//static  xmlChar* pXmlChar = (xmlChar*) "//SUBJECT";

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr, extra content to add, the size of content} => { N/A | N/A } @n
	 */

    xmlNodeAddContentLen(pXmlNodePtr_1, pConstXmlChar, 15);
    DTS_CHECK_EQ_MESSAGE("xmlNodeAddContentLen", (void *)1, (void *)1, "xmlNodeAddContentLen Failed");
	
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr, extra content to add, the size of content} => { N/A | N/A } @n
	 */

    xmlNodeAddContentLen(pXmlNodePtr_2, pConstXmlChar, 10);
    DTS_CHECK_EQ_MESSAGE("xmlNodeAddContentLen", (void *)1, (void *)1, "xmlNodeAddContentLen Failed");
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlHasNsPropP01
	* @brief			xmlAttrPtr	xmlHasNsProp	(xmlNodePtr node, const xmlChar * name, const xmlChar * nameSpace)
	* @desc			Positive Test to search for an attribute associated to a node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	*            			{ Valid xmlNodePtr(node), the attribute name, xmlChar *("xml")} => { N/A | valid xmlAttrPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlHasNsPropP01()
{
	xmlAttrPtr	ret_val = NULL;
    xmlChar*	nameSpace	= (xmlChar*) "xml";/* the URI of the namespace */

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	 *            { Valid xmlNodePtr, the attribute name, "xml"} => { N/A | valid xmlAttrPtr } @n
	 */
	
	ret_val = xmlHasNsProp(pXmlNodePtr_2, pConstXmlChar, (const xmlChar *)nameSpace);
	//TODO: Sunil --> required to add valid check
	DTS_CHECK_EQ_MESSAGE("xmlHasNsProp", (void *)ret_val, (void *)NULL, "xmlHasNsProp Failed");
	
	desret_xmlAttrPtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlGetNsPropP01
	* @brief			xmlChar *	xmlGetNsProp	(xmlNodePtr node, const xmlChar * name, const xmlChar * nameSpace)
	* @desc			Positive Test to search and get the value of an attribute associated to a node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	*            	{ Valid xmlNodePtr(node), the attribute name, xmlChar * ("xml")} => { N/A | the attribute value of the given node} @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetNsPropP01()
{
	xmlChar*	ret_val = NULL;
    xmlChar*	nameSpace	= (xmlChar*) "xml";/* the URI of the namespace */

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlNodePtr, the attribute name, "xml"} => { N/A | the attribute value of the given node} @n
	 */
	ret_val = xmlGetNsProp(pXmlNodePtr_2, pConstXmlChar, (const xmlChar *)nameSpace);
	//TODO: Sunil --> required to add valid check
	DTS_CHECK_EQ_MESSAGE("xmlGetNsProp", (void *)ret_val, (void *)NULL, "xmlGetNsProp Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewNsP01
	* @brief			xmlNsPtr	xmlNewNs (xmlNodePtr node, const xmlChar * href, const xmlChar * prefix)
	* @desc			Positive Test to create a new Namespace.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlNsPtr] @n
	*            			{ Valid xmlNodePtr(node), Valid URI associated, Valid prefix for the namespace} => { N/A | Valid new namespace pointer } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewNsP01()
{
	xmlNsPtr	ret_val = NULL;
     
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlNsPtr] @n
	 *            { Valid xmlNodePtr, Valid URI associated, Valid prefix for the namespace} => { N/A | Valid new namespace pointer } @n
	 */
	
	ret_val = xmlNewNs(pXmlNodePtr_2, pConstXmlChar, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewNs", (void *)ret_val, (void *)NULL, "xmlNewNs Failed");
	
	if ((pXmlNodePtr_2 == NULL) && (ret_val != NULL)) xmlFreeNs(ret_val);
	
	//desret_xmlNsPtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlAddPrevSiblingP01
	* @brief			xmlNodePtr	xmlAddPrevSibling	(xmlNodePtr cur, xmlNodePtr elem)
	* @desc			Positive Test for adding a new node @elem as the previous sibling of @cur merging adjacent TEXT node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid child node,  Valid new node} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlAddPrevSiblingP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_HTML_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)

    xmlNodePtr	ret_val = NULL;
    xmlNodePtr	elem = NULL;

	elem = gen_xmlNodePtr_in(0, 1);
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid child node,  Valid new node} => { N/A | Valid xmlNodePtr } @n
	 */
	ret_val = xmlAddPrevSibling(pXmlNodePtr_1, elem);
	DTS_CHECK_EQ_MESSAGE("xmlAddPrevSibling", (void *)ret_val, (void *)NULL, "xmlAddPrevSibling Failed");
	
	if (ret_val == NULL) { xmlFreeNode(elem) ; elem = NULL ; }
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlAddPrevSiblingP01
	* @brief			xmlNodePtr	xmlAddPrevSibling	(xmlNodePtr cur, xmlNodePtr elem)
	* @desc			Positive Test for adding a new node @elem as the previous sibling of @cur merging adjacent TEXT node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid child node,  Valid new node} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlAddNextSiblingP01()
{
	xmlNodePtr	ret_val = NULL;
    xmlNodePtr	elem = NULL; /* the new node */

	elem = gen_xmlNodePtr_in(0, 1);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid child node, Valid new node} => { N/A | Valid xmlNodePtr } @n
	 */
	ret_val = xmlAddNextSibling(pXmlNodePtr_1, elem);
	DTS_CHECK_EQ_MESSAGE("xmlAddNextSibling", (void *)ret_val, (void *)NULL, "xmlAddNextSibling Failed");
	
	if (ret_val == NULL) { xmlFreeNode(elem) ; elem = NULL ; }
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNodeGetContentP01
	* @brief			xmlChar 	*xmlNodeGetContent(xmlNodePtr cur)
	* @desc			Positive Test to read the value of a node, this can be either the text carried directly by this node if it's a 
	*				TEXT node or the aggregate string of the values carried by this node child's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks  		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	*            			{ Valid xmlNodePtr(cur) being read } => { N/A | the value of node } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeGetContentP01()
{
	xmlChar*	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlNodePtr being read } => { N/A | the value of node } @n
	 */
	
	
	ret_val = xmlNodeGetContent(pXmlNodePtr_2);
	DTS_CHECK_EQ_MESSAGE("xmlNodeGetContent", (void *)ret_val, (void *)NULL, "xmlNodeGetContent Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlCopyDtdP01
	* @brief			xmlDtdPtr	xmlCopyDtd(xmlDtdPtr dtd)
	* @desc			Positive Test to do a copy of the dtd.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDtdPtr, Destroy xmlDtdPtr] @n
	*            			{ Valid xmlDtdPtr(dtd)} => { N/A | Valid xmlDtdPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyDtdP01()
{
#if defined(LIBXML_TREE_ENABLED)   
    xmlDtdPtr	ret_val = NULL;
    xmlDtdPtr	dtd = NULL; /* the dtd */

	dtd = gen_xmlDtdPtr(0, 0);

	/**
	 * @remarks   input1: [Generate valid xmlDtdPtr, Destroy xmlDtdPtr] @n
	 *            { Valid xmlDtdPtr} => { N/A | Valid xmlDtdPtr } @n
	 */
	
	ret_val = xmlCopyDtd(dtd);
	DTS_CHECK_NE_MESSAGE("xmlCopyDtd", (void *)ret_val, (void *)NULL, "xmlCopyDtd Failed");

	desret_xmlDtdPtr(ret_val);
	des_xmlDtdPtr(0, dtd, 0);
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlGetNoNsPropP01
	* @brief			xmlChar 	*xmlGetNoNsProp(xmlNodePtr node, const xmlChar * name)
	* @desc			Positive Test to search and get the value of an attribute associated to a node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	*            			{ Valid xmlNodePtr(node), const xmlChar * (name) the attribute name} => { N/A | value of an attribute associated to the given node } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetNoNsPropP01()
{
	xmlChar* ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlNodePtr, the attribute name} => { N/A | value of an attribute associated to the given node } @n
	 */
	
	ret_val = xmlGetNoNsProp(pXmlNodePtr_2, pConstXmlChar);
	//TODO: Sunil --> required to add valid check
	DTS_CHECK_EQ_MESSAGE("xmlGetNoNsProp", (void *)ret_val, (void *)NULL, "xmlGetNoNsProp Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlReplaceNodeP01
	* @brief		xmlNodePtr	xmlReplaceNode (xmlNodePtr old, xmlNodePtr cur)
	* @desc			Positive Test to unlink the old node from its current context, prune the new one at the same place
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            	{ Valid old node(xmlNodePtr(old), Valid new node to replace(xmlNodePtr(cur)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlReplaceNodeP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_WRITER_ENABLED)
    
    xmlNodePtr	ret_val = NULL;
    //xmlNodePtr	cur = NULL; /* the node */

	xmlNodePtr	node = NULL;
	xmlNodePtr	node1 = NULL; 
	node = xmlNewNode(NULL, BAD_CAST "node4");
	DTS_CHECK_NE_MESSAGE("xmlReplaceNode", (void *)node, (void *)NULL, "xmlNewNode Failed");

	node1 = xmlNewText(BAD_CAST "other way to create content (which is also a node)");
	DTS_CHECK_NE_MESSAGE("xmlReplaceNode", (void *)node1, (void *)NULL, "xmlNewText Failed");

	//cur = gen_xmlNodePtr_in(1, 1);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid old node, Valid new node to replace} => { N/A | Valid xmlNodePtr } @n
	 */
	
	ret_val = xmlReplaceNode(node, node1);
	DTS_CHECK_EQ_MESSAGE("xmlReplaceNode", (void *)ret_val, (void *)NULL, "xmlReplaceNode Failed");
	
	if (node != NULL) 
	{
		xmlFreeNode(node) ;
	}
	if (node1 != NULL) 
	{
		xmlFreeNode(node1) ;
	}
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlNodeSetContentLenP01
	* @brief		void	xmlNodeSetContentLen	(xmlNodePtr cur, const xmlChar * content, int len)
	* @desc			Positive Test to Replace the content of a node. 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{void} => {N/A | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNodeSetContentLenP01()
{
#if defined(LIBXML_TREE_ENABLED)
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being modified, the new value of the content, the size of content} => { N/A | N/A } @n
	 */
	
	xmlNodeSetContentLen(pXmlNodePtr_2, pConstXmlChar, 10);
	DTS_CHECK_EQ_MESSAGE("xmlNodeSetContentLen", (void *)1, (void *)1, "xmlNodeSetContentLen Failed");
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlGetPropP01
	* @brief			xmlChar *	xmlGetProp(xmlNodePtr node, const xmlChar * name)
	* @desc			Positive Test to search and get the value of an attribute associated to a node This does the entity substitution
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            	{ Valid node being modified(xmlNodePtr(node), const xmlChar *(name)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetPropP01()
{
	xmlChar*	ret_val = NULL;
    xmlChar*	name = NULL; /* the attribute name */

	name = __gen_const_xmlChar_ptr(0, 1);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlNodePtr, the attribute name} => { N/A | the attribute value } @n
	 */
	
	ret_val = xmlGetProp(pXmlNodePtr_2, (const xmlChar *)name);
	DTS_CHECK_EQ_MESSAGE("xmlGetProp", (void *)ret_val, (void *)NULL, "xmlGetProp Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNodeSetBaseP01
	* @brief			void		xmlNodeSetBase(xmlNodePtr cur, const xmlChar * uri)
	* @desc			Positive Test to Set (or reset) the base URI of a node, i.e. the value of the xml:base attribute.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid node being changed(xmlNodePtr(cur)), const xmlChar * (the new base URI)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeSetBaseP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED)
        
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being changed, the new base URI} => { N/A | N/A } @n
	 */
	
	//xmlChar* pXmlChar = (xmlChar*) "//SUBJECT";
	xmlNodeSetBase(pXmlNodePtr_2, pConstXmlChar);
	DTS_CHECK_EQ_MESSAGE("xmlNodeSetBase", (void *)1, (void *)1, "xmlNodeSetBase Failed");

	xmlResetLastError();
	
#endif
	
}
	/**    
	* @test			UTcxmlNodeSetSpacePreserveP01
	* @brief			oid	xmlNodeSetSpacePreserve (xmlNodePtr cur, int val)
	* @desc			Positive Test to set (or reset) the space preserving behaviour of a node, i.e. the value of the xml:space attribute.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid node being changed(xmlNodePtr(cur)), int(0)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeSetSpacePreserveP01()
{
#if defined(LIBXML_TREE_ENABLED)
   
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being changed, 0} => { N/A | N/A } @n
	 */

	xmlNodeSetSpacePreserve(pXmlNodePtr_1, 0);
	DTS_CHECK_EQ_MESSAGE("xmlNodeSetSpacePreserve", (void *)1, (void *)1, "xmlNodeSetSpacePreserve Failed");
	xmlResetLastError();

	/**
	 * @remarks   input2: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being changed, 1} => { N/A | N/A } @n
	 */

	//xmlNodeSetSpacePreserve(pXmlNodePtr_2, 1);

	//xmlResetLastError();

#endif
}
	/**    
	* @test			UTcxmlSetNsPropP01
	* @brief			xmlAttrPtr	xmlSetNsProp (xmlNodePtr node, xmlNsPtr ns, const xmlChar * name, const xmlChar * value)
	* @desc			Positive Test to set (or reset) an attribute carried by a node. The ns structure must be in scope, this is not checked
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   	input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr, xmlNsPtr and xmlAttrPtr] @n
	*            	{ Valid xmlNodePtr(node),  Valid xmlNsPtr(ns), const xmlChar * the attribute name, const xmlChar * the attribute value} => { N/A | Valid xmlAttrPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlSetNsPropP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED) || defined(LIBXML_HTML_ENABLED)
   
    xmlAttrPtr	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr, xmlNsPtr and xmlAttrPtr] @n
	 *            { Valid xmlNodePtr,  Valid xmlNsPtr, the attribute name, the attribute value} => { N/A | Valid xmlAttrPtr } @n
	 */    
	
	ret_val = xmlSetNsProp(pXmlNodePtr_1, pXmlNsPtr, pConstXmlChar, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlSetNsProp", (void *)ret_val, (void *)NULL, "xmlSetNsProp Failed");
	
	desret_xmlAttrPtr(ret_val);
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlAddChildListP01
	* @brief			xmlNodePtr	xmlAddChildList(xmlNodePtr parent, xmlNodePtr cur)
	* @desc			Positive Test to add a list of node at the end of the child list of the parent merging adjacent TEXT nodes (@cur may be freed)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid parent node(xmlNodePtr(parent)), Valid first node in the list(xmlNodePtr(cur)} => { N/A | valid last child node} @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlAddChildListP01()
{
	xmlNodePtr	ret_val = NULL;
    xmlNodePtr	cur = NULL; /* the first node in the list */

	cur = gen_xmlNodePtr_in(0, 1);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid parent node, Valid first node in the list} => { N/A | valid last child node} @n
	 */
	
	ret_val = xmlAddChildList(pXmlNodePtr_1, cur);
	DTS_CHECK_EQ_MESSAGE("xmlAddChildList", (void *)ret_val, (void *)NULL, "xmlAddChildList Failed");
	
	if (ret_val == NULL) { xmlFreeNodeList(cur) ; cur = NULL ; }
	
	desret_xmlNodePtr(ret_val);  
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlHasPropP01
	* @brief			xmlAttrPtr	xmlHasProp(xmlNodePtr node, const xmlChar * name)
	* @desc			Positive Test for searching an attribute associated to a node 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	*            			{ Valid xmlNodePtr(node), const xmlChar * the attribute name} => { N/A | Valid xmlAttrPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlHasPropP01()
{
	xmlAttrPtr	ret_val = NULL;
    xmlChar*	name; /* the attribute name */

	name = __gen_const_xmlChar_ptr(0, 1);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	 *            { Valid xmlNodePtr, the attribute name} => { N/A | Valid xmlAttrPtr } @n
	 */
	
	ret_val = xmlHasProp(pXmlNodePtr_2, (const xmlChar *)name);
	DTS_CHECK_EQ_MESSAGE("xmlHasProp", (void *)ret_val, (void *)NULL, "xmlHasProp Failed");
	
	//desret_xmlAttrPtr(ret_val);
	//xmlFree(name);
	xmlResetLastError();
}

	/**    
	* @test			UTcxmlNodeSetNameP01
	* @brief			void	xmlNodeSetName (xmlNodePtr cur, const xmlChar * name)
	* @desc			Positive Test to set (or reset) the name of a node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid node being changed(xmlNodePtr(cur), xmlChar *(the new tag name)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeSetNameP01()
{
#if defined(LIBXML_TREE_ENABLED)
	xmlNodePtr	node = NULL;
    xmlChar*	pCompStr	= (xmlChar*) "//SUBJECT";
    node = xmlNewNode(NULL,BAD_CAST "temp");
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being changed, the new tag name} => { N/A | N/A } @n
	 */
    if(node)
    {
		xmlNodeSetName(node, pCompStr);

		if(node->name == NULL)
		{
			DTS_FAIL("xmlNodeSetName", "Failed");
		}
		//DTS_ASSERT_MESSAGE("xmlNodeSetName", (node->name == NULL), "xmlNodeSetName Failed");
		DTS_CHECK_EQ_MESSAGE("xmlNodeSetName", (void *)(xmlStrcmp(node->name, pCompStr)), (void *)0, "xmlNodeSetName Failed");
    }
	xmlResetLastError(); 
#endif
}
	/**    
	* @test			UTcxmlNodeSetLangP01
	* @brief			void		xmlNodeSetLang(xmlNodePtr cur, const xmlChar * lang)
	* @desc			Positive Test for to set the language of a node, i.e. the values of the xml:lang attribute.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid node being changed(xmlNodePtr(cur)), the language description(const xmlChar *(lang)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeSetLangP01()
{
#if defined(LIBXML_TREE_ENABLED)  
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being changed, the language description} => { N/A | N/A } @n
	 */
	
	xmlNodeSetLang(pXmlNodePtr_2, pConstXmlChar);
	DTS_CHECK_EQ_MESSAGE("xmlNodeSetLang", (void *)1, (void *)1, "xmlNodeSetLang Failed");
	xmlResetLastError(); 
#endif
}
	/**    
	* @test			UTcxmlSetPropP01
	* @brief			xmlAttrPtr	xmlSetProp(xmlNodePtr node, const xmlChar * name, const xmlChar * value)
	* @desc			Positive Test to set (or reset) an attribute carried by a node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	*            			{ Valid xmlNodePtr(node), const xmlChar * the attribute name, const xmlChar * the attribute value } => { N/A | Valid xmlAttrPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlSetPropP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_XINCLUDE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED) || defined(LIBXML_HTML_ENABLED)
    xmlAttrPtr	ret_val = NULL;
    xmlChar*	name = NULL; /* the attribute name (a QName) */
    int			n_name = 0;
    xmlChar*	value = NULL; /* the attribute value */

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	 *            { Valid xmlNodePtr, the attribute name, the attribute value } => { N/A | Valid xmlAttrPtr } @n
	 */

    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr-2;n_name++) {
		name = __gen_const_xmlChar_ptr(n_name, 1);
		value = __gen_const_xmlChar_ptr(n_name, 2);
		
		ret_val = xmlSetProp(pXmlNodePtr_2, (const xmlChar *)name, (const xmlChar *)value);
		DTS_CHECK_EQ_MESSAGE("xmlSetProp", (void *)ret_val, (void *)NULL, "xmlSetProp Failed");
		
		desret_xmlAttrPtr(ret_val);		
		xmlResetLastError(); 
	}
#endif	
}
	/**    
	* @test			UTcxmlNodeListGetRawStringP01
	* @brief			xmlChar *	xmlNodeListGetRawString (xmlDocPtr doc, xmlNodePtr list, int inLine)
	* @desc			Positive Test to builds the string equivalent to the text contained in the Node 
	*				list made of TEXTs and ENTITY_REFs, contrary to xmlNodeListGetString()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlChar*] @n
	*            			{ Valid xmlDocPtr, Valid Node list, 1} => { N/A | a pointer to the string copy } @n
	*				input2: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlChar*] @n
	*            			{ Valid xmlDocPtr(doc), Valid Node list(xmlNodePtr(list), int(0)} => { N/A | a pointer to the string copy } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeListGetRawStringP01()
{
#if defined(LIBXML_TREE_ENABLED)
    xmlChar*	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlDocPtr, Valid Node list, 1} => { N/A | a pointer to the string copy } @n
	 */
	
	ret_val = xmlNodeListGetRawString(pXmlDocPtr, pXmlNodePtr_1, 1);
	//Passed inputs are not proper: TODO---SUNIL
	DTS_CHECK_EQ_MESSAGE("xmlNodeListGetRawString", (void *)ret_val, (void *)NULL, "xmlNodeListGetRawString Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();

	/**
	 * @remarks   input2: [Generate valid xmlDocPtr and xmlNodePtr, Destroy xmlDocPtr, xmlNodePtr and xmlChar*] @n
	 *            { Valid xmlDocPtr, Valid Node list, 0} => { N/A | a pointer to the string copy } @n
	 */
	
	ret_val = xmlNodeListGetRawString(pXmlDocPtr, pXmlNodePtr_1, 0);
	//Passed inputs are not proper: TODO---SUNIL
	DTS_CHECK_EQ_MESSAGE("xmlNodeListGetRawString", (void *)ret_val, (void *)NULL, "xmlNodeListGetRawString Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();

#endif
}
	/**    
	* @test			UTcxmlUnsetNsPropP01
	* @brief			int	xmlUnsetNsProp (xmlNodePtr node, xmlNsPtr ns, const xmlChar * name)
	* @desc			Positive Test to remove an attribute carried by a node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	*            			{ Valid xmlNodePtr(node), Valid namespace definition(xmlNsPtr(ns)),const xmlChar * the attribute name} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUnsetNsPropP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
    int			ret_val = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	 *            { Valid xmlNodePtr, Valid namespace definition, the attribute name} => { N/A | 0 } @n
	 */

	ret_val = xmlUnsetNsProp(pXmlNodePtr_1, pXmlNsPtr, pConstXmlChar);
	//Passed inputs are not proper: TODO---SUNIL
	DTS_CHECK_NE_MESSAGE("xmlUnsetNsProp", (void *)ret_val, (void *)0, "xmlUnsetNsProp Failed");
	
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlCopyDocP01
	* @brief			xmlDocPtr	xmlCopyDoc(xmlDocPtr doc, int recursive)
	* @desc			Positive Test to do a copy of the document info.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr] @n
	*            			{ Valid xmlDocPtr(doc), int(0)} => { N/A | Valid xmlDocPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyDocP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
    xmlDocPtr ret_val = NULL;

	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr] @n
	 *            { Valid xmlDocPtr, 0} => { N/A | Valid xmlDocPtr } @n
	 */
	ret_val = xmlCopyDoc(pXmlDocPtr, 0);
	DTS_CHECK_NE_MESSAGE("xmlCopyDoc", (void *)ret_val, (void *)NULL, "xmlCopyDoc Failed");
	
	desret_xmlDocPtr(ret_val);
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlGetLineNoP01
	* @brief			long		xmlGetLineNo	(xmlNodePtr node)
	* @desc			Positive Test to get line number of @node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr(node)} => { N/A | line number of node } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetLineNoP01()
{
	long		ret_val = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr} => { N/A | line number of node } @n
	 */
   
   ret_val = xmlGetLineNo(pXmlNodePtr_2);
	DTS_CHECK_EQ_MESSAGE("xmlGetLineNo", (void *)ret_val, (void *)-1, "xmlGetLineNo Failed");
   
   xmlResetLastError();

}
	/**    
	* @test			UTcxmlBufferResizeP01
	* @brief			int	xmlBufferResize (xmlBufferPtr buf, unsigned int size)
	* @desc			Positive Test to resize a buffer to accommodate minimum size of @size.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid buffer to resize(xmlBufferPtr(buf), the desired size(unsigned int(size)} => { N/A | 1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlBufferResizeP01()
{
	int				ret_val = 0;
    xmlBufferPtr	buf = NULL; /* the buffer to resize */

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid buffer to resize, the desired size} => { N/A | 1 } @n
	 */

    buf = gen_xmlBufferPtr(0, 0);
	
	ret_val = xmlBufferResize(buf, 10);
	DTS_CHECK_EQ_MESSAGE("xmlBufferResize", (void *)ret_val, (void *)1, "xmlBufferResize Failed");
	
	des_xmlBufferPtr(0, buf, 0);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlTextConcatP01
	* @brief			int	xmlTextConcat (xmlNodePtr node, const xmlChar * content, int len)
	* @desc			Positive Test to concat the given string at the end of the existing node content
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr(node), const xmlChar * the content, int(content length)} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlTextConcatP01()
{
	int			ret_val = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr, the content, content length} => { N/A | 0 } @n
	 */
	
	ret_val = xmlTextConcat(pXmlNodePtr_2, pConstXmlChar, 10);
	//Passed inputs are not proper: TODO---SUNIL
	DTS_CHECK_NE_MESSAGE("xmlTextConcat", (void *)ret_val, (void *)0, "xmlTextConcat Failed");
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlBufferAddHeadP01
	* @brief			int	xmlBufferAddHead	(xmlBufferPtr buf, const xmlChar * str, int len)
	* @desc			Positive Test to add a string range to the beginning of an XML buffer.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid xmlBufferPtr(buf), Valid xmlChar * (str), int(the number of xmlChar to add)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferAddHeadP01()
{
	xmlBufferPtr buf = NULL; /* the buffer */
	
	buf = gen_xmlBufferPtr(0, 0);    

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid xmlBufferPtr, Valid xmlChar string, the number of xmlChar to add} => { N/A | N/A } @n
	 */
	
	xmlBufferAddHead(buf, pConstXmlChar, 10);
	DTS_CHECK_EQ_MESSAGE("xmlBufferAddHead", (void *)1, (void *)1, "xmlBufferAddHead Failed");
	des_xmlBufferPtr(0, buf, 0);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewDocPropP01
	* @brief			xmlAttrPtr	xmlNewDocProp (xmlDocPtr doc, const xmlChar * name, const xmlChar * value)
	* @desc			Positive Test to create a new property carried by a document.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlAttrPtr] @n
	*            			{ Valid xmlDocPtr(doc), const xmlChar * the name of the attribute, const xmlChar * the value of the attribute} => { N/A | Valid xmlAttrPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/	
static void
UTcxmlNewDocPropP01()
{
	xmlAttrPtr ret_val = NULL;
   
	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlAttrPtr] @n
	 *            { Valid xmlDocPtr, the name of the attribute, the value of the attribute} => { N/A | Valid xmlAttrPtr } @n
	 */

    ret_val = xmlNewDocProp(pXmlDocPtr, pConstXmlChar, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewDocProp", (void *)ret_val, (void *)NULL, "xmlNewDocProp Failed");
	
	desret_xmlAttrPtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlUnsetPropP01
	* @brief			int	xmlUnsetProp	(xmlNodePtr node,  const xmlChar * name)
	* @desc			Positive Test to remove an attribute carried by a node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr(node), const xmlChar *(the attribute name)} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUnsetPropP01()
{
#if defined(LIBXML_TREE_ENABLED) || defined(LIBXML_SCHEMAS_ENABLED)
    int			ret_val = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr, the attribute name} => { N/A | 0 } @n
	 */
	
	ret_val = xmlUnsetProp(pXmlNodePtr_2, pConstXmlChar);
	//Passed inputs are not proper: TODO---SUNIL
	DTS_CHECK_NE_MESSAGE("xmlUnsetProp", (void *)ret_val, (void *)NULL, "xmlUnsetProp Failed");
	
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlIsBlankNodeP01
	* @brief			int		xmlIsBlankNode(xmlNodePtr node)
	* @desc			Positive Test to checks whether this node is an empty or whitespace only (and possibly ignorable) text-node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks  		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr(node)} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlIsBlankNodeP01()
{
	int			ret_val = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr} => { N/A | 0 } @n
	 */
	
	ret_val = xmlIsBlankNode(pXmlNodePtr_2);	
	DTS_CHECK_EQ_MESSAGE("xmlIsBlankNode", (void *)ret_val, (void *)0, "xmlIsBlankNode Failed");
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewReferenceP01
	* @brief			xmlNodePtr	xmlNewReference (xmlDocPtr doc, const xmlChar * name)
	* @desc			Positive Test to create of a new reference node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	*            			{ Valid xmlDocPtr(doc), const xmlChar * the reference name} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewReferenceP01()
{
	xmlNodePtr	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	 *            { Valid xmlDocPtr, the reference name} => { N/A | Valid xmlNodePtr } @n
	 */

    ret_val = xmlNewReference(pXmlDocPtr, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewReference", (void *)ret_val, (void *)NULL, "xmlNewReference Failed");
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();

}
	/**    
	* @test			UTcxmlRemovePropP01
	* @brief			int	xmlRemoveProp (xmlAttrPtr cur)
	* @desc			Positive Test to unlink and free one attribute, all the content is freed too
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlAttrPtr, Destroy xmlAttrPtr] @n
	*            			{ Valid xmlAttrPtr(cur)} => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlRemovePropP01()
{
	int		ret_val = 0;
	xmlAttrPtr	ret_val_attr = NULL;

	xmlChar name[20];
	xmlDocPtr doc = NULL;
	xmlNodePtr doc_root = NULL;


	if (doc == NULL) {
		doc = xmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
	}
	if ((doc != NULL) && (doc->children != NULL) &&
		(doc->children->next != NULL) &&
		(doc->children->next->type == XML_ELEMENT_NODE))
		doc_root = doc->children->next;

	if (doc_root == NULL)
	{
		ret_val_attr = NULL;

	}
	else if (doc_root->properties != NULL) {
		ret_val_attr = doc_root->properties;
	}
	else
	{
		ret_val_attr = xmlSetProp(api_root, name, (const xmlChar *) "bar");
	}
	/**
	 * @remarks   input1: [Generate valid xmlAttrPtr, Destroy xmlAttrPtr] @n
	 *            { Valid xmlAttrPtr} => { N/A | 0 } @n
	 */

	ret_val = xmlRemoveProp(ret_val_attr);
	DTS_CHECK_EQ_MESSAGE("xmlRemoveProp", (void *)ret_val, (void *)0, "xmlRemoveProp Failed");

	//desret_xmlAttrPtr(ret_val_attr);
	//xmlFreeNode(ret_val_attr);
	xmlFreeDoc(doc);
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlBuildQNameP01
	* @brief			xmlChar *	xmlBuildQName(const xmlChar * ncname, const xmlChar * prefix, xmlChar * memory, int len)
	* @desc			Positive Test to builds the QName @prefix:@ncname in 
	*				@memory if there is enough space and prefix is not NULL nor empty
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, Destroy xmlChar*] @n
	*            			{ const xmlChar *(Valid QName), const xmlChar * (prefix), xmlChar *(memory), int(len)} => { N/A | new string } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBuildQNameP01()
{
	xmlChar*	ret_val = NULL;
    xmlChar*	memory = NULL; /* preallocated memory */

	memory = gen_xmlChar_ptr(0, 2);
    
	/**
	 * @remarks   input1: [N/A, Destroy xmlChar*] @n
	 *            { Valid QName, the prefix, preallocated memory, preallocated memory length} => { N/A | new string } @n
	 */
	
	ret_val = xmlBuildQName(pConstXmlChar, pConstXmlChar, memory, 10);
	DTS_CHECK_NE_MESSAGE("xmlBuildQName", (void *)ret_val, (void *)NULL, "xmlBuildQName Failed");
	
	if ((ret_val != NULL) && (ret_val != pConstXmlChar)&& (ret_val != memory))
		xmlFree(ret_val);
	
	ret_val = NULL;
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewCharRefP01
	* @brief			xmlNodePtr	xmlNewCharRef (xmlDocPtr doc, const xmlChar * name)
	* @desc			Positive Test for creation of a new character reference node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	*            			{ Valid xmlDocPtr(doc), const xmlChar *(name) } => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewCharRefP01()
{
	xmlNodePtr	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	 *            { Valid xmlDocPtr, the char ref string starting with #} => { N/A | Valid xmlNodePtr } @n
	 */
	ret_val = xmlNewCharRef(pXmlDocPtr, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewCharRef", (void *)ret_val, (void *)NULL, "xmlNewCharRef Failed");

	desret_xmlNodePtr(ret_val);	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewPIP01
	* @brief			xmlNodePtr	xmlNewPI(const xmlChar * name, const xmlChar * content)
	* @desc			Positive Test to creation of a processing instruction element.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, Destroy xmlNodePtr] @n
	*            			{xmlChar * (processing instruction name), const xmlChar *(content)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewPIP01()
{
	xmlNodePtr	ret_val = NULL;
    
	/**
	 * @remarks   input1: [N/A, Destroy xmlNodePtr] @n
	 *            { the processing instruction name, the PI content} => { N/A | Valid xmlNodePtr } @n
	 */
	
	ret_val = xmlNewPI(pConstXmlChar, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewPI", (void *)ret_val, (void *)NULL, "xmlNewPI Failed");
	
	desret_xmlNodePtr(ret_val);	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlTextMergeP01
	* @brief			xmlNodePtr	xmlTextMerge	(xmlNodePtr first, xmlNodePtr second)
	* @desc			Positive Test to merge two text nodes into one
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks  		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ xmlNodePtr(Valid first text node), xmlNodePtr(Valid second text node being merged)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlTextMergeP01()
{
	xmlNodePtr	ret_val = NULL;
    xmlNodePtr	first = NULL; /* the first text node */
    xmlNodePtr	second = NULL; /* the second text node being merged */

	first = gen_xmlNodePtr_in(0, 0);
	second = gen_xmlNodePtr_in(0, 1);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid first text node, Valid second text node being merged} => { N/A | Valid xmlNodePtr } @n
	 */

    ret_val = xmlTextMerge(first, second);
	DTS_CHECK_NE_MESSAGE("xmlTextMerge", (void *)ret_val, (void *)NULL, "xmlTextMerge Failed");
	
	if ((first != NULL) && (first->type != XML_TEXT_NODE)) {
		xmlUnlinkNode(second);
		xmlFreeNode(second) ; second = NULL ; 
	}
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewCDataBlockP01
	* @brief			xmlNodePtr	xmlNewCDataBlock (xmlDocPtr doc, const xmlChar * content,int len)
	* @desc			Positive Test to create a new node containing a CDATA block.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	*            			{ Valid xmlDocPtr(doc), const xmlChar * the CDATA block content, int(length of the block)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewCDataBlockP01()
{
	xmlNodePtr	ret_val = NULL;

	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	 *            { Valid xmlDocPtr, the CDATA block content, the length of the block} => { N/A | Valid xmlNodePtr } @n
	 */
	
	ret_val = xmlNewCDataBlock(pXmlDocPtr, pConstXmlChar, 10);
	DTS_CHECK_NE_MESSAGE("xmlNewCDataBlock", (void *)ret_val, (void *)NULL, "xmlNewCDataBlock Failed");
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewCommentP01
	* @brief			xmlNodePtr	xmlNewComment (const xmlChar * content)
	* @desc			Positive Test to Create of a new node containing a comment.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, Destroy xmlNodePtr] @n
	*            			{const xmlChar *(content)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewCommentP01()
{
	xmlNodePtr	ret_val = NULL;

	/**
	 * @remarks   input1: [N/A, Destroy xmlNodePtr] @n
	 *            {the comment content} => { N/A | Valid xmlNodePtr } @n
	 */
	
	ret_val = xmlNewComment(pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewComment", (void *)ret_val, (void *)NULL, "xmlNewComment Failed");
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNodeGetSpacePreserveP01
	* @brief			int	xmlNodeGetSpacePreserve (xmlNodePtr cur)
	* @desc			Positive Test to search the space preserving behaviour of a node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ xmlNodePtr(cur)} => { N/A | space preserving behaviour of a node (-1, 0 or 1) } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeGetSpacePreserveP01()
{
	int			ret_val = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being checked} => { N/A | space preserving behaviour of a node (-1, 0 or 1) } @n
	 */
	
	ret_val = xmlNodeGetSpacePreserve(pXmlNodePtr_2);
	DTS_CHECK_NE_MESSAGE("xmlNodeGetSpacePreserve", (void *)ret_val, (void *)0, "xmlNodeGetSpacePreserve Failed");
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewDocFragmentP01
	* @brief			xmlNodePtr	xmlNewDocFragment (xmlDocPtr doc)
	* @desc			Positive Test to create of a new Fragment node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	*            			{ Valid document owning the fragment(xmlDocPtr(doc)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewDocFragmentP01()
{
#if defined(LIBXML_TREE_ENABLED)
    xmlNodePtr	ret_val = NULL;

	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	 *            { Valid document owning the fragment} => { N/A | Valid xmlNodePtr } @n
	 */

    ret_val = xmlNewDocFragment(pXmlDocPtr);
	DTS_CHECK_NE_MESSAGE("xmlNewDocFragment", (void *)ret_val, (void *)NULL, "xmlNewDocFragment Failed");
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
#endif
}
	/**    
	* @test			UTcxmlBufferGrowP01
	* @brief			int	xmlBufferGrow (xmlBufferPtr buf, unsigned int len)
	* @desc			Positive Test for Growing the available space of an XML buffer.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid xmlBufferPtr(buf), the minimum free size to allocate(unsigned int(len)} => { N/A | new available space } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferGrowP01()
{
	int				ret_val = 0;
    xmlBufferPtr	buf = NULL; /* the buffer */
    int				n_buf = 0;

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid xmlBufferPtr, the minimum free size to allocate} => { N/A | new available space } @n
	 */

    for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr-1;n_buf++) {
		buf = gen_xmlBufferPtr(n_buf, 0);
		
		ret_val = xmlBufferGrow(buf, 10);
		DTS_CHECK_NE_MESSAGE("xmlBufferGrow", (void *)ret_val, (void *)-1, "xmlBufferGrow Failed");
		
		des_xmlBufferPtr(n_buf, buf, 0);
		xmlResetLastError();
	}
}
	/**    
	* @test			UTcxmlSetDocCompressModeP01
	* @brief			void	xmlSetDocCompressMode(xmlDocPtr doc, int mode)
	* @desc			Positive Test to set the compression ratio for a document, ZLIB based Correct values: 
	*				0 (uncompressed) to 9 (max compression)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, N/A] @n
	*            			{ Valid xmlDocPtr, 0} => { N/A | N/A } @n
	*				input2: [N/A, N/A] @n
	*            			{ Valid xmlDocPtr(doc), int(1)} => { N/A | N/A } @n
	*				input3: [N/A, N/A] @n
	*            			{ Valid xmlDocPtr(doc), int(9)} => { N/A | N/A } @n
	*				input4: [N/A, N/A] @n
	*            			{ Valid xmlDocPtr(doc), int(-1)} => { N/A | N/A } @n
	*				input5: [N/A, N/A] @n
	*            			{ Valid xmlDocPtr(doc), int(10)} => { N/A | N/A } @n
	*				input6: [N/A, N/A] @n
	*            			{NULL, 1} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlSetDocCompressModeP01()
{
	
	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, N/A] @n
	 *            { Valid xmlDocPtr, 0} => { N/A | N/A } @n
	 */

   xmlSetDocCompressMode(pXmlDocPtr, 0);
	int ret = xmlGetDocCompressMode(pXmlDocPtr);
   DTS_CHECK_EQ_MESSAGE("xmlGetDocCompressMode", (void *)ret, (void *)0, "xmlGetDocCompressMode 1 Failed");
   
   xmlResetLastError();
   
	/**
	 * @remarks   input2: [N/A, N/A] @n
	 *            { Valid xmlDocPtr, 1} => { N/A | N/A } @n
	 */

   xmlSetDocCompressMode(pXmlDocPtr, 1);
   ret = xmlGetDocCompressMode(pXmlDocPtr);
   DTS_CHECK_EQ_MESSAGE("xmlGetDocCompressMode", (void *)ret, (void *)1, "xmlGetDocCompressMode 2  Failed");

   xmlResetLastError();

   
	/**
	 * @remarks   input3: [N/A, N/A] @n
	 *            { Valid xmlDocPtr, 9} => { N/A | N/A } @n
	 */

   xmlSetDocCompressMode(pXmlDocPtr, 9);
   ret = xmlGetDocCompressMode(pXmlDocPtr);
   DTS_CHECK_EQ_MESSAGE("xmlGetDocCompressMode", (void *)ret, (void *)9, "xmlGetDocCompressMode 3 Failed");
   
   xmlResetLastError();

   
	/**
	 * @remarks   input4: [N/A, N/A] @n
	 *            { Valid xmlDocPtr, -1} => { N/A | N/A } @n
	 */

   xmlSetDocCompressMode(pXmlDocPtr, -1);
   ret = xmlGetDocCompressMode(pXmlDocPtr);
   DTS_CHECK_EQ_MESSAGE("xmlGetDocCompressMode", (void *)ret, (void *)0, "xmlGetDocCompressMode 4 Failed");
   
   xmlResetLastError();
   
	/**
	 * @remarks   input5: [N/A, N/A] @n
	 *            { Valid xmlDocPtr, 10} => { N/A | N/A } @n
	 */

   xmlSetDocCompressMode(pXmlDocPtr, 10);
   ret = xmlGetDocCompressMode(pXmlDocPtr);
   DTS_CHECK_EQ_MESSAGE("xmlGetDocCompressMode", (void *)ret, (void *)9, "xmlGetDocCompressMode 5 Failed");
   
   xmlResetLastError();

   
	/**
	 * @remarks   input6: [N/A, N/A] @n
	 *            {NULL, 1} => { N/A | N/A } @n
	 */

   xmlSetDocCompressMode(NULL, 1);   
   xmlResetLastError();

}
	/**    
	* @test			UTcxmlBufferEmptyP01
	* @brief			void	  xmlBufferEmpty (xmlBufferPtr buf)
	* @desc			Positive Test to empty a buffer
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid xmlBufferPtr(buf)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferEmptyP01()
{
	xmlBufferPtr	buf = NULL; /* the buffer */
    int				n_buf = 0;

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid xmlBufferPtr} => { N/A | N/A } @n
	 */

    for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr-1;n_buf++) {
		buf = gen_xmlBufferPtr(n_buf, 0);
		
		xmlBufferEmpty(buf);
		 DTS_CHECK_EQ_MESSAGE("xmlBufferEmpty", (void *)1, (void *)1, "xmlBufferEmpty Failed");
		des_xmlBufferPtr(n_buf, buf, 0);
		xmlResetLastError();
	}
}
	/**    
	* @test			UTcxmlBufferSetAllocationSchemeP01
	* @brief			void	xmlBufferSetAllocationScheme(xmlBufferPtr buf, xmlBufferAllocationScheme scheme)
	* @desc			Positive Test for Setting the allocation scheme for this buffer
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid xmlBufferPtr(buf), Valid xmlBufferAllocationScheme(scheme)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferSetAllocationSchemeP01()
{
	xmlBufferPtr				buf = NULL; /* the buffer to tune */
    int							n_buf = 0;
    xmlBufferAllocationScheme	scheme = XML_BUFFER_ALLOC_DOUBLEIT; /* allocation scheme to use */
    xmlBufferAllocationScheme	newscheme; /* allocation scheme to use */
	
    int							n_scheme = 0;

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid xmlBufferPtr, Valid xmlBufferAllocationScheme} => { N/A | N/A } @n
	 */

    for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr-1;n_buf++) {
		for (n_scheme = 2;n_scheme < gen_nb_xmlBufferAllocationScheme-1;n_scheme++) {
			buf = gen_xmlBufferPtr(n_buf, 0);
			scheme = gen_xmlBufferAllocationScheme(n_scheme, 1);
			
			xmlBufferSetAllocationScheme(buf, scheme);
			newscheme = xmlGetBufferAllocationScheme();
			DTS_CHECK_EQ_MESSAGE("xmlGetBufferAllocationScheme", (void *)newscheme, (void *)scheme, "xmlGetBufferAllocationScheme Failed");
			
			if ((buf != NULL) && (scheme == XML_BUFFER_ALLOC_IMMUTABLE) && (buf->content != NULL)/* && (buf->content != static_buf_content) */) { 
				xmlFree(buf->content); 
				buf->content = NULL;
			}
			des_xmlBufferPtr(n_buf, buf, 0);
			xmlResetLastError();
		}
	}
}
	/**    
	* @test			UTcxmlCopyNamespaceP01
	* @brief			xmlNsPtr	xmlCopyNamespace (xmlNsPtr cur)
	* @desc			Positive Test to do a copy of the namespace.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNsPtr, Destroy xmlNsPtr] @n
	 *            		{ Valid xmlNsPtr(cur)} => { N/A | Valid xmlNsPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyNamespaceP01()
{
	xmlNsPtr	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlNsPtr, Destroy xmlNsPtr] @n
	 *            { Valid xmlNsPtr} => { N/A | Valid xmlNsPtr } @n
	 */
	
	ret_val = xmlCopyNamespace(pXmlNsPtr);
	DTS_CHECK_EQ_MESSAGE("xmlCopyNamespace", (void *)ret_val, (void *)NULL, "xmlCopyNamespace Failed");
	
	if (ret_val != NULL) 
	desret_xmlNsPtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlCopyNamespaceListP01
	* @brief			xmlNsPtr	xmlCopyNamespaceList	(xmlNsPtr cur)
	* @desc			Positive Test to do a copy of an namespace list.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNsPtr, Destroy xmlNsPtr] @n
	 *            		{ Valid xmlNsPtr(cur)} => { N/A | Valid xmlNsPtr } @n
	 @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyNamespaceListP01()
{
	xmlNsPtr	ret_val = NULL;
	xmlNodePtr api_nodeptr;
    xmlDocPtr doc;
	/**
	 * @remarks   input1: [Generate valid xmlNsPtr, Destroy xmlNsPtr] @n
	 *            { Valid xmlNsPtr} => { N/A | Valid xmlNsPtr } @n
	 */
	doc = xmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
	if ((doc != NULL) && (doc->children != NULL) &&
		(doc->children->next != NULL) &&
		(doc->children->next->type == XML_ELEMENT_NODE))
	{
		api_nodeptr = doc->children->next;
		ret_val = xmlCopyNamespaceList(api_nodeptr->nsDef);
	}
	DTS_CHECK_NE_MESSAGE("xmlCopyNamespaceList", (void *)ret_val, (void *)NULL, "xmlCopyNamespaceList Failed");
	
	if (ret_val != NULL) 	
	desret_xmlNsPtr(ret_val);
	xmlFreeDoc(doc);
	xmlResetLastError();
}
		/**    
	* @test			UTcxmlCopyPropListP01
	* @brief			xmlAttrPtr	xmlCopyPropList (xmlNodePtr target, xmlAttrPtr cur)
	* @desc			Positive Test to do a copy of an attribute list.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr and xmlAttrPtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	*            			{ Valid node where the attributes will be grafted(xmlNodePtr(target), the first attribute(xmlAttrPtr(cur)} => { N/A | Valid xmlAttrPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyPropListP01()
{
	xmlAttrPtr	ret_val = NULL;
	xmlAttrPtr	ret_val_attr = NULL;

	xmlChar name[20];
	xmlDocPtr doc = NULL;
	xmlNodePtr doc_root = NULL;


	if (doc == NULL) {
		doc = xmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
	}
	if ((doc != NULL) && (doc->children != NULL) &&
		(doc->children->next != NULL) &&
		(doc->children->next->type == XML_ELEMENT_NODE))
		doc_root = doc->children->next;

	if (doc_root == NULL)
	{
		ret_val_attr = NULL;

	}
	else if (doc_root->properties != NULL) {
		ret_val_attr = doc_root->properties;
	}
	else
	{
		ret_val_attr = xmlSetProp(api_root, name, (const xmlChar *) "bar");
	}
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr and xmlAttrPtr, Destroy xmlNodePtr and xmlAttrPtr] @n
	 *            { Valid node where the attributes will be grafted, the first attribute} => { N/A | Valid xmlAttrPtr } @n
	 */
	
	ret_val = xmlCopyPropList(pXmlNodePtr_2, ret_val_attr);
	DTS_CHECK_NE_MESSAGE("xmlCopyPropList", (void *)ret_val, (void *)NULL, "xmlCopyPropList Failed");
	
	desret_xmlAttrPtr(ret_val_attr);
	desret_xmlAttrPtr(ret_val);
	xmlFreeDoc(doc);
	xmlResetLastError();
}
		/**    
	* @test			UTcxmlNodeAddContentP01
	* @brief			void	xmlNodeAddContent (xmlNodePtr cur, const xmlChar * content)
	* @desc			Positive Test to Append the extra substring to the node content.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid node being modified(xmlNodePtr(cur), extra content(const xmlChar *(content)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeAddContentP01()
{
	
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being modified, extra content} => { N/A | N/A } @n
	 */
	
	xmlNodeAddContent(pXmlNodePtr_2, pConstXmlChar);
	DTS_CHECK_EQ_MESSAGE("xmlNodeAddContent", (void *)1, (void *)1, "xmlNodeAddContent Failed");
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlNodeGetLangP01
	* @brief			xmlChar *	xmlNodeGetLang (xmlNodePtr cur)
	* @desc			Positive Test to search the language of a node,
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	*            			{ Valid node being checked(xmlNodePtr(cur)} => { N/A | a pointer to the language value } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeGetLangP01()
{
	xmlChar*	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr and xmlChar*] @n
	 *            { Valid node being checked} => { N/A | a pointer to the language value } @n
	 */
	
	ret_val = xmlNodeGetLang(pXmlNodePtr_1);
	//Passed inputs are not proper: TODO---SUNIL
	DTS_CHECK_EQ_MESSAGE("xmlNodeGetLang", (void *)ret_val, (void *)NULL, "xmlNodeGetLang Failed");
	
	desret_xmlChar_ptr(ret_val);
	xmlResetLastError();

}
	/**    
	* @test			UTcxmlNodeIsTextP01
	* @brief			int	xmlNodeIsText (xmlNodePtr node)
	* @desc			Positive Test to check whether  this node is a Text node ?
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid node which is not a text node(xmlNodePtr(node) } => { N/A | 0 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeIsTextP01()
{
	int			ret_val = 0;
    
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node which is not a text node } => { N/A | 0 } @n
	 */
	
	ret_val = xmlNodeIsText(pXmlNodePtr_2);
	DTS_CHECK_EQ_MESSAGE("xmlNodeIsText", (void *)ret_val, (void *)0, "xmlNodeIsText Failed");
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlSetCompressModeP01
	* @brief			void	xmlSetCompressMode (int mode)
	* @desc			Positive Test for setting the default compression mode used, 
	*				ZLIB based Correct values: 0 (uncompressed) to 9 (max compression)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A] @n
	*            			{ the compression ratio int(0-9)} => { N/A | N/A } @n
	*				input2: [N/A, N/A] @n
	*            			{int(-1)} => { N/A | N/A } @n
	*				input3: [N/A, N/A] @n
	*            			{int(10)} => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlSetCompressModeP01()
{
	int	mode = 0; /* the compression ratio */
	int newmode = 0;
   
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { the compression ratio (0-9)} => { N/A | N/A } @n
	 */

    for (mode = 0; mode < 10; mode++) {

		xmlSetCompressMode(mode);
		newmode = xmlGetCompressMode();
		DTS_CHECK_EQ_MESSAGE("xmlSetCompressMode", (void *)mode, (void *)newmode, "xmlSetCompressMode Failed");
		
		xmlResetLastError();
	}

	/**
	 * @remarks   input2: [N/A, N/A] @n
	 *            {-1} => { N/A | N/A } @n
	 */

	xmlSetCompressMode(-1);
	newmode = xmlGetCompressMode();
	
	DTS_CHECK_EQ_MESSAGE("xmlSetCompressMode", (void *)newmode, (void *)0, "xmlSetCompressMode Failed");

	xmlResetLastError();

	/**
	 * @remarks   input3: [N/A, N/A] @n
	 *            {10} => { N/A | N/A } @n
	 */

	xmlSetCompressMode(10);
	newmode = xmlGetCompressMode();

	DTS_CHECK_EQ_MESSAGE("xmlSetCompressMode", (void *)newmode, (void *)9, "xmlSetCompressMode Failed");


}
	/**    
	* @test			UTcxmlBufferContentP01
	* @brief			const xmlChar *	xmlBufferContent	(const xmlBufferPtr buf)
	* @desc			Positive Test to extract the content of a buffer
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr and xmlChar*] @n
	*            			{ Valid xmlBufferPtr(buf)} => { N/A | internal content } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferContentP01()
{
	const xmlChar*	ret_val = NULL;
    xmlBufferPtr	buf = NULL; /* the buffer */

	buf = gen_const_xmlBufferPtr(0, 0);

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr and xmlChar*] @n
	 *            { Valid xmlBufferPtr} => { N/A | internal content } @n
	 */
	
	ret_val = xmlBufferContent((const xmlBufferPtr)buf);
	DTS_CHECK_NE_MESSAGE("xmlBufferContent", (void *)ret_val, (void *)NULL, "xmlBufferContent Failed");

	if (buf != NULL) {
		xmlBufferFree(buf);
	}
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlBufferLengthP01
	* @brief			int	xmlBufferLength (const xmlBufferPtr buf)
	* @desc			Positive Test to get the length of a buffer
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid xmlBufferPtr(buf)} => { N/A | the length of data in the internal content } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferLengthP01()
{
	int				ret_val = 0;
    xmlBufferPtr	buf = NULL; /* the buffer */

	buf = gen_const_xmlBufferPtr(0, 0);

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid xmlBufferPtr} => { N/A | the length of data in the internal content } @n
	 */
	
	ret_val = xmlBufferLength((const xmlBufferPtr)buf);
	DTS_CHECK_EQ_MESSAGE("xmlBufferContent", (void *)ret_val, (void *)0, "xmlBufferContent Failed");

	if (buf != NULL) {
		xmlBufferFree(buf);
	}
	
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlGetLastChildP01
	* @brief			xmlNodePtr	xmlGetLastChild(xmlNodePtr parent)
	* @desc			Positive Test to Search the last child of a node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*           			{ Valid parent node(xmlNodePtr(parent)} => { N/A | the last child node  } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlGetLastChildP01()
{
	xmlNodePtr		ret_val = NULL;
	xmlNodePtr	node = NULL;
	xmlNodePtr	node1 = NULL; 
	node = xmlNewNode(NULL, BAD_CAST "node4");
	DTS_CHECK_NE_MESSAGE("xmlGetLastChild", (void *)node, (void *)NULL, "xmlNewNode 1 Failed");

	node1 = xmlNewText(BAD_CAST "other way to create content (which is also a node)");
	DTS_CHECK_NE_MESSAGE("xmlGetLastChild", (void *)node1, (void *)NULL, "xmlNewNode 2 Failed");

	xmlAddChild(node, node1);
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid parent node} => { N/A | the last child node  } @n
	 */
	
	ret_val = xmlGetLastChild(node);
	DTS_CHECK_NE_MESSAGE("xmlGetLastChild", (void *)ret_val, (void *)NULL, "xmlGetLastChild Failed");
	
	//desret_xmlNodePtr(ret_val);
	if (NULL != node)
	{
		xmlFreeNode(node);
	}
	xmlResetLastError();
}
	
	/**    
	* @test			UTcxmlNewDocCommentP01
	* @brief			xmlNodePtr	xmlNewDocComment	(xmlDocPtr doc, const xmlChar * content)
	* @desc			Positive Test for Creation of a new node containing a comment within a document.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	*            			{ Valid xmlDocPtr(doc), the comment content(const xmlChar *(content)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewDocCommentP01()
{
	xmlNodePtr		ret_val = NULL;

	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	 *            { Valid xmlDocPtr, the comment content} => { N/A | Valid xmlNodePtr } @n
	 */

   ret_val = xmlNewDocComment(pXmlDocPtr, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewDocComment", (void *)ret_val, (void *)NULL, "xmlNewDocComment Failed");
   
   desret_xmlNodePtr(ret_val);
   xmlResetLastError();
}
	/**    
	* @test			UTcxmlSetNsP01
	* @brief			void	xmlSetNs	 (xmlNodePtr node, xmlNsPtr ns)
	* @desc			Positive Test for Associating a namespace to a node, a posteriori.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	*            			{ Valid node in the document(xmlNodePtr(node), Valid namespace pointer(xmlNsPtr(ns)} => { N/A | N/A } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlSetNsP01()
{
	
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	 *            { Valid node in the document, Valid namespace pointer} => { N/A | N/A } @n
	 */
	
	xmlSetNs(pXmlNodePtr_1, pXmlNsPtr);
	DTS_CHECK_EQ_MESSAGE("xmlSetNs", (void *)1, (void *)1, "xmlSetNs Failed");
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlCopyNodeP01
	* @brief			xmlNodePtr	xmlCopyNode	(const xmlNodePtr node, int extended)
	* @desc			Positive Test  to Do a copy of the node.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr(node), int(1)} => { N/A | Valid xmlNodePtr } @n
	*				input2: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid xmlNodePtr(node), int(2)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyNodeP01()
{
	xmlNodePtr	ret_val = NULL;
    xmlNodePtr	node = NULL; /* the node */

	node = xmlNewDocText(pXmlDocPtr, pConstXmlChar);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr, 1} => { N/A | Valid xmlNodePtr } @n
	 */  
	
	ret_val = xmlCopyNode((const xmlNodePtr)node, 1);
	DTS_CHECK_NE_MESSAGE("xmlCopyNode", (void *)ret_val, (void *)NULL, "xmlCopyNode Failed");
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();

	/**
	 * @remarks   input2: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid xmlNodePtr, 2} => { N/A | Valid xmlNodePtr } @n
	 */  
	
	ret_val = xmlCopyNode((const xmlNodePtr)node, 2);
	DTS_CHECK_NE_MESSAGE("xmlCopyNode", (void *)ret_val, (void *)NULL, "xmlCopyNode Failed");
	
	desret_xmlNodePtr(node);
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();

}
	/**    
	* @test			UTcxmlCopyNodeListP01
	* @brief			xmlNodePtr	xmlCopyNodeList (const xmlNodePtr node)
	* @desc			Positive Test to Do a recursive copy of the node list. 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	*            			{ Valid first node in the list(const xmlNodePtr(node)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCopyNodeListP01()
{
	xmlNodePtr	ret_val = NULL;
    xmlNodePtr	node = NULL; /* the first node in the list. */

	node = xmlNewDocText(pXmlDocPtr, pConstXmlChar);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid first node in the list} => { N/A | Valid xmlNodePtr } @n
	 */

    ret_val = xmlCopyNodeList((const xmlNodePtr)node);
	DTS_CHECK_NE_MESSAGE("xmlCopyNodeList", (void *)ret_val, (void *)NULL, "xmlCopyNodeList Failed");
	
	desret_xmlNodePtr(node);
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlDocCopyNodeP01
	* @brief			xmlNodePtr	xmlDocCopyNode(const xmlNodePtr node, xmlDocPtr doc, int extended)
	* @desc			Positive Test to Do a copy of the node to a given document.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr and xmlDocPtr, Destroy xmlNodePtr and xmlDocPtr] @n
	*            			{ Valid xmlNodePtr(node), Valid xmlDocPtr(doc), int(1)} => { N/A | Valid xmlNodePtr } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlDocCopyNodeP01()
{
	xmlNodePtr	ret_val = NULL;
    xmlNodePtr	node = NULL; /* the node */

	node = xmlNewDocText(pXmlDocPtr, pConstXmlChar);
	
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr and xmlDocPtr, Destroy xmlNodePtr and xmlDocPtr] @n
	 *            { Valid xmlNodePtr, Valid xmlDocPtr, 1} => { N/A | Valid xmlNodePtr } @n
	 */

    ret_val = xmlDocCopyNode((const xmlNodePtr)node, pXmlDocPtr, 1);
	DTS_CHECK_NE_MESSAGE("xmlDocCopyNode", (void *)ret_val, (void *)NULL, "xmlDocCopyNode Failed");
	
	desret_xmlNodePtr(node);
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlGetBufferAllocationSchemeP01
	* @brief			xmlBufferAllocationScheme	xmlGetBufferAllocationScheme(void)
	* @desc			Positive Test to get the buffer allocation scheme
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Set BufferAllocationScheme as XML_BUFFER_ALLOC_EXACT, N/A] @n
	*            			{ void } => { N/A | XML_BUFFER_ALLOC_EXACT } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetBufferAllocationSchemeP01()
{
	xmlBufferAllocationScheme ret_val = XML_BUFFER_ALLOC_DOUBLEIT;

	xmlSetBufferAllocationScheme(XML_BUFFER_ALLOC_EXACT);

	/**
	 * @remarks   input1: [Set BufferAllocationScheme as XML_BUFFER_ALLOC_EXACT, N/A] @n
	 *            { void } => { N/A | XML_BUFFER_ALLOC_EXACT } @n
	 */
	
	ret_val = xmlGetBufferAllocationScheme();
	DTS_CHECK_EQ_MESSAGE("xmlGetBufferAllocationScheme", (void *)ret_val, (void *)XML_BUFFER_ALLOC_EXACT, "xmlGetBufferAllocationScheme Failed");
	
	xmlResetLastError();        
}
	/**    
	* @test			UTcxmlGetCompressModeP01
	* @brief			int	xmlGetCompressMode (void)
	* @desc			Positive Test to get the default compression mode used, ZLIB based.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Set CompressMode as 2, N/A] @n
	*           			{ void } => { N/A | 2 } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetCompressModeP01()
{
	int	ret_val = 0;

	xmlSetCompressMode(2);

	/**
	 * @remarks   input1: [Set CompressMode as 2, N/A] @n
	 *            { void } => { N/A | 2 } @n
	 */
	
	ret_val = xmlGetCompressMode();
	DTS_CHECK_EQ_MESSAGE("xmlGetCompressMode", (void *)ret_val, (void *)2, "xmlGetCompressMode Failed");

	xmlResetLastError();
}
	/**    
	* @test			UTcxmlSetBufferAllocationSchemeP01
	* @brief			void	xmlSetBufferAllocationScheme(xmlBufferAllocationScheme scheme)
	* @desc			Positive Test to set the buffer allocation method
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A] @n
	*            			{ Valid xmlBufferAllocationScheme(scheme) } => { N/A | N/A } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlSetBufferAllocationSchemeP01()
{
	xmlBufferAllocationScheme	scheme = XML_BUFFER_ALLOC_DOUBLEIT; /* allocation method to use */
	xmlBufferAllocationScheme	newscheme; /* allocation method to use */
	int							n_scheme = 0;

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { Valid xmlBufferAllocationScheme } => { N/A | N/A } @n
	 */

    for (n_scheme = 0;n_scheme < gen_nb_xmlBufferAllocationScheme-1;n_scheme++) {
		scheme = gen_xmlBufferAllocationScheme(n_scheme, 0);
		
		xmlSetBufferAllocationScheme(scheme);
		newscheme = xmlGetBufferAllocationScheme();
		DTS_CHECK_EQ_MESSAGE("xmlSetBufferAllocationScheme", (void *)scheme, (void *)newscheme, "xmlSetBufferAllocationScheme Failed");
		
		xmlResetLastError();
	}
}
		/**    
	* @test			UTcxmlBufferWriteCharP01
	* @brief			void	xmlBufferWriteChar (xmlBufferPtr buf, const char * string)
	* @desc			Positive Test for routine which manages and grows an output buffer.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid XML output buffer(xmlBufferPtr(buf), the string to add(const char *(string)} => { N/A | xmlBufferPtr with added input string at the end } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferWriteCHARP01()
{
	xmlBufferPtr	buf = NULL; /* the XML buffer */
    int				n_buf = 0;

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid XML output buffer, the string to add} => { N/A | xmlBufferPtr with added input string at the end} @n
	 */
	xmlSetBufferAllocationScheme(XML_BUFFER_ALLOC_EXACT);
    for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr-1;n_buf++) {
		buf = gen_xmlBufferPtr(n_buf, 0);

		xmlBufferWriteCHAR(buf, pConstXmlChar);
		DTS_CHECK_EQ_MESSAGE("xmlBufferWriteCHAR", (void *)1, (void *)1, "xmlBufferWriteCHAR Failed");
		des_xmlBufferPtr(n_buf, buf, 0);
		xmlResetLastError();
	}
}
	/**    
	* @test			UTcxmlBufferWriteCharP01
	* @brief			void	xmlBufferWriteChar (xmlBufferPtr buf, const char * string)
	* @desc			Positive Test for routine which manages and grows an output buffer.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	*            			{ Valid XML output buffer(xmlBufferPtr(buf), the string to add(const char *(string)} => { N/A | xmlBufferPtr with added input string at the end } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferWriteCharP01()
{
	xmlBufferPtr	buf = NULL; /* the XML buffer output */
    int				n_buf = 0;

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr, Destroy xmlBufferPtr] @n
	 *            { Valid XML output buffer, the string to add} => { N/A | xmlBufferPtr with added input string at the end } @n
	 */
	xmlSetBufferAllocationScheme(XML_BUFFER_ALLOC_EXACT);
    for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr-1;n_buf++) {
		buf = gen_xmlBufferPtr(n_buf, 0);
		xmlBufferWriteChar(buf, "Test String");
		DTS_CHECK_EQ_MESSAGE("xmlBufferWriteChar", (void *)1, (void *)1, "xmlBufferWriteChar Failed");
		des_xmlBufferPtr(n_buf, buf, 0);
	}
}
	/**    
	* @test			UTcxmlNewDocRawNodeP01
	* @brief			xmlNodePtr	xmlNewDocRawNode(xmlDocPtr doc, xmlNsPtr ns, const xmlChar * name, const xmlChar * content)
	* @desc			Positive Test to Create of a new node element within a document. @ns and @content are optional (NULL).
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	*            			{ Valid xmlDocPtr(doc), Valid namespace(xmlNsPtr(ns)), const xmlChar * the node name, const xmlChar * the text content} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewDocRawNodeP01()
{
#if defined(LIBXML_TREE_ENABLED)
#ifdef LIBXML_TREE_ENABLED
    xmlNodePtr	ret_val = NULL;
    
	/**
	 * @remarks   input1: [Generate valid xmlDocPtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	 *            { Valid xmlDocPtr, Valid namespace, the node name, the text content} => { N/A | Valid xmlNodePtr } @n
	 */
	
	ret_val = xmlNewDocRawNode(pXmlDocPtr, pXmlNsPtr, pConstXmlChar, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewDocRawNode", (void *)ret_val, (void *)NULL, "xmlNewDocRawNode Failed");
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
#endif
#endif
}
		/**    
	* @test			UTcxmlNewDocTextP01
	* @brief			xmlNodePtr	xmlNewDocText(xmlDocPtr doc, const xmlChar * content)
	* @desc			Positive Test for Creation of a new text node within a document.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	*            			{ Valid xmlDocPtr(doc), const xmlChar * the text content} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewDocTextP01()
{
	xmlNodePtr	ret_val = NULL;

	/**
	 * @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlNodePtr] @n
	 *            { Valid xmlDocPtr, the text content} => { N/A | Valid xmlNodePtr } @n
	 */

  ret_val = xmlNewDocText(pXmlDocPtr, pConstXmlChar);
  DTS_CHECK_NE_MESSAGE("xmlNewDocText", (void *)ret_val, (void *)NULL, "xmlNewDocText Failed");

  desret_xmlNodePtr(ret_val);
  xmlResetLastError();
}
	/**    
	* @test			UTcxmlNewTextChildP01
	* @brief			xmlNodePtr	xmlNewTextChild (xmlNodePtr parent, xmlNsPtr ns, const xmlChar * name, const xmlChar * content)
	* @desc			Positive Test for Creation of a new child element, added at the end of @parent children list.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	*            			{ Valid parent node(xmlNodePtr(parent), xmlNsPtr(namespace), const xmlChar *(name) the name of the child, const xmlChar * (content) the text content of the child} => { N/A | Valid xmlNodePtr } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNewTextChildP01()
{
#if defined(LIBXML_TREE_ENABLED)
#ifdef LIBXML_TREE_ENABLED
    xmlNodePtr	ret_val = NULL;
    xmlChar*	name = NULL; /* the name of the child */
    xmlChar*	content = NULL; /* the text content of the child if any. */

	name = __gen_const_xmlChar_ptr(0, 2);
	content = __gen_const_xmlChar_ptr(2, 3);

	/**
	 * @remarks   input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	 *            { Valid parent node, Valid namespace, the name of the child, the text content of the child} => { N/A | Valid xmlNodePtr } @n
	 */
	
	ret_val = xmlNewTextChild(pXmlNodePtr_2, pXmlNsPtr, (const xmlChar *)name, (const xmlChar *)content);
	DTS_CHECK_EQ_MESSAGE("xmlNewTextChild", (void *)ret_val, (void *)NULL, "xmlNewTextChild Failed");
	
	desret_xmlNodePtr(ret_val);
	xmlResetLastError();
#endif
#endif
}
	/**    
	* @test			UTcxmlNodeSetContentP01
	* @brief			xmlNodePtr	xmlNewTextChild(xmlNodePtr parent, xmlNsPtr ns, const xmlChar * name,const xmlChar * content)
	* @desc			Positive Test for Creation of a new child element, added at the end of @parent children list. 
	*				@ns and @content parameters are optional (NULL).
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlNodePtr and xmlNsPtr, Destroy xmlNodePtr and xmlNsPtr] @n
	*            			{ Valid parent node xmlNodePtr(parent), Valid namespace xmlNsPtr(ns), the name of the child(const xmlChar *(name)), the text content of the child, const xmlChar *(content)} => { N/A | Valid xmlNodePtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNodeSetContentP01()
{
	
	/**
	 * @remarks   input1: [Generate valid xmlNodePtr, Destroy xmlNodePtr] @n
	 *            { Valid node being modified, the new value of the content} => { N/A | N/A } @n
	 */
	
	xmlNodeSetContent(pXmlNodePtr_1, pConstXmlChar);
	DTS_CHECK_EQ_MESSAGE("xmlNodeSetContent", (void *)1, (void *)1, "xmlNodeSetContent Failed");
	xmlResetLastError();

}
	/**    
	* @test			UTcxmlNewDtdP01
	* @brief			xmlDtdPtr	xmlNewDtd(xmlDocPtr doc,  const xmlChar * name,  const xmlChar * ExternalID, const xmlChar * SystemID)
	* @desc			Positive Test for Creation of a new DTD for the external subset.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlDtdPtr] @n
	*            			{ Valid xmlDocPtr(doc), const xmlChar * (name), const xmlChar *(external ID), const xmlChar *(system ID)} => { N/A | Valid xmlDtdPtr } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlNewDtdP01()
{
	xmlDtdPtr	ret_val = NULL;
	
	/**
	* @remarks   input1: [Generate valid xmlDocPtr, Destroy xmlDocPtr and xmlDtdPtr] @n
	*            { Valid xmlDocPtr, the DTD name, the external ID, the system ID} => { N/A | Valid xmlDtdPtr } @n
	*/

	ret_val = xmlNewDtd(pXmlDocPtr, pConstXmlChar, pConstXmlChar, pConstXmlChar);
	DTS_CHECK_NE_MESSAGE("xmlNewDtd", (void *)ret_val, (void *)NULL, "xmlNewDtd Failed");


	desret_xmlDtdPtr(ret_val);
	xmlResetLastError();
}

#ifdef STDIO_FILE
	/**    
	* @test			UTcxmlBufferDumpP01
	* @brief			int	xmlBufferDump(FILE * file, xmlBufferPtr buf)
	* @desc			Positive Test for Dumps an XML buffer to a FILE.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Generate valid xmlBufferPtr and create a file, Destroy xmlBufferPtr] @n
	*            			{ Valid FILE pointer(FILE *(file)), Valid XML buffer(xmlBufferPtr(buf))} => { N/A | number of characters written } @n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlBufferDumpP01()
{
	int				ret_val;
	xmlBufferPtr	pBuf = NULL;
	FILE*			file;
	Exception		e = 0;

	file = fopen(UTSXMLHOME"/UTcxmlBufferDumpP01.xml", "w");
	

	xmlSetBufferAllocationScheme(XML_BUFFER_ALLOC_EXACT);
	pBuf = xmlBufferCreateSize(64);
	xmlBufferAdd(pBuf, (const xmlChar*) "UTcxmlBufferDumpP01", 20);

	/**
	 * @remarks   input1: [Generate valid xmlBufferPtr and create a file, Destroy xmlBufferPtr] @n
	 *            { Valid FILE pointer, Valid XML buffer} => { N/A | number of characters written } @n
	 */

	ret_val = xmlBufferDump( file, pBuf);
	DTS_CHECK_GT_MESSAGE("xmlBufferDump", (void *)ret_val, (void *)0, "xmlBufferDump Failed");

	fclose(file);
	if (pBuf) {
		xmlBufferFree(pBuf);
	}
}
#endif

static void startup( void);
static void cleanup( void);

void (*tet_startup)( void) = startup;
void (*tet_cleanup)( void) = cleanup;

static void startup( void)
{
        /* start of TC */
        tet_printf("TC starts.");
	pXmlDocPtr = gen_xmlDocPtr(0,0);
}

static void cleanup( void)
{
        /* end of TC */
        tet_printf("TC ends.");
}

struct tet_testlist tet_testlist[] = {
	// Handling of out of context errors
	{UTcTreeP01,1},
	{UTcTreeP02,2},
	{UTcxmlStringLenGetNodeListP01,3},
	{UTcxmlValidateQNameP01,4},
	{UTcxmlGetNodePathP01,5},
	{UTcxmlValidateNMTokenP01,6},
	{UTcxmlValidateNameP01,7},
	{UTcxmlReconciliateNsP01,8},
	{UTcxmlSearchNsP01,9},
	{UTcxmlValidateNCNameP01,10},
	
	{UTcxmlSearchNsByHrefP01,11},
	{UTcxmlNodeBufGetContentP01,12},
	{UTcxmlNodeGetBaseP01,13},
	{UTcxmlCopyPropP01,14},
	{UTcxmlNodeAddContentLenP01,15},
	{UTcxmlHasNsPropP01,16},
	{UTcxmlGetNsPropP01,17},
	{UTcxmlNewNsP01,18},
	{UTcxmlAddPrevSiblingP01,19},
	{UTcxmlAddNextSiblingP01,20},
	
	{UTcxmlNodeGetContentP01,21},
	{UTcxmlCopyDtdP01,22},
	{UTcxmlGetNoNsPropP01,23},
	{UTcxmlReplaceNodeP01,24},
	{UTcxmlNodeSetContentLenP01,25},
	{UTcxmlGetPropP01,26},
	{UTcxmlNodeSetBaseP01,27},
	{UTcxmlNodeSetSpacePreserveP01,28},
	{UTcxmlSetNsPropP01,29},
	{UTcxmlAddChildListP01,30},
	
	{UTcxmlHasPropP01,31},
	{UTcxmlNodeSetNameP01,32},
	{UTcxmlNodeSetLangP01,33},
	{UTcxmlSetPropP01,35},
	{UTcxmlNodeListGetRawStringP01,36},
	{UTcxmlUnsetNsPropP01,37},
	{UTcxmlCopyDocP01,38},
	{UTcxmlGetLineNoP01,39},
	{UTcxmlBufferResizeP01,40},
	
	{UTcxmlTextConcatP01,41},
	{UTcxmlBufferAddHeadP01,42},
	{UTcxmlNewDocPropP01,43},
	{UTcxmlUnsetPropP01,44},
	{UTcxmlIsBlankNodeP01,45},
	{UTcxmlNewReferenceP01,46},
	{UTcxmlRemovePropP01,47},
	{UTcxmlBuildQNameP01,48},
	{UTcxmlNewDtdP01,49},
	{UTcxmlNewCharRefP01,50},
	
	{UTcxmlNewPIP01,51},
	{UTcxmlTextMergeP01,52},
	{UTcxmlNewCDataBlockP01,53},
	{UTcxmlNewCommentP01,54},
	{UTcxmlNodeGetSpacePreserveP01,55},
	{UTcxmlNewDocFragmentP01,56},
	{UTcxmlBufferGrowP01,57},
	{UTcxmlSetDocCompressModeP01,58},
	{UTcxmlBufferEmptyP01,59},
	{UTcxmlBufferSetAllocationSchemeP01,60},
	
	{UTcxmlCopyNamespaceListP01,61},
	{UTcxmlCopyNamespaceP01,62},
	{UTcxmlCopyPropListP01,63},
	{UTcxmlNodeAddContentP01,64},
	{UTcxmlNodeGetLangP01,65},
	{UTcxmlNodeIsTextP01,66},
	{UTcxmlSetCompressModeP01,67},
	{UTcxmlBufferContentP01,68},
	{UTcxmlBufferLengthP01,69},
	{UTcxmlGetLastChildP01,70},
	
	{UTcxmlNewDocCommentP01,71},
	{UTcxmlSetNsP01,72},
	{UTcxmlCopyNodeP01,73},
	{UTcxmlCopyNodeListP01,74},
	{UTcxmlDocCopyNodeP01,75},
	{UTcxmlGetBufferAllocationSchemeP01,76},
	{UTcxmlGetCompressModeP01,77},
	{UTcxmlSetBufferAllocationSchemeP01,78},
	{UTcxmlBufferWriteCHARP01,79},
	{UTcxmlBufferWriteCharP01,80},
	
	{UTcxmlNewDocRawNodeP01,81},
	{UTcxmlNewDocTextP01,82},
	{UTcxmlNewTextChildP01,83},
	{UTcxmlNodeSetContentP01,84},
#ifdef STDIO_FILE
	{UTcxmlBufferDumpP01, 85},
#endif

	{ NULL, 0 },
	
};
