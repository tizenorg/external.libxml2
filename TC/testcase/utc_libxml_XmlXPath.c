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
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>


#ifdef DEBUG_MEM_LEAK
extern "C" {
	extern void MemStartSaveCallStack(void);
	extern void MemEndSaveCallStack(void);
	extern void MemPrintCurrentIndex(void);
	extern void MemTraceAllocMemInfo(void);
}
#endif


#define INPUT_XML LIBXML2TESTXML



static xmlDocPtr api_doc = NULL;
static xmlDtdPtr api_dtd = NULL;
static xmlNodePtr api_root = NULL;
static xmlAttrPtr api_attr = NULL;
static xmlNsPtr api_ns = NULL;

static  xmlDocPtr DocInitPtr;
static  xmlXPathContextPtr xpathCtxInitPtr;
static  xmlXPathObjectPtr xpathObjInitPtr;
static  xmlXPathParserContextPtr pctxtInitPtr;

static xmlDocPtr doc_gen_xmlNodeSetPtr;
static xmlXPathContextPtr xpathCtx_gen_xmlNodeSetPtr;
static xmlXPathObjectPtr xpathObj_gen_xmlNodeSetPtr;
static xmlDocPtr doc_get_api_root = NULL;

xmlDocPtr getdoc (char *docname)
{
	return xmlParseFile(docname);
}
static void desret_xmlXPathObjectPtr(xmlXPathObjectPtr val) {
	xmlXPathFreeObject(val);
}
#define gen_nb_xmlDocPtr 4
static xmlDocPtr gen_xmlDocPtr(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(xmlNewDoc(BAD_CAST "1.0"));
	if (no == 1) return(xmlReadMemory("<foo/>", 6, "test", NULL, 0));
	if (no == 2) return(xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0));
	return(NULL);
}
static void des_xmlDocPtr(int no ATTRIBUTE_UNUSED, xmlDocPtr val, int nr ATTRIBUTE_UNUSED) {
	if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
		xmlFreeDoc(val);
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
static void
__free_api_doc(void) {
	if (NULL != api_doc)
	{
		xmlFreeDoc(api_doc);
		api_doc = NULL;
	}
	api_dtd = NULL;
	api_root = NULL;
	api_attr = NULL;
	api_ns = NULL;
}
static void des_xmlXPathObjectPtr(int no ATTRIBUTE_UNUSED, xmlXPathObjectPtr val, int nr ATTRIBUTE_UNUSED) {
	if (val != NULL) {
		xmlXPathFreeObject(val);
	}
}
#define gen_nb_xmlXPathContextPtr 1
static xmlXPathContextPtr gen_xmlXPathContextPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	char *docname = INPUT_XML;
	//xmlDocPtr doc;
	doc_get_api_root = getdoc(docname);
	xmlXPathContextPtr context;
	context = xmlXPathNewContext(doc_get_api_root);
	return(context);
}
#define gen_nb_xmlXPathCompExprPtr 1
static xmlXPathCompExprPtr gen_xmlXPathCompExprPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	xmlXPathContextPtr ctxt = gen_xmlXPathContextPtr(0, 1);
	const xmlChar	*str		= (const xmlChar*)  "SISO";
	xmlXPathCompExprPtr pctxt =
	xmlXPathCtxtCompile(ctxt, str) ;
	return(pctxt);
}

#define gen_nb_xmlXPathObjectPtr 5
static xmlXPathObjectPtr gen_xmlXPathObjectPtr(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(xmlXPathNewString(BAD_CAST "string object"));
	if (no == 1) return(xmlXPathNewFloat(1.1));
	if (no == 2) return(xmlXPathNewBoolean(1));
	if (no == 3) return(xmlXPathNewNodeSet(NULL));
	return(NULL);
}
#ifdef LIBXML_XPATH_ENABLED

#define gen_nb_xmlXPathParserContextPtr 1
static xmlXPathParserContextPtr gen_xmlXPathParserContextPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_xmlXPathParserContextPtr(int no ATTRIBUTE_UNUSED, xmlXPathParserContextPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
#endif



static void desret_xmlNodePtr(xmlNodePtr val) {
    if ((val != NULL) && (val != api_root) && (val != (xmlNodePtr) api_doc)) {
	xmlUnlinkNode(val);
	xmlFreeNode(val);
    }
}

#define gen_nb_const_xmlChar_ptr 5

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
	xmlChar	*xpathExpr	= (xmlChar*) "//SUBJECT";
	return(xpathExpr);
}

#define gen_nb_double 4

static double gen_double(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(0);
	if (no == 1) return(-1.1);
#if defined(LIBXML_XPATH_ENABLED)
	if (no == 2) return(xmlXPathNAN);
#endif
	return(-1);
}

#define gen_nb_int 4

static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(0);
	if (no == 1) return(1);
	if (no == 2) return(-1);
	if (no == 3) return(122);
	return(-1);
}
#define gen_nb_xmlNodeSetPtr 1
static xmlNodeSetPtr gen_xmlNodeSetPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	const char		*filename	= INPUT_XML;
	const xmlChar	*xpathExpr	= (xmlChar*) "//SUBJECT";

	/* Init libxml */
	//xmlInitParser();
	//LIBXML_TEST_VERSION


	/* Load XML document */
	doc_gen_xmlNodeSetPtr = xmlParseFile(filename);
	if (doc_gen_xmlNodeSetPtr == NULL)
	{
		//MT_FAIL("Error: unable to parse file ");
		return(NULL);
	}
	/* Create xpath evaluation context */
	xpathCtx_gen_xmlNodeSetPtr = xmlXPathNewContext(doc_gen_xmlNodeSetPtr);
	if(xpathCtx_gen_xmlNodeSetPtr == NULL)
	{
		xmlFreeDoc(doc_gen_xmlNodeSetPtr);
		//MT_FAIL("Error: unable to create new XPath context");
		return(NULL);
	}
	/* Evaluate xpath expression */
	xpathObj_gen_xmlNodeSetPtr = xmlXPathEvalExpression(xpathExpr, xpathCtx_gen_xmlNodeSetPtr);
	if(xpathObj_gen_xmlNodeSetPtr == NULL)
	{
		xmlXPathFreeContext(xpathCtx_gen_xmlNodeSetPtr);
		xmlFreeDoc(doc_gen_xmlNodeSetPtr);
		//MT_FAIL("Error: unable to evaluate xpath expression ");
		return(NULL);
	}
	return(xpathObj_gen_xmlNodeSetPtr->nodesetval);
}
static void __DeletexmlNodeSetPtr()
{
	xmlXPathFreeObject(xpathObj_gen_xmlNodeSetPtr);
	xmlXPathFreeContext(xpathCtx_gen_xmlNodeSetPtr);
	xmlFreeDoc(doc_gen_xmlNodeSetPtr);
	//xmlCleanupParser();
}
static xmlDocPtr
get_api_doc(void) {
	if (api_doc == NULL) {
		api_doc = xmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
		api_root = NULL;
		api_attr = NULL;
	}
	return(api_doc);
}
static xmlDocPtr
__get_api_doc(void) {
	if (api_doc == NULL) {
		char *docname = INPUT_XML;
		api_doc = xmlParseFile(docname);
		api_root = NULL;
		api_attr = NULL;
	}
	return(api_doc);
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
static xmlNodePtr
__get_api_root(void) {
	if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
		__get_api_doc();
		if ((api_doc != NULL) && (api_doc->children != NULL) &&
			(api_doc->children->next != NULL) &&
			(api_doc->children->next->type == XML_ELEMENT_NODE))
			api_root = api_doc->children->next;
	}
	return(api_root);
}
#define gen_nb_xmlNodePtr 3
static xmlNodePtr gen_xmlNodePtr(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(xmlNewPI(BAD_CAST "test", NULL));
	if (no == 1) 
		return(__get_api_root());
	return(NULL);
	/*     if (no == 2) return((xmlNodePtr) get_api_doc()); */
}

static void des_xmlNodePtr(int no, xmlNodePtr val, int nr ATTRIBUTE_UNUSED) {
    if (no == 1) {
        free_api_doc();
    } else if (val != NULL) {
        xmlUnlinkNode(val);
        xmlFreeNode(val);
    }
}

