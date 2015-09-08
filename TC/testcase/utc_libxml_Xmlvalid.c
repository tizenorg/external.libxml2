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
#include <libxml/xmlmemory.h>
#include <libxml/uri.h>
#include <libxml/globals.h>
#include <libxml/xmlunicode.h>
#include <libxml/tree.h>




/***************************************************************************
* SUTsXmlList
***************************************************************************/


/**************************************

HELPERS

****************************************/

#define gen_nb_xmlBufferPtr 3
#define gen_nb_xmlNotationPtr 1
#define gen_nb_xmlNotationTablePtr 1
static xmlDocPtr api_doc = NULL;
static xmlDtdPtr api_dtd = NULL;
static xmlNodePtr api_root = NULL;
static xmlAttrPtr api_attr = NULL;
static xmlNsPtr api_ns = NULL;
static void
free_api_doc(void) {
	xmlFreeDoc(api_doc);
	api_doc = NULL;
	api_dtd = NULL;
	api_root = NULL;
	api_attr = NULL;
	api_ns = NULL;
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
static const char *static_buf_content = "a static buffer";
static xmlBufferPtr gen_xmlBufferPtr(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(xmlBufferCreate());
	if (no == 1) return(xmlBufferCreateStatic((void *)static_buf_content, 13));
	return(NULL);
}

static xmlNotationPtr gen_xmlNotationPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlBufferPtr(int no ATTRIBUTE_UNUSED, xmlBufferPtr val, int nr ATTRIBUTE_UNUSED) {
	if (val != NULL) {
		xmlBufferFree(val);
	}
}

static void des_xmlNotationPtr(int no ATTRIBUTE_UNUSED, xmlNotationPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static xmlNotationTablePtr gen_xmlNotationTablePtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlNotationTablePtr(int no ATTRIBUTE_UNUSED, xmlNotationTablePtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_const_xmlChar_ptr 5

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return((xmlChar *) "foo");
	if (no == 1) return((xmlChar *) "<foo/>");
	if (no == 2) return((xmlChar *) "nøne");
	if (no == 3) return((xmlChar *) " 2ab ");
	return(NULL);
}
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}


#define gen_nb_xmlElementContentType 4
static xmlElementContentType gen_xmlElementContentType(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 1) return(XML_ELEMENT_CONTENT_ELEMENT);
	if (no == 2) return(XML_ELEMENT_CONTENT_OR);
	if (no == 3) return(XML_ELEMENT_CONTENT_PCDATA);
	if (no == 4) return(XML_ELEMENT_CONTENT_SEQ);
	return((xmlElementContentType)(0));
}

