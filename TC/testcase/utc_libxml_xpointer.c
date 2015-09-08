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
#include <libxml/xpointer.h>
#include <libxml/xpath.h>
#include <libxml/xmlwriter.h>
#include <libxml/xmlreader.h>
#include <libxml/xpathInternals.h>



/***************************************************************************
* SUTsXmlWriter
***************************************************************************/
#define MY_ENCODING "ISO-8859-1"

#define	OUTFILE1	UTSHOME"/writer1.res"
#define	OUTFILE2	UTSHOME"/missing.xml"
#define	OUTFILE3	UTSHOME"/test.out"



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
#if 0
#define gen_nb_xmlOutputBufferPtr 1
static xmlOutputBufferPtr gen_xmlOutputBufferPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlOutputBufferCreateFilename(OUTFILE3, NULL, 0));
    return(NULL);
}
static void des_xmlOutputBufferPtr(int no ATTRIBUTE_UNUSED, xmlOutputBufferPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) {
        xmlOutputBufferClose(val);
    }
}
static void desret_xmlTextWriterPtr(xmlTextWriterPtr val) {
    xmlFreeTextWriter(val);
}
#endif

#define gen_nb_int 1

static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(-1);
    if (no == 3) return(122);
    return(-1);
}

static void des_int(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
#if 0
#define gen_nb_xmlBufferPtr 1

static const char *static_buf_content = "a static buffer";
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
#define gen_nb_xmlParserCtxtPtr 1
static xmlParserCtxtPtr gen_xmlParserCtxtPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewParserCtxt());
    //if (no == 1) return(xmlCreateMemoryParserCtxt("<doc/>", 6));
    return(NULL);
}
static void des_xmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, xmlParserCtxtPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL)
        xmlFreeParserCtxt(val);
}
#define gen_nb_const_char_ptr 2
static char *gen_const_char_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((char *) "foo");
    if (no == 1) return((char *) "<foo/>");
    if (no == 2) return((char *) "test/ent2");
    return(NULL);
}
static void des_const_char_ptr(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void desret_xmlParserCtxtPtr(xmlParserCtxtPtr val) {
    xmlFreeParserCtxt(val);
}
#endif

#define gen_nb_xmlNodePtr 2
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

#define gen_nb_xmlDocPtr 1
static xmlDocPtr gen_xmlDocPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewDoc(BAD_CAST "1.0"));
    if (no == 1) return(xmlReadMemory("<foo/>", 6, "test", NULL, 0));
    if (no == 2) return(xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0));
    return(NULL);
}
#if 0
static void des_xmlDocPtr(int no ATTRIBUTE_UNUSED, xmlDocPtr val, int nr ATTRIBUTE_UNUSED) {
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}
#define gen_nb_xmlTextWriterPtr 1
static xmlTextWriterPtr gen_xmlTextWriterPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewTextWriterFilename(OUTFILE3, 0));
    return(NULL);
}
static void des_xmlTextWriterPtr(int no ATTRIBUTE_UNUSED, xmlTextWriterPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) xmlFreeTextWriter(val);
}

static void desret_int(int val ATTRIBUTE_UNUSED) {
}
#endif
#define gen_nb_const_xmlChar_ptr_ptr 1
#define gen_nb_xmlLocationSetPtr 1
#if 0
static xmlChar ** gen_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, const xmlChar ** val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_const_xmlChar_ptr 1

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "n?e");
    if (no == 3) return((xmlChar *) " 2ab ");
    return(NULL);
}
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
#endif
static int call_tests = 0;
static int function_tests = 0;
#define gen_nb_xmlXPathObjectPtr 5
#define gen_nb_xmlXPathParserContextPtr 1

static void des_xmlXPathObjectPtr(int no ATTRIBUTE_UNUSED, xmlXPathObjectPtr val, int nr ATTRIBUTE_UNUSED)
{
    if (val != NULL)
    {
        xmlXPathFreeObject(val);
    }
}

static void desret_xmlNodePtr(xmlNodePtr val)
{
    if ((val != NULL) && (val != api_root) && (val != (xmlNodePtr) api_doc))
    {
      xmlUnlinkNode(val);
      xmlFreeNode(val);
    }
}