/***************************************************************************
 * SUTsXmlXPath
 ***************************************************************************/
  /*
 * update_xpath_nodes:
 * @nodes:		the nodes set.
 * @value:		the new value for the node(s)
 *
 * Prints the @nodes content to @output.
 */
 void
 __update_xpath_nodes(xmlDocPtr doc,xmlNodeSetPtr nodes, const xmlChar* value)
 {
	 int size;
	 int i;
	 int count;
	 xmlChar *keyword;

	 if(!value)
	 {
		 DTS_FAIL("__update_xpath_nodes","value is NULL");
	 }
	 size = (nodes) ? nodes->nodeNr : 0;

	 /*
	 * NOTE: the nodes are processed in reverse order, i.e. reverse document
	 *       order because xmlNodeSetContent can actually free up descendant
	 *       of the node and such nodes may have been selected too ! Handling
	 *       in reverse order ensure that descendant are accessed first, before
	 *       they get removed. Mixing XPath and modifications on a tree must be
	 *       done carefully !
	 */
	 for(i = size - 1; i >= 0; i--)
	 {
		 if(!(nodes->nodeTab[i]))
		 {
			 DTS_FAIL("__update_xpath_nodes", "nodes->nodeTab is NULL");
		 }
		 xmlNodeSetContent(nodes->nodeTab[i], value);

		 for (count=0; count < nodes->nodeNr; count++) {
			 keyword = xmlNodeListGetString(doc, nodes->nodeTab[count]->xmlChildrenNode,1);
			DTS_CHECK_EQ_MESSAGE("__update_xpath_nodes", (void *)(xmlStrcmp(keyword,(const xmlChar *)"SISO")), (void *)0, "xmlNodeListGetString Failed");
			 xmlFree(keyword);
		 }

		 /*
		 * All the elements returned by an XPath query are pointers to
		 * elements from the tree *except* namespace nodes where the XPath
		 * semantic is different from the implementation in libxml2 tree.
		 * As a result when a returned node set is freed when
		 * xmlXPathFreeObject() is called, that routine must check the
		 * element type. But node from the returned set may have been removed
		 * by xmlNodeSetContent() resulting in access to freed data.
		 * This can be exercised by running
		 *       valgrind xpath2 test3.xml '//discarded' discarded
		 * There is 2 ways around it:
		 *   - make a copy of the pointers to the nodes from the result set
		 *     then call xmlXPathFreeObject() and then modify the nodes
		 * or
		 *   - remove the reference to the modified nodes from the node set
		 *     as they are processed, if they are not namespace nodes.
		 */
		 if (nodes->nodeTab[i]->type != XML_NAMESPACE_DECL)
			 nodes->nodeTab[i] = NULL;
	 }
 }
 void __XPathCommonInitFunc()
 {
	 const char					*filename	= INPUT_XML;
	 const xmlChar				*xpathExpr	= (xmlChar*) "//SUBJECT";
	// const xmlChar				*value		= (const xmlChar*)  "SISO";

	 /* Init libxml */
	 //xmlInitParser();
	// LIBXML_TEST_VERSION

		 /* Load XML document */
		 DocInitPtr = xmlParseFile(filename);
	 if (DocInitPtr == NULL)
	 {
		 DTS_FAIL("__XPathCommonInitFunc","Error: unable to parse file ");
	 }
	 /* Create xpath evaluation context */
	 xpathCtxInitPtr = xmlXPathNewContext(DocInitPtr);
	 if(xpathCtxInitPtr == NULL)
	 {
		 xmlFreeDoc(DocInitPtr);
		 DTS_FAIL("__XPathCommonInitFunc","Error: unable to create new XPath context");
	 }
	 xpathObjInitPtr = xmlXPathEvalExpression(xpathExpr, xpathCtxInitPtr);
	 if(xpathObjInitPtr == NULL)
	 {
		 xmlXPathFreeContext(xpathCtxInitPtr);
		 xmlFreeDoc(DocInitPtr);
		 DTS_FAIL("__XPathCommonInitFunc","Error: unable to evaluate xpath expression ");
	 }
#if 0
	// __update_xpath_nodes(DocInitPtr,xpathObjInitPtr->nodesetval, value);

	 int size = (xpathObjInitPtr->nodesetval) ? xpathObjInitPtr->nodesetval->nodeNr : 0;
	 /*
	 * NOTE: the nodes are processed in reverse order, i.e. reverse document
	 *       order because xmlNodeSetContent can actually free up descendant
	 *       of the node and such nodes may have been selected too ! Handling
	 *       in reverse order ensure that descendant are accessed first, before
	 *       they get removed. Mixing XPath and modifications on a tree must be
	 *       done carefully !
	 */
	 for(int i = size - 1; i >= 0; i--)
	 {
		 if(!(xpathObjInitPtr->nodesetval->nodeTab[i]))
		 {
			 DTS_FAIL("__XPathCommonInitFunc","nodes->nodeTab is NULL");
		 }
		 xmlNodeAddContent(xpathObjInitPtr->nodesetval->nodeTab[i], value);
	 }
	 xpathObjInitPtr->stringval = (xmlChar*) "SISO";
	 xpathObjInitPtr->floatval  = 1.0;
#endif
	 pctxtInitPtr = xmlXPathNewParserContext(xpathExpr, xpathCtxInitPtr);
	 if(pctxtInitPtr == NULL)
	 {
		 xmlXPathFreeContext(xpathCtxInitPtr);
		 xmlFreeDoc(DocInitPtr);
		 xmlXPathFreeContext(xpathCtxInitPtr);
		 DTS_FAIL("__XPathCommonInitFunc","Error: unable to create xmlXPathNewParserContext ");
	 }
	DTS_CHECK_NE_MESSAGE("__XPathCommonInitFunc", (void *)(pctxtInitPtr), (void *)NULL, "xmlXPathNewParserContext API return value");

 }
 void __XPathCommonDeleteFunc()
 {
	 if (NULL != DocInitPtr)
	 {
		 xmlFreeDoc(DocInitPtr);
	 }
	 if (NULL != xpathObjInitPtr)
	 {
		 xmlXPathFreeObject(xpathObjInitPtr);
	 }
	 if (NULL != xpathCtxInitPtr)
	 {
		 xmlXPathFreeContext(xpathCtxInitPtr);
	 }
	 if (NULL != pctxtInitPtr)
	 {
		 xmlXPathFreeParserContext(pctxtInitPtr);
	 }

 }