static void des_xmlElementContentType(int no ATTRIBUTE_UNUSED, xmlElementContentType val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void desret_xmlElementContentPtr(xmlElementContentPtr val) {
	if (val != NULL)
		xmlFreeElementContent(val);
}

#define gen_nb_xmlElementContentPtr 1
static xmlElementContentPtr gen_xmlElementContentPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlElementContentPtr(int no ATTRIBUTE_UNUSED, xmlElementContentPtr val, int nr ATTRIBUTE_UNUSED) {
	if (val != NULL)
		xmlFreeElementContent(val);
}

#define gen_nb_char_ptr 1
static char * gen_char_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_char_ptr(int no ATTRIBUTE_UNUSED, char * val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_int 4

static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(0);
	if (no == 1) return(1);
	if (no == 2) return(-1);
	if (no == 3) return(122);
	return(-1);
}
static void des_int(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
#define gen_nb_xmlDtdPtr 3
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
#define gen_nb_xmlElementTypeVal 4
static xmlElementTypeVal gen_xmlElementTypeVal(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 1) return(XML_ELEMENT_TYPE_ANY);
	if (no == 2) return(XML_ELEMENT_TYPE_ELEMENT);
	if (no == 3) return(XML_ELEMENT_TYPE_EMPTY);
	if (no == 4) return(XML_ELEMENT_TYPE_MIXED);
	return((xmlElementTypeVal)(0));
}

static void des_xmlElementTypeVal(int no ATTRIBUTE_UNUSED, xmlElementTypeVal val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
#define gen_nb_xmlValidCtxtPtr 2
static xmlValidCtxtPtr gen_xmlValidCtxtPtr(int no, int nr ATTRIBUTE_UNUSED) {
#ifdef LIBXML_VALID_ENABLED
	if (no == 0) return(xmlNewValidCtxt());
#endif
	return(NULL);
}
static void des_xmlValidCtxtPtr(int no ATTRIBUTE_UNUSED, xmlValidCtxtPtr val, int nr ATTRIBUTE_UNUSED) {
#ifdef LIBXML_VALID_ENABLED
	if (val != NULL)
		xmlFreeValidCtxt(val);
#endif
}
static void desret_xmlElementPtr(xmlElementPtr val) {
	if (val != NULL) {
		xmlUnlinkNode((xmlNodePtr) val);
	}
}

#define gen_nb_xmlAttributeDefault 4
static xmlAttributeDefault gen_xmlAttributeDefault(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 1) return(XML_ATTRIBUTE_FIXED);
	if (no == 2) return(XML_ATTRIBUTE_IMPLIED);
	if (no == 3) return(XML_ATTRIBUTE_NONE);
	if (no == 4) return(XML_ATTRIBUTE_REQUIRED);
	return((xmlAttributeDefault)(0));
}

static void des_xmlAttributeDefault(int no ATTRIBUTE_UNUSED, xmlAttributeDefault val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_xmlAttributeType 4
static xmlAttributeType gen_xmlAttributeType(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 1) return(XML_ATTRIBUTE_CDATA);
	if (no == 2) return(XML_ATTRIBUTE_ENTITIES);
	if (no == 3) return(XML_ATTRIBUTE_ENTITY);
	if (no == 4) return(XML_ATTRIBUTE_ENUMERATION);
	return((xmlAttributeType)(0));
}

static void des_xmlAttributeType(int no ATTRIBUTE_UNUSED, xmlAttributeType val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_xmlBufferAllocationScheme 4
static xmlBufferAllocationScheme gen_xmlBufferAllocationScheme(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 1) return(XML_BUFFER_ALLOC_DOUBLEIT);
	if (no == 2) return(XML_BUFFER_ALLOC_EXACT);
	if (no == 3) return(XML_BUFFER_ALLOC_IMMUTABLE);
	return((xmlBufferAllocationScheme)(0));
}

static void des_xmlBufferAllocationScheme(int no ATTRIBUTE_UNUSED, xmlBufferAllocationScheme val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void desret_xmlBufferAllocationScheme(xmlBufferAllocationScheme val ATTRIBUTE_UNUSED) {
}


#define gen_nb_xmlEnumerationPtr 1
static xmlEnumerationPtr gen_xmlEnumerationPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlEnumerationPtr(int no ATTRIBUTE_UNUSED, xmlEnumerationPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void desret_xmlAttributePtr(xmlAttributePtr val) {
	if (val != NULL) {
		xmlUnlinkNode((xmlNodePtr) val);
	}
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
	//snprintf((char *) name, 20, "foo%d", nr++);
	api_attr = xmlSetProp(api_root, name, (const xmlChar *) "bar");
#endif
	return(api_attr);
}

#define gen_nb_xmlAttrPtr 2
static xmlAttrPtr gen_xmlAttrPtr(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(get_api_attr());
	return(NULL);
}
static void des_xmlAttrPtr(int no, xmlAttrPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) free_api_doc();
}

static void desret_xmlAttrPtr(xmlAttrPtr val) {
	if (val != NULL) {
		xmlUnlinkNode((xmlNodePtr) val);
		xmlFreeNode((xmlNodePtr) val);
	}
}

#define gen_nb_xmlNodePtr 3
static xmlNodePtr gen_xmlNodePtr(int no, int nr ATTRIBUTE_UNUSED) {
	if (no == 0) return(xmlNewPI(BAD_CAST "test", NULL));
	if (no == 1) return(get_api_root());
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

static void desret_int(int val ATTRIBUTE_UNUSED) {
}
#define gen_nb_xmlElementPtr 1
static xmlElementPtr gen_xmlElementPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlElementPtr(int no ATTRIBUTE_UNUSED, xmlElementPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {

}

static void desret_xmlChar_ptr(xmlChar *val) {
	if (val != NULL)
		xmlFree(val);
}


#define gen_nb_xmlAttributePtr 1
static xmlAttributePtr gen_xmlAttributePtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlAttributePtr(int no ATTRIBUTE_UNUSED, xmlAttributePtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}


#define gen_nb_xmlElementTablePtr 1
static xmlElementTablePtr gen_xmlElementTablePtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlElementTablePtr(int no ATTRIBUTE_UNUSED, xmlElementTablePtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}


#define gen_nb_xmlAttributeTablePtr 1
static xmlAttributeTablePtr gen_xmlAttributeTablePtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	return(NULL);
}
static void des_xmlAttributeTablePtr(int no ATTRIBUTE_UNUSED, xmlAttributeTablePtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
	/**    
	* @test			UTcxmlNewValidCtxtP01
	* @brief		xmlValidCtxtPtr	xmlNewValidCtxt	(void)
	* @desc			Positive Test for allocating a validation context structure.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A]	@n
	*   			{xmlNewValidCtxt(void} => {N/A | xmlValidCtxtPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlNewValidCtxtP01()
{
	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{void} => {N/A | xmlValidCtxtPtr}	@n
	*/
#ifdef  LIBXML_VALID_ENABLED
	xmlValidCtxtPtr outValue = xmlNewValidCtxt();
	DTS_CHECK_NE_MESSAGE("UTcxmlNewValidCtxtP01", (void *)outValue, (void *)NULL, "xmlNewValidCtxt Failed");
	xmlFreeValidCtxt(outValue);
#endif
}
	/**    
	* @test			UTcxmlFreeValidCtxtP01
	* @brief		void xmlFreeValidCtxt (xmlValidCtxtPtr cur)
	* @desc			Positive Test for Freeing a validation context structure.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlValidCtxtPtr(outVal) is created ,N/A]	@n
	*   			{xmlValidCtxtPtr(outVal)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlFreeValidCtxtP01()
{

	/**
	* @remarks   input1: [xmlValidCtxtPtr(outVal) is created ,N/A]	@n
	*					{outVal} => {N/A | N/A}	@n
	*/	
#ifdef  LIBXML_VALID_ENABLED
	xmlValidCtxtPtr outValue = xmlNewValidCtxt();
	DTS_CHECK_NE_MESSAGE("UTcxmlFreeValidCtxtP01", (void *)outValue, (void *)NULL, "xmlNewValidCtxt Failed");
	xmlFreeValidCtxt(outValue);
#endif
}
	/**    
	* @test			UTcxmlAddNotationDeclP01
	* @brief		xmlNotationPtr	xmlAddNotationDecl (xmlValidCtxtPtr ctxt,
					xmlDtdPtr dtd,
					const xmlChar * name,
					const xmlChar * PublicID,
   				    const xmlChar * SystemID)
	* @desc			Positive Test for registering a new notation declaration
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDtdPtr(dtd) is created , N/A]	@n
	*   			{NULL,xmlDtdPtr(dtd),xmlChar(name),xmlChar(pId1),xmlChar(sId1)} => {N/A |xmlNotationPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlAddNotationDeclP01()
{

	xmlDtdPtr dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	//xmlElementPtr elem = xmlAddElementDecl(NULL, dtd, (const xmlChar *)"test", XML_ELEMENT_TYPE_EMPTY, NULL); /* An element table */

	xmlElementTablePtr table = xmlHashCreate(0);
	xmlHashAddEntry(table,(xmlChar*)"Id1",(void*)"element1");
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) is created , N/A]	@n
	*					{NULL,dtd,"name","pId1","sId1"} => {N/A |xmlNotationPtr}	@n
	*/	
	xmlNotationPtr ret_val = xmlAddNotationDecl(NULL,dtd,(xmlChar *)"name",(xmlChar *)"pId1",(xmlChar *)"sId1");
	DTS_CHECK_NE_MESSAGE("UTcxmlAddNotationDeclP01", (void *)ret_val, (void *)NULL, "xmlNewValidCtxt Failed");
		
	DTS_CHECK_EQ_MESSAGE("UTcxmlAddNotationDeclP01", (void *)(strcmp((char*)ret_val->name,"name")), (void *)0, "xmlNewValidCtxt Failed");
	DTS_CHECK_EQ_MESSAGE("UTcxmlAddNotationDeclP01", (void *)(strcmp((char*)ret_val->SystemID,"sId1")), (void *)0, "xmlNewValidCtxt Failed");	
	DTS_CHECK_EQ_MESSAGE("UTcxmlAddNotationDeclP01", (void *)(strcmp((char*)ret_val->PublicID,"pId1")), (void *)0, "xmlNewValidCtxt Failed");
	

	if (NULL != table)
	{
		//xmlHashRemoveEntry(table,(xmlChar*)"Id1",NULL);
		xmlHashFree(table,NULL);
	}
	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
}
	/**    
	* @test			UTcxmlCopyNotationTableP01
	* @brief		xmlNotationTablePtr	xmlCopyNotationTable (xmlNotationTablePtr table)
	* @desc			Positive Test for building a copy of a notation table
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ N/A , N/A]	@n
	*   			{NULL} => {N/A |xmlNotationTablePtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlCopyNotationTableP01()
{
	/**
	* @remarks   input1: [ N/A , N/A]	@n
	*					{NULL} => {N/A |xmlNotationTablePtr}	@n
	*/	
	xmlNotationTablePtr table2 = xmlCopyNotationTable(NULL);
	DTS_CHECK_EQ_MESSAGE("UTcxmlCopyNotationTableP01", (void *)table2, (void *)NULL, "xmlCopyNotationTable Failed");
}
	/**    
	* @test			UTcxmlFreeNotationTableP01
	* @brief		int	xmlHashAddEntry3	(xmlHashTablePtr table,
					const xmlChar * name, 
					const xmlChar * name2,
					const xmlChar * name3, 
					void * userdata)
	* @desc			Positive Test for adding the userdata to the hash table
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlElementTablePtr(table) is created with size 4 , N/A]	@n
	*   			{xmlHashTablePtr(table)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlFreeNotationTableP01()
{
	xmlElementTablePtr table = xmlHashCreate(4);
	xmlHashAddEntry3(table,(xmlChar*)"Id1",(xmlChar*)"name2",(xmlChar*)"name3",NULL);
	/**
	* @remarks   input1: [xmlElementTablePtr(table) is created with size 4 , N/A]	@n
	*					{table} => {N/A | N/A}	@n
	*/	
	xmlFreeNotationTable(table);
	DTS_CHECK_EQ_MESSAGE("xmlFreeNotationTable", (void *)1, (void *)1, "xmlFreeNotationTable Failed");
}	

	/**    
	* @test			UTcxmlDumpNotationDeclP01
	* @brief		void	xmlDumpNotationDecl	(xmlBufferPtr buf,
					xmlNotationPtr nota)
	* @desc			Positive Test for dumping the content the notation declaration as an XML DTD definition
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlBufferPtr(buf) is created \n xmlNotationPtr(nota) is created with name ="hello" PrimaryId ="pId" SystemId ="sId" , N/A]	@n
	*   			{xmlBufferPtr(buf),xmlNotationPtr(nota)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlDumpNotationDeclP01()
{
//	int test_ret = 0;
	xmlBufferPtr buf; /* the XML buffer output */
	xmlNotationPtr nota = (xmlNotationPtr)malloc(sizeof(xmlNotation)); /* A notation declaration */
	unsigned char* pname = (unsigned char*)"hello";
	buf = xmlBufferCreate();
	DTS_CHECK_NE_MESSAGE("UTcxmlFreeValidCtxtP01", (void *)buf, (void *)NULL, "xmlBufferCreate Failed");
		
	buf->alloc = XML_BUFFER_ALLOC_EXACT;
	nota->name = pname;
	nota->PublicID = NULL;
	nota->SystemID = NULL;
	/**
	* @remarks   input1: [xmlBufferPtr(buf) is created \n xmlNotationPtr(nota) is created with name ="hello" PrimaryId ="pId" SystemId ="sId" , N/A]	@n
	*					{buf,nota} => {N/A | N/A}	@n
	*/	
	xmlDumpNotationDecl(buf, nota);
	unsigned char* out = (unsigned char*)(buf->content);
	int check = strcmp("<!NOTATION hello SYSTEM \"\" >\n",(const char*)out);
	DTS_CHECK_EQ_MESSAGE("UTcxmlFreeValidCtxtP01", (void *)check, (void *)0, "xmlDumpNotationDecl Failed");
		
	xmlResetLastError();

	free( nota);
	if (buf != NULL)
	{
		xmlBufferFree(buf);
	}
}
	/**    
	* @test			UTcxmlDumpNotationTableP01
	* @brief		void	xmlDumpNotationTable	(xmlBufferPtr buf, 	
					xmlNotationTablePtr table)
	* @desc			Positive Test for dumping the content of the notation table as an XML DTD definition
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlBufferPtr(buf) is created \n xmlNotationTablePtr(table) is created , N/A]	@n
	*   			{xmlBufferPtr(buf),xmlNotationTablePtr(table)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlDumpNotationTableP01()
{
	xmlBufferPtr buf; /* the XML buffer output */
	int n_buf;
	xmlNotationTablePtr table; /* A notation table */
	int n_table;

	/**
	* @remarks   input1: [xmlBufferPtr(buf) is created \n xmlNotationTablePtr(table) is created , N/A]	@n
	*					{buf,table} => {N/A | N/A}	@n
	*/
	for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr;n_buf++) {
		for (n_table = 0;n_table < gen_nb_xmlNotationTablePtr;n_table++) {
			buf = gen_xmlBufferPtr(n_buf, 0);
			table = gen_xmlNotationTablePtr(n_table, 1);

			xmlDumpNotationTable(buf, table);
			DTS_CHECK_EQ_MESSAGE("xmlDumpNotationTable", (void *)1, (void *)1, "xmlDumpNotationTable Failed");
			des_xmlBufferPtr(n_buf, buf, 0);
			des_xmlNotationTablePtr(n_table, table, 1);
			xmlResetLastError();

		}
	}

}
	/**    
	* @test			UTcxmlNewElementContentP01
	* @brief		xmlElementContentPtr	xmlNewElementContent	(const xmlChar * name, xmlElementContentType type)
	* @desc			Positive Test for allocating an element content structure
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A]	@n
	*   			{"foo",XML_ELEMENT_CONTENT_PCDATA} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlNewElementContentP01()
{
//	int test_ret = 0;

	xmlElementContentPtr ret_val;
	xmlChar * name; /* the subelement name or NULL */
	name = (xmlChar *)("foo");
	ret_val = xmlNewElementContent((const xmlChar *)name, XML_ELEMENT_CONTENT_ELEMENT);
	DTS_CHECK_NE_MESSAGE("UTcxmlNewElementContentP01", (void *)ret_val, (void *)NULL, "xmlNewElementContent Failed");
	
	if (ret_val != NULL)
	{
		DTS_CHECK_EQ_MESSAGE("UTcxmlNewElementContentP01", (void *)ret_val->type, (void *)XML_ELEMENT_CONTENT_ELEMENT, "xmlNewElementContent 1 Failed");
		DTS_CHECK_EQ_MESSAGE("UTcxmlNewElementContentP01", (void *)(strcmp((const char*)(ret_val->name),"foo")), (void *)0, "xmlNewElementContent 2 Failed");
		xmlFreeElementContent(ret_val);
	}
	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{"foo",XML_ELEMENT_CONTENT_PCDATA} => {N/A | N/A}	@n
	*/	
	//ret_val = xmlNewElementContent((const xmlChar *)name, xmlElementContentType(0));
	//MT_CHECK(ret_val == NULL);
}
	/**    
	* @test			UTcxmlCopyElementContentP01
	* @brief		xmlElementContentPtr	xmlCopyElementContent	(xmlElementContentPtr cur)
	* @desc			Positive Test for building a copy of an element content description
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlElementContentPtr(cur) is created with name "foo" and XML_ELEMENT_CONTENT_ELEMENT, N/A]	@n
	*   			{cur} => {N/A |xmlElementContentPtr}	@n
					input1: [N/A, N/A]	@n
					{xmlElementContentPtr} => {N/A | Copy of xmlElementContentPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlCopyElementContentP01()
{
	xmlChar * name;
	name = (xmlChar *)("foo");

	xmlElementContentPtr ret_val = NULL;
	xmlElementContentPtr cur = xmlNewElementContent((const xmlChar *)name, XML_ELEMENT_CONTENT_ELEMENT); /* An element content pointer. */
	/**
	* @remarks   input1: [xmlElementContentPtr(cur) is created with name "foo" and XML_ELEMENT_CONTENT_ELEMENT, N/A]	@n
	*					{cur} => {N/A |xmlElementContentPtr}	@n
	*/	
	ret_val = xmlCopyElementContent(cur);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementContentP01", (void *)ret_val, (void *)NULL, "xmlCopyElementContent Failed");
	
	if (ret_val != NULL)
	{
		DTS_CHECK_EQ_MESSAGE("UTcxmlCopyElementContentP01", (void *)ret_val->type, (void *)XML_ELEMENT_CONTENT_ELEMENT, "xmlCopyElementContent  1 Failed");
		DTS_CHECK_EQ_MESSAGE("UTcxmlCopyElementContentP01", (void *)(strcmp((const char*)(ret_val->name),"foo")), (void *)0, "xmlCopyElementContent 2 Failed");
		xmlFreeElementContent(ret_val);
		ret_val = NULL;
	}
	if (cur != NULL)
	{
		xmlFreeElementContent(cur);
		cur = NULL;
	}

	cur = xmlNewElementContent((const xmlChar *)"prefix:xml", XML_ELEMENT_CONTENT_ELEMENT); /* An element content pointer. */

	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{xmlElementContentPtr} => {N/A | Copy of xmlElementContentPtr}	@n
	*/	
	ret_val = xmlCopyElementContent(cur);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementContentP01", (void *)ret_val, (void *)NULL, "xmlCopyElementContent Failed");
	
	if (ret_val != NULL)
	{
		DTS_CHECK_EQ_MESSAGE("UTcxmlCopyElementContentP01", (void *)ret_val->type, (void *)XML_ELEMENT_CONTENT_ELEMENT, "xmlCopyElementContent  21 Failed");
		DTS_CHECK_EQ_MESSAGE("UTcxmlCopyElementContentP01", (void *)(strcmp((const char*)(ret_val->name),"xml")), (void *)0, "xmlCopyElementContent 22 Failed");
		DTS_CHECK_EQ_MESSAGE("UTcxmlCopyElementContentP01", (void *)(strcmp((const char*)(ret_val->prefix),"prefix")), (void *)0, "xmlCopyElementContent 23 Failed");
		xmlFreeElementContent(ret_val);
	}
	
	if (cur != NULL)
	{
		xmlFreeElementContent(cur);
	}
}
	/**    
	* @test			UTcxmlErrValidP01
	* @brief		xmlElementContentPtr	xmlNewElementContent	(const xmlChar * name, xmlElementContentType type)
	* @desc			Positive Test for allocating an element content structure.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create New ElementContent with name = NULL, N/A]	@n
	*   			{Input is set internally by API} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlErrValidP01()
{
	xmlChar * name;
	name = (xmlChar *)("foo");

	xmlElementContentPtr cur = xmlNewElementContent((const xmlChar *)name, XML_ELEMENT_CONTENT_ELEMENT); 

	//xmlElementContentPtr cur = xmlNewElementContent(NULL, XML_ELEMENT_CONTENT_ELEMENT); /* An element content pointer. */
	DTS_CHECK_NE_MESSAGE("UTcxmlErrValidP01", (void *)cur, (void *)NULL, "xmlNewElementContent Failed");
	
	if (cur != NULL)
	{
		DTS_CHECK_NE_MESSAGE("UTcxmlErrValidP01", (void *)cur->name, (void *)NULL, "xmlNewElementContent  1 Failed");
		xmlFreeElementContent(cur);
	}
}

	/**    
	* @test			UTcxmlFreeElementContentP01
	* @brief		void	xmlFreeElementContent	(xmlElementContentPtr cur)
	* @desc			Positive Test for freeing an element content structure
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlElementContentPtr(cur) is created with name "foo" and XML_ELEMENT_CONTENT_ELEMENT, N/A]	@n
	*   			{xmlElementContentPtr(cur)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlFreeElementContentP01()
{
	xmlChar * name;
	name = (xmlChar *)("foo");

	xmlElementContentPtr cur = xmlNewElementContent((const xmlChar *)name, XML_ELEMENT_CONTENT_ELEMENT);
	DTS_CHECK_NE_MESSAGE("xmlFreeElementContent", (void *)cur, (void *)NULL, "xmlNewElementContent Failed");
	/**
	* @remarks   input1: [xmlElementContentPtr(cur) is created with name "foo" and XML_ELEMENT_CONTENT_ELEMENT, N/A]	@n
	*					{cur} => {N/A | N/A}	@n
	*/	
	xmlFreeElementContent(cur);
	DTS_CHECK_EQ_MESSAGE("xmlFreeElementContent", (void *)1, (void *)1, "xmlFreeElementContent Failed");
}
	/**    
	* @test			UTcxmlSnprintfElementContentP01
	* @brief		void	xmlSnprintfElementContent (char * buf, size, xmlElementContentPtr content, int englob)
	* @desc			Positive Test for dumping the content of the element content definition Intended just for the debug routine
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlElementContentPtr(content) is created with name "foo" and XML_ELEMENT_CONTENT_ELEMENT, N/A]	@n
	*   			{char(buf),int(4),xmlElementContentPtr(content),int(0)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlSnprintfElementContentP01()
{
//	int test_ret = 0;

	char* buf = (char *)malloc(4);
	xmlElementContentPtr content = xmlNewElementContent((const xmlChar *)("foo"), XML_ELEMENT_CONTENT_ELEMENT);
	/**
	* @remarks   input1: [xmlElementContentPtr(content) is created with name "foo" and XML_ELEMENT_CONTENT_ELEMENT, N/A]	@n
	*					{buf,4,content,0} => {N/A | N/A}	@n
	*/
	xmlSnprintfElementContent(buf, 4, content, 0);
	DTS_CHECK_NE_MESSAGE("UTcxmlSnprintfElementContentP01", (void *)buf, (void *)NULL, "xmlSnprintfElementContent Failed");
	if (content != NULL)
	{
		xmlFreeElementContent(content);
	}
	free( buf);