static xmlXPathObjectPtr gen_xmlXPathObjectPtr(int no, int nr ATTRIBUTE_UNUSED)
{
    if (no == 0) return(xmlXPathNewString(BAD_CAST "string object"));
    if (no == 1) return(xmlXPathNewFloat(1.1));
    if (no == 2) return(xmlXPathNewBoolean(1));
    if (no == 3) return(xmlXPathNewNodeSet(NULL));
    if (no == 4)
    {
    	xmlDocPtr doc = gen_xmlDocPtr(1, 1);

    	return(xmlXPathNewNodeSet(xmlDocGetRootElement(doc)));
    }
    return(NULL);
}

static xmlXPathParserContextPtr gen_xmlXPathParserContextPtr(int no , int nr ATTRIBUTE_UNUSED)
{
	const xmlChar *str = (const xmlChar *)"checked";//ATTRIBUTE_UNUSED
	xmlDocPtr doc = gen_xmlDocPtr(1, 1);
	xmlNodePtr here = gen_xmlNodePtr(1, 2);
	xmlNodePtr origin = gen_xmlNodePtr(1, 3);

	if(no == 0)
		return(NULL);
	else if(no == 1)
		return(xmlXPathNewParserContext(str, xmlXPtrNewContext(doc, here, origin)));

	return(NULL);

}

static void des_xmlXPathParserContextPtr(int no ATTRIBUTE_UNUSED, xmlXPathParserContextPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{

}
	/**    
	* @test			UTcxmlXPtrBuildNodeListP01
	* @brief		xmlNodePtr xmlXPtrBuildNodeList(xmlXPathObjectPtr obj)
	* @desc			Positive and negetive Test for xmlXPtrBuildNodeList
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlNodePtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(obj)} => {N/A | xmlXPathObjectPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrBuildNodeListP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlNodePtr ret_val;
    xmlXPathObjectPtr obj; /* the XPointer result from the evaluation. */
    int n_obj;

    for (n_obj = 0;n_obj < gen_nb_xmlXPathObjectPtr;n_obj++) {
        obj = gen_xmlXPathObjectPtr(n_obj, 0);

        if(n_obj <= 3)// -ve case
        {
        	ret_val = xmlXPtrBuildNodeList(obj);
		DTS_CHECK_EQ_MESSAGE("xmlXPtrBuildNodeList", (void *)ret_val, (void *)(NULL), "xmlXPtrBuildNodeList Failed");
        }
        else if(n_obj > 3)// +ve case
        {
        	ret_val = xmlXPtrBuildNodeList(obj);
		DTS_CHECK_NE_MESSAGE("xmlXPtrBuildNodeList", (void *)ret_val, (void *)(NULL), "xmlXPtrBuildNodeList Failed");
        }

        desret_xmlNodePtr(ret_val);
        call_tests++;
        des_xmlXPathObjectPtr(n_obj, obj, 0);
        xmlResetLastError();
    }
#endif
}
	/**
	* @test			UTcxmlXPtrEvalRangePredicateP01
	* @brief		void xmlXPtrEvalRangePredicate(xmlXPathParserContextPtr ctxt)
	* @desc			Positive and negetive Test for xmlXPtrEvalRangePredicate
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt)} => {N/A | xmlXPathParserContextPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrEvalRangePredicateP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathParserContextPtr ctxt; /* the XPointer Parser context */
    int n_ctxt;

    for (n_ctxt = 0;n_ctxt < (gen_nb_xmlXPathParserContextPtr + 1);n_ctxt++) {
        ctxt = gen_xmlXPathParserContextPtr(n_ctxt, 0);

        xmlXPtrEvalRangePredicate(ctxt);
        if(ctxt == NULL)// -ve case
	 {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrEvalRangePredicate", (void *)ctxt, (void *)(NULL), "xmlXPtrEvalRangePredicate Failed");

        }
        else if(ctxt != NULL)// +ve case
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrEvalRangePredicate", (void *)ctxt, (void *)(NULL), "xmlXPtrEvalRangePredicate Failed");
        }

        call_tests++;
        des_xmlXPathParserContextPtr(n_ctxt, ctxt, 0);
        xmlResetLastError();
    }
    function_tests++;
#endif
}