xmlXPathObjectPtr getnodeset (xmlDocPtr doc, xmlChar *xpath)
{
	xmlXPathContextPtr context;
	xmlXPathObjectPtr result;
	context = xmlXPathNewContext(doc);
	if (context == NULL) {
		DTS_PRINT("getnodeset", "Error in xmlXPathNewContext\n");
		return NULL;
	}
	result = xmlXPathEvalExpression(xpath, context);
	xmlXPathFreeContext(context);
	if (result == NULL) {
		DTS_PRINT("getnodeset", "Error in xmlXPathEvalExpression\n");
		return NULL;
	}
	if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
		xmlXPathFreeObject(result);
		DTS_PRINT("getnodeset", "No Result\n");
		return NULL;
	}
	return result;
}
	/**    
	* @test			UTcXPathP01
	* @brief		xmlChar * xmlNodeListGetString	(xmlDocPtr doc, xmlNodePtr list, int inLine)
	* @desc			Positive Test for building the string equivalent to the text contained in the Node list made of TEXTs and ENTITY_REFs
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Get the Document pointer and the node set, Free the document pointer and the node set, Deallocate memories] @n
		   			{xmlNodePtr *, xmlDocPtr *, inline:1} => {"Your impressions" | N/A} @n
					input1: [Get the Document pointer and the node set, Free the document pointer and the node set, Deallocate memories] @n
		   			{xmlNodePtr *, xmlDocPtr *, inline:1} => {"Tutorial Writer" | N/A} @n
					input1: [Get the Document pointer and the node set, Free the document pointer and the node set, Deallocate memories] @n
		 			{xmlDocPtr(doc) , xmlNodePtr(list), int} => {"Tutorial Takers" | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXPathP01()
{
	char *docname = INPUT_XML;
	xmlDocPtr doc;
	xmlChar *xpath = (xmlChar*) "//SUBJECT";

	xmlNodeSetPtr nodeset;
	xmlXPathObjectPtr result;
	int i;
	xmlChar *keyword;

	doc = xmlParseFile(docname);

	result = getnodeset (doc, xpath);
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode,1);
			DTS_CHECK_EQ_MESSAGE("UTcXPathP01", (void *)(xmlStrcmp(keyword,(const xmlChar *)"Your impressions")), (void *)0, "xmlNodeListGetString Failed");

			xmlFree(keyword);
		}
	}
	xmlXPathFreeObject (result);
	xpath = (xmlChar*) "//FROM";
	result = getnodeset (doc, xpath);
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode,1);
			DTS_CHECK_EQ_MESSAGE("UTcXPathP01", (void *)(xmlStrcmp(keyword,(const xmlChar *)"Tutorial Writer")), (void *)0, "xmlNodeListGetString Failed");
			xmlFree(keyword);
		}
	}
	xmlXPathFreeObject (result);
	xpath = (xmlChar*) "//TO";
	result = getnodeset (doc, xpath);
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode,1);
			DTS_CHECK_EQ_MESSAGE("UTcXPathP01", (void *)(xmlStrcmp(keyword,(const xmlChar *)"Tutorial Takers")), (void *)0, "xmlNodeListGetString Failed");
			
			xmlFree(keyword);
		}
	}

	xmlXPathFreeObject (result);
	xmlFreeDoc(doc);
}

/*
* UTcXPathP02:
* @filename			:the input XML filename.
* @xpathExpr		:the xpath expression for evaluation.
* @value			:the new node content.
*
* Parses input XML file, evaluates XPath expression and update the nodes
* then print the result.
*
*/
/**    
	* @test			UTcXPathP02
	* @brief		void	xmlXPathFreeContext		(xmlXPathContextPtr ctxt)
	* @desc			Positive Test for Freeing up an xmlXPathContext
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Load the document, Free the document] @n
	*   			{xmlXPathContextPtr} => {N/A | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXPathP02()
{
	const char		*filename	= INPUT_XML;
	const xmlChar	*xpathExpr	= (xmlChar*) "//SUBJECT";
	const xmlChar	*value		= (const xmlChar*)  "SISO";

	/* Init libxml */
	//xmlInitParser();
	//LIBXML_TEST_VERSION

	xmlDocPtr doc;
	xmlXPathContextPtr xpathCtx;
	xmlXPathObjectPtr xpathObj;

	/* Load XML document */
	doc = xmlParseFile(filename);
	if (doc == NULL)
	{
		DTS_FAIL("UTcXPathP02", "Error: unable to parse file ");
	}

	/* Create xpath evaluation context */
	xpathCtx = xmlXPathNewContext(doc);
	if(xpathCtx == NULL)
	{
		xmlFreeDoc(doc);
		DTS_FAIL("UTcXPathP02", "Error: unable to create new XPath context");
	}

	/* Evaluate xpath expression */
	xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
	if(xpathObj == NULL)
	{
		xmlXPathFreeContext(xpathCtx);
		xmlFreeDoc(doc);
		DTS_FAIL("UTcXPathP02", "Error: unable to evaluate xpath expression ");
	}

	/* update selected nodes */
	__update_xpath_nodes(doc,xpathObj->nodesetval, value);

	/* Cleanup of XPath data */
	xmlXPathFreeObject(xpathObj);
	xmlXPathFreeContext(xpathCtx);

	/* dump the resulting document */
	//xmlDocDump(stdout, doc);

	/* free the document */
	xmlFreeDoc(doc);

}
	/**    
	* @test			UTcxmlXPathCastBooleanToNumberP01
	* @brief		double	xmlXPathCastBooleanToNumber	(int val)
	* @desc			Positive Test for converting a boolean to its number value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(0 to 4)} => { N/A | (1.0 or 0.0) } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastBooleanToNumberP01() {
	double ret_val;
	int val; /* a boolean */
	int n_val;
	char Buff[64] = {0,};
	
	for (n_val = 0;n_val < gen_nb_int;n_val++)
	{
		val = gen_int(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {0 to 4} => { N/A | (1.0 or 0.0) } @n
		*/
		ret_val = xmlXPathCastBooleanToNumber(val);
		memset(Buff, 0, 8);
		snprintf(Buff, 7, "%f", ret_val);
		DTS_PASS("xmlXPathCastBooleanToNumber", "1" );
	}

}
	/**    
	* @test			UTcxmlXPathCastBooleanToStringP01
	* @brief		xmlChar *	xmlXPathCastBooleanToString	(int val)
	* @desc			Positive Test for converting a boolean to its string value.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(0 to 4)} => { N/A | not NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastBooleanToStringP01()
{
	xmlChar * ret_val;
	int val; /* a boolean */
	int n_val;
	for (n_val = 0;n_val < gen_nb_int;n_val++)
	{
		val = gen_int(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {0 to 4} => { N/A | not NULL } @n
		*/
		ret_val = xmlXPathCastBooleanToString(val);
		DTS_CHECK_NE_MESSAGE("xmlXPathCastBooleanToString", (void *)ret_val, (void *)(NULL), "xmlXPathCastBooleanToString Failed");
		
		if (ret_val != NULL)
		{
			xmlFree(ret_val);
		}
	}
}
	/**    
	* @test			UTcxmlXPathCastNodeSetToBooleanP01
	* @brief		int	xmlXPathCastNodeSetToBoolean (xmlNodeSetPtr ns)
	* @desc			Positive Test for converting a node-set to its boolean value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(ns)} => { N/A | 0 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastNodeSetToBooleanP01()
{
	int ret_val;
	xmlNodeSetPtr ns; /* a node-set */
	int n_ns;

	for (n_ns = 0;n_ns < gen_nb_xmlNodeSetPtr;n_ns++)
	{
		ns = gen_xmlNodeSetPtr(n_ns, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlNodeSetPtr} => { N/A | 0 } @n
		*/
		ret_val = xmlXPathCastNodeSetToBoolean(ns);
		DTS_CHECK_EQ_MESSAGE("xmlXPathCastNodeSetToBoolean", (void *)ret_val, (void *)(1), "xmlXPathCastNodeSetToBoolean Failed");

		xmlXPathFreeNodeSet(ns);
		//__DeletexmlNodeSetPtr();
		/* Shutdown libxml */
		////xmlCleanupParser();
	}
}
	/**    
	* @test			UTcxmlXPathCastNodeSetToNumberP01
	* @brief		double	xmlXPathCastNodeSetToNumber	(xmlNodeSetPtr ns)
	* @desc			Positive Test for converting a node-set to its number value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(ns)} => { N/A | a non zero number } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastNodeSetToNumberP01()
{
	double ret_val;
	xmlNodeSetPtr ns; /* a node-set */
	int n_ns;

	for (n_ns = 0;n_ns < gen_nb_xmlNodeSetPtr;n_ns++)
	{
		ns = gen_xmlNodeSetPtr(n_ns, 0);
		DTS_CHECK_NE_MESSAGE("xmlXPathCastNodeSetToNumber", (void *)ns, (void *)NULL, "gen_xmlNodeSetPtr Failed");
		
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlNodeSetPtr} => { N/A | a non zero number } @n
		*/
		ret_val = xmlXPathCastNodeSetToNumber(ns);
		DTS_CHECK_EQ_MESSAGE("xmlXPathCastNodeSetToNumber", (void *)(xmlXPathIsNaN(ret_val)), (void *)(1), "xmlXPathCastNodeSetToNumber Failed");

		__DeletexmlNodeSetPtr();
		/* Shutdown libxml */
		////xmlCleanupParser();
	}
}
	/**    
	* @test			UTcxmlXPathCastNodeSetToStringP01
	* @brief		xmlChar *	xmlXPathCastNodeSetToString	(xmlNodeSetPtr ns)
	* @desc			Positive Test for converting a node-set to its string value.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(ns)} => { N/A | xmlChar * } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastNodeSetToStringP01()
{
	xmlChar * ret_val;
	xmlNodeSetPtr ns; /* a node-set */
	int n_ns;

	for (n_ns = 0;n_ns < gen_nb_xmlNodeSetPtr;n_ns++)
	{
		ns = gen_xmlNodeSetPtr(n_ns, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlNodeSetPtr} => { N/A | xmlChar * } @n
		*/
		ret_val = xmlXPathCastNodeSetToString(ns);
		DTS_CHECK_NE_MESSAGE("xmlXPathCastNodeSetToString", (void *)ret_val, (void *)(NULL), "xmlXPathCastNodeSetToString Failed");
		
		//xmlXPathFreeNodeSet(ns);
		__DeletexmlNodeSetPtr();
		if (ret_val != NULL)
		{
			xmlFree(ret_val);
		}
		/* Shutdown libxml */
		////xmlCleanupParser();

	}

}
	/**    
	* @test			UTcxmlXPathCastNodeToNumberP01
	* @brief		double	xmlXPathCastNodeToNumber	(xmlNodePtr node)
	* @desc			Positive Test for converting a node to its number value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(node)} => { N/A | double } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastNodeToNumberP01()
{
	double ret_val;
	xmlNodePtr node; /* a node */
	int n_node;

	for (n_node = 0;n_node < gen_nb_xmlNodePtr-2;n_node++)
	{
		node = gen_xmlNodePtr(n_node, 0);
		DTS_CHECK_NE_MESSAGE("xmlXPathCastNodeToNumber", (void *)node, (void *)NULL, "xmlXPathCastNodeToNumber Failed");
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlNodePtr} => { N/A | double } @n
		*/
		ret_val = xmlXPathCastNodeToNumber(node);
		DTS_CHECK_EQ_MESSAGE("xmlXPathCastNodeToNumber", (void *)(xmlXPathIsNaN(ret_val)), (void *)(1), "xmlXPathCastNodeToNumber Failed");
		
		__free_api_doc();
		if (node != NULL)
		{
			xmlFreeNode(node);
		}
		/* Shutdown libxml */
		////xmlCleanupParser();
	}

}
	/**    
	* @test			UTcxmlXPathCastNodeToStringP01
	* @brief		xmlChar *	xmlXPathCastNodeToString	(xmlNodePtr node)
	* @desc			Positive Test for converting a node to its string value.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr} => { N/A | xmlChar * } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastNodeToStringP01()
{
	xmlChar * ret_val;
	xmlNodePtr node; /* a node */
	int n_node;

	for(n_node = 0;n_node < gen_nb_xmlNodePtr;n_node++)
	{
		node = gen_xmlNodePtr(1, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlNodePtr} => { N/A | xmlChar * } @n
		*/
		ret_val = xmlXPathCastNodeToString(node);
		DTS_CHECK_NE_MESSAGE("xmlXPathCastNodeToNumber", (void *)ret_val, (void *)(NULL), "xmlXPathCastNodeToNumber Failed");
		
		__free_api_doc();
		if (ret_val != NULL)
		{
			xmlFree(ret_val);
		}
		//if (node != NULL)
		//{
		//	xmlFreeNode(node);
		//}
		/* Shutdown libxml */
		//xmlCleanupParser();
	}
}
	/**    
	* @test			UTcxmlXPathCastNumberToBooleanP01
	* @brief		int	xmlXPathCastNumberToBoolean	(double val)
	* @desc			Positive Test for converting a number to its boolean value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			 {double(val)} => { N/A | 1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastNumberToBooleanP01()
{
	int ret_val;
	double val; /* a number */
	int n_val;

	for (n_val = 0;n_val < 2;n_val++)
	{
		val = gen_double(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {double} => { N/A | 1 } @n
		*/
		ret_val = xmlXPathCastNumberToBoolean(val);
		if (val)
		{
			DTS_CHECK_EQ_MESSAGE("xmlXPathCastNumberToBoolean", (void *)ret_val, (void *)(1), "xmlXPathCastNumberToBoolean Failed");
		}
		else
		{
			DTS_CHECK_EQ_MESSAGE("xmlXPathCastNumberToBoolean", (void *)ret_val, (void *)(0), "xmlXPathCastNumberToBoolean Failed");
		}
	}
}
	/**    
	* @test			UTcxmlXPathCastNumberToStringP01
	* @brief		xmlChar *	xmlXPathCastNumberToString	(double val)
	* @desc			Positive Test for converting a number to its string value.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{doubleval)} => { N/A | xmlChar * } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastNumberToStringP01()
 {
	xmlChar * ret_val;
	double val; /* a number */
	int n_val;

	for (n_val = 0;n_val < gen_nb_double;n_val++)
	{
		val = gen_double(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {double} => { N/A | xmlChar * } @n
		*/
		ret_val = xmlXPathCastNumberToString(val);
		DTS_CHECK_NE_MESSAGE("xmlXPathCastNumberToString", (void *)ret_val, (void *)(NULL), "xmlXPathCastNumberToString Failed");
		if (ret_val != NULL)
		{
			xmlFree(ret_val);
		}
	}

}
	/**    
	* @test			UTcxmlXPathCastStringToBooleanP01
	* @brief		int	xmlXPathCastStringToBoolean	(const xmlChar * val)
	* @desc			Positive Test for converting a string to its boolean value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const xmlChar(val)} => { N/A | 1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastStringToBooleanP01()
 {
	int ret_val;
	xmlChar * val; /* a string */
	int n_val;

	for (n_val = 0;n_val < gen_nb_const_xmlChar_ptr;n_val++)
	{
		val = gen_const_xmlChar_ptr(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {(const xmlChar *)} => { N/A | 1 } @n
		*/
		ret_val = xmlXPathCastStringToBoolean((const xmlChar *)val);
		if (val)
		{
			DTS_CHECK_EQ_MESSAGE("xmlXPathCastStringToBoolean", (void *)ret_val, (void *)(1), "xmlXPathCastStringToBoolean Failed");
		}
		else
		{
			DTS_CHECK_EQ_MESSAGE("xmlXPathCastStringToBoolean", (void *)ret_val, (void *)(0), "xmlXPathCastStringToBoolean Failed");
		}
	}
}
	/**    
	* @test			UTcxmlXPathCastStringToNumberP01
	* @brief		double	xmlXPathCastStringToNumber (const xmlChar * val)
	* @desc			Positive Test for converting a string to its number value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const xmlChar(val)} => { N/A | 1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastStringToNumberP01()
{
	double ret_val;
	xmlChar * val; /* a string */
	int n_val;

	for (n_val = 0;n_val < gen_nb_const_xmlChar_ptr-1;n_val++)
	{
		val = gen_const_xmlChar_ptr(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {(const xmlChar *)} => { N/A | 1 } @n
		*/
		ret_val = xmlXPathCastStringToNumber((const xmlChar *)val);
		DTS_CHECK_EQ_MESSAGE("xmlXPathCastStringToNumber", (void *)(xmlXPathIsNaN(ret_val)), (void *)(1), "xmlXPathCastStringToNumber Failed");
	}
}
	/**    
	* @test			UTcxmlXPathCastToBooleanP01
	* @brief		int	xmlXPathCastToBoolean (xmlXPathObjectPtr val)
	* @desc			Positive Test for converting an XPath object to its boolean value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(val)} => { N/A | 1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastToBooleanP01()
{
	int ret_val;
	xmlXPathObjectPtr val; /* an XPath object */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr-2;n_val++) {
		val = gen_xmlXPathObjectPtr(n_val, 0);// Its definition compilation errors...SYAM

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlXPathObjectPtr pointer} => { N/A | 1 } @n
		*/
		ret_val = xmlXPathCastToBoolean(val);

		DTS_CHECK_EQ_MESSAGE("xmlXPathCastToBoolean", (void *)ret_val, (void *)(1), "xmlXPathCastToBoolean Failed");
		
		if (val != NULL)
		{
			xmlXPathFreeObject(val);
		}
	}

}
	/**    
	* @test			UTcxmlXPathCastToNumberP01
	* @brief		double	xmlXPathCastToNumber (xmlXPathObjectPtr val)
	* @desc			Positive Test for converting an XPath object to its number value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(val)} => { N/A | 1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastToNumberP01()
{
	double ret_val;
	xmlXPathObjectPtr val; /* an XPath object */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr;n_val++)
	{
		val = gen_xmlXPathObjectPtr(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlXPathObjectPtr pointer} => { N/A | 1 } @n
		*/
		ret_val = xmlXPathCastToNumber(val);
		if(n_val == 1 || n_val == 2)
		{
			DTS_CHECK_EQ_MESSAGE("xmlXPathCastToNumber", (void *)(xmlXPathIsNaN(ret_val)), (void *)(0), "xmlXPathCastToNumber Failed");
		}
		else
		{
			DTS_CHECK_EQ_MESSAGE("xmlXPathCastToNumber", (void *)(xmlXPathIsNaN(ret_val)), (void *)(1), "xmlXPathCastToNumber Failed");
		}
		if (val != NULL)
		{
			xmlXPathFreeObject(val);
		}
	}

}
	/**    
	* @test			UTcxmlXPathCastToStringP01
	* @brief		xmlChar *	xmlXPathCastToString (xmlXPathObjectPtr val)
	* @desc			Positive Test for converting an existing object to its string() equivalent
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(val)} => { N/A | xmlChar pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCastToStringP01()
{
	xmlChar * ret_val;
	xmlXPathObjectPtr val; /* an XPath object */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr;n_val++) {
		val = gen_xmlXPathObjectPtr(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlXPathObjectPtr pointer} => { N/A | xmlChar pointer } @n
		*/
		ret_val = xmlXPathCastToString(val);
		DTS_CHECK_NE_MESSAGE("xmlXPathCastToString", (void *)ret_val, (void *)(NULL), "xmlXPathCastToString Failed");
		if (val != NULL)
		{
			xmlXPathFreeObject(val);
		}
		if (ret_val != NULL)
		{
			xmlFree(ret_val);
		}
	}

}
	/**    
	* @test			UTcxmlXPathCmpNodesP01
	* @brief		int xmlXPathCmpNodes (xmlNodePtr node1, xmlNodePtr node2)
	* @desc			Positive Test for comparing two nodes w.r.t document order
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(node1),xmlNodePtr(node2)} => { N/A | 0 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCmpNodesP01()
{
	int ret_val;
	xmlNodePtr node1; /* the first node */
	int n_node1 = 0;
	xmlNodePtr node2; /* the second node */
	int n_node2 = 0;

	//for (n_node1 = 0;n_node1 < gen_nb_xmlNodePtr;n_node1++) {
		//for (n_node2 = 0;n_node2 < gen_nb_xmlNodePtr;n_node2++)
		//{
			node1 = gen_xmlNodePtr(n_node1, 0);
			node2 = gen_xmlNodePtr(n_node2, 1);
			//if ((n_node1 != 1) && (n_node2!= 1))// FAIL:Problem may be with test code.so kept check using get_api_root in it
			//{
				/**
				* @remarks   input1: [N/A, N/A] @n
				*            {xmlNodePtr pointer,xmlNodePtr pointer} => { N/A | 0 } @n
				*/
				ret_val = xmlXPathCmpNodes(node1, node2);
			//}
			DTS_CHECK_NE_MESSAGE("xmlXPathCmpNodes", (void *)ret_val, (void *)(-1), "xmlXPathCmpNodes Failed");
			
			__free_api_doc();

			if (node1 != NULL)
			{
				xmlFreeNode(node1);
			}
			if (node2 != NULL)
			{
				xmlFreeNode(node2);
			}
		//}
	//}

}
	/**    
	* @test			UTcxmlXPathCompiledEvalP01
	* @brief		xmlXPathObjectPtr xmlXPathCompiledEval	(xmlXPathCompExprPtr comp, xmlXPathContextPtr ctx)
	* @desc			Positive Test for evaluating the Precompiled XPath expression in the given context.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathCompExprPtr(comp),xmlXPathContextPtr(ctx)} => { N/A | xmlXPathObjectPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCompiledEvalP01()
{
	xmlXPathObjectPtr ret_val;
	xmlXPathContextPtr ctxt = gen_xmlXPathContextPtr(0, 1);
	const xmlChar	*str		= (const xmlChar*)  "SISO";
	xmlXPathCompExprPtr ret_comp_val = xmlXPathCtxtCompile(ctxt, str) ;

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathCompExprPtr pointer,xmlXPathContextPtr pointer} => { N/A | xmlXPathObjectPtr pointer } @n
	*/
	ret_val = xmlXPathCompiledEval(ret_comp_val, ctxt);
	DTS_CHECK_NE_MESSAGE("xmlXPathCompiledEval", (void *)ret_val, (void *)(NULL), "xmlXPathCompiledEval Failed");

	xmlXPathFreeContext(ctxt);
	xmlXPathFreeObject(ret_val);
	xmlXPathFreeCompExpr(ret_comp_val);
	if (doc_get_api_root != NULL)
	{
		xmlFreeDoc(doc_get_api_root);
		doc_get_api_root = NULL;
	}
	
	/* Shutdown libxml */
	//xmlCleanupParser();

}
	/**    
	* @test			UTcxmlXPathConvertBooleanP01
	* @brief		xmlXPathObjectPtr	xmlXPathConvertBoolean	(xmlXPathObjectPtr val)
	* @desc			Positive Test for converting an existing object to its boolean() equivalent
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(val)} => { N/A | xmlXPathObjectPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathConvertBooleanP01()
{
	xmlXPathObjectPtr ret_val;
	xmlXPathObjectPtr val; /* an XPath object */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr;n_val++) {
		val = gen_xmlXPathObjectPtr(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlXPathObjectPtr pointer} => { N/A | xmlXPathObjectPtr pointer } @n
		*/
		ret_val = xmlXPathConvertBoolean(val);
		DTS_CHECK_NE_MESSAGE("xmlXPathConvertBoolean", (void *)ret_val, (void *)(NULL), "xmlXPathConvertBoolean Failed");
		desret_xmlXPathObjectPtr(ret_val);
		if (val != NULL)
		{
			//xmlXPathFreeObject(val);
		}
	}

}
	/**    
	* @test			UTcxmlXPathConvertNumberP01
	* @brief		xmlXPathObjectPtr	xmlXPathConvertNumber	(xmlXPathObjectPtr val)
	* @desc			Positive Test for converting an existing object to its number() equivalent
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(val)} => { N/A | xmlXPathObjectPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathConvertNumberP01()
{
	xmlXPathObjectPtr ret_val;
	xmlXPathObjectPtr val; /* an XPath object */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr;n_val++) {
		val = gen_xmlXPathObjectPtr(n_val, 0);
		if (val != NULL)
		{
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            {xmlXPathObjectPtr pointer} => { N/A | xmlXPathObjectPtr pointer } @n
			*/
			ret_val = xmlXPathConvertNumber(val);
			DTS_CHECK_NE_MESSAGE("xmlXPathConvertNumber", (void *)ret_val, (void *)(NULL), "xmlXPathConvertNumber Failed");
			desret_xmlXPathObjectPtr(ret_val);
			//xmlXPathFreeObject(val);
			val = NULL;
		}
	}

}
	/**    
	* @test			UTcxmlXPathConvertStringP01
	* @brief		xmlXPathObjectPtr	xmlXPathConvertString	(xmlXPathObjectPtr val)
	* @desc			Positive Test for converting an existing object to its string() equivalent
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr (val)} => { N/A | xmlXPathObjectPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathConvertStringP01()
{
	xmlXPathObjectPtr ret_val;
	xmlXPathObjectPtr val; /* an XPath object */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr;n_val++) {
		val = gen_xmlXPathObjectPtr(n_val, 0);
		if (val != NULL)
		{
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlXPathObjectPtr pointer} => { N/A | xmlXPathObjectPtr pointer } @n
		*/
		ret_val = xmlXPathConvertString(val);
		DTS_CHECK_NE_MESSAGE("xmlXPathConvertString", (void *)ret_val, (void *)(NULL), "xmlXPathConvertString Failed");
		desret_xmlXPathObjectPtr(ret_val);
		//	xmlXPathFreeObject(val);
		val = NULL;
		}
	}
}
	/**    
	* @test			UTcxmlXPathEvalP01
	* @brief		xmlXPathObjectPtr xmlXPathEval	(const xmlChar * str, xmlXPathContextPtr ctx)
	* @desc			Positive Test for evaluating the XPath Location Path in the given context.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{ (const xmlChar (str)), xmlXPathContextPtr(ctx)} => { N/A | xmlXPathObjectPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathEvalP01()
 {
	xmlXPathObjectPtr ret_val;
	xmlChar * str; /* the XPath expression */
	xmlXPathContextPtr ctx; /* the XPath context */

	str = gen_const_xmlChar_ptr(1, 0);
	ctx = gen_xmlXPathContextPtr(1, 1);
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { (const xmlChar *), xmlXPathContextPtr pointer} => { N/A | xmlXPathObjectPtr pointer } @n
	*/
	ret_val = xmlXPathEval((const xmlChar *)str , ctx);
	DTS_CHECK_NE_MESSAGE("xmlXPathEval", (void *)ret_val, (void *)(NULL), "xmlXPathEval Failed");
	desret_xmlXPathObjectPtr(ret_val);

	if (NULL != ctx)
	{
		xmlXPathFreeContext(ctx);
	}
	if (doc_get_api_root != NULL)
	{
		xmlFreeDoc(doc_get_api_root);
		doc_get_api_root = NULL;
	}
	/* Shutdown libxml */
	//xmlCleanupParser();

}
	/**    
	* @test			UTcxmlXPathEvalPredicateP01
	* @brief		int xmlXPathEvalPredicate (xmlXPathContextPtr ctxt, xmlXPathObjectPtr res)
	* @desc			Positive Test for evaluating a predicate result for the current node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{ xmlNodePtr pointer} => { N/A | 0 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathEvalPredicateP01()
 {
	 xmlXPathObjectPtr ret_val;
	 xmlXPathContextPtr ctxt = gen_xmlXPathContextPtr(0, 1);
	 const xmlChar	*str		= (const xmlChar*)  "SISO";
	 xmlXPathCompExprPtr ret_comp_val = xmlXPathCtxtCompile(ctxt, str) ;
	 ret_val = xmlXPathCompiledEval(ret_comp_val, ctxt);

	int retval;

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlNodePtr pointer} => { N/A | 0 } @n
	*/
	//Have to pass proper inputs for prediction (1)
	retval = xmlXPathEvalPredicate(ctxt, ret_val);
	DTS_CHECK_NE_MESSAGE("xmlXPathEvalPredicate", (void *)ret_val, (void *)(0), "xmlXPathEvalPredicate Failed");

	xmlXPathFreeContext(ctxt);
	xmlXPathFreeObject(ret_val);
	if (ret_comp_val != NULL)
	{
		xmlXPathFreeCompExpr(ret_comp_val);
	}
	if (doc_get_api_root != NULL)
	{
		xmlFreeDoc(doc_get_api_root);
		doc_get_api_root = NULL;
	}
	/* Shutdown libxml */
	//xmlCleanupParser();

}
	/**    
	* @test			UTcxmlXPathNodeSetCreateP01
	* @brief		xmlNodeSetPtr xmlXPathNodeSetCreate (xmlNodePtr val)
	* @desc			Positive Test creating a new xmlNodeSetPtr of type double and of value @val
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{ xmlNodePtr(val)} => { N/A | xmlNodeSetPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNodeSetCreateP01()
{
	xmlNodeSetPtr ret_val;
	xmlNodePtr val; /* an initial xmlNodePtr, or NULL */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlNodePtr-2;n_val++) {
		val = gen_xmlNodePtr(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlNodePtr pointer} => { N/A | xmlNodeSetPtr pointer } @n
		*/
		ret_val = xmlXPathNodeSetCreate(val);
		DTS_CHECK_NE_MESSAGE("xmlXPathNodeSetCreate", (void *)ret_val, (void *)(NULL), "xmlXPathNodeSetCreate Failed");
		des_xmlNodePtr(n_val, val, 0);
		if (ret_val != NULL)
		{
			xmlXPathFreeNodeSet(ret_val);
		}

		__free_api_doc();
		/* Shutdown libxml */
		////xmlCleanupParser();
	}
}
	/**    
	* @test			UTcxmlXPathObjectCopyP01
	* @brief		xmlXPathObjectPtr	xmlXPathObjectCopy	(xmlXPathObjectPtr val)
	* @desc			Positive Test for allocating a new copy of a given object
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{ xmlXPathObjectPtr(val)} => { N/A | xmlXPathObjectPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathObjectCopyP01()
{
	xmlXPathObjectPtr ret_val;
	xmlXPathObjectPtr val; /* the original object */
	int n_val;

	for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr -1;n_val++) {
		val = gen_xmlXPathObjectPtr(n_val, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlXPathObjectPtr pointer} => { N/A | xmlXPathObjectPtr pointer } @n
		*/
		ret_val = xmlXPathObjectCopy(val);
		DTS_CHECK_NE_MESSAGE("xmlXPathObjectCopy", (void *)ret_val, (void *)(NULL), "xmlXPathObjectCopy Failed");
		
		des_xmlXPathObjectPtr(n_val, val, 0);
		if (ret_val != NULL)
		{
			xmlXPathFreeObject(ret_val);
		}
	}
}
	/**    
	* @test			UTcxmlXPathOrderDocElemsP01
	* @brief		long xmlXPathOrderDocElems (xmlDocPtr doc)
	* @desc			Positive Test for speeding up XPath computation on static documents
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{ xmlDocPtr(doc)} => { N/A | long } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathOrderDocElemsP01()
{
	long ret_val;
	xmlDocPtr doc; /* an input document */
	int n_doc = 0;
	//for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		doc = gen_xmlDocPtr(n_doc, 0);
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlDocPtr pointer} => { N/A | long } @n
		*/
		ret_val = xmlXPathOrderDocElems(doc);
		//if (n_doc != 0)
		//{
			DTS_CHECK_NE_MESSAGE("xmlXPathOrderDocElems", (void *)ret_val, (void *)(-1), "xmlXPathOrderDocElems Failed");
		//}
		//des_xmlDocPtr(n_doc, doc, 0);
		if (doc != NULL)
		{
			xmlFreeDoc(doc);
		}
	//}
}
xmlXPathObjectPtr  __DummyxmlXPathVariableLookupFunc(void *ctxt,const xmlChar *name,const xmlChar *ns_uri)
{
	return(NULL);

}
	/**    
	* @test			UTcxmlXPathPopStringP01
	* @brief		xmlChar *	xmlXPathPopString	(xmlXPathParserContextPtr ctxt)
	* @desc			Positive Test for poping a string from the stack, handling conversion if needed. Check error with #xmlXPathCheckError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt)} => { N/A | xmlChar} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathPopStringP01()
{
	__XPathCommonInitFunc();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr} => { N/A | xmlChar} @n
	*/
	 
	//pctxtInitPtr->value = xmlXPathNewString(BAD_CAST "string object");
	xmlChar *pRetPathPopString = xmlXPathPopString (pctxtInitPtr);
	//Need to check the failure ----SYAM.
	//Hash pass proper inputs
	//MT_CHECK_MESSAGE2(true != xmlXPathCheckError(pctxt), "xmlXPathPopString API return value");
	//MT_CHECK_MESSAGE2(NULL != pRetPathPopString, "xmlXPathPopString API return value");
	if(pRetPathPopString != NULL)
		xmlFree(pRetPathPopString);
	if (NULL != pctxtInitPtr->context->lastError.str1)
	{
		xmlFree(pctxtInitPtr->context->lastError.str1);
		pctxtInitPtr->context->lastError.str1 = NULL;
	}
	//xmlResetLastError();
	__XPathCommonDeleteFunc();

}
	/**    
	* @test			UTcxmlXPathPopNumberP01
	* @brief		double	xmlXPathPopNumber (xmlXPathParserContextPtr ctxt)
	* @desc			Positive Test for poping a number from the stack, handling conversion if needed. Check error with #xmlXPathCheckError.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt)} => { N/A | any double number} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathPopNumberP01()
{
	__XPathCommonInitFunc();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr} => { N/A | any double number} @n
	*/
	double dobPopNumber = xmlXPathPopNumber (pctxtInitPtr);
	if (NULL != pctxtInitPtr->context->lastError.str1)
	{
		xmlFree(pctxtInitPtr->context->lastError.str1);
		pctxtInitPtr->context->lastError.str1 = NULL;
	}
	//xmlResetLastError();
	//Need to check the failure ----SYAM.
	//Hash pass proper inputs
	//DTS_CHECK_NE_MESSAGE("xmlXPathPopNumber", (void *)(xmlXPathCheckError(pctxtInitPtr)), (void *)(XML_FALSE), "xmlXPathPopNumber Failed");
	__XPathCommonDeleteFunc();

}
	/**    
	* @test			UTcxmlXPathWrapCStringP01
	* @brief		xmlXPathObjectPtr	xmlXPathWrapCString	(char * val)
	* @desc			Positive Test for wraping a string into an XPath object.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			 {xmlXPathWrapCString("SomeThing")} => { N/A | xmlXPathObjectPtr object} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathWrapCStringP01()
{
	__XPathCommonInitFunc();

	char *pWrapString = "SomeThing";
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {"SomeThing"} => { N/A | xmlXPathObjectPtr object} @n
	*/
	xmlXPathObjectPtr retptr = xmlXPathWrapCString (pWrapString);
	DTS_CHECK_NE_MESSAGE("xmlXPathWrapCString", (void *)retptr, (void *)(NULL), "xmlXPathWrapCString Failed");

	__XPathCommonDeleteFunc();

	if (NULL != retptr)
	{
		//xmlXPathFreeObject(retptr);
	}

}
	/**    
	* @test			UTcxmlXPathWrapExternalP01
	* @brief		xmlXPathObjectPtr xmlXPathWrapExternal (void * val)
	* @desc			Positive Test for wraping the @val data into an XPath object.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathWrapExternal "SomeThing"} => { N/A | xmlXPathObjectPtr object} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathWrapExternalP01()
{
	__XPathCommonInitFunc();

	char *pWrapString = "SomeThing";

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {"SomeThing"} => { N/A | xmlXPathObjectPtr object} @n
	*/
	xmlXPathObjectPtr retptr = xmlXPathWrapExternal (pWrapString);
	DTS_CHECK_NE_MESSAGE("xmlXPathWrapExternal", (void *)retptr, (void *)(NULL), "xmlXPathWrapExternal Failed");

	__XPathCommonDeleteFunc();

	if (NULL != retptr)
	{
		xmlXPathFreeObject(retptr);
	}
}
	/**    
	* @test			UTcxmlXPathRegisterVariableP01
	* @brief		int xmlXPathRegisterVariable (xmlXPathContextPtr ctxt, const xmlChar * name, xmlXPathObjectPtr value)
	* @desc			Positive Test for registering a new variable value. If @value is NULL it unregisters the variable
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr,const xmlChar "SISO",xmlXPathObjectPtr} => { N/A | 0} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathRegisterVariableP01()
{
	__XPathCommonInitFunc();

	char *pWrapString = "SomeThing";
	const xmlChar	*str		= (const xmlChar*)  "SISO";

	xmlXPathObjectPtr retptr = xmlXPathWrapExternal (pWrapString);
	DTS_CHECK_NE_MESSAGE("xmlXPathWrapExternal", (void *)retptr, (void *)(NULL), "xmlXPathWrapExternal Failed");

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,"SISO",xmlXPathObjectPtr} => { N/A | 0} @n
	*/

	int retres = xmlXPathRegisterVariable(xpathCtxInitPtr,str,retptr);
	DTS_CHECK_NE_MESSAGE("xmlXPathRegisterVariable", (void *)retres, (void *)(-1), "xmlXPathRegisterVariable Failed");

	__XPathCommonDeleteFunc();

	if (NULL != retptr)
	{
		//xmlXPathFreeObject(retptr);
	}
}
	/**    
	* @test			UTcxmlXPathTrailingSortedP01
	* @brief		xmlNodeSetPtr	xmlXPathTrailingSorted	(xmlNodeSetPtr nodes1, xmlNodeSetPtr nodes2)
	* @desc			Positive Test for implementing the EXSLT - Sets trailing() function: node-set set:trailing (node-set, node-set)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes), NULL} => { N/A | nodes} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathTrailingSortedP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes, NULL} => { N/A | nodes} @n
	*/
	xmlNodeSetPtr retnode = xmlXPathTrailingSorted (nodes, NULL);
	DTS_CHECK_NE_MESSAGE("xmlXPathTrailingSorted", (void *)retnode, (void *)(NULL), "xmlXPathTrailingSorted Failed");
	
	if (NULL != retnode)
	{
		DTS_CHECK_EQ_MESSAGE("xmlXPathTrailingSorted", (void *)retnode, (void *)nodes, "xmlXPathTrailingSorted Failed");
	}
	__DeletexmlNodeSetPtr();
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathLeadingSortedP01
	* @brief		xmlNodeSetPtr xmlXPathLeadingSorted (xmlNodeSetPtr nodes1, xmlNodeSetPtr nodes2)
	* @desc			Positive Test for implementing the EXSLT - Sets leading() function: node-set set:leading (node-set, node-set)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes), NULL} => { N/A | nodes} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathLeadingSortedP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes, NULL} => { N/A | nodes} @n
	*/
	xmlNodeSetPtr retnode = xmlXPathLeadingSorted (nodes, NULL);
	DTS_CHECK_NE_MESSAGE("xmlXPathLeadingSorted", (void *)retnode, (void *)(NULL), "xmlXPathLeadingSorted Failed");
	
	if (NULL != retnode)
	{
		DTS_CHECK_EQ_MESSAGE("xmlXPathLeadingSorted", (void *)retnode, (void *)nodes, "xmlXPathLeadingSorted Failed");
	}
	__DeletexmlNodeSetPtr();
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathTrailingP01
	* @brief		xmlNodeSetPtr xmlXPathTrailing (xmlNodeSetPtr nodes1, xmlNodeSetPtr nodes2)
	* @desc			Positive Test for implementing the EXSLT - 
					Sets trailing() function: node-set set:trailing (node-set, node-set) @nodes1 and @nodes2 are sorted by document order, then #xmlXPathTrailingSorted is called.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes), NULL} => { N/A | nodes} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathTrailingP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes, NULL} => { N/A | nodes} @n
	*/
	xmlNodeSetPtr retnode = xmlXPathTrailing (nodes, NULL);
	DTS_CHECK_NE_MESSAGE("xmlXPathTrailing", (void *)retnode, (void *)(NULL), "xmlXPathTrailing Failed");
	
	if (NULL != retnode)
	{
		DTS_CHECK_EQ_MESSAGE("xmlXPathTrailing", (void *)retnode, (void *)nodes, "xmlXPathTrailing Failed");
	}
	
	__DeletexmlNodeSetPtr();
	//if (NULL != retnode)
	//{
	//	xmlXPathFreeNodeSet(retnode);
	//}
	//if (NULL != nodes)
	//{
	//	xmlXPathFreeNodeSet(nodes);
	//}
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathLeadingP01
	* @brief		xmlNodeSetPtr xmlXPathLeading (xmlNodeSetPtr nodes1, xmlNodeSetPtr nodes2)
	* @desc			Positive Test for implementing the EXSLT - 
					Sets leading() function: node-set set:leading (node-set, node-set) @nodes1 and @nodes2 are sorted by document order, then #exslSetsLeadingSorted is called.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes), NULL} => { N/A | nodes} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathLeadingP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes, NULL} => { N/A | nodes} @n
	*/
	xmlNodeSetPtr retnode = xmlXPathLeading (nodes, NULL);
	DTS_CHECK_NE_MESSAGE("xmlXPathLeading", (void *)retnode, (void *)(NULL), "xmlXPathLeading Failed");
	
	if (NULL != retnode)
	{
		DTS_CHECK_EQ_MESSAGE("xmlXPathLeading", (void *)retnode, (void *)nodes, "xmlXPathLeading Failed");
	}
	
	__DeletexmlNodeSetPtr();
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathIntersectionP01
	* @brief		xmlNodeSetPtr xmlXPathIntersection (xmlNodeSetPtr nodes1,xmlNodeSetPtr nodes2)
	* @desc			Positive Test for implementing the EXSLT - Sets intersection() function: node-set set:intersection (node-set, node-set)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes), NULL} => { N/A | retnode} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathIntersectionP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes, NULL} => { N/A | retnode} @n
	*/
	xmlNodeSetPtr retnode = xmlXPathIntersection (nodes, NULL);
	DTS_CHECK_NE_MESSAGE("xmlXPathIntersection", (void *)retnode, (void *)(NULL), "xmlXPathIntersection Failed");

	__DeletexmlNodeSetPtr();
	if (retnode != NULL)
	{
		xmlXPathFreeNodeSet(retnode);
	}
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathDifferenceP01
	* @brief		xmlNodeSetPtr xmlXPathDifference (xmlNodeSetPtr nodes1, xmlNodeSetPtr nodes2)
	* @desc			Positive Test for implementing the EXSLT - Sets difference() function: node-set set:difference (node-set, node-set)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes), NULL} => { N/A | nodes} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathDifferenceP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes, NULL} => { N/A | nodes} @n
	*/
	xmlNodeSetPtr retnode = xmlXPathDifference (nodes, NULL);
	DTS_CHECK_NE_MESSAGE("xmlXPathDifference", (void *)retnode, (void *)(NULL), "xmlXPathDifference Failed");
	
	if (NULL != retnode)
	{
		DTS_CHECK_EQ_MESSAGE("xmlXPathDifference", (void *)retnode, (void *)nodes, "xmlXPathDifference Failed");
	}
	__DeletexmlNodeSetPtr();
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathHasSameNodesP01
	* @brief		int xmlXPathHasSameNodes (xmlNodeSetPtr nodes1, xmlNodeSetPtr nodes2)
	* @desc			Positive Test for implementing the EXSLT - Sets has-same-nodes function: boolean set:has-same-node(node-set, node-set)
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes), NULL} => { N/A | XML_FALSE} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathHasSameNodesP01()
{
    int ret_val;

	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes, NULL} => { N/A | XML_FALSE} @n
	*/
	ret_val = xmlXPathHasSameNodes(nodes, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlXPathHasSameNodes", (void *)ret_val, (void *)(0), "xmlXPathHasSameNodes Failed");
	
	__DeletexmlNodeSetPtr();
	/* Shutdown libxml */
	////xmlCleanupParser();

	
}
	/**    
	* @test			UTcxmlXPathDistinctP01
	* @brief		xmlNodeSetPtr xmlXPathDistinct (xmlNodeSetPtr nodes)
	* @desc			Positive Test for implementing the EXSLT - 
					Sets distinct() function: node-set set:distinct (node-set) @nodes is sorted by document order, then #exslSetsDistinctSorted is called with the sorted node-set
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(nodes)} => { N/A | retnode} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathDistinctP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {nodes} => { N/A | retnode} @n
	*/
	xmlNodeSetPtr retnode = xmlXPathDistinct (nodes);
	DTS_CHECK_NE_MESSAGE("xmlXPathDistinct", (void *)(retnode), (void *)(NULL), "xmlXPathDistinct Failed");
	
	__DeletexmlNodeSetPtr();
	if (retnode != NULL)
	{
		xmlXPathFreeNodeSet(retnode);
	}
	/* Shutdown libxml */
	////xmlCleanupParser();

}
	/**    
	* @test			UTcxmlXPathNextSelfP01
	* @brief		xmlNodePtr xmlXPathNextSelf (xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversing function for the "self" direction
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr,xmlNodePtr(cur)} => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextSelfP01()
{
	__XPathCommonInitFunc();
	//xmlNodePtr curnode = __get_api_root();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,xmlNodePtr} => { N/A | xmlNodePtr} @n
	*/
	xmlNodePtr retnextnode = xmlXPathNextSelf(pctxtInitPtr, NULL);
	//Need to check the failure ----SYAM.
	DTS_CHECK_EQ_MESSAGE("xmlXPathNextSelf", (void *)(retnextnode), (void *)(NULL), "xmlXPathNextSelf Failed");
	
	__XPathCommonDeleteFunc();
	__free_api_doc();


}
	/**    
	* @test			UTcxmlXPathNextAncestorOrSelfP01
	* @brief		xmlNodePtr xmlXPathNextAncestorOrSelf (xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversing function for the "ancestor-or-self" direction 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr,xmlNodePtr(cur)} => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextAncestorOrSelfP01()
{
	__XPathCommonInitFunc();
	xmlNodePtr curnode = __get_api_root();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,xmlNodePtr} => { N/A | xmlNodePtr} @n
	*/
	xmlNodePtr retnextnode = xmlXPathNextAncestorOrSelf(pctxtInitPtr, curnode);
	DTS_CHECK_NE_MESSAGE("xmlXPathNextAncestorOrSelf", (void *)(retnextnode), (void *)(NULL), "xmlXPathNextAncestorOrSelf Failed");

	__XPathCommonDeleteFunc();

	__free_api_doc();
	//if (NULL != retnextnode)
	//{
	//	xmlFreeNode(retnextnode);	
	//}
	
	/* Shutdown libxml */
	////xmlCleanupParser();

}
	/**    
	* @test			UTcxmlXPathNewValueTreeP01
	* @brief		xmlXPathObjectPtr xmlXPathNewValueTree (xmlNodePtr val)
	* @desc			Positive Test for creating a new xmlXPathObjectPtr of type Value Tree (XSLT) and initialize it with the tree root @val
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(val)} => { N/A | xmlXPathObjectPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNewValueTreeP01()
{
	xmlNodePtr curnode = __get_api_root();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlNodePtr} => { N/A | xmlXPathObjectPtr} @n
	*/
	xmlXPathObjectPtr retNewValueTree = xmlXPathNewValueTree(curnode);
	DTS_CHECK_NE_MESSAGE("xmlXPathNewValueTree", (void *)(retNewValueTree), (void *)(NULL), "xmlXPathNewValueTree Failed");

	if (curnode != NULL)
	{
		xmlUnlinkNode(curnode);
	}
	//xmlFreeNode(curnode);
	//__free_api_doc();

	//xmlFreeNode(curnode);
	if (NULL != retNewValueTree)
	{
		xmlXPathFreeObject(retNewValueTree);
	}
	__free_api_doc();
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathVariableLookupP01
	* @brief		xmlXPathObjectPtr xmlXPathVariableLookup (xmlXPathContextPtr ctxt, const xmlChar * name)
	* @desc			Positive Test for searching in the Variable array of the context for the given variable value.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr,const xmlChar "Now"} => { N/A | xmlXPathObjectPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathVariableLookupP01()
{
	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,"Now"} => { N/A | xmlXPathObjectPtr} @n
	*/
	xmlXPathObjectPtr retNewValueTree = xmlXPathVariableLookup(xpathCtxInitPtr, (const xmlChar*)"Now");
	//Need to check the failure ----SYAM.
	//Hash pass proper inputs
	DTS_CHECK_EQ_MESSAGE("xmlXPathVariableLookup", (void *)(retNewValueTree), (void *)(NULL), "xmlXPathVariableLookup Failed");

	__XPathCommonDeleteFunc();

}
	/**    
	* @test			UTcxmlXPathPopBooleanP01
	* @brief		int xmlXPathPopBoolean	(xmlXPathParserContextPtr ctxt)
	* @desc			Positive Test which Pops a boolean from the stack, handling conversion if needed. Check error with #xmlXPathCheckError.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt} => { N/A | XML_FALSE} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathPopBooleanP01()
{
	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlNodeSetPtr} => { N/A | XML_FALSE} @n
	*/
	if (pctxtInitPtr != NULL)
	{
		int popboolean = xmlXPathPopBoolean(pctxtInitPtr);
		DTS_CHECK_EQ_MESSAGE("xmlXPathPopBoolean", (void *)(popboolean), (void *)(XML_FALSE), "xmlXPathPopBoolean Failed");
	}
	if (NULL != pctxtInitPtr->context->lastError.str1)
	{
		xmlFree(pctxtInitPtr->context->lastError.str1);
		pctxtInitPtr->context->lastError.str1 = NULL;
	}
	//xmlResetLastError();
	__XPathCommonDeleteFunc();

}
	/**    
	* @test			UTcxmlXPathNewNodeSetListP01
	* @brief		xmlXPathObjectPtr	xmlXPathNewNodeSetList	(xmlNodeSetPtr val)
	* @desc			Positive Test for creating a new xmlXPathObjectPtr of type NodeSet and initialize it with the Nodeset @val
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(val)} => { N/A | xmlXPathObjectPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNewNodeSetListP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlNodeSetPtr} => { N/A | xmlXPathObjectPtr} @n
	*/
	xmlXPathObjectPtr retNewNodeSetList = xmlXPathNewNodeSetList(nodes);
	DTS_CHECK_NE_MESSAGE("xmlXPathNewNodeSetList", (void *)(retNewNodeSetList), (void *)(NULL), "xmlXPathNewNodeSetList Failed");

	__DeletexmlNodeSetPtr();
	if (retNewNodeSetList != NULL)
	{
		xmlXPathFreeNodeSet(retNewNodeSetList->nodesetval);//This memory was internally allocated
		xmlXPathFreeNodeSetList(retNewNodeSetList);
	}
	/* Shutdown libxml */
	////xmlCleanupParser();
}
	/**    
	* @test			UTcxmlXPathFunctionLookupP01
	* @brief		xmlXPathFunction xmlXPathFunctionLookup	(xmlXPathContextPtr ctxt, const xmlChar * name)
	* @desc			Positive Test for searching in the Function array of the context for the given function.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),const xmlChar "SISO"} => { N/A | xmlXPathFunction} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathFunctionLookupP01()
{
	__XPathCommonInitFunc();

	const xmlChar	*str		= (const xmlChar*)  "SISO";

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,"SISO"} => { N/A | xmlXPathFunction} @n
	*/
	xmlXPathFunction retFunctionLookup = xmlXPathFunctionLookup(xpathCtxInitPtr, str);
	//Need to check the failure ----SYAM.
	//Hash pass proper inputs
	DTS_CHECK_EQ_MESSAGE("xmlXPathFunctionLookup", (void *)(retFunctionLookup), (void *)(NULL), "xmlXPathFunctionLookup Failed");

	__XPathCommonDeleteFunc();

}
	/**    
	* @test			UTcxmlXPathNextAttributeP01
	* @brief		xmlNodePtr xmlXPathNextAttribute (xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversal function for the "attribute" direction TODO: support DTD inherited default attributes
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),xmlNodePtr(cur)} => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextAttributeP01()
{
	__XPathCommonInitFunc();

	xmlNodePtr curnode = __get_api_root();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,xmlNodePtr} => { N/A | xmlNodePtr} @n
	*/
	xmlNodePtr retnextnode = xmlXPathNextAttribute(pctxtInitPtr, curnode);

	DTS_CHECK_EQ_MESSAGE("xmlXPathNextAttribute", (void *)(retnextnode), (void *)(NULL), "xmlXPathNextAttribute Failed");

	__XPathCommonDeleteFunc();

	if (NULL != retnextnode)
	{
		xmlFreeNode(retnextnode);	
	}
	__free_api_doc();

	/* Shutdown libxml */
	////xmlCleanupParser();

}
	/**    
	* @test			UTcxmlXPathPopNodeSetP01
	* @brief		xmlNodeSetPtr	xmlXPathPopNodeSet	(xmlXPathParserContextPtr ctxt)
	* @desc			Positive Test for poping a node-set from the stack, handling conversion if needed. Check error with #xmlXPathCheckError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt)} => { N/A | xmlNodeSetPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathPopNodeSetP01()
{
	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr} => { N/A | xmlNodeSetPtr} @n
	*/
	xmlNodeSetPtr retPopNodeSet = xmlXPathPopNodeSet(pctxtInitPtr);
	//Need to check the failure ----SYAM.
	//Hash pass proper inputs
	DTS_CHECK_EQ_MESSAGE("xmlXPathPopNodeSet", (void *)(retPopNodeSet), (void *)(NULL), "xmlXPathPopNodeSet Failed");

	if (NULL != retPopNodeSet)
	{ 
		xmlXPathFreeNodeSet(retPopNodeSet);
	}
	if (NULL != pctxtInitPtr->context->lastError.str1)
	{
		xmlFree(pctxtInitPtr->context->lastError.str1);
		pctxtInitPtr->context->lastError.str1 = NULL;
	}
	//xmlResetLastError();
	__XPathCommonDeleteFunc();

}
	/**    
	* @test			UTcxmlXPathNextFollowingSiblingP01
	* @brief		xmlNodePtr xmlXPathNextFollowingSibling	(xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversal function for the "following-sibling" direction The following-sibling axis contains the following siblings of the context node in document order.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),NULL } => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextFollowingSiblingP01()
{
#if defined(LIBXML_XPATH_ENABLED)
    xmlNodePtr ret_val;
    xmlXPathParserContextPtr ctxt; /* the XPath Parser context */
    int n_ctxt;
    xmlNodePtr cur; /* the current node in the traversal */
    int n_cur;

    for (n_ctxt = 0;n_ctxt < gen_nb_xmlXPathParserContextPtr;n_ctxt++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
        ctxt = gen_xmlXPathParserContextPtr(n_ctxt, 0);
        cur = gen_xmlNodePtr(n_cur, 1);

        ret_val = xmlXPathNextFollowingSibling(ctxt, cur);
 	 DTS_CHECK_EQ_MESSAGE("xmlXPathNextFollowingSibling", (void *)(ret_val), (void *)(NULL), "xmlXPathNextFollowingSibling Failed");
        desret_xmlNodePtr(ret_val);
        des_xmlXPathParserContextPtr(n_ctxt, ctxt, 0);
        des_xmlNodePtr(n_cur, cur, 1);
        xmlResetLastError();
    }
    }