#if 0
	int test_ret = 0;

	char * buf; /* an output buffer */
	int n_buf;
	int size; /* the buffer size */
	int n_size;
	xmlElementContentPtr content; /* An element table */
	int n_content;
	int englob; /* 1 if one must print the englobing parenthesis, 0 otherwise */
	int n_englob;

	for (n_buf = 0;n_buf < gen_nb_char_ptr;n_buf++) {
		for (n_size = 0;n_size < gen_nb_int;n_size++) {
			for (n_content = 0;n_content < gen_nb_xmlElementContentPtr;n_content++) {
				for (n_englob = 0;n_englob < gen_nb_int;n_englob++) {
					buf = gen_char_ptr(n_buf, 0);
					size = gen_int(n_size, 1);
					content = gen_xmlElementContentPtr(n_content, 2);
					englob = gen_int(n_englob, 3);
					xmlSnprintfElementContent(buf, size, content, englob);
					des_char_ptr(n_buf, buf, 0);
					des_int(n_size, size, 1);
					des_xmlElementContentPtr(n_content, content, 2);
					des_int(n_englob, englob, 3);
					xmlResetLastError();
				}
			}
		}
	}

#endif

}
	/**    
	* @test			UTcxmlCopyElementTableP01
	* @brief		xmlElementTablePtr	xmlCopyElementTable	(xmlElementTablePtr table)
	* @desc			Positive Test for building a copy of an element table.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL} => {N/A |NULL}	@n
					input2: [N/A, N/A]	@n
					{xmlElementTablePtr(table)} => {N/A | Copy of xmlElementTablePtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlCopyElementTableP01()
{
	int result = -1;
	const char *pFilename = LIBXML2TESTXML;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/

	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{NULL} => {N/A |NULL}	@n
	*/
	xmlElementTablePtr outValue = xmlCopyElementTable(NULL);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementTableP01", (void *)outValue, (void *)NULL, "xmlCopyElementTable Failed");


	if(outValue == NULL)
	{
		DTS_FAIL("UTcxmlCopyElementTableP01", "xmlCopyElementTable Failed");
		return;
	}
	
	xmlElementTablePtr inValue = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementTableP01", (void *)inValue, (void *)NULL, "xmlHashCreate Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_ASSERT_MESSAGE("UTcxmlCopyElementTableP01", (void *)(NULL == doc), "xmlReadFile Failed");

	xmlDtdPtr dtdPtr = xmlGetIntSubset(doc);
	xmlElementPtr elemPtr = xmlGetDtdElementDesc(dtdPtr, (const xmlChar *)"TO");
	//DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementTableP01", (void *)inValue, (void *)NULL, "xmlGetIntSubset Failed");

	result = xmlHashAddEntry(inValue, (const xmlChar *)"King", (void *)elemPtr);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementTableP01", (void *)result, (void *)-1, "xmlHashAddEntry Failed");

	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{xmlElementTablePtr} => {N/A | Copy of xmlElementTablePtr}	@n
	*/
	outValue = xmlCopyElementTable(inValue);	
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementTableP01", (void *)outValue, (void *)NULL, "xmlCopyElementTable Failed");
	if (elemPtr != NULL)
	{
		xmlFreeElementContent((xmlElementContentPtr )elemPtr);
	}
	if (NULL != inValue)
	{
		xmlHashFree(inValue,NULL);
	}
	if (NULL != outValue)
	{
		xmlHashFree(outValue,NULL);
	}
	//if (dtdPtr != NULL)
	//{
	//	xmlFreeDtd(dtdPtr);
	//}
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	//xmlCleanupCharEncodingHandlers();
}
	/**    
	* @test			UTcxmlGetDtdNotationDescP01
	* @brief		xmlNotationPtr	xmlGetDtdNotationDesc (xmlDtdPtr dtd, const xmlChar * name)
	* @desc			Positive Test for searching the DTD for the description of this notation
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDtdPtr(dtd) is created having notations as a hash table with name "test", N/A]	@n 
	*   			{xmlDtdPtr(dtd),const xmlChar("noString")} => {N/A |xmlNotationPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlGetDtdNotationDescP01()
{
	xmlDtdPtr dtd = xmlNewDtd(NULL, BAD_CAST "test", NULL, NULL);
	DTS_CHECK_NE_MESSAGE("UTcxmlGetDtdNotationDescP01", (void *)dtd, (void *)NULL, "xmlNewDtd Failed");
		
	xmlElementTablePtr table = xmlHashCreate(0);
	xmlHashAddEntry(table,(xmlChar*)"test",NULL);
	dtd->notations = table;
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) is created having notations as a hash table with name "test", N/A]	@n
	*					{dtd,"noString"} => {N/A |xmlNotationPtr}	@n
	*/
	xmlNotationPtr outValue = xmlGetDtdNotationDesc(dtd,(xmlChar*)"noString");
	DTS_CHECK_EQ_MESSAGE("UTcxmlGetDtdNotationDescP01", (void *)outValue, (void *)NULL, "xmlGetDtdNotationDesc Failed");

	dtd->notations = NULL;

	if (NULL != table)
	{
		xmlHashFree(table,NULL);
	}
	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
}
	/**    
	* @test			UTcxmlSprintfElementContentP01
	* @brief		void	xmlSprintfElementContent (char * buf, xmlElementContentPtr content, int englob)
	* @desc			Positive Test for Deprecated, unsafe, use xmlSnprintfElementContent
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlElementContentPtr(content) is created, N/A]	@n
	*   			{char(buf),xmlElementContentPtr(content),int(0)} => {N/A |xmlNotationPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlSprintfElementContentP01()
{
	char * buf = NULL; /* an output buffer */
	xmlElementContentPtr content = xmlNewElementContent((const xmlChar *)("foo"), XML_ELEMENT_CONTENT_ELEMENT);
	DTS_CHECK_NE_MESSAGE("UTcxmlSprintfElementContentP01", (void *)content, (void *)NULL, "xmlNewElementContent Failed");
	/**
	* @remarks   input1: [xmlElementContentPtr(content) is created, N/A]	@n
	*					{buf,content,0} => {N/A |xmlNotationPtr}	@n
	*/
	xmlSprintfElementContent(buf, content, 0);
	if (content != NULL)
	{
		xmlFreeElementContent(content);
	}


#if 0
	int n_buf;
	xmlElementContentPtr content; /* An element table */
	int n_content;
	int englob; /* 1 if one must print the englobing parenthesis, 0 otherwise */
	int n_englob;

	for (n_buf = 0;n_buf < gen_nb_char_ptr;n_buf++) {
		for (n_content = 0;n_content < gen_nb_xmlElementContentPtr;n_content++) {
			for (n_englob = 0;n_englob < gen_nb_int;n_englob++) {

				buf = gen_char_ptr(n_buf, 0);
				content = gen_xmlElementContentPtr(n_content, 1);
				englob = gen_int(n_englob, 2);

				xmlSprintfElementContent(buf, content, englob);
				des_char_ptr(n_buf, buf, 0);
				des_xmlElementContentPtr(n_content, content, 1);
				des_int(n_englob, englob, 2);
				xmlResetLastError();
			}
		}
	}