static void des_xmlLocationSetPtr(int no ATTRIBUTE_UNUSED, xmlLocationSetPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{

}

static xmlLocationSetPtr gen_xmlLocationSetPtr(int no, int nr ATTRIBUTE_UNUSED)
{
	if(no == 1)
		return(xmlXPtrLocationSetCreate(gen_xmlXPathObjectPtr(4, 1)));
	else
		return(NULL);
}
	/**
	* @test			UTcxmlXPtrLocationSetAddP01
	* @brief		void xmlXPtrLocationSetAdd(xmlLocationSetPtr cur, xmlXPathObjectPtr val)
	* @desc			Positive and neg Test for xmlXPtrLocationSetAdd
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlLocationSetPtr(cur), xmlXPathObjectPtr(val)} => {N/A | xmlLocationSetPtr(!=NULL), xmlXPathObjectPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrLocationSetAddP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlLocationSetPtr cur; /* the initial range set */
    int n_cur;
    xmlXPathObjectPtr val; /* a new xmlXPathObjectPtr */
    int n_val;

    for (n_cur = 0;n_cur < (gen_nb_xmlLocationSetPtr + 1);n_cur++) {
    for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr;n_val++) {
        cur = gen_xmlLocationSetPtr(n_cur, 0);
        val = gen_xmlXPathObjectPtr(n_val, 1);
        xmlXPtrLocationSetAdd(cur, val);

        if((n_val == 4) && (n_cur == 1))//+ve case
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrLocationSetAdd", (void *)cur, (void *)(NULL), "xmlXPtrLocationSetAdd Failed");
		DTS_CHECK_NE_MESSAGE("xmlXPtrLocationSetAdd", (void *)val, (void *)(NULL), "xmlXPtrLocationSetAdd Failed");
        }
        if(n_cur != 1)//-ve case
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetAdd", (void *)cur, (void *)(NULL), "xmlXPtrLocationSetAdd Failed");
        }
        if(n_val != 4)//-ve case
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrLocationSetAdd", (void *)val, (void *)(NULL), "xmlXPtrLocationSetAdd Failed");
        }

        call_tests++;
        des_xmlLocationSetPtr(n_cur, cur, 0);
        des_xmlXPathObjectPtr(n_val, val, 1);
        xmlResetLastError();
    }
    }
	val = NULL;
	xmlXPtrLocationSetAdd(cur, val);
	if(val == NULL)//-ve case
	{
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetAdd", (void *)val, (void *)(NULL), "xmlXPtrLocationSetAdd Failed");
	}

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrLocationSetCreateP01
	* @brief		xmlLocationSetPtr xmlXPtrLocationSetCreate(xmlXPathObjectPtr val)
	* @desc			Positive and neg Test for xmlXPtrLocationSetCreate
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlLocationSetPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(val)} => {N/A | xmlXPathObjectPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrLocationSetCreateP01()
{
    xmlXPathObjectPtr list;
    xmlLocationSetPtr ret_val;
    int n_list = 1;

	list = gen_xmlXPathObjectPtr(n_list, 0);

	ret_val = xmlXPtrLocationSetCreate(list);
	if(ret_val != NULL)//+ve case
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrLocationSetCreate", (void *)ret_val, (void *)(NULL), "xmlXPtrLocationSetCreate Failed");
        }
	else//-ve case
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetCreate", (void *)ret_val, (void *)(NULL), "xmlXPtrLocationSetCreate Failed");
        }
}
	/**
	* @test			UTcxmlXPtrLocationSetDelP01
	* @brief        void xmlXPtrLocationSetDel(xmlLocationSetPtr cur, xmlXPathObjectPtr val)
	* @desc			Positive and neg Test for xmlXPtrLocationSetDel
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlLocationSetPtr(cur), xmlXPathObjectPtr(val)} => {N/A | xmlLocationSetPtr(!=NULL), xmlXPathObjectPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrLocationSetDelP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlLocationSetPtr cur; /* the initial range set */
    int n_cur;
    xmlXPathObjectPtr val; /* an xmlXPathObjectPtr */
    int n_val;

    for (n_cur = 0;n_cur < (gen_nb_xmlLocationSetPtr + 1);n_cur++) {
    for (n_val = 0;n_val < gen_nb_xmlXPathObjectPtr;n_val++) {
        cur = gen_xmlLocationSetPtr(n_cur, 0);//n_cur
        val = gen_xmlXPathObjectPtr(n_val, 1);

        xmlXPtrLocationSetDel(cur, val);
        if(n_cur == 1)//+ve case
        {
        	int ret = ((NULL != cur) && (NULL != val));
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetDel", (void *)ret, (void *)(1), "xmlXPtrLocationSetDel 1 Failed");
        }

        call_tests++;
        des_xmlLocationSetPtr(n_cur, cur, 0);
        des_xmlXPathObjectPtr(n_val, val, 1);
        xmlResetLastError();
    }
    }
    cur = NULL;
    xmlXPtrLocationSetDel(cur, val);
    if(cur == NULL)//-ve case
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetDel", (void *)cur, (void *)(NULL), "xmlXPtrLocationSetDel 2 Failed");
        }

    val = NULL;
    xmlXPtrLocationSetDel(cur, val);
    if(val == NULL)//-ve case
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetDel", (void *)val, (void *)(NULL), "xmlXPtrLocationSetDel 3 Failed");
        }

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrLocationSetMergeP01
	* @brief		xmlLocationSetPtr xmlXPtrLocationSetMerge(xmlLocationSetPtr val1, xmlLocationSetPtr val2)
	* @desc			Positive and neg Test for xmlXPtrLocationSetMerge
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlLocationSetPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlLocationSetPtr(val1), xmlLocationSetPtr(val2)} => {N/A | xmlLocationSetPtr(!=NULL), xmlLocationSetPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrLocationSetMergeP01()
{
	xmlLocationSetPtr val1, val2;
	xmlLocationSetPtr ret_val;
	int n_cur1 = 1;
	int n_cur2 = 2;

	val1 = gen_xmlLocationSetPtr(n_cur1, 0);
	val2 = gen_xmlLocationSetPtr(n_cur2, 1);

	ret_val = xmlXPtrLocationSetMerge(val1, val2);
	if(ret_val == val1)//+ve case
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetMerge", (void *)ret_val, (void *)(val1), "xmlXPtrLocationSetMerge Failed");
        }
	else//-ve case
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrLocationSetMerge", (void *)ret_val, (void *)(val1), "xmlXPtrLocationSetMerge Failed");
        }

	ret_val = xmlXPtrLocationSetMerge(NULL, val2);
	if(ret_val == NULL)//-ve case
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetMerge", (void *)ret_val, (void *)(NULL), "xmlXPtrLocationSetMerge Failed");
        }

	ret_val = xmlXPtrLocationSetMerge(val1, NULL);
	if(ret_val == val1)//-ve case
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetMerge", (void *)ret_val, (void *)(val1), "xmlXPtrLocationSetMerge Failed");
        }
}
	/**
	* @test			UTcxmlXPtrLocationSetRemoveP01
	* @brief		void xmlXPtrLocationSetRemove(xmlLocationSetPtr cur, int val)
	* @desc			Positive Test for xmlNewTextWriter
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlLocationSetPtr(cur), int(val)} => {N/A | xmlLocationSetPtr(!=NULL), val(valid)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrLocationSetRemoveP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlLocationSetPtr cur; /* the initial range set */
    int n_cur;
    int val; /* the index to remove */
    int n_val;

    for (n_cur = 0;n_cur < gen_nb_xmlLocationSetPtr;n_cur++) {
    for (n_val = 0;n_val < gen_nb_int;n_val++) {
        cur = gen_xmlLocationSetPtr(n_cur, 0);
        val = gen_int(n_val, 1);

        xmlXPtrLocationSetRemove(cur, val);
        if(cur != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrLocationSetRemove", (void *)cur, (void *)(NULL), "xmlXPtrLocationSetRemove Failed");
        }
        else if(cur == NULL)
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrLocationSetRemove", (void *)cur, (void *)(NULL), "xmlXPtrLocationSetRemove Failed");
        }

        call_tests++;
        des_xmlLocationSetPtr(n_cur, cur, 0);
        des_int(n_val, val, 1);
        xmlResetLastError();
    }
    }
    function_tests++;