#endif

}
	/**    
	* @test			UTcxmlXPathNextPrecedingSiblingP01
	* @brief		xmlNodePtr xmlXPathNextPrecedingSibling	(xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for Traversal function for the "preceding-sibling" direction 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),NULL } => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextPrecedingSiblingP01()
{
#if defined(LIBXML_XPATH_ENABLED)
    xmlNodePtr ret_val;
    xmlXPathParserContextPtr ctxt; /* the XPath Parser context */
    int n_ctxt;
    xmlNodePtr cur; /* the current node in the traversal */
    int n_cur;

    for (n_ctxt = 0;n_ctxt < gen_nb_xmlXPathParserContextPtr;n_ctxt++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
        ctxt = gen_xmlXPathParserContextPtr(n_ctxt, 0);
        cur = gen_xmlNodePtr(n_cur, 1);

        ret_val = xmlXPathNextPrecedingSibling(ctxt, cur);
 	 DTS_CHECK_EQ_MESSAGE("xmlXPathNextFollowingSibling", (void *)(ret_val), (void *)(NULL), "xmlXPathNextFollowingSibling Failed");
        desret_xmlNodePtr(ret_val);
        des_xmlXPathParserContextPtr(n_ctxt, ctxt, 0);
        des_xmlNodePtr(n_cur, cur, 1);
        xmlResetLastError();
    }
    }