#endif
}
/**    
	* @test			UTcxmlAddElementDeclP01
	* @brief		xmlElementPtr	xmlAddElementDecl (xmlValidCtxtPtr ctxt, xmlDtdPtr dtd, const xmlChar * name, xmlElementTypeVal type, xmlElementContentPtr content)
	* @desc			Register a new element declaration
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDtdPtr(dtd) is created, N/A]	@n
					{NULL,dtd,"test",XML_ELEMENT_TYPE_EMPTY,NULL} => {N/A |xmlElementPtr}	@n
					input2: [N/A, N/A]	@n
					{NULL,dtd,"test",XML_ELEMENT_TYPE_ANY,NULL} => {N/A |xmlElementPtr}	@n
					input3: [N/A, N/A]	@n
					{NULL,xmlDtdPtr(dtd),"test",XML_ELEMENT_TYPE_MIXED,NULL} => {N/A |NULL}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlAddElementDeclP01()
{
	xmlDtdPtr dtd;
	xmlChar * name = (xmlChar *)"test";
	xmlElementContentPtr content = xmlNewElementContent((const xmlChar *)("foo"), XML_ELEMENT_CONTENT_ELEMENT);
	DTS_CHECK_NE_MESSAGE("UTcxmlAddElementDeclP01", (void *)content, (void *)NULL, "xmlNewElementContent Failed");
		
	xmlValidCtxtPtr ctxt = NULL;
	dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) is created, N/A]	@n
	*					{NULL,dtd,"test",XML_ELEMENT_TYPE_EMPTY,NULL} => {N/A |xmlElementPtr}	@n
	*/
	xmlElementPtr ret_val = xmlAddElementDecl(ctxt, dtd, (const xmlChar *)name, XML_ELEMENT_TYPE_EMPTY, NULL);
	DTS_CHECK_NE_MESSAGE("UTcxmlAddElementDeclP01", (void *)ret_val, (void *)NULL, "xmlAddElementDecl Failed");
	if (ret_val != NULL)
	{
		xmlFreeElementContent((xmlElementContentPtr )ret_val);
	}
	/**
	* @remarks   input2: [N/A, N/A]	@n
	*					{NULL,dtd,"test",XML_ELEMENT_TYPE_ANY,NULL} => {N/A |xmlElementPtr}	@n
	*/
	ret_val = xmlAddElementDecl(ctxt, dtd, (const xmlChar *)name, XML_ELEMENT_TYPE_ANY, NULL);
	DTS_CHECK_EQ_MESSAGE("UTcxmlAddElementDeclP01", (void *)ret_val, (void *)NULL, "xmlAddElementDecl Failed");
	/**
	* @remarks   input3: [N/A, N/A]	@n
	*					{NULL,dtd,"test",XML_ELEMENT_TYPE_MIXED,NULL} => {N/A |NULL}	@n
	*/
	ret_val = xmlAddElementDecl(ctxt, dtd, (const xmlChar *)name, XML_ELEMENT_TYPE_MIXED, NULL);
	DTS_CHECK_EQ_MESSAGE("UTcxmlAddElementDeclP01", (void *)ret_val, (void *)NULL, "xmlAddElementDecl Failed");
	
	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
	if (content != NULL)
	{
		xmlFreeElementContent(content);
	}
	if (name != NULL)
	{
		//xmlFree(name);
	}




#if 0
	int test_ret = 0;
	xmlElementPtr ret_val;
	xmlValidCtxtPtr ctxt; /* the validation context */
	int n_ctxt;
	xmlDtdPtr dtd; /* pointer to the DTD */
	int n_dtd;
	xmlChar * name; /* the entity name */
	int n_name;
	xmlElementTypeVal type; /* the element type */
	int n_type;
	xmlElementContentPtr content; /* the element content tree or NULL */
	int n_content;
	for (n_ctxt = 0;n_ctxt < gen_nb_xmlValidCtxtPtr;n_ctxt++) {
		for (n_dtd = 0;n_dtd < gen_nb_xmlDtdPtr;n_dtd++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_type = 0;n_type < gen_nb_xmlElementTypeVal;n_type++) {
					for (n_content = 0;n_content < gen_nb_xmlElementContentPtr;n_content++) {
						ctxt = gen_xmlValidCtxtPtr(n_ctxt, 0);
						dtd = gen_xmlDtdPtr(n_dtd, 1);
						name = gen_const_xmlChar_ptr(n_name, 2);
						type = gen_xmlElementTypeVal(n_type, 3);
						content = gen_xmlElementContentPtr(n_content, 4);

						ret_val = xmlAddElementDecl(ctxt, dtd, (const xmlChar *)name, type, content);
						desret_xmlElementPtr(ret_val);
						des_xmlValidCtxtPtr(n_ctxt, ctxt, 0);
						des_xmlDtdPtr(n_dtd, dtd, 1);
						des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
						des_xmlElementTypeVal(n_type, type, 3);
						des_xmlElementContentPtr(n_content, content, 4);
						xmlResetLastError();
					}
				}
			}
		}
	}
#endif
}
	/**    
	* @test			UTcxmlCreateEnumerationP01
	* @brief		xmlEnumerationPtr	xmlCreateEnumeration	(const xmlChar * name)
	* @desc			Positive Test for creating and initializing an enumeration attribute node
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A]	@n
	*   			{xmlChar("Enumeration")} => {N/A |xmlEnumerationPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlCreateEnumerationP01()
{
	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{"Enumeration"} => {N/A |xmlEnumerationPtr}	@n
	*/
	xmlEnumerationPtr outVal = xmlCreateEnumeration((xmlChar*)"Enumeration");
	DTS_CHECK_NE_MESSAGE("UTcxmlCreateEnumerationP01", (void *)outVal, (void *)NULL, "xmlCreateEnumeration Failed");

		
	if (NULL != outVal)
	{
		DTS_CHECK_EQ_MESSAGE("UTcxmlCreateEnumerationP01", (void *)(strcmp((char*)outVal->name,"Enumeration")), (void *)0, "xmlAddElementDecl Failed");

		xmlFreeEnumeration(outVal);
	}
}
	/**    
	* @test			UTcxmlFreeEnumerationP01
	* @brief		void	xmlFreeEnumeration	(xmlEnumerationPtr cur)
	* @desc			Positive Test for freeing an enumeration attribute node (recursive).
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlEnumerationPtr(outVal) is created with string "Enumeration", N/A]	@n
	*   			{outVal} => {N/A |xmlEnumerationPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlFreeEnumerationP01()
{
	xmlEnumerationPtr outVal = xmlCreateEnumeration((xmlChar*)"Enumeration");
	DTS_CHECK_NE_MESSAGE("UTcxmlFreeEnumerationP01", (void *)outVal, (void *)NULL, "xmlCreateEnumeration Failed");

	
	/**
	* @remarks   input1: [xmlEnumerationPtr(outVal) is created with string "Enumeration", N/A]	@n
	*					{outVal} => {N/A |xmlEnumerationPtr}	@n
	*/
	xmlFreeEnumeration(outVal);

}
	/**    
	* @test			UTcxmlCopyEnumerationP01
	* @brief		xmlEnumerationPtr	xmlCopyEnumeration	(xmlEnumerationPtr cur)
	* @desc			Positive Test for copying an enumeration attribute node (recursive).
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlEnumerationPtr(outVal) is created with string "Enumeration", N/A]	@n
	*   			{outVal} => {N/A |xmlEnumerationPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlCopyEnumerationP01()
{
	xmlEnumerationPtr outVal = xmlCreateEnumeration((xmlChar*)"Enumeration");
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyEnumerationP01", (void *)outVal, (void *)NULL, "xmlCreateEnumeration Failed");

	/**
	* @remarks   input1: [xmlEnumerationPtr(outVal) is created with string "Enumeration", N/A]	@n
	*					{outVal} => {N/A |xmlEnumerationPtr}	@n
	*/
	xmlEnumerationPtr cpyVal = xmlCopyEnumeration(outVal);
	
	if (NULL != cpyVal)
	{
		DTS_CHECK_EQ_MESSAGE("UTcxmlCopyEnumerationP01", (void *)(strcmp((char*)cpyVal->name,"Enumeration")), (void *)0, "xmlCopyEnumeration Failed");

		xmlFreeEnumeration(cpyVal);
	}
	if (NULL != outVal)
	{
		xmlFreeEnumeration(outVal);
	}

}
	/**    
	* @test			UTcxmlAddAttributeDeclP01
	* @brief		xmlAttributePtr	xmlAddAttributeDecl (xmlValidCtxtPtr ctxt, xmlDtdPtr dtd, const xmlChar * elem, const xmlChar * name, 
					const xmlChar * ns, xmlAttributeType type, xmlAttributeDefault def, const xmlChar * defaultValue, xmlEnumerationPtr tree)
	* @desc			Positive Test for registering a new attribute declaration Note that tree becomes the ownership of the DTD
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDtdPtr(dtd) is created, N/A]	@n
	*   			{NULL,dtd,"XmlElementName","XmlName","namespace",XML_ATTRIBUTE_FIXED,"Default",NULL} => {N/A |xmlAttributePtr}	@n
					input2: [N/A, N/A]	@n
					{NULL,xmlDtdPtr(dtd),const xmlChar("XmlElementName"),const xmlChar("XmlName"),"namespace",XML_ATTRIBUTE_FIXED,"Default",NULL} => {N/A |NULL}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlAddAttributeDeclP01()
{
#if 1
	xmlChar * elem;
	xmlAttributePtr ret_val;
	xmlValidCtxtPtr ctxt;
	xmlDtdPtr dtd;
	xmlChar * ns;
	xmlChar * name;
	xmlAttributeDefault def;
	xmlChar * defaultValue;
	xmlEnumerationPtr tree;


#ifdef LIBXML_VALID_ENABLED
	ctxt = xmlNewValidCtxt();
#else
	ctxt = NULL;
#endif

	dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	elem = (xmlChar *) "XmlElementName";
	name =  (xmlChar *) "XmlName";
	ns = (xmlChar *) "namespace";
	def = XML_ATTRIBUTE_FIXED;
	defaultValue = (xmlChar *) "Default";
	tree =  NULL;
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) is created, N/A]	@n
	*					{NULL,dtd,"XmlElementName","XmlName","namespace",XML_ATTRIBUTE_FIXED,"Default",NULL} => {N/A |xmlAttributePtr}	@n
	*/
	ret_val = xmlAddAttributeDecl(ctxt, dtd, (const xmlChar *)elem, (const xmlChar *)name, (const xmlChar *)ns, XML_ATTRIBUTE_CDATA, def, (const xmlChar *)defaultValue, tree);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyEnumerationP01", (void *)ret_val, (void *)NULL, "xmlCopyEnumeration Failed");
	/**
	* @remarks   input2: [N/A, N/A]	@n
	*					{NULL,dtd,"XmlElementName","XmlName","namespace",XML_ATTRIBUTE_FIXED,"Default",NULL} => {N/A |NULL}	@n
	*/	
	ret_val = xmlAddAttributeDecl(ctxt, dtd, (const xmlChar *)elem, (const xmlChar *)name, (const xmlChar *)ns, XML_ATTRIBUTE_CDATA, def, (const xmlChar *)defaultValue, tree);
	DTS_CHECK_EQ_MESSAGE("UTcxmlCopyEnumerationP01", (void *)ret_val, (void *)NULL, "xmlCopyEnumeration Failed");

	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