#endif
}

static void desret_xmlXPathObjectPtr(xmlXPathObjectPtr val)
{
    xmlXPathFreeObject(val);
}
	/**
	* @test			UTcxmlXPtrNewCollapsedRangeP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewCollapsedRange(xmlNodePtr start)
	* @desc			Positive Test for xmlNewTextWriter
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(start)} => {N/A | xmlNodePtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewCollapsedRangeP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlNodePtr start; /* the starting and ending node */
    int n_start;

    for (n_start = 0;n_start < gen_nb_xmlNodePtr;n_start++) {
        start = gen_xmlNodePtr(n_start, 0);

        ret_val = xmlXPtrNewCollapsedRange(start);

        if(ret_val == NULL)
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewCollapsedRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewCollapsedRange Failed");
        }
        else
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewCollapsedRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewCollapsedRange Failed");
        }

        ret_val = xmlXPtrNewCollapsedRange(NULL);

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlNodePtr(n_start, start, 0);
        xmlResetLastError();
    }
    ret_val = xmlXPtrNewCollapsedRange(NULL);
    if(ret_val == NULL)
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewCollapsedRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewCollapsedRange Failed");
        }
    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewContextP01
	* @brief		xmlXPathContextPtr xmlXPtrNewContext(xmlDocPtr doc, xmlNodePtr here, xmlNodePtr origin)
	* @desc			Positive and neg Test for xmlXPtrNewContext
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathContextPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlDocPtr(doc), xmlNodePtr(here), xmlNodePtr(origin)} => {N/A | xmlDocPtr(!=NULL), xmlNodePtr(!=NULL), xmlNodePtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewContextP01()
{
	xmlXPathContextPtr ret_val;
	xmlDocPtr doc;
	xmlNodePtr here;
	xmlNodePtr origin;
	int n_cur = 1;

	doc = gen_xmlDocPtr(n_cur, 1);
	here = gen_xmlNodePtr(n_cur, 2);
	origin = gen_xmlNodePtr(n_cur, 3);

	ret_val = xmlXPtrNewContext(doc, here, origin);
	if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewCollapsedRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewCollapsedRange Failed");
        }
}