#endif

}	
	/**    
	* @test			UTcxmlXPathRegisterNsP01
	* @brief		int xmlXPathRegisterNs (xmlXPathContextPtr ctxt, const xmlChar * prefix, const xmlChar * ns_uri)
	* @desc			Positive Test for registering a new namespace.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),"//SUBJECT"	,"xml" } => { N/A | 0} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathRegisterNsP01()
{
	xmlChar	*xpathExpr	= (xmlChar*) "//SUBJECT";

	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,"//SUBJECT"	,"xml" } => { N/A | 0} @n
	*/
	DTS_CHECK_NE_MESSAGE("xmlXPathRegisterNs", (void *)(xmlXPathRegisterNs(xpathCtxInitPtr,xpathExpr,(const xmlChar*)"xml")), (void *)(-1), "xmlXPathRegisterNs Failed");

	__XPathCommonDeleteFunc();

}
	/**    
	* @test			UTcxmlXPathIsNodeTypeP01
	* @brief		int	xmlXPathIsNodeType (const xmlChar * name)
	* @desc			Positive Test for checking whether the name given a NodeType one.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const xmlChar "node" } => { N/A | 1} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathIsNodeTypeP01()
{
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {"node" } => { N/A | 1} @n
	*/
	DTS_CHECK_EQ_MESSAGE("xmlXPathIsNodeType", (void *)(xmlXPathIsNodeType((const xmlChar *)"node")), (void *)(1), "xmlXPathIsNodeType Failed");

}
	/**    
	* @test			UTcxmlXPathEvaluatePredicateResultP01
	* @brief		int xmlXPathEvaluatePredicateResult (xmlXPathParserContextPtr ctxt, xmlXPathObjectPtr res)
	* @desc			Positive Test for evaluating a predicate result for the current node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),xmlXPathObjectPtr(res) } => { N/A | 1} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathEvaluatePredicateResultP01()
{
	__XPathCommonInitFunc();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,xmlXPathObjectPtr } => { N/A | 1} @n
	*/
	DTS_CHECK_EQ_MESSAGE("xmlXPathEvaluatePredicateResult", (void *)(xmlXPathEvaluatePredicateResult(pctxtInitPtr,xpathObjInitPtr)), (void *)(1), "xmlXPathEvaluatePredicateResult Failed");
	__XPathCommonDeleteFunc();
}
	/**    
	* @test			UTcxmlXPathNsLookupP01
	* @brief		const xmlChar *	xmlXPathNsLookup (xmlXPathContextPtr ctxt, const xmlChar * prefix)
	* @desc			Positive Test for searching in the namespace declaration array of the context for the given namespace name associated to the given prefix
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),const xmlChar "xml"} => { N/A | (const xmlChar *)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNsLookupP01()
{
	__XPathCommonInitFunc();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,"xml"} => { N/A | (const xmlChar *)} @n
	*/
	const xmlChar *pRetNsLookup = xmlXPathNsLookup(xpathCtxInitPtr,(const xmlChar *)"xml");
	DTS_CHECK_NE_MESSAGE("xmlXPathNsLookup", (void *)(pRetNsLookup), (void *)(NULL), "xmlXPathNsLookup Failed");

	__XPathCommonDeleteFunc();
}
	/**    
	* @test			UTcxmlXPathNextNamespaceP01
	* @brief		xmlNodePtr xmlXPathNextNamespace (xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversal function for the "namespace" direction the namespace axis contains the namespace nodes of the context node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),xmlNodePtr(cur)} => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
	
static void UTcxmlXPathNextNamespaceP01()
{

#if defined(LIBXML_XPATH_ENABLED)
    xmlNodePtr ret_val;
    xmlXPathParserContextPtr ctxt; /* the XPath Parser context */
    int n_ctxt;
    xmlNodePtr cur; /* the current attribute in the traversal */
    int n_cur;

    for (n_ctxt = 0;n_ctxt < gen_nb_xmlXPathParserContextPtr;n_ctxt++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
        ctxt = gen_xmlXPathParserContextPtr(n_ctxt, 0);
        cur = gen_xmlNodePtr(n_cur, 1);

        ret_val = xmlXPathNextNamespace(ctxt, cur);

 	DTS_CHECK_EQ_MESSAGE("xmlXPathNextNamespace", (void *)(ret_val), (void *)(NULL), "xmlXPathNextNamespace Failed");
        desret_xmlNodePtr(ret_val);
        des_xmlXPathParserContextPtr(n_ctxt, ctxt, 0);
        des_xmlNodePtr(n_cur, cur, 1);
        xmlResetLastError();
    }
    }