#if 0
	int test_ret = 0;
	xmlAttributePtr ret_val;
	xmlValidCtxtPtr ctxt; /* the validation context */
	int n_ctxt;
	xmlDtdPtr dtd; /* pointer to the DTD */
	int n_dtd;
	xmlChar * elem; /* the element name */
	int n_elem;
	xmlChar * name; /* the attribute name */
	int n_name;
	xmlChar * ns; /* the attribute namespace prefix */
	int n_ns;
	xmlAttributeType type; /* the attribute type */
	int n_type;
	xmlAttributeDefault def; /* the attribute default type */
	int n_def;
	xmlChar * defaultValue; /* the attribute default value */
	int n_defaultValue;
	xmlEnumerationPtr tree; /* if it's an enumeration, the associated list */
	int n_tree;

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlValidCtxtPtr;n_ctxt++) {
		for (n_dtd = 0;n_dtd < gen_nb_xmlDtdPtr;n_dtd++) {
			for (n_elem = 0;n_elem < gen_nb_const_xmlChar_ptr;n_elem++) {
				for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
					for (n_ns = 0;n_ns < gen_nb_const_xmlChar_ptr;n_ns++) {
						for (n_type = 0;n_type < gen_nb_xmlAttributeType;n_type++) {
							for (n_def = 0;n_def < gen_nb_xmlAttributeDefault;n_def++) {
								for (n_defaultValue = 0;n_defaultValue < gen_nb_const_xmlChar_ptr;n_defaultValue++) {
									for (n_tree = 0;n_tree < gen_nb_xmlEnumerationPtr;n_tree++) {
										ctxt = gen_xmlValidCtxtPtr(n_ctxt, 0);
										dtd = gen_xmlDtdPtr(n_dtd, 1);
										elem = gen_const_xmlChar_ptr(n_elem, 2);
										name = gen_const_xmlChar_ptr(n_name, 3);
										ns = gen_const_xmlChar_ptr(n_ns, 4);
										type = gen_xmlAttributeType(n_type, 5);
										def = gen_xmlAttributeDefault(n_def, 6);
										defaultValue = gen_const_xmlChar_ptr(n_defaultValue, 7);
										tree = gen_xmlEnumerationPtr(n_tree, 8);

										ret_val = xmlAddAttributeDecl(ctxt, dtd, (const xmlChar *)elem, (const xmlChar *)name, (const xmlChar *)ns, type, def, (const xmlChar *)defaultValue, tree);
										desret_xmlAttributePtr(ret_val);
										des_xmlValidCtxtPtr(n_ctxt, ctxt, 0);
										des_xmlDtdPtr(n_dtd, dtd, 1);
										des_const_xmlChar_ptr(n_elem, (const xmlChar *)elem, 2);
										des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 3);
										des_const_xmlChar_ptr(n_ns, (const xmlChar *)ns, 4);
										des_xmlAttributeType(n_type, type, 5);
										des_xmlAttributeDefault(n_def, def, 6);
										des_const_xmlChar_ptr(n_defaultValue, (const xmlChar *)defaultValue, 7);
										des_xmlEnumerationPtr(n_tree, tree, 8);
										xmlResetLastError();

									}
								}
							}
						}
					}
				}
			}
		}
	}
#endif
#endif
}
	/**    
	* @test			UTcxmlCopyAttributeTableP01
	* @brief		xmlAttributeTablePtr	xmlCopyAttributeTable	(xmlAttributeTablePtr table)
	* @desc			Positive Test for building a copy of an attribute table.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlAttributeTablePtr(table)} => {N/A |xmlAttributeTablePtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlCopyAttributeTableP01()
{
	int result = -1;
	const char *pFilename = LIBXML2TESTXML;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/

	xmlAttributeTablePtr inValue = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyAttributeTableP01", (void *)inValue, (void *)NULL, "xmlHashCreate Failed");


	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{NULL} => {N/A |xmlAttributeTablePtr}	@n
	*/
	xmlAttributeTablePtr outValue = xmlCopyAttributeTable(NULL);
	DTS_CHECK_EQ_MESSAGE("UTcxmlCopyAttributeTableP01", (void *)outValue, (void *)NULL, "xmlCopyAttributeTable Failed");


	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_ASSERT_MESSAGE("UTcxmlCopyAttributeTableP01", (void *)(NULL == doc), "xmlReadFile Failed");
		

	xmlDtdPtr dtdPtr = xmlGetIntSubset(doc);
	//xmlDtdPtr dtdPtr = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	xmlAttributePtr attrPtr = xmlGetDtdAttrDesc(dtdPtr, (const xmlChar *)"SIGN",(const xmlChar *)"email");

	result = xmlHashAddEntry(inValue, (const xmlChar *)"King", (void *)attrPtr);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyAttributeTableP01", (void *)result, (void *)-1, "xmlHashAddEntry Failed");

	//xmlElementPtr elemPtr = xmlGetDtdElementDesc(dtdPtr, (const xmlChar *)"TO");

	//result = xmlHashAddEntry(inValue, (const xmlChar *)"King", (void *)elemPtr);
	//MT_CHECK(-1 != result);

	outValue = xmlCopyAttributeTable(inValue);	
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyAttributeTableP01", (void *)outValue, (void *)NULL, "xmlCopyAttributeTable Failed");

	//if (elemPtr != NULL)
	//{
	//	xmlFreeElementContent((xmlElementContentPtr )elemPtr);
	//}
	
	if (NULL != inValue)
	{
		xmlHashFree(inValue,NULL);
	}
	if (NULL != outValue)
	{
		xmlHashFree(outValue,NULL);
	}
	//if (dtdPtr != NULL)
	//{
	//	xmlFreeDtd(dtdPtr);
	//}
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	//xmlCleanupCharEncodingHandlers();

}
	/**    
	* @test			UTcxmlFreeAttributeTableP01
	* @brief		void	xmlFreeAttributeTable (xmlAttributeTablePtr table)
	* @desc			Positive Test for deallocating the memory used by an entities hash table
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlAttributeTablePtr(inValue) is created, N/A]	@n
	*   			{inValue} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlFreeAttributeTableP01()
{
	xmlAttributeTablePtr inValue = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlFreeAttributeTableP01", (void *)inValue, (void *)NULL, "xmlHashCreate Failed");
	xmlHashAddEntry3(inValue,(xmlChar*)"Id1",(xmlChar*)"name2",(xmlChar*)"name3",NULL);

	/**
	* @remarks   input1: [xmlAttributeTablePtr(inValue) is created, N/A]	@n
	*					{inValue} => {N/A | N/A}	@n
	*/
	xmlFreeAttributeTable(inValue);

}
	/**    
	* @test			UTcxmlAddIDP01
	* @brief		xmlIDPtr xmlAddID (xmlValidCtxtPtr ctxt, xmlDocPtr doc, const xmlChar * value, xmlAttrPtr attr)
	* @desc			Positive Test for registering a new id declaration
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc) and xmlAttrPtr(attr) are created, N/A]	@n
	*   			{NULL,xmlDocPtr(doc),const xmlChar("input"),xmlAttrPtr(attr)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlAddIDP01()
{
	xmlIDTablePtr inpVal = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlAddIDP01", (void *)inpVal, (void *)NULL, "xmlHashCreate Failed");
	xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
	xmlAttrPtr attr = gen_xmlAttrPtr(0, 2);
	/**
	* @remarks   input1: [xmlDocPtr(doc) and xmlAttrPtr(attr) are created, N/A]	@n
	*					{NULL,doc,"input",attr} => {N/A | N/A}	@n
	*/
	xmlIDPtr outVal = xmlAddID(NULL,doc,(xmlChar*)"input",attr);
	DTS_CHECK_EQ_MESSAGE("UTcxmlAddIDP01", (void *)(strcmp((char*)(outVal->value),"input")), (void *)0, "xmlHashCreate Failed");

	if ((NULL != doc) && (NULL != attr))
	{
		xmlRemoveID(doc,attr);
	}
	if (NULL != inpVal)
	{
		xmlFreeIDTable(inpVal);
	}
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	if (attr != NULL)
	{
		xmlRemoveProp(attr);
	}
	free_api_doc();
}
	/**    
	* @test			UTcxmlFreeIDTableP01
	* @brief		void xmlFreeIDTable (xmlIDTablePtr table)
	* @desc			Positive Test for deallocating the memory used by an ID hash table
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlIDTablePtr(inpVal) is created, N/A]	@n
	*   			{inpVal} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlFreeIDTableP01()
{
	xmlIDTablePtr inpVal = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlFreeIDTableP01", (void *)inpVal, (void *)NULL, "xmlHashCreate Failed");
	/**
	* @remarks   input1: [xmlIDTablePtr(inpVal) is created, N/A]	@n
	*					{inpVal} => {N/A | N/A}	@n
	*/
	xmlFreeIDTable(inpVal);
}
	/**    
	* @test			UTcxmlGetIDP01
	* @brief		xmlAttrPtr xmlGetID (xmlDocPtr doc, const xmlChar * ID)
	* @desc			Positive Test for searching the attribute declaring the given ID
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc) is created, N/A]	@n
	*   			{xmlDocPtr(doc),const xmlCha("foo")} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlGetIDP01()
{

//	int test_ret = 0;
	xmlAttrPtr ret_val;
	xmlDocPtr doc; /* pointer to the document */
	int n_doc = 0;
	xmlChar * ID; /* the ID value */
	int n_ID = 0;
	/**
	* @remarks   input1: [xmlDocPtr(doc) is created, N/A]	@n
	*					{doc,"foo"} => {N/A | N/A}	@n
	*/
	//for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		//for (n_ID = 0;n_ID < gen_nb_const_xmlChar_ptr;n_ID++) {
			doc = gen_xmlDocPtr(n_doc, 0);
			ID = gen_const_xmlChar_ptr(n_ID, 1);

			ret_val = xmlGetID(doc, (const xmlChar *)ID);
			DTS_CHECK_EQ_MESSAGE("UTcxmlGetIDP01", (void *)ret_val, (void *)NULL, "xmlGetID Failed");
			desret_xmlAttrPtr(ret_val);
			des_xmlDocPtr(n_doc, doc, 0);
			//des_const_xmlChar_ptr(n_ID, (const xmlChar *)ID, 1);
			//xmlFree(ID);
			free_api_doc();

		//}
	//}

}
	/**    
	* @test			UTcxmlIsIDP01
	* @brief		int xmlIsID (xmlDocPtr doc, xmlNodePtr elem, xmlAttrPtr attr)
	* @desc			Positive Test for determining whether an attribute is of type ID.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc), xmlNodePtr(elem) and xmlAttrPtr(attr) are created, N/A]	@n
	*   			{xmlDocPtr(doc),xmlNodePtr(elem),xmlAttrPtr(attr-"foo"} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlIsIDP01()
{

	int ret_val;
	xmlDocPtr doc; /* the document */
	int n_doc = 0;
	xmlNodePtr elem; /* the element carrying the attribute */
	int n_elem = 0;
	xmlAttrPtr attr; /* the attribute */
	int n_attr = 0;
	/**
	* @remarks   input1: [xmlDocPtr(doc), xmlNodePtr(elem) and xmlAttrPtr(attr) are created, N/A]	@n
	*					{doc,elem,attr"foo"} => {N/A | N/A}	@n
	*/
	//for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		//for (n_elem = 0;n_elem < gen_nb_xmlNodePtr;n_elem++) {
			//for (n_attr = 0;n_attr < gen_nb_xmlAttrPtr;n_attr++) {
				doc = gen_xmlDocPtr(n_doc, 0);
				elem = gen_xmlNodePtr(n_elem, 1);
				attr = gen_xmlAttrPtr(n_attr, 2);

				ret_val = xmlIsID(doc, elem, attr);
				DTS_CHECK_EQ_MESSAGE("UTcxmlIsIDP01", (void *)ret_val, (void *)NULL, "xmlIsID Failed");
				desret_int(ret_val);
				des_xmlDocPtr(n_doc, doc, 0);
				des_xmlNodePtr(n_elem, elem, 1);
				des_xmlAttrPtr(n_attr, attr, 2);
				free_api_doc();
			//}
		//}
	//}

}
	/**    
	* @test			UTcxmlRemoveIDP01
	* @brief		int xmlRemoveID (xmlDocPtr doc, xmlAttrPtr attr)
	* @desc			Positive Test for removing the given attribute from the ID table maintained internally.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc) and xmlAttrPtr(attr) are created, N/A]	@n
	*   			{xmlDocPtr(doc),xmlAttrPtr(attr)} => {N/A |-1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlRemoveIDP01()
{

	int ret_val;
	xmlDocPtr doc; /* the document */
	int n_doc = 0;
	xmlAttrPtr attr; /* the attribute */
	int n_attr = 0;
	/**
	* @remarks   input1: [xmlDocPtr(doc) and xmlAttrPtr(attr) are created, N/A]	@n
	*					{doc,attr} => {N/A |-1}	@n
	*/
	//for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		//for (n_attr = 0;n_attr < gen_nb_xmlAttrPtr;n_attr++) {
			doc = gen_xmlDocPtr(n_doc, 0);
			attr = gen_xmlAttrPtr(n_attr, 1);

			ret_val = xmlRemoveID(doc, attr);
			DTS_CHECK_EQ_MESSAGE("UTcxmlRemoveIDP01", (void *)ret_val, (void *)-1, "xmlRemoveID Failed");
			desret_int(ret_val);
			des_xmlDocPtr(n_doc, doc, 0);
			des_xmlAttrPtr(n_attr, attr, 1);
			free_api_doc();
		//}
	//}
}
	/**    
	* @test			UTcxmlAddRefP01
	* @brief		xmlRefPtr xmlAddRef (xmlValidCtxtPtr ctxt, xmlDocPtr doc, const xmlChar * value, xmlAttrPtr attr)
	* @desc			Positive Test for registering a new ref declaration
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc) and xmlAttrPtr(attr) are created, N/A]	@n
	*   			{NULL,xmlDocPtr(doc),const xmlChar("input"),xmlAttrPtr(attr)} => {N/A |-1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlAddRefP01()
{
//	int result = -1;
                     //Target
//	const char *pFilename = LIBXML2TESTXML;
	xmlRefTablePtr inpVal = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlAddRefP01", (void *)inpVal, (void *)NULL, "xmlHashCreate Failed");
	xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");

	xmlAttrPtr attr = gen_xmlAttrPtr(0, 2);
	/**
	* @remarks   input1: [xmlDocPtr(doc) and xmlAttrPtr(attr) are created, N/A]	@n
	*					{NULL,doc,"input",attr} => {N/A |-1}	@n
	*/
	xmlRefPtr outVal = xmlAddRef(NULL,doc,(xmlChar*)"input",attr);
	DTS_CHECK_EQ_MESSAGE("UTcxmlAddRefP01", (void *)(strcmp((char*)(outVal->value),"input")), (void *)0, "xmlAddRef Failed");

	if (NULL != inpVal)
	{
		xmlFreeRefTable(inpVal);
	}
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	free_api_doc();
	
}

	/**    
	* @test			UTcxmlFreeRefTableP01
	* @brief		void xmlFreeRefTable	(xmlRefTablePtr table)
	* @desc			Positive Test for deallocating the memory used by an Ref hash table.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlRefTablePtr(inpVal)is created, N/A]	@n
	*   			{inpVal} => {N/A |-1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlFreeRefTableP01()
{
	xmlRefTablePtr inpVal = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlFreeRefTableP01", (void *)inpVal, (void *)NULL, "xmlHashCreate Failed");
	/**
	* @remarks   input1: [xmlRefTablePtr(inpVal)is created, N/A]	@n
	*					{inpVal} => {N/A |-1}	@n
	*/
	xmlFreeRefTable(inpVal);
}
	/**    
	* @test			UTcxmlIsRefP01
	* @brief		int xmlIsRef (xmlDocPtr doc, xmlNodePtr elem, xmlAttrPtr attr)
	* @desc			Positive Test for determining whether an attribute is of type Ref.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc),xmlAttrPtr(attr) and xmlNodePtr(elem) are created, N/A]	@n
	*   			{xmlDocPtr(doc),xmlNodePtr(elem),xmlAttrPtr(attr)} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlIsRefP01()
{
	int ret_val;
	xmlDocPtr doc; /* the document */
	xmlNodePtr elem; /* the element carrying the attribute */
	xmlAttrPtr attr; /* the attribute */
	doc = gen_xmlDocPtr(0, 0);
	DTS_CHECK_NE_MESSAGE("UTcxmlIsRefP01", (void *)doc, (void *)NULL, "gen_xmlDocPtr Failed");
		
	elem = gen_xmlNodePtr(0, 1);
	DTS_CHECK_NE_MESSAGE("UTcxmlIsRefP01", (void *)elem, (void *)NULL, "gen_xmlNodePtr Failed");
		
	attr = gen_xmlAttrPtr(0, 2);
	DTS_CHECK_NE_MESSAGE("UTcxmlIsRefP01", (void *)attr, (void *)NULL, "gen_xmlAttrPtr Failed");
		
	/**
	* @remarks   input1: [xmlDocPtr(doc),xmlAttrPtr(attr) and xmlNodePtr(elem) are created, N/A]	@n
	*					{doc,elem,attr} => {N/A |0}	@n
	*/
	ret_val = xmlIsRef(doc, elem, attr);
	DTS_CHECK_EQ_MESSAGE("UTcxmlIsRefP01", (void *)ret_val, (void *)0, "xmlIsRef Failed");
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	if (NULL != elem)
	{
		xmlFreeNode(elem);
	}
	//if (NULL != attr)
	//{
	//	xmlFreePropList(attr);
	//}
	free_api_doc();
	

}
	/**    
	* @test			UTcxmlRemoveRefP01
	* @brief		int xmlRemoveRef (xmlDocPtr doc, xmlAttrPtr attr)
	* @desc			Positive Test for removing the given attribute from the Ref table maintained internally.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc),xmlAttrPtr(attr) are created, N/A]	@n
	*   			{xmlDocPtr(doc),xmlAttrPtr(attr)} => {N/A |-1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlRemoveRefP01()
{
	int ret_val;
	xmlDocPtr doc; /* the document */
	xmlNodePtr elem; /* the element carrying the attribute */
	xmlAttrPtr attr; /* the attribute */
	doc = gen_xmlDocPtr(0, 0);
	elem = gen_xmlNodePtr(0, 1);
	attr = gen_xmlAttrPtr(0, 2);
	/**
	* @remarks   input1: [xmlDocPtr(doc),xmlAttrPtr(attr) are created, N/A]	@n
	*					{doc,elem,attr} => {N/A |-1}	@n
	*/
	ret_val = xmlRemoveRef(doc,attr);
	DTS_CHECK_EQ_MESSAGE("UTcxmlRemoveRefP01", (void *)ret_val, (void *)-1, "xmlRemoveRef Failed");

	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	if (NULL != elem)
	{
		xmlFreeNode(elem);
	}
	free_api_doc();
	//if (NULL != attr)
	//{
	//	xmlFreePropList(attr);
	//}
	
}
	/**    
	* @test			UTcxmlGetRefsP01
	* @brief		xmlListPtr xmlGetRefs (xmlDocPtr doc, const xmlChar * ID)
	* @desc			Positive Test for finding the set of references for the supplied ID
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr(doc) is created, N/A]	@n
	*   			{xmlDocPtr(doc),const xmlChar("test")} => {N/A |-1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlGetRefsP01()
{
	xmlListPtr ret_val;
	xmlDocPtr doc; /* the document */
	doc = gen_xmlDocPtr(0, 0);
	/**
	* @remarks   input1: [xmlDocPtr(doc) is created, N/A]	@n
	*					{doc,"test"} => {N/A |-1}	@n
	*/
	ret_val = xmlGetRefs(doc,(const xmlChar*)"test");
	DTS_CHECK_EQ_MESSAGE("UTcxmlGetRefsP01", (void *)ret_val, (void *)NULL, "xmlGetRefs Failed");
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
}
	/**    
	* @test			UTcxmlDumpElementTableP01
	* @brief		void xmlDumpElementTable (xmlBufferPtr buf, xmlElementTablePtr table)
	* @desc			Positive Test for dumping the content of the element table as an XML DTD definition
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlBufferPtr(buf) and xmlElementTablePtr(table) are created, N/A]	@n
	*   			{xmlBufferPtr(buf),xmlElementTablePtr(table)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlDumpElementTableP01()
{

	/**
	* @remarks   input1: [xmlBufferPtr(buf) and xmlElementTablePtr(table) are created, N/A]	@n
	*					{buf,table} => {N/A | N/A}	@n
	*/