static void des_xmlNodeSetPtr(int no ATTRIBUTE_UNUSED, xmlNodeSetPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{

}

#define gen_nb_xmlNodeSetPtr 1

static xmlNodeSetPtr gen_xmlNodeSetPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
    return(NULL);
}
	/**
	* @test			UTcxmlXPtrNewLocationSetNodeSetP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewLocationSetNodeSet(xmlNodeSetPtr set)
	* @desc			Positive and neg Test for xmlXPtrNewLocationSetNodeSet
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodeSetPtr(set)} => {N/A | xmlNodeSetPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewLocationSetNodeSetP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlNodeSetPtr set; /* a node set */
    int n_set;

    for (n_set = 0;n_set < gen_nb_xmlNodeSetPtr;n_set++) {
        set = gen_xmlNodeSetPtr(n_set, 0);

        ret_val = xmlXPtrNewLocationSetNodeSet(set);

        if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewLocationSetNodeSet", (void *)ret_val, (void *)(NULL), "xmlXPtrNewLocationSetNodeSet Failed");
        }
        else
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewLocationSetNodeSet", (void *)ret_val, (void *)(NULL), "xmlXPtrNewLocationSetNodeSet Failed");
        }

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlNodeSetPtr(n_set, set, 0);
        xmlResetLastError();
    }
    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewLocationSetNodesP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewLocationSetNodes(xmlNodePtr start, xmlNodePtr end)
	* @desc			Positive and neg Test for xmlXPtrNewLocationSetNodes
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(start), xmlNodePtr(end)} => {N/A | xmlNodePtr(!=NULL), xmlNodePtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewLocationSetNodesP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlNodeSetPtr set; /* a node set */
    int n_set;

    for (n_set = 0;n_set < gen_nb_xmlNodeSetPtr;n_set++) {
        set = gen_xmlNodeSetPtr(n_set, 0);

        ret_val = xmlXPtrNewLocationSetNodeSet(set);
        if(ret_val == NULL)
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewLocationSetNodeSet", (void *)ret_val, (void *)(NULL), "xmlXPtrNewLocationSetNodeSet Failed");
        }
        else
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewLocationSetNodeSet", (void *)ret_val, (void *)(NULL), "xmlXPtrNewLocationSetNodeSet Failed");
        }

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlNodeSetPtr(n_set, set, 0);
        xmlResetLastError();
    }
    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewRangeP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewRange(xmlNodePtr start, int startindex,
	                xmlNodePtr end, int endindex)
	* @desc			Positive and neg Test for xmlXPtrNewRange
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(start), int(startindex), xmlNodePtr(end), int(endindex)} => {N/A | xmlNodePtr(!=NULL), xmlNodePtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewRangeP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlNodePtr start; /* the starting node */
    int n_start;
    int startindex; /* the start index */
    int n_startindex;
    xmlNodePtr end; /* the ending point */
    int n_end;
    int endindex; /* the ending index */
    int n_endindex;

    for (n_start = 0;n_start < gen_nb_xmlNodePtr;n_start++) {
    for (n_startindex = 0;n_startindex < gen_nb_int;n_startindex++) {
    for (n_end = 0;n_end < gen_nb_xmlNodePtr;n_end++) {
    for (n_endindex = 0;n_endindex < gen_nb_int;n_endindex++) {
        start = gen_xmlNodePtr(n_start, 0);
        startindex = gen_int(n_startindex, 1);
        end = gen_xmlNodePtr(n_end, 2);
        endindex = gen_int(n_endindex, 3);

        ret_val = xmlXPtrNewRange(start, startindex, end, endindex);
        if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRange Failed");
        }
        else
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRange Failed");
        }

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlNodePtr(n_start, start, 0);
        des_int(n_startindex, startindex, 1);
        des_xmlNodePtr(n_end, end, 2);
        des_int(n_endindex, endindex, 3);
        xmlResetLastError();
    }
    }
    }
    }
    ret_val = xmlXPtrNewRange(NULL, startindex, end, endindex);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRange Failed");

    ret_val = xmlXPtrNewRange(start, startindex, NULL, endindex);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRange Failed");

    ret_val = xmlXPtrNewRange(start, -1, end, endindex);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRange Failed");

    ret_val = xmlXPtrNewRange(start, startindex, end, -1);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRange", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRange Failed");

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewRangeNodeObjectP01
	* @brief		xmlXPathObjectPtr	xmlXPtrNewRangeNodeObject(xmlNodePtr start, xmlXPathObjectPtr end)
	* @desc			Positive and neg Test for xmlXPtrNewRangeNodeObject
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(start), xmlXPathObjectPtr(end)} => {N/A | xmlNodePtr(!=NULL), xmlXPathObjectPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/	
static void UTcxmlXPtrNewRangeNodeObjectP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlNodePtr start; /* the starting node */
    int n_start;
    xmlXPathObjectPtr end; /* the ending object */
    int n_end;

    for (n_start = 0;n_start < gen_nb_xmlNodePtr;n_start++) {
    for (n_end = 0;n_end < gen_nb_xmlXPathObjectPtr;n_end++) {
        start = gen_xmlNodePtr(n_start, 0);
        end = gen_xmlXPathObjectPtr(n_end, 1);

        ret_val = xmlXPtrNewRangeNodeObject(start, end);
        if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewRangeNodeObject", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodeObject Failed");
        }
        else
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodeObject", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodeObject Failed");
        }
		
        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlNodePtr(n_start, start, 0);
        des_xmlXPathObjectPtr(n_end, end, 1);
        xmlResetLastError();
    }
    }
    ret_val = xmlXPtrNewRangeNodeObject(NULL, end);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodeObject", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodeObject Failed");

    ret_val = xmlXPtrNewRangeNodeObject(start, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodeObject", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodeObject Failed");

    ret_val = xmlXPtrNewRangeNodeObject(NULL, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodeObject", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodeObject Failed");

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewRangeNodePointP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewRangeNodePoint(xmlNodePtr start, xmlXPathObjectPtr end)
	* @desc			Positive and neg Test for xmlXPtrNewRangeNodePoint
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(start), xmlXPathObjectPtr(end)} => {N/A | xmlNodePtr(!=NULL), xmlXPathObjectPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewRangeNodePointP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlNodePtr start; /* the starting node */
    int n_start;
    xmlXPathObjectPtr end; /* the ending point */
    int n_end;

    for (n_start = 0;n_start < gen_nb_xmlNodePtr;n_start++) {
    for (n_end = 0;n_end < gen_nb_xmlXPathObjectPtr;n_end++) {
        start = gen_xmlNodePtr(n_start, 0);
        end = gen_xmlXPathObjectPtr(n_end, 1);

        ret_val = xmlXPtrNewRangeNodePoint(start, end);
        if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");
        }
        else
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");
        }

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlNodePtr(n_start, start, 0);
        des_xmlXPathObjectPtr(n_end, end, 1);
        xmlResetLastError();
    }
    }
    ret_val = xmlXPtrNewRangeNodePoint(NULL, end);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");

    ret_val = xmlXPtrNewRangeNodePoint(start, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");

    ret_val = xmlXPtrNewRangeNodePoint(NULL, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewRangeNodesP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewRangeNodes(xmlNodePtr start, xmlNodePtr end)
	* @desc			Positive and neg Test for xmlXPtrNewRangeNodes
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(start), xmlNodePtr(end)} => {N/A | xmlNodePtr(!=NULL), xmlNodePtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewRangeNodesP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlNodePtr start; /* the starting node */
    int n_start;
    xmlNodePtr end; /* the ending node */
    int n_end;

    for (n_start = 0;n_start < gen_nb_xmlNodePtr;n_start++) {
    for (n_end = 0;n_end < gen_nb_xmlNodePtr;n_end++) {
        start = gen_xmlNodePtr(n_start, 0);
        end = gen_xmlNodePtr(n_end, 1);

        ret_val = xmlXPtrNewRangeNodes(start, end);
        if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewRangeNodes", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodes Failed");
        }
        else
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodes", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodes Failed");
        }

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlNodePtr(n_start, start, 0);
        des_xmlNodePtr(n_end, end, 1);
        xmlResetLastError();
    }
    }
    ret_val = xmlXPtrNewRangeNodes(NULL, end);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");

    ret_val = xmlXPtrNewRangeNodes(start, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");

    ret_val = xmlXPtrNewRangeNodes(NULL, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangeNodePoint", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangeNodePoint Failed");

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewRangePointNodeP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewRangePointNode(xmlXPathObjectPtr start, xmlNodePtr end)
	* @desc			Positive and neg Test for xmlXPtrNewRangePointNode
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(start), xmlNodePtr(end)} => {N/A | xmlXPathObjectPtr(!=NULL), xmlNodePtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewRangePointNodeP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlXPathObjectPtr start; /* the starting point */
    int n_start;
    xmlNodePtr end; /* the ending node */
    int n_end;

    for (n_start = 0;n_start < gen_nb_xmlXPathObjectPtr;n_start++) {
    for (n_end = 0;n_end < gen_nb_xmlNodePtr;n_end++) {
        start = gen_xmlXPathObjectPtr(n_start, 0);
        end = gen_xmlNodePtr(n_end, 1);

        ret_val = xmlXPtrNewRangePointNode(start, end);
        if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewRangePointNode", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePointNode Failed");
        }
        else
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePointNode", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePointNode Failed");
        }

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlXPathObjectPtr(n_start, start, 0);
        des_xmlNodePtr(n_end, end, 1);
        xmlResetLastError();
    }
    }
    ret_val = xmlXPtrNewRangePointNode(NULL, end);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePointNode", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePointNode Failed");

    ret_val = xmlXPtrNewRangePointNode(start, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePointNode", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePointNode Failed");

    ret_val = xmlXPtrNewRangePointNode(NULL, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePointNode", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePointNode Failed");

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrNewRangePointsP01
	* @brief		xmlXPathObjectPtr xmlXPtrNewRangePoints(xmlXPathObjectPtr start, xmlXPathObjectPtr end)
	* @desc			Positive and neg Test for xmlXPtrNewRangePoints
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathObjectPtr(start), xmlXPathObjectPtr(end)} => {N/A | xmlXPathObjectPtr(!=NULL), xmlXPathObjectPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrNewRangePointsP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlXPathObjectPtr start; /* the starting point */
    int n_start;
    xmlXPathObjectPtr end; /* the ending point */
    int n_end;

    for (n_start = 0;n_start < gen_nb_xmlXPathObjectPtr;n_start++) {
    for (n_end = 0;n_end < gen_nb_xmlXPathObjectPtr;n_end++) {
        start = gen_xmlXPathObjectPtr(n_start, 0);
        end = gen_xmlXPathObjectPtr(n_end, 1);

        ret_val = xmlXPtrNewRangePoints(start, end);
        if(ret_val != NULL)
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrNewRangePoints", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePoints Failed");
        }
        else
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePoints", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePoints Failed");
        }

        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlXPathObjectPtr(n_start, start, 0);
        des_xmlXPathObjectPtr(n_end, end, 1);
        xmlResetLastError();
    }
    }
    ret_val = xmlXPtrNewRangePoints(NULL, end);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePoints", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePoints Failed");

    ret_val = xmlXPtrNewRangePoints(start, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePoints", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePoints Failed");

    ret_val = xmlXPtrNewRangePoints(NULL, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlXPtrNewRangePoints", (void *)ret_val, (void *)(NULL), "xmlXPtrNewRangePoints Failed");

    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrRangeToFunctionP01
	* @brief		void xmlXPtrRangeToFunction(xmlXPathParserContextPtr ctxt, int nargs)
	* @desc			Positive and neg Test for xmlXPtrRangeToFunction
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXPathParserContextPtr(ctxt), int(nargs)} => {N/A | xmlXPathParserContextPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlXPtrRangeToFunctionP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathParserContextPtr ctxt; /* the XPointer Parser context */
    int n_ctxt;
    int nargs; /* the number of args */
    int n_nargs;

    for (n_ctxt = 0;n_ctxt < gen_nb_xmlXPathParserContextPtr;n_ctxt++) {
    for (n_nargs = 0;n_nargs < gen_nb_int;n_nargs++) {
        ctxt = gen_xmlXPathParserContextPtr(n_ctxt, 0);
        nargs = gen_int(n_nargs, 1);

        if(ctxt == NULL)
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrRangeToFunction", (void *)ctxt, (void *)(NULL), "gen_xmlXPathParserContextPtr Failed");
        }

        xmlXPtrRangeToFunction(ctxt, nargs);
        if(ctxt == NULL)
        {
		DTS_CHECK_EQ_MESSAGE("xmlXPtrRangeToFunction", (void *)ctxt, (void *)(NULL), "xmlXPtrRangeToFunction Failed");
        }
        else
        {
		DTS_CHECK_NE_MESSAGE("xmlXPtrRangeToFunction", (void *)ctxt, (void *)(NULL), "xmlXPtrRangeToFunction Failed");
        }

        call_tests++;
        des_xmlXPathParserContextPtr(n_ctxt, ctxt, 0);
        des_int(n_nargs, nargs, 1);
        xmlResetLastError();
    }
    }
    function_tests++;