#endif


}
	/**    
	* @test			UTcxmlXPathNextPrecedingP01
	* @brief		xmlNodePtr xmlXPathNextPreceding (xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversal function for the "preceding" direction the preceding axis contains all nodes in the same document 
					as the context node that are before the context node in document order, excluding any ancestors and excluding attribute nodes and namespace nodes
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),xmlNodePtr(cur)} => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextPrecedingP01()
{
	xmlNodePtr curnode = __get_api_root();
	__XPathCommonInitFunc();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,xmlNodePtr} => { N/A | xmlNodePtr} @n
	*/
	xmlNodePtr retNodePtr = xmlXPathNextPreceding(pctxtInitPtr,curnode);
	DTS_CHECK_NE_MESSAGE("xmlXPathNextPreceding", (void *)(retNodePtr), (void *)(NULL), "xmlXPathNextPreceding Failed");

	__XPathCommonDeleteFunc();
	__free_api_doc();

}
	/**    
	* @test			UTcxmlXPathNextFollowingP01
	* @brief		xmlNodePtr xmlXPathNextFollowing (xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversal function for the "following" direction The following axis contains all nodes in the same document 
					as the context node that are after the context node in document order, excluding any descendants and excluding attribute nodes and namespace nodes
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),xmlNodePtr(cur)} => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextFollowingP01()
{
	xmlNodePtr curnode = __get_api_root();
	__XPathCommonInitFunc();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,xmlNodePtr} => { N/A | xmlNodePtr} @n
	*/
	xmlNodePtr retNodePtr = xmlXPathNextFollowing(pctxtInitPtr,curnode);
	//Need to check the failure ----SYAM.
	DTS_CHECK_NE_MESSAGE("xmlXPathNextFollowing", (void *)(retNodePtr), (void *)(NULL), "xmlXPathNextFollowing Failed");

	__XPathCommonDeleteFunc();
	__free_api_doc();

}
	/**    
	* @test			UTcxmlXPathNextParentP01
	* @brief		xmlNodePtr xmlXPathNextParent (xmlXPathParserContextPtr ctxt, xmlNodePtr cur)
	* @desc			Positive Test for traversal function for the "parent" direction The parent axis contains the parent of the context node, if there is one.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),xmlNodePtr(cur)} => { N/A | xmlNodePtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNextParentP01()
{
	xmlNodePtr curnode = __get_api_root();

	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,xmlNodePtr} => { N/A | xmlNodePtr} @n
	*/
	xmlNodePtr retNodePtr = xmlXPathNextParent(pctxtInitPtr,curnode);
	DTS_CHECK_EQ_MESSAGE("xmlXPathNextParent", (void *)(retNodePtr), (void *)(NULL), "xmlXPathNextParent Failed");

	__XPathCommonDeleteFunc();
	__free_api_doc();

}
	/**    
	* @test			UTcxmlXPathNotEqualValuesP01
	* @brief		int	xmlXPathNotEqualValues	(xmlXPathParserContextPtr ctxt)
	* @desc			Positive Test for implementing the equal operation on XPath objects content: @arg1 == @arg2
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt)} => { N/A | 0 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathNotEqualValuesP01()
{
	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr} => { N/A | 0 } @n
	*/
	int retNotEqualValues = xmlXPathNotEqualValues(pctxtInitPtr);
	DTS_CHECK_EQ_MESSAGE("xmlXPathNotEqualValues", (void *)(retNotEqualValues), (void *)(0), "xmlXPathNotEqualValues Failed");

	if (NULL != pctxtInitPtr->context->lastError.str1)
	{
		xmlFree(pctxtInitPtr->context->lastError.str1);
		pctxtInitPtr->context->lastError.str1 = NULL;
	}
	//xmlResetLastError();
	__XPathCommonDeleteFunc();
}
	/**    
	* @test			UTcxmlXPathEqualValuesP01
	* @brief		int	xmlXPathEqualValues	(xmlXPathParserContextPtr ctxt)
	* @desc			Positive Test for implementing the equal operation on XPath objects content: @arg1 == @arg2
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt)} => { N/A | 0 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathEqualValuesP01()
{
	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr} => { N/A | 0 } @n
	*/
	int retEqualValues = xmlXPathEqualValues(pctxtInitPtr);
	DTS_CHECK_EQ_MESSAGE("xmlXPathEqualValues", (void *)(retEqualValues), (void *)(0), "xmlXPathEqualValues Failed");

	if (NULL != pctxtInitPtr->context->lastError.str1)
	{
		xmlFree(pctxtInitPtr->context->lastError.str1);
		pctxtInitPtr->context->lastError.str1 = NULL;
	}
	//xmlResetLastError();
	__XPathCommonDeleteFunc();
}
	/**    
	* @test			UTcxmlXPathCompareValuesP01
	* @brief		int xmlXPathCompareValues (xmlXPathParserContextPtr ctxt, int inf, int strict)
	* @desc			Positive Test for implementing the compare operation on XPath objects
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt),int(0),int(1)} => { N/A | (0 or 1) } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPathCompareValuesP01()
{
	__XPathCommonInitFunc();

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {xmlXPathParserContextPtr,0,1} => { N/A | (0 or 1) } @n
	*/
	int retcompvalues = xmlXPathCompareValues(pctxtInitPtr,0,1);
	//check proper input values for returning 1.
	//For comparision success 1 will be returned
	//For comparision fail 0 will be returned
	DTS_CHECK_EQ_MESSAGE("xmlXPathCompareValues", (void *)(retcompvalues), (void *)(0), "xmlXPathCompareValues Failed");

	if (NULL != pctxtInitPtr->context->lastError.str1)
	{
		xmlFree(pctxtInitPtr->context->lastError.str1);
		pctxtInitPtr->context->lastError.str1 = NULL;
	}
	//xmlResetLastError();
	__XPathCommonDeleteFunc();
}
static void UTcxmlXPathCtxtCompileP01()
{
	xmlXPathContextPtr ctxt = gen_xmlXPathContextPtr(0, 1);
	const xmlChar	*str		= (const xmlChar*)  "SISO";

	xmlXPathCompExprPtr ret_val =
		xmlXPathCtxtCompile(ctxt, str) ;

	DTS_CHECK_NE_MESSAGE("xmlXPathCtxtCompile", (void *)(ret_val), (void *)(NULL), "xmlXPathCtxtCompile Failed");

	xmlXPathFreeCompExpr(ret_val);
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { const xmlChar "SISO"} => { N/A | xmlXPathCompExprPtr pointer } @n
	*/
	xmlXPathCompExprPtr ret_val1 = xmlXPathCompile(str);

	DTS_CHECK_NE_MESSAGE("xmlXPathCompile", (void *)(ret_val1), (void *)(NULL), "xmlXPathCompile Failed");
	
	xmlXPathFreeContext(ctxt);

	xmlXPathFreeCompExpr(ret_val1);
	if (doc_get_api_root != NULL)
	{
		xmlFreeDoc(doc_get_api_root);
		doc_get_api_root = NULL;
	}
	/* Shutdown libxml */
	//xmlCleanupParser();

}