#if defined(LIBXML_OUTPUT_ENABLED)
	//xmlBufferPtr buf; /* the XML buffer output */
	xmlBufferPtr buf2; /* the XML buffer output */
	int result = -1;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/
	const char *pFilename = LIBXML2TESTXML;
	//int n_buf;
	//xmlElementTablePtr table; /* An element table */
	//int n_table;

	//for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr;n_buf++) {
	//	for (n_table = 0;n_table < gen_nb_xmlElementTablePtr;n_table++) {
	//		buf = gen_xmlBufferPtr(n_buf, 0);
	//		table = gen_xmlElementTablePtr(n_table, 1);

	//		xmlDumpElementTable(buf, table);
	//		des_xmlBufferPtr(n_buf, buf, 0);
	//		des_xmlElementTablePtr(n_table, table, 1);
	//	}
	//}

	xmlElementTablePtr inValue = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlDumpElementTableP01", (void *)inValue, (void *)NULL, "xmlHashCreate Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_ASSERT_MESSAGE("UTcxmlDumpElementTableP01", (void *)(NULL == doc),  "xmlReadFile Failed");

	xmlDtdPtr dtdPtr = xmlGetIntSubset(doc);
	xmlElementPtr elemPtr = xmlGetDtdElementDesc(dtdPtr, (const xmlChar *)"TO");

	result = xmlHashAddEntry(inValue, (const xmlChar *)"King", (void *)elemPtr);
	DTS_CHECK_NE_MESSAGE("UTcxmlDumpElementTableP01", (void *)inValue, (void *)-1, "xmlHashAddEntry Failed");

	buf2 = xmlBufferCreate();
	DTS_ASSERT_MESSAGE("UTcxmlDumpElementTableP01", (void *)(NULL == buf2),  "xmlBufferCreate Failed");

	xmlDumpElementTable(buf2, inValue);

	//if (dtdPtr != NULL)
	//{
	//	xmlFreeDtd(dtdPtr);
	//}
	if (elemPtr != NULL)
	{
		xmlFreeElementContent((xmlElementContentPtr )elemPtr);
	}
	if (NULL != inValue)
	{
		xmlHashFree(inValue,NULL);
	}
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	if (buf2 != NULL)
	{
		xmlBufferFree(buf2);
	}

#endif

}
/**    
	* @test			UTcxmlDumpAttributeTableP01
	* @brief		void xmlDumpAttributeTable (xmlBufferPtr buf, xmlAttributeTablePtr table)
	* @desc			Positive Test for dumping the content of the attribute table as an XML DTD definition
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlBufferPtr(buf) and xmlElementTablePtr(table) are created, N/A]	@n
	*   			{xmlBufferPtr(buf),xmlAttributeTablePtr(table)} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlDumpAttributeTableP01()
{
	/**
	* @remarks   input1: [xmlBufferPtr(buf) and xmlElementTablePtr(table) are created, N/A]	@n
	*					{buf,table} => {N/A | N/A}	@n
	*/