#endif
}
	/**
	* @test			UTcxmlXPtrWrapLocationSetP01
	* @brief		xmlXPathObjectPtr xmlXPtrWrapLocationSet(xmlLocationSetPtr val)
	* @desc			Positive and neg Test for xmlXPtrWrapLocationSet
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXPathObjectPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlLocationSetPtr(val)} => {N/A | xmlLocationSetPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void UTcxmlXPtrWrapLocationSetP01()
{
#if defined(LIBXML_XPTR_ENABLED)
    xmlXPathObjectPtr ret_val;
    xmlLocationSetPtr val; /* the LocationSet value */
    int n_val;

    for (n_val = 0;n_val < (gen_nb_xmlLocationSetPtr + 1) ;n_val++) {
        val = gen_xmlLocationSetPtr(n_val, 0);

        if(n_val != 0)
        {
        	ret_val = xmlXPtrWrapLocationSet(val);
	        if(ret_val != NULL)
	        {
			DTS_CHECK_NE_MESSAGE("xmlXPtrRangeToFunction", (void *)ret_val, (void *)(NULL), "xmlXPtrRangeToFunction Failed");
	        }
	        else
	        {
			DTS_CHECK_EQ_MESSAGE("xmlXPtrRangeToFunction", (void *)ret_val, (void *)(NULL), "xmlXPtrRangeToFunction Failed");
	        }
        }
        desret_xmlXPathObjectPtr(ret_val);
        call_tests++;
        des_xmlLocationSetPtr(n_val, val, 0);
        xmlResetLastError();
    }
    function_tests++;
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
	{UTcxmlXPtrBuildNodeListP01,1},
	{UTcxmlXPtrEvalRangePredicateP01,2},
	{UTcxmlXPtrLocationSetAddP01,3},
	{UTcxmlXPtrLocationSetCreateP01,4},
	{UTcxmlXPtrLocationSetDelP01,5},
	{UTcxmlXPtrLocationSetMergeP01,6},
	{UTcxmlXPtrLocationSetRemoveP01,7},
	{UTcxmlXPtrNewCollapsedRangeP01,8},
	{UTcxmlXPtrNewContextP01,9},
	{UTcxmlXPtrNewLocationSetNodeSetP01,10},
	{UTcxmlXPtrNewLocationSetNodesP01,11},
	{UTcxmlXPtrNewRangeP01,12},
	{UTcxmlXPtrNewRangeNodeObjectP01,13},
	{UTcxmlXPtrNewRangeNodePointP01,14},
	{UTcxmlXPtrNewRangeNodesP01,15},
	{UTcxmlXPtrNewRangePointNodeP01,16},
	{UTcxmlXPtrNewRangePointsP01,17},
	{UTcxmlXPtrRangeToFunctionP01,18},
	{UTcxmlXPtrWrapLocationSetP01,19},
	{ NULL, 0 },
	
};