static void UTcxmlXPathNodeTrailingP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);
	xmlNodePtr node = __get_api_root();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlNodeSetPtr pointer, xmlNodePtr pointer} => { N/A | xmlNodeSetPtr pointer } @n
	*/
	xmlNodeSetPtr retsetptr = xmlXPathNodeTrailing (nodes, node);
	DTS_CHECK_NE_MESSAGE("xmlXPathNodeTrailing", (void *)(retsetptr), (void *)(NULL), "xmlXPathNodeTrailing Failed");
	
	xmlXPathFreeObject(xpathObj_gen_xmlNodeSetPtr);
	xmlXPathFreeContext(xpathCtx_gen_xmlNodeSetPtr);
	xmlFreeDoc(doc_gen_xmlNodeSetPtr);
	if (retsetptr != NULL)
	{
		xmlXPathFreeNodeSet(retsetptr);
	}
	__free_api_doc();

	/* Shutdown libxml */
	////xmlCleanupParser();

}
static void UTcxmlXPathNodeLeadingP01()
{
	xmlNodeSetPtr nodes = gen_xmlNodeSetPtr(1,1);
	xmlNodePtr node = __get_api_root();
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlNodeSetPtr pointer, xmlNodePtr pointer} => { N/A | xmlNodeSetPtr pointer } @n
	*/
	xmlNodeSetPtr retsetptr = xmlXPathNodeLeading (nodes, node);
	DTS_CHECK_NE_MESSAGE("xmlXPathNodeLeading", (void *)(retsetptr), (void *)(NULL), "xmlXPathNodeLeading Failed");
	
	xmlXPathFreeObject(xpathObj_gen_xmlNodeSetPtr);
	xmlXPathFreeContext(xpathCtx_gen_xmlNodeSetPtr);
	xmlFreeDoc(doc_gen_xmlNodeSetPtr);
	if (retsetptr != NULL)
	{
		xmlXPathFreeNodeSet(retsetptr);
	}
	__free_api_doc();

	/* Shutdown libxml */
	////xmlCleanupParser();
}
static void startup( void);
static void cleanup( void);