#if defined(LIBXML_OUTPUT_ENABLED)
//	xmlBufferPtr buf; /* the XML buffer output */
	xmlBufferPtr buf2; /* the XML buffer output */
	int result = -1;
	const char *pFilename = LIBXML2TESTXML;


	xmlDocPtr doc; /* the resulting document tree used as i/p*/

	//int n_buf;
	//xmlAttributeTablePtr table; /* An attribute table */
	//int n_table;
	xmlElementTablePtr table = xmlHashCreate(4);
	xmlHashAddEntry3(table,(xmlChar*)"Id1",(xmlChar*)"name2",(xmlChar*)"name3",NULL);
	//for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr;n_buf++) {
	//	for (n_table = 0;n_table < gen_nb_xmlAttributeTablePtr;n_table++) {
	//		buf = gen_xmlBufferPtr(n_buf, 0);
	//		//table = gen_xmlAttributeTablePtr(n_table, 1);

	//		xmlDumpAttributeTable(buf, table);
	//		des_xmlBufferPtr(n_buf, buf, 0);
	//		des_xmlAttributeTablePtr(n_table, table, 1);
	//		xmlResetLastError();
	//	}
	//}
	if (NULL != table)
	{
		xmlHashFree(table,NULL);
	}

	xmlAttributeTablePtr inValue = xmlHashCreate(0);
	DTS_CHECK_NE_MESSAGE("UTcxmlDumpAttributeTableP01", (void *)inValue, (void *)NULL, "xmlHashCreate Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_ASSERT_MESSAGE("UTcxmlDumpElementTableP01", (void *)(NULL == doc),  "xmlBufferCreate Failed");

	xmlDtdPtr dtdPtr = xmlGetIntSubset(doc);
	xmlAttributePtr attrPtr = xmlGetDtdAttrDesc(dtdPtr, (const xmlChar *)"SIGN",(const xmlChar *)"email");

	result = xmlHashAddEntry(inValue, (const xmlChar *)"King", (void *)attrPtr);
	DTS_CHECK_NE_MESSAGE("UTcxmlDumpAttributeTableP01", (void *)result, (void *)-1, "xmlHashAddEntry Failed");

	buf2 = xmlBufferCreate();
	DTS_ASSERT_MESSAGE("UTcxmlDumpElementTableP01", (void *)(NULL == buf2),  "xmlBufferCreate Failed");

	xmlDumpAttributeTable(buf2, inValue);

	//if (dtdPtr != NULL)
	//{
	//	xmlFreeDtd(dtdPtr);
	//}
	if (NULL != inValue)
	{
		xmlHashFree(inValue,NULL);
	}
	if (NULL != doc)
	{
		xmlFreeDoc(doc);
	}
	if (buf2 != NULL)
	{
		xmlBufferFree(buf2);
	}
#endif
}
	/**    
	* @test			UTcxmlGetDtdQElementDescP01
	* @brief		xmlElementPtr	xmlGetDtdQElementDesc	(xmlDtdPtr dtd, const xmlChar * name, const xmlChar * prefix)
	* @desc			Positive Test for searching the DTD for the description of this element
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDtdPtr(dtd) having element 'Id1' is created, N/A]	@n
	*   			{dtd,"Id1"} => {N/A |xmlElementPtr}	@n
					input2: [N/A, N/A]	@n
					{xmlDtdPtr(dtd),const xmlChar("Id2")} => {N/A |NULL}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlGetDtdQElementDescP01()
{

	xmlElementPtr ret_val;
	xmlChar * name; /* the element name */
	xmlDtdPtr dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	DTS_CHECK_NE_MESSAGE("UTcxmlGetDtdQElementDescP01", (void *)dtd, (void *)NULL, "xmlNewDtd Failed");
	//xmlElementPtr elem = xmlAddElementDecl(NULL, dtd, (const xmlChar *)"test", XML_ELEMENT_TYPE_EMPTY, NULL); /* An element table */
	//
	//if (NULL != dtd->elements)
	//{
	//	xmlHashFree((xmlHashTablePtr)dtd->elements,NULL);
	//}
	xmlElementTablePtr table = xmlHashCreate(0);
	xmlHashAddEntry(table,(xmlChar*)"Id1",(void*)"element1");
	name = (xmlChar*)"Id1";
	dtd->elements = table;
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) having element 'Id1' is created, N/A]	@n
	*					{dtd,"Id1"} => {N/A |xmlElementPtr}	@n
	*/
	ret_val = xmlGetDtdQElementDesc(dtd, (const xmlChar *)name, NULL);
	DTS_CHECK_NE_MESSAGE("UTcxmlGetDtdQElementDescP01", (void *)ret_val, (void *)NULL, "xmlGetDtdQElementDesc Failed");
	//if (ret_val != NULL)
	//{
	//	//xmlFreeElementContent((xmlElementContentPtr )ret_val);
	//	xmlFreeElement(ret_val);
	//}
	
	/**
	* @remarks   input2: [N/A, N/A]	@n
	*					{dtd,"Id2"} => {N/A |NULL}	@n
	*/
	ret_val = xmlGetDtdQElementDesc(dtd, (const xmlChar *)"Id2", NULL);
	DTS_CHECK_EQ_MESSAGE("UTcxmlGetDtdQElementDescP01", (void *)ret_val, (void *)NULL, "xmlGetDtdQElementDesc Failed");

	/*if (NULL != elem)
	{
		xmlFreeElementContent((xmlElementContentPtr )elem);
	}*/


	dtd->elements = NULL;

	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
	if (NULL != table)
	{
		xmlHashFree(table,NULL);
	}

	//if (elem != NULL)
	//{
	//	xmlFree(elem);
	//}
	//if (name != NULL)
	//{
	//	xmlFree(name);
	//}

#if 0
	for (n_dtd = 0;n_dtd < gen_nb_xmlDtdPtr;n_dtd++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
				dtd = gen_xmlDtdPtr(n_dtd, 0);
				name = gen_const_xmlChar_ptr(n_name, 1);
				prefix = gen_const_xmlChar_ptr(n_prefix, 2);

				ret_val = xmlGetDtdQElementDesc(dtd, (const xmlChar *)name, (const xmlChar *)prefix);
				MT_CHECK(ret_val == NULL);
				desret_xmlElementPtr(ret_val);
				des_xmlDtdPtr(n_dtd, dtd, 0);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
				des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 2);
			}
		}
	}
#endif

}
	/**    
	* @test			UTcxmlGetDtdQAttrDescP01
	* @brief		xmlAttributePtr	xmlGetDtdQAttrDesc (xmlDtdPtr dtd, const xmlChar * elem, const xmlChar * name, const xmlChar * prefix)
	* @desc			Positive Test for searching the DTD for the description of this qualified attribute on this element.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		 input1: [xmlDtdPtr(dtd) having attribute 'Id1' is created, N/A]	@n
	*   			{dtd,NULL,"Id1",NULL} => {N/A |xmlAttributePtr}	@n
					input2: [N/A, N/A]	@n	
					{xmlDtdPtr(dtd),NULL,const xmlChar("Id2"),NULL} => {N/A |NULL}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlGetDtdQAttrDescP01()
{
	xmlAttributePtr ret_val;
	xmlChar * name; /* the attribute name */

	xmlDtdPtr dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	DTS_CHECK_NE_MESSAGE("UTcxmlGetDtdQAttrDescP01", (void *)dtd, (void *)NULL, "xmlNewDtd Failed");
	xmlElementPtr elem = xmlAddElementDecl(NULL, dtd, (const xmlChar *)"test", XML_ELEMENT_TYPE_EMPTY, NULL); /* An element table */

	xmlElementTablePtr table = xmlHashCreate(0);
	xmlHashAddEntry(table,(xmlChar*)"Id1",(void*)"element1");

	name = (xmlChar*)"Id1";
	dtd->attributes = table;
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) having attribute 'Id1' is created, N/A]	@n
	*					{dtd,NULL,"Id1",NULL} => {N/A |xmlAttributePtr}	@n
	*/
	ret_val = xmlGetDtdQAttrDesc(dtd, NULL, (const xmlChar *)name, NULL);
	DTS_CHECK_NE_MESSAGE("UTcxmlGetDtdQAttrDescP01", (void *)ret_val, (void *)NULL, "xmlGetDtdQAttrDesc 1 Failed");
	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{dtd,NULL,"Id2",NULL} => {N/A |NULL}	@n
	*/
	ret_val = xmlGetDtdQAttrDesc(dtd, (const xmlChar *)elem, (const xmlChar *)"iD2", NULL);
	DTS_CHECK_EQ_MESSAGE("UTcxmlGetDtdQAttrDescP01", (void *)ret_val, (void *)NULL, "xmlGetDtdQAttrDesc 2 Failed");

	dtd->attributes = NULL;
	if (NULL != table)
	{
		xmlHashFree(table,NULL);
	}
	//if (name != NULL)
	//{
	//	xmlFree(name);
	//}
	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}


#if 0

	for (n_dtd = 0;n_dtd < gen_nb_xmlDtdPtr;n_dtd++) {
		for (n_elem = 0;n_elem < gen_nb_const_xmlChar_ptr;n_elem++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
					dtd = gen_xmlDtdPtr(n_dtd, 0);
					elem = gen_const_xmlChar_ptr(n_elem, 1);
					name = gen_const_xmlChar_ptr(n_name, 2);
					prefix = gen_const_xmlChar_ptr(n_prefix, 3);

					ret_val = xmlGetDtdQAttrDesc(dtd, (const xmlChar *)elem, (const xmlChar *)name, (const xmlChar *)prefix);
					desret_xmlAttributePtr(ret_val);
					des_xmlDtdPtr(n_dtd, dtd, 0);
					des_const_xmlChar_ptr(n_elem, (const xmlChar *)elem, 1);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
					des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 3);
					xmlResetLastError();
				}
			}
		}
	}
#endif

}
	/**    
	* @test			UTcxmlCopyElementP01
	* @brief		xmlElementContentPtr	xmlCopyElementContent	(xmlElementContentPtr cur)
	* @desc			Positive Test for building a copy of an element content description
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlElementContentPtr(cur) is created with name = "foo", N/A]	@n
	*   			{xmlElementContentPtr(cur)} => {N/A |xmlAttributePtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlCopyElementP01()
{
	xmlElementContentPtr ret_val;
	xmlElementContentPtr cur; /* An element content pointer. */
	ret_val = xmlCopyElementContent(NULL);
	DTS_CHECK_EQ_MESSAGE("UTcxmlCopyElementP01", (void *)ret_val, (void *)NULL, "xmlCopyElementContent Failed");

	cur =  xmlNewElementContent((const xmlChar *)("foo"), XML_ELEMENT_CONTENT_ELEMENT);
	
	/**
	* @remarks   input1: [xmlElementContentPtr(cur) is created with name = "foo", N/A]	@n
	*					{cur} => {N/A |xmlAttributePtr}	@n
	*/
	ret_val = xmlCopyElementContent(cur);
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementP01", (void *)ret_val, (void *)NULL, "xmlGetDtdQAttrDesc Failed");
	if (ret_val != NULL)
	{
		xmlFreeElementContent(ret_val);
	}
	if (cur != NULL)
	{
		xmlFreeElementContent(cur);
	}
}
	/**    
	* @test			UTcxmlDumpElementDeclP01
	* @brief		void xmlDumpElementDecl (xmlBufferPtr buf, xmlElementPtr elem)
	* @desc			Positive Test for dumping the content of the element declaration as an XML DTD definition
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlBufferPtr(buf) is created \n xmlElementPtr(elem) is created with name = "test", N/A]	@n
	*   			{xmlBufferPtr(buf),xmlElementPtr(elem)} => {N/A |xmlAttributePtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlDumpElementDeclP01()
{
	/**
	* @remarks   input1: [xmlBufferPtr(buf) is created \n xmlElementPtr(elem) is created with name = "test", N/A]	@n
	*					{buf,elem} => {N/A |xmlAttributePtr}	@n
	*/
#if defined(LIBXML_OUTPUT_ENABLED)
	xmlBufferPtr buf; /* the XML buffer output */
	xmlValidCtxtPtr ctxt = NULL;
	xmlDtdPtr dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");

	xmlElementPtr elem = xmlAddElementDecl(ctxt, dtd, (const xmlChar *)"test", XML_ELEMENT_TYPE_EMPTY, NULL); /* An element table */
	buf = xmlBufferCreate();
	DTS_CHECK_NE_MESSAGE("UTcxmlCopyElementP01", (void *)buf, (void *)NULL, "xmlBufferCreate Failed");
	
	buf->alloc = XML_BUFFER_ALLOC_EXACT;
	xmlDumpElementDecl(buf, elem);
	DTS_CHECK_EQ_MESSAGE("UTcxmlCopyElementP01", (void *)(strcmp((char*)buf->content,"<!ELEMENT test EMPTY>\n")), (void *)0, "xmlDumpElementDecl Failed");

	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
	if (buf != NULL)
	{
		xmlBufferFree(buf);
	}

#endif
}
	/**    
	* @test			UTcxmlGetDtdElementDesclP01
	* @brief		xmlElementPtr xmlGetDtdElementDesc (xmlDtdPtr dtd, const xmlChar * name)
	* @desc			Positive Test for searching the DTD for the description of this element
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDtdPtr(dtd) is created with element having name "Id1" \n, N/A]	@n
	*   			{dtd,"Id1"} => {N/A |xmlElementPtr}	@n
					input2: [N/A , N/A]	@n
					{xmlDtdPtr(dtd),const xmlChar("noString")} => {N/A |NULL}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlGetDtdElementDesclP01()
{
	xmlElementPtr ret_val;
	xmlDtdPtr dtd; /* a pointer to the DtD to search */
	xmlChar * name; /* the element name */
	xmlElementTablePtr table = xmlHashCreate(0);
	xmlHashAddEntry(table,(xmlChar*)"Id1",(void*)"element1");
	dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	DTS_CHECK_NE_MESSAGE("UTcxmlGetDtdElementDesclP01", (void *)dtd, (void *)NULL, "xmlNewDtd Failed");
	
	name = (xmlChar*)"Id1";
	dtd->elements = table;
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) is created with element having name "Id1" \n, N/A]	@n
	*					{dtd,"Id1"} => {N/A |xmlElementPtr}	@n
	*/
	ret_val = xmlGetDtdElementDesc(dtd, (const xmlChar *)name);
	DTS_CHECK_NE_MESSAGE("UTcxmlGetDtdElementDesclP01", (void *)ret_val, (void *)NULL, "xmlGetDtdElementDesc Failed");
	/**
	* @remarks   input2: [N/A , N/A]	@n
	*					{dtd,"noString"} => {N/A |NULL}	@n
	*/
	ret_val = xmlGetDtdElementDesc(dtd, (const xmlChar *)"noString");
	DTS_CHECK_EQ_MESSAGE("UTcxmlGetDtdElementDesclP01", (void *)ret_val, (void *)NULL, "xmlGetDtdElementDesc Failed");

	dtd->elements = NULL;

	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
	if (NULL != table)
	{
		xmlHashFree(table,NULL);
	}
	//if (name != NULL)
	//{
	//	xmlFree(name);
	//}
	
}
	/**    
	* @test			UTcxmlIsMixedElementP01
	* @brief		int xmlIsMixedElement (xmlDocPtr doc, const xmlChar * name)
	* @desc			Positive Test for searching in the DtDs whether an element accept Mixed content (or ANY) basically if it is supposed to accept text childs
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDtdPtr(dtd) is created with element having name "Id1" and having type = XML_ELEMENT_TYPE_ELEMENT \n, N/A]	@n
	*   			{dtd,"Id1"} => {N/A |1}	@n
					input2: [N/A, N/A]	@n
					{xmlDocPtr(dtd),const xmlChar("hello")} => {N/A |-1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlIsMixedElementP01()
{
	int ret_val;
	xmlDocPtr doc; /* the document */
	xmlChar * name; /* the element name */

	xmlElementTablePtr table = xmlHashCreate(0);
	xmlHashAddEntry(table,(xmlChar*)"Id1",NULL);
	doc = xmlNewDoc(BAD_CAST "1.0");
	DTS_CHECK_NE_MESSAGE("UTcxmlIsMixedElementP01", (void *)doc, (void *)NULL, "xmlNewDoc Failed");
	
	xmlDtdPtr dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	DTS_CHECK_NE_MESSAGE("UTcxmlIsMixedElementP01", (void *)dtd, (void *)NULL, "xmlNewDtd Failed");
	
	doc->intSubset = dtd;
	name = (xmlChar*)"Id1";
	dtd->elements = table;
	/**
	* @remarks   input1: [xmlDtdPtr(dtd) is created with element having name "Id1" and having type = XML_ELEMENT_TYPE_ELEMENT \n, N/A]	@n
	*					{dtd,"Id1"} => {N/A |1}	@n
	*/
	ret_val = xmlIsMixedElement(doc, (const xmlChar *)name);
	DTS_CHECK_EQ_MESSAGE("UTcxmlIsMixedElementP01", (void *)ret_val, (void *)-1, "xmlIsMixedElement Failed");
	/**
	* @remarks   input2: [N/A, N/A]	@n
	*					{dtd,"hello"} => {N/A |-1}	@n
	*/
	ret_val = xmlIsMixedElement(doc, (const xmlChar *)"hello");
	DTS_CHECK_EQ_MESSAGE("UTcxmlIsMixedElementP01", (void *)ret_val, (void *)-1, "xmlIsMixedElement Failed");

	dtd->elements = NULL;
	doc->intSubset = NULL;
	if (NULL != table)
	{
		xmlHashFree(table,NULL);
	}
	//if (name != NULL)
	//{
	//	xmlFree(name);
	//}
	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
	if (doc != NULL)
	{
		xmlFreeDoc(doc);
	}
}
	/**    
	* @test			UTcxmlDumpAttributeDeclP01
	* @brief		void xmlDumpAttributeDecl (xmlBufferPtr buf, xmlAttributePtr attr)
	* @desc			Positive Test for dumping the content of the attribute declaration as an XML DTD definition
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlBufferPtr(buf) is creaetd \n xmlAttributePtr(ret_val) is created with type = XML_ATTRIBUTE_ID and name = "test", N/A]	@n
	*   			{xmlBufferPtr(buf),ret_val} => {N/A | N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void 
UTcxmlDumpAttributeDeclP01()
{
	/**
	* @remarks   input1: [xmlBufferPtr(buf) is creaetd \n xmlAttributePtr(ret_val) is created with type = XML_ATTRIBUTE_ID and name = "test", N/A]	@n
	*					{buf,ret_val} => {N/A | N/A}	@n
	*/
#if defined(LIBXML_OUTPUT_ENABLED)
	xmlBufferPtr buf; /* the XML buffer output */
	xmlDtdPtr dtd = xmlNewDtd(NULL, BAD_CAST "dtd", BAD_CAST"foo", BAD_CAST"bar");
	//xmlElementPtr elem = xmlAddElementDecl(NULL, dtd, (const xmlChar *)"test", XML_ELEMENT_TYPE_EMPTY, NULL); /* An element table */
	buf = xmlBufferCreate();
	DTS_CHECK_NE_MESSAGE("UTcxmlDumpAttributeDeclP01", (void *)buf, (void *)-1, "xmlBufferCreate Failed");

	buf->alloc = XML_BUFFER_ALLOC_EXACT;
	xmlAttributePtr ret_val = (xmlAttributePtr)malloc(sizeof( xmlAttribute));
	DTS_CHECK_NE_MESSAGE("UTcxmlDumpAttributeDeclP01", (void *)ret_val, (void *)NULL, "xmlAttribute Failed");
	
	ret_val->name = (xmlChar *)"test";
	ret_val->elem = NULL;
	ret_val->prefix = NULL;
	ret_val->atype = XML_ATTRIBUTE_ID;
	ret_val->def = XML_ATTRIBUTE_NONE;
	ret_val->defaultValue = NULL;

	xmlDumpAttributeDecl(buf, ret_val);
	DTS_CHECK_EQ_MESSAGE("UTcxmlDumpAttributeDeclP01", (void *)(strcmp("<!ATTLIST  test ID>\n",(char*)buf->content)), (void *)0, "xmlDumpAttributeDecl Failed");

	if (dtd != NULL)
	{
		xmlFreeDtd(dtd);
	}
	if (buf != NULL)
	{
		xmlBufferFree(buf);
	}
	if (ret_val != NULL)
	{
		free( ret_val);
	}
	

#endif

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
	{UTcxmlNewValidCtxtP01,1},
	{UTcxmlFreeValidCtxtP01,2},
	{UTcxmlAddNotationDeclP01,3},
	{UTcxmlCopyNotationTableP01,4},
	{UTcxmlFreeNotationTableP01,5},
	{UTcxmlDumpNotationDeclP01,6},
	{UTcxmlDumpNotationTableP01,7},
	{UTcxmlNewElementContentP01,8},
	{UTcxmlCopyElementContentP01,9},
	{UTcxmlFreeElementContentP01,10},
	
	{UTcxmlSnprintfElementContentP01,11},
	{UTcxmlSprintfElementContentP01,12},
	{UTcxmlAddElementDeclP01,13},
	{UTcxmlCreateEnumerationP01,14},
	{UTcxmlFreeEnumerationP01,15},
	{UTcxmlCopyEnumerationP01,16},
	{UTcxmlAddAttributeDeclP01,17},
	{UTcxmlCopyAttributeTableP01,18},
	{UTcxmlFreeAttributeTableP01,19},
	{UTcxmlAddIDP01,20},
	
	{UTcxmlFreeIDTableP01,21},
	{UTcxmlGetIDP01,22},
	{UTcxmlIsIDP01,23},
	{UTcxmlRemoveIDP01,24},
	{UTcxmlAddRefP01,25},
	{UTcxmlFreeRefTableP01,26},
	{UTcxmlIsRefP01,27},
	{UTcxmlRemoveRefP01,28},
	{UTcxmlGetRefsP01,29},
	{UTcxmlDumpElementTableP01,30},
	
	{UTcxmlDumpAttributeTableP01,31},
	{UTcxmlGetDtdQElementDescP01,32},
	{UTcxmlCopyElementP01,33},
	{UTcxmlDumpElementDeclP01,34},
	{UTcxmlGetDtdElementDesclP01,35},
	{UTcxmlGetDtdQAttrDescP01,36},
	{UTcxmlIsMixedElementP01,37},
	{UTcxmlDumpAttributeDeclP01,38},
	{UTcxmlGetDtdNotationDescP01,39},
	{UTcxmlErrValidP01,40},

	//{UTcxmlCopyElementTableP01,41},	
	{ NULL, 0 },
	
};