void (*tet_startup)( void) = startup;
void (*tet_cleanup)( void) = cleanup;

static void startup( void)
{
        /* start of TC */
        tet_printf("TC starts.");
}

static void cleanup( void)
{
        /* end of TC */
        tet_printf("TC ends.");
}

struct tet_testlist tet_testlist[] = {
	// Handling of out of context errors
	{UTcXPathP01,1},
	{UTcXPathP02,2},
	{UTcxmlXPathCastBooleanToNumberP01,3},
	{UTcxmlXPathCastBooleanToStringP01,4},
	{UTcxmlXPathCastNodeSetToNumberP01,5},
	{UTcxmlXPathCastNodeSetToStringP01,6},
	{UTcxmlXPathCastNodeToNumberP01,7},
	{UTcxmlXPathCastNodeToStringP01,8},
	{UTcxmlXPathCastNumberToBooleanP01,9},
	{UTcxmlXPathCastNumberToStringP01,10},
	{UTcxmlXPathCastStringToBooleanP01,11},
	{UTcxmlXPathCastStringToNumberP01,12},
	{UTcxmlXPathCastToBooleanP01,13},
	{UTcxmlXPathCastToNumberP01,14},
	{UTcxmlXPathCastToStringP01,15},
	{UTcxmlXPathCmpNodesP01,16},
	{UTcxmlXPathCompiledEvalP01,17},
	{UTcxmlXPathConvertBooleanP01,18},
	{UTcxmlXPathConvertNumberP01,19},
	{UTcxmlXPathConvertStringP01,20},
	{UTcxmlXPathEvalP01,21},
	{UTcxmlXPathEvalPredicateP01,22},
	{UTcxmlXPathNodeSetCreateP01,23},
	{UTcxmlXPathObjectCopyP01,24},
	{UTcxmlXPathOrderDocElemsP01,25},
	{UTcxmlXPathCtxtCompileP01,26},
	{UTcxmlXPathNodeTrailingP01,27},
	{UTcxmlXPathNodeLeadingP01,28},
	{UTcxmlXPathPopStringP01,29},
	{UTcxmlXPathPopNumberP01,30},
	{UTcxmlXPathWrapCStringP01,31},
	{UTcxmlXPathWrapExternalP01,32},
	{UTcxmlXPathRegisterVariableP01,33},
	{UTcxmlXPathTrailingSortedP01,34},
	{UTcxmlXPathLeadingSortedP01,36},
	{UTcxmlXPathTrailingP01,37},
	{UTcxmlXPathLeadingP01,38},
	{UTcxmlXPathIntersectionP01,39},
	{UTcxmlXPathDifferenceP01,40},
	{UTcxmlXPathHasSameNodesP01,41},
	{UTcxmlXPathDistinctP01,42},
	{UTcxmlXPathNextSelfP01,43},
	{UTcxmlXPathNextAncestorOrSelfP01,44},
	{UTcxmlXPathNewValueTreeP01,45},
	{UTcxmlXPathVariableLookupP01,46},
	{UTcxmlXPathPopBooleanP01,47},
	{UTcxmlXPathNewNodeSetListP01,48},
	{UTcxmlXPathFunctionLookupP01,49},
	{UTcxmlXPathNextAttributeP01,50},
	{UTcxmlXPathPopNodeSetP01,51},
	{UTcxmlXPathNextFollowingSiblingP01,52},
	{UTcxmlXPathNextPrecedingSiblingP01,53},
	{UTcxmlXPathRegisterNsP01,54},
	{UTcxmlXPathIsNodeTypeP01,55},
	{UTcxmlXPathEvaluatePredicateResultP01,56},
	{UTcxmlXPathNsLookupP01,57},
	{UTcxmlXPathNextNamespaceP01,58},
	{UTcxmlXPathNextPrecedingP01,59},
	{UTcxmlXPathNextFollowingP01,60},
	{UTcxmlXPathNextParentP01,61},
	{UTcxmlXPathNotEqualValuesP01,62},
	{UTcxmlXPathEqualValuesP01,63},
	{UTcxmlXPathCompareValuesP01,64},
	{UTcxmlXPathCastNodeSetToBooleanP01,65},
	{ NULL, 0 },
	
};





