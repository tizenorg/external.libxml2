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
#include <libxml/HTMLtree.h>
#include <libxml/tree.h>
#include <libxml/encoding.h>
#include <libxml/xmlmemory.h>
#include "utc_libxml_include.h"

/***************************************************************************
* SUTsXmlWriter
***************************************************************************/
#define MY_ENCODING "ISO-8859-1"

#define	OUTFILE2	UTSHOME"/missing.xml"
#define	OUTFILE3	UTSHOME"/test.out"

static xmlDocPtr api_doc = NULL;
static xmlDtdPtr api_dtd = NULL;
static xmlNodePtr api_root = NULL;
static xmlAttrPtr api_attr = NULL;
static xmlNsPtr api_ns = NULL;

static int call_tests = 0;
static int function_tests = 0;
int test_ret = 0;
#define gen_nb_htmlDocPtr 3
#define gen_nb_xmlChar_ptr_ptr 1
#define gen_nb_int_ptr 2
static int inttab[1024];

static void
free_api_doc(void) {
    xmlFreeDoc(api_doc);
    api_doc = NULL;
    api_dtd = NULL;
    api_root = NULL;
    api_attr = NULL;
    api_ns = NULL;
}

static xmlDocPtr get_api_doc(void)
{
    if (api_doc == NULL)
    {
        api_doc = xmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
        api_root = NULL;
        api_attr = NULL;
    }
    return(api_doc);
}

static xmlNodePtr get_api_root(void)
{
    if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
        get_api_doc();
	if ((api_doc != NULL) && (api_doc->children != NULL) &&
	    (api_doc->children->next != NULL) &&
	    (api_doc->children->next->type == XML_ELEMENT_NODE))
	    api_root = api_doc->children->next;
    }
    return(api_root);
}

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

#define gen_nb_fileoutput 1

static void des_fileoutput(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

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

#define gen_nb_xmlNodePtr 2
static xmlNodePtr gen_xmlNodePtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewPI(BAD_CAST "test", NULL));
    if (no == 1) return(get_api_root());
    return(NULL);
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
static void des_xmlDocPtr(int no ATTRIBUTE_UNUSED, xmlDocPtr val, int nr ATTRIBUTE_UNUSED) {
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}

static void desret_int(int val ATTRIBUTE_UNUSED) {
}

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
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{

}

static FILE *gen_FILE_ptr(int no, int nr ATTRIBUTE_UNUSED)
{
    if (no == 0) return(fopen("test.out", "a+"));
    return(NULL);
}

static void des_FILE_ptr(int no ATTRIBUTE_UNUSED, FILE *val, int nr ATTRIBUTE_UNUSED)
{
    if (val != NULL) fclose(val);
}

	/**    
	* @test			UTchtmlIsBooleanAttrP01
	* @brief		int htmlIsBooleanAttr(const xmlChar *name);
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlIsBooleanAttrP01()
{
	int ret_val;


	const xmlChar *name1 = (const xmlChar *)"checked";
	const xmlChar *name2 = (const xmlChar *)"junk";


	ret_val = htmlIsBooleanAttr(name1);  // passing valid string(+ve)
	DTS_CHECK_EQ_MESSAGE("htmlIsBooleanAttr", ret_val, 1, "htmlIsBooleanAttr Failes");

	ret_val = htmlIsBooleanAttr(name2);  // passing invalid string(-ve)
	DTS_CHECK_EQ_MESSAGE("htmlIsBooleanAttr", ret_val, 0, "htmlIsBooleanAttr Failes");

	ret_val = htmlIsBooleanAttr(NULL);   // passing NULL(-ve)
	DTS_CHECK_EQ_MESSAGE("htmlIsBooleanAttr", ret_val, 0, "htmlIsBooleanAttr Failes");

}
	/**
	* @test			UTchtmlDocDumpP01
	* @brief		int htmlDocDump(FILE *f, xmlDocPtr cur);
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlDocDumpP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED) && defined(STDIO_FILE)
    int ret_val;
    FILE * f; /* the FILE* */
    int n_f;
    xmlDocPtr cur; /* the document */
    int n_cur;

    for (n_f = 0;n_f < gen_nb_FILE_ptr;n_f++) {
    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
        f = gen_FILE_ptr(n_f, 0);
        cur = gen_xmlDocPtr(n_cur, 1);

		ret_val = htmlDocDump(f, cur);
        if(ret_val == -1) // checking for failure(-ve)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlDocDump", ret_val, -1, "htmlDocDump Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlDocDump", ret_val, -1, "htmlDocDump Failes");
        	}
    	ret_val = htmlDocDump(NULL, cur); // checking for failure(-ve)
		DTS_CHECK_EQ_MESSAGE("htmlDocDump", ret_val, -1, "htmlDocDump Failes");

		ret_val = htmlDocDump(f, NULL);   // checking for failure(-ve)
		DTS_CHECK_EQ_MESSAGE("htmlDocDump", ret_val, -1, "htmlDocDump Failes");

		ret_val = htmlDocDump(NULL, NULL); // checking for failure(-ve)
		DTS_CHECK_EQ_MESSAGE("htmlDocDump", ret_val, -1, "htmlDocDump Failes");

        desret_int(ret_val);
        call_tests++;
        des_FILE_ptr(n_f, f, 0);
        des_xmlDocPtr(n_cur, cur, 1);
        xmlResetLastError();
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlNodeDumpP01
	* @brief		int htmlNodeDump(xmlBufferPtr buf, xmlDocPtr doc, xmlNodePtr cur);
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlNodeDumpP01()
{
    int test_ret = 0;

#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    int mem_base;
    int ret_val;
    xmlBufferPtr buf; /* the HTML buffer output */
    int n_buf;
    xmlDocPtr doc; /* the document */
    int n_doc;
    xmlNodePtr cur; /* the current node */
    int n_cur;

    for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr;n_buf++) {
    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
        buf = gen_xmlBufferPtr(n_buf, 0);
        doc = gen_xmlDocPtr(n_doc, 1);
        cur = gen_xmlNodePtr(n_cur, 2);

        ret_val = htmlNodeDump(buf, doc, cur);
        if(ret_val == -1) // checking for failure(-ve)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlNodeDump", ret_val, -1, "htmlNodeDump Failes");
        	}
        else // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlNodeDump", ret_val, -1, "htmlNodeDump Failes");
        	}		

        ret_val = htmlNodeDump(NULL, doc, cur); // checking for failure(-ve)
	DTS_CHECK_EQ_MESSAGE("htmlNodeDump", ret_val, -1, "htmlNodeDump Failes");

        ret_val = htmlNodeDump(buf, doc, NULL); // checking for failure(-ve)
        DTS_CHECK_EQ_MESSAGE("htmlNodeDump", ret_val, -1, "htmlNodeDump Failes");

        ret_val = htmlNodeDump(NULL, NULL, NULL); // checking for failure(-ve)
       DTS_CHECK_EQ_MESSAGE("htmlNodeDump", ret_val, -1, "htmlNodeDump Failes");

        ret_val = htmlNodeDump(buf, doc, cur); // checking for failure(-ve)
        DTS_CHECK_NE_MESSAGE("htmlNodeDump", ret_val, NULL, "htmlNodeDump Failes");

        desret_int(ret_val);
        call_tests++;
        des_xmlBufferPtr(n_buf, buf, 0);
        des_xmlDocPtr(n_doc, doc, 1);
        des_xmlNodePtr(n_cur, cur, 2);
        xmlResetLastError();
    }
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlNodeDumpFileFormatP01
	* @brief		int htmlNodeDumpFileFormat(FILE *out, xmlDocPtr doc, xmlNodePtr cur, const char *encoding, int format);
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlNodeDumpFileFormatP01()
{
#ifdef 	STDIO_FILE
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {FILE*(out), xmlDocPtr(doc), xmlNodePtr(cur), const char*(encoding), int(format)} => { N/A | int(bytes) } @n
	*/
    int ret_val;
    FILE * out; /* the FILE pointer */
    int n_out;
    xmlDocPtr doc; /* the document */
    int n_doc;
    xmlNodePtr cur; /* the current node */
    int n_cur;
    char * encoding; /* the document encoding */
    int n_encoding;
    int format; /* should formatting spaces been added */
    int n_format;

    for (n_out = 0;n_out < gen_nb_FILE_ptr;n_out++) {
    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    for (n_format = 0;n_format < gen_nb_int;n_format++) {
        out = gen_FILE_ptr(n_out, 0);
        doc = gen_xmlDocPtr(n_doc, 1);
        cur = gen_xmlNodePtr(n_cur, 2);
        encoding = gen_const_char_ptr(n_encoding, 3);
        format = gen_int(n_format, 4);

        ret_val = htmlNodeDumpFileFormat(out, doc, cur, (const char *)encoding, format);
        if(ret_val == -1) // checking for failure(-ve)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlNodeDumpFileFormat", ret_val, -1, "htmlNodeDumpFileFormat Failes");
        	}
        else // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlNodeDumpFileFormat", ret_val, -1, "htmlNodeDumpFileFormat Failes");
        	}		

        ret_val = htmlNodeDumpFileFormat(NULL, doc, cur, (const char *)encoding, format);// checking for failure(-ve)
        DTS_CHECK_EQ_MESSAGE("htmlNodeDumpFileFormat", ret_val, -1, "htmlNodeDumpFileFormat Failes");

        ret_val = htmlNodeDumpFileFormat(out, NULL, cur, (const char *)encoding, format);// checking for failure(-ve)
        DTS_CHECK_EQ_MESSAGE("htmlNodeDumpFileFormat", ret_val, -1, "htmlNodeDumpFileFormat Failes");

        ret_val = htmlNodeDumpFileFormat(out, doc, NULL, (const char *)encoding, format);// checking for failure(-ve)
        DTS_CHECK_EQ_MESSAGE("htmlNodeDumpFileFormat", ret_val, -1, "htmlNodeDumpFileFormat Failes");

        desret_int(ret_val);
        call_tests++;
        des_FILE_ptr(n_out, out, 0);
        des_xmlDocPtr(n_doc, doc, 1);
        des_xmlNodePtr(n_cur, cur, 2);
        des_const_char_ptr(n_encoding, (const char *)encoding, 3);
        des_int(n_format, format, 4);
        xmlResetLastError();
    }
    }
    }
    }
    }
    function_tests++;
#endif /*STDIO_FILE*/
}
/**
	* @test			UTchtmlSaveFileP01
	* @brief		int htmlSaveFile(const char *filename, xmlDocPtr cur)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlSaveFileP01()
{
    int test_ret = 0;

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            {const char *(filename), xmlDocPtr(cur)} => { N/A | int(bytes) } @n
	*/
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    int ret_val;
    const char * filename; /* the filename (or URL) */
    int n_filename;
    xmlDocPtr cur; /* the document */
    int n_cur;

    for (n_filename = 0;n_filename < gen_nb_fileoutput;n_filename++) {
    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
        filename = gen_fileoutput(n_filename, 0);
        cur = gen_xmlDocPtr(n_cur, 1);
		
        ret_val = htmlSaveFile(filename, cur);
        if(ret_val == -1) // checking for failure(-ve)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlSaveFile", ret_val, -1, "htmlSaveFile Failes");
        	}
        else // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlSaveFile", ret_val, -1, "htmlSaveFile Failes");
        	}		

        ret_val = htmlSaveFile(NULL, cur); // checking for failure(-ve)
        DTS_CHECK_EQ_MESSAGE("htmlSaveFile", ret_val, -1, "htmlSaveFile Failes");

        ret_val = htmlSaveFile(filename, NULL); // checking for failure(-ve)
        DTS_CHECK_EQ_MESSAGE("htmlSaveFile", ret_val, -1, "htmlSaveFile Failes");

        ret_val = htmlSaveFile(NULL, NULL); // checking for failure(-ve)
       DTS_CHECK_EQ_MESSAGE("htmlSaveFile", ret_val, -1, "htmlSaveFile Failes");

        desret_int(ret_val);
        call_tests++;
        des_fileoutput(n_filename, filename, 0);
        des_xmlDocPtr(n_cur, cur, 1);
        xmlResetLastError();
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlNodeDumpFormatOutputP01
	* @brief		void htmlNodeDumpFormatOutput(xmlOutputBufferPtr buf, xmlDocPtr doc,
	                xmlNodePtr cur, const char *encoding, int format)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlNodeDumpFormatOutputP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    xmlOutputBufferPtr buf; /* the HTML buffer output */
    int n_buf;
    xmlDocPtr doc; /* the document */
    int n_doc;
    xmlNodePtr cur; /* the current node */
    int n_cur;
    char * encoding; /* the encoding string */
    int n_encoding;
    int format; /* should formatting spaces been added */
    int n_format;

    for (n_buf = 0;n_buf < gen_nb_xmlOutputBufferPtr;n_buf++) {
    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    for (n_format = 0;n_format < gen_nb_int;n_format++) {
        buf = gen_xmlOutputBufferPtr(n_buf, 0);
        doc = gen_xmlDocPtr(n_doc, 1);
        cur = gen_xmlNodePtr(n_cur, 2);
        encoding = gen_const_char_ptr(n_encoding, 3);
        format = gen_int(n_format, 4);

        htmlNodeDumpFormatOutput(buf, doc, cur, (const char *)encoding, format);
        if(NULL == buf) // checking for failure(-ve)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlNodeDumpFormatOutput", buf, NULL, "htmlNodeDumpFormatOutput Failes");
        	}
        else // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlNodeDumpFormatOutput", buf, NULL, "htmlNodeDumpFormatOutput Failes");
        	}		

        call_tests++;
        des_xmlOutputBufferPtr(n_buf, buf, 0);
        des_xmlDocPtr(n_doc, doc, 1);
        des_xmlNodePtr(n_cur, cur, 2);
        des_const_char_ptr(n_encoding, (const char *)encoding, 3);
        des_int(n_format, format, 4);
        xmlResetLastError();
    }
    }
    }
    }
    }
    function_tests++;
#endif
}
	/**
	* @test			UTchtmlNodeDumpOutputP01
	* @brief		void htmlNodeDumpOutput(xmlOutputBufferPtr buf, xmlDocPtr doc,
	                xmlNodePtr cur, const char *encoding)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlNodeDumpOutputP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    xmlOutputBufferPtr buf; /* the HTML buffer output */
    int n_buf;
    xmlDocPtr doc; /* the document */
    int n_doc;
    xmlNodePtr cur; /* the current node */
    int n_cur;
    char * encoding; /* the encoding string */
    int n_encoding;

    for (n_buf = 0;n_buf < gen_nb_xmlOutputBufferPtr;n_buf++) {
    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
        buf = gen_xmlOutputBufferPtr(n_buf, 0);
        doc = gen_xmlDocPtr(n_doc, 1);
        cur = gen_xmlNodePtr(n_cur, 2);
        encoding = gen_const_char_ptr(n_encoding, 3);

        htmlNodeDumpOutput(buf, doc, cur, (const char *)encoding);
		if(buf == NULL)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlNodeDumpOutput", buf, NULL, "htmlNodeDumpOutput Failes");
        	}
        else // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlNodeDumpOutput", buf, NULL, "htmlNodeDumpOutput Failes");
        	}			
        call_tests++;
        des_xmlOutputBufferPtr(n_buf, buf, 0);
        des_xmlDocPtr(n_doc, doc, 1);
        des_xmlNodePtr(n_cur, cur, 2);
        des_const_char_ptr(n_encoding, (const char *)encoding, 3);
        xmlResetLastError();
    }
    }
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlSaveFileEncP01
	* @brief		int htmlSaveFileEnc(const char *filename, xmlDocPtr cur, const char *encoding)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlSaveFileEncP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    int ret_val;
    const char * filename; /* the filename */
    int n_filename;
    xmlDocPtr cur; /* the document */
    int n_cur;
    char * encoding; /* the document encoding */
    int n_encoding;

    for (n_filename = 0;n_filename < gen_nb_fileoutput;n_filename++) {
    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
        filename = gen_fileoutput(n_filename, 0);
        cur = gen_xmlDocPtr(n_cur, 1);
        encoding = gen_const_char_ptr(n_encoding, 2);

        ret_val = htmlSaveFileEnc(filename, cur, (const char *)encoding);
		if(ret_val == -1)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlSaveFileEnc", ret_val, -1, "htmlSaveFileEnc Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlSaveFileEnc", ret_val, -1, "htmlSaveFileEnc Failes");
        	}			
		

        ret_val = htmlSaveFileEnc(NULL, cur, (const char *)encoding); // checking for failure(-ve)
	DTS_CHECK_EQ_MESSAGE("htmlSaveFileEnc", ret_val, -1, "htmlSaveFileEnc Failes");

        ret_val = htmlSaveFileEnc(filename, NULL, (const char *)encoding); // checking for failure(-ve)
		DTS_CHECK_EQ_MESSAGE("htmlSaveFileEnc", ret_val, -1, "htmlSaveFileEnc Failes");

        ret_val = htmlSaveFileEnc(NULL, NULL, NULL); // checking for failure(-ve)
		DTS_CHECK_EQ_MESSAGE("htmlSaveFileEnc", ret_val, -1, "htmlSaveFileEnc Failes");

        desret_int(ret_val);
        call_tests++;
        des_fileoutput(n_filename, filename, 0);
        des_xmlDocPtr(n_cur, cur, 1);
        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
        xmlResetLastError();
    }
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlSaveFileFormatP01
	* @brief		int htmlSaveFileFormat(const char *filename, xmlDocPtr cur,
	                const char *encoding, int format)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlSaveFileFormatP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    int ret_val;
    const char * filename; /* the filename */
    int n_filename;
    xmlDocPtr cur; /* the document */
    int n_cur;
    char * encoding; /* the document encoding */
    int n_encoding;
    int format; /* should formatting spaces been added */
    int n_format;

    for (n_filename = 0;n_filename < gen_nb_fileoutput;n_filename++) {
    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    for (n_format = 0;n_format < gen_nb_int;n_format++) {
        filename = gen_fileoutput(n_filename, 0);
        cur = gen_xmlDocPtr(n_cur, 1);
        encoding = gen_const_char_ptr(n_encoding, 2);
        format = gen_int(n_format, 3);

        ret_val = htmlSaveFileFormat(filename, cur, (const char *)encoding, format);
        if(ret_val == -1)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlSaveFileFormat", ret_val, -1, "htmlSaveFileFormat Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlSaveFileFormat", ret_val, -1, "htmlSaveFileFormat Failes");
        	}		

        ret_val = htmlSaveFileFormat(NULL, cur, (const char *)encoding, format);
		DTS_CHECK_EQ_MESSAGE("htmlSaveFileFormat", ret_val, -1, "htmlSaveFileFormat Failes");

        ret_val = htmlSaveFileFormat(filename, NULL, (const char *)encoding, format);
		DTS_CHECK_EQ_MESSAGE("htmlSaveFileFormat", ret_val, -1, "htmlSaveFileFormat Failes");

        ret_val = htmlSaveFileFormat(NULL, NULL, NULL, format);
		DTS_CHECK_EQ_MESSAGE("htmlSaveFileFormat", ret_val, -1, "htmlSaveFileFormat Failes");

        desret_int(ret_val);
        call_tests++;
        des_fileoutput(n_filename, filename, 0);
        des_xmlDocPtr(n_cur, cur, 1);
        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
        des_int(n_format, format, 3);
        xmlResetLastError();
    }
    }
    }
    }
    function_tests++;
#endif
}

static void des_htmlDocPtr(int no ATTRIBUTE_UNUSED, htmlDocPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}

static htmlDocPtr gen_htmlDocPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
    if (no == 0) return(htmlNewDoc(NULL, NULL));
    if (no == 1) return(htmlReadMemory("<html/>", 7, "test", NULL, 0));
    return(NULL);
}
/**
	* @test			UTchtmlSetMetaEncodingP01
	* @brief		int htmlSetMetaEncoding(htmlDocPtr doc, const xmlChar *encoding)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlSetMetaEncodingP01()
{
#if defined(LIBXML_HTML_ENABLED)
    int ret_val;
    htmlDocPtr doc; /* the document */
    int n_doc;
    xmlChar * encoding; /* the encoding string */
    int n_encoding;

    for (n_doc = 0;n_doc < gen_nb_htmlDocPtr;n_doc++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_xmlChar_ptr;n_encoding++) {
        doc = gen_htmlDocPtr(n_doc, 0);
        encoding = gen_const_xmlChar_ptr(n_encoding, 1);

        if(n_doc <= 1)
        {
			ret_val = htmlSetMetaEncoding(doc, (const xmlChar *)encoding);
			if(ret_val == -1)
		        	{
					DTS_CHECK_EQ_MESSAGE("htmlSetMetaEncoding", ret_val, -1, "htmlSetMetaEncoding Failes");
		        	}
		        else  // checking for success(+ve)
		        	{
					DTS_CHECK_NE_MESSAGE("htmlSetMetaEncoding", ret_val, -1, "htmlSetMetaEncoding Failes");
		        	}			
        }
        desret_int(ret_val);
        call_tests++;
        des_htmlDocPtr(n_doc, doc, 0);
        des_const_xmlChar_ptr(n_encoding, (const xmlChar *)encoding, 1);
        xmlResetLastError();
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlDocContentDumpFormatOutputP01
	* @brief		void htmlDocContentDumpFormatOutput(xmlOutputBufferPtr buf, xmlDocPtr cur,
	                const char *encoding, int format)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlDocContentDumpFormatOutputP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    xmlOutputBufferPtr buf; /* the HTML buffer output */
    int n_buf;
    xmlDocPtr cur; /* the document */
    int n_cur;
    char * encoding; /* the encoding string */
    int n_encoding;
    int format; /* should formatting spaces been added */
    int n_format;

    for (n_buf = 0;n_buf < gen_nb_xmlOutputBufferPtr;n_buf++) {
    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    for (n_format = 0;n_format < gen_nb_int;n_format++) {
        buf = gen_xmlOutputBufferPtr(n_buf, 0);
        cur = gen_xmlDocPtr(n_cur, 1);
        encoding = gen_const_char_ptr(n_encoding, 2);
        format = gen_int(n_format, 3);

        htmlDocContentDumpFormatOutput(buf, cur, (const char *)encoding, format);
        if(NULL == buf)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlDocContentDumpFormatOutput", buf, NULL, "htmlDocContentDumpFormatOutput Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlDocContentDumpFormatOutput", buf, NULL, "htmlDocContentDumpFormatOutput Failes");
        	}			
		
        call_tests++;
        des_xmlOutputBufferPtr(n_buf, buf, 0);
        des_xmlDocPtr(n_cur, cur, 1);
        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
        des_int(n_format, format, 3);
        xmlResetLastError();
    }
    }
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlDocContentDumpOutputP01
	* @brief		void htmlDocContentDumpOutput(xmlOutputBufferPtr buf, xmlDocPtr cur,
	                const char *encoding)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/

static void UTchtmlDocContentDumpOutputP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    int mem_base;
    xmlOutputBufferPtr buf; /* the HTML buffer output */
    int n_buf;
    xmlDocPtr cur; /* the document */
    int n_cur;
    char * encoding; /* the encoding string */
    int n_encoding;

    for (n_buf = 0;n_buf < gen_nb_xmlOutputBufferPtr;n_buf++) {
    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
        buf = gen_xmlOutputBufferPtr(n_buf, 0);
        cur = gen_xmlDocPtr(n_cur, 1);
        encoding = gen_const_char_ptr(n_encoding, 2);

        htmlDocContentDumpOutput(buf, cur, (const char *)encoding);
        if(NULL == buf)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlDocContentDumpOutput", buf, NULL, "htmlDocContentDumpOutput Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlDocContentDumpOutput", buf, NULL, "htmlDocContentDumpOutput Failes");
        	}			
		
        call_tests++;
        des_xmlOutputBufferPtr(n_buf, buf, 0);
        des_xmlDocPtr(n_cur, cur, 1);
        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
        xmlResetLastError();
    }
    }
    }
    function_tests++;
#endif
}

static void des_int_ptr(int no ATTRIBUTE_UNUSED, int *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{

}

static void des_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, xmlChar ** val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{

}

static int *gen_int_ptr(int no, int nr)
{
    if (no == 0) return(&inttab[nr]);
    return(NULL);
}

static xmlChar ** gen_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
    return(NULL);
}

/**
	* @test			UTchtmlDocDumpMemoryP01
	* @brief		void htmlDocDumpMemory(xmlDocPtr cur, xmlChar**mem, int *size)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlDocDumpMemoryP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    xmlDocPtr cur; /* the document */
    int n_cur;
    xmlChar ** mem; /* OUT: the memory pointer */
    int n_mem;
    int * size; /* OUT: the memory length */
    int n_size;

    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
    for (n_mem = 0;n_mem < gen_nb_xmlChar_ptr_ptr;n_mem++) {
    for (n_size = 0;n_size < gen_nb_int_ptr;n_size++) {
        cur = gen_xmlDocPtr(n_cur, 0);
        mem = gen_xmlChar_ptr_ptr(n_mem, 1);
        size = gen_int_ptr(n_size, 2);
		if( cur && mem && size )
		{
        htmlDocDumpMemory(cur, mem, size);
        if(NULL == mem)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlDocDumpMemory", mem, NULL, "htmlDocDumpMemory Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlDocDumpMemory", mem, NULL, "htmlDocDumpMemory Failes");
        	}			
		
        call_tests++;
        des_xmlDocPtr(n_cur, cur, 0);
        des_xmlChar_ptr_ptr(n_mem, mem, 1);
        des_int_ptr(n_size, size, 2);
        xmlResetLastError();
		}
    }
    }
    }
    function_tests++;
#endif
}

static void desret_const_xmlChar_ptr(const xmlChar *val ATTRIBUTE_UNUSED)
{

}
/**
	* @test			UTchtmlGetMetaEncodingP01
	* @brief		const xmlChar *htmlGetMetaEncoding(htmlDocPtr doc)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		const xmlChar *
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlGetMetaEncodingP01()
{
#if defined(LIBXML_HTML_ENABLED)
    const xmlChar * ret_val;
    htmlDocPtr doc; /* the document */
    int n_doc;

    for (n_doc = 0;n_doc < gen_nb_htmlDocPtr;n_doc++) {
        doc = gen_htmlDocPtr(n_doc, 0);

		ret_val = htmlGetMetaEncoding(doc);
		if(NULL == ret_val)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlGetMetaEncoding", ret_val, NULL, "htmlGetMetaEncoding Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlGetMetaEncoding", ret_val, NULL, "htmlGetMetaEncoding Failes");
        	}			

        desret_const_xmlChar_ptr(ret_val);
        call_tests++;
        des_htmlDocPtr(n_doc, doc, 0);
        xmlResetLastError();
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlNodeDumpFileP01
	* @brief		void htmlNodeDumpFile(FILE *out, xmlDocPtr doc, xmlNodePtr cur)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlNodeDumpFileP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED) && defined(STDIO_FILE)
    FILE * out; /* the FILE pointer */
    int n_out;
    xmlDocPtr doc; /* the document */
    int n_doc;
    xmlNodePtr cur; /* the current node */
    int n_cur;

    for (n_out = 0;n_out < gen_nb_FILE_ptr;n_out++) {
    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
    for (n_cur = 0;n_cur < gen_nb_xmlNodePtr;n_cur++) {
        out = gen_FILE_ptr(n_out, 0);
        doc = gen_xmlDocPtr(n_doc, 1);
        cur = gen_xmlNodePtr(n_cur, 2);
		if( out && doc && cur )
		{
        htmlNodeDumpFile(out, doc, cur);
        	{
			DTS_CHECK_EQ_MESSAGE("htmlNodeDumpFile", out, NULL, "htmlNodeDumpFile Failes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlNodeDumpFile", out, NULL, "htmlNodeDumpFile Failes");
        	}
        call_tests++;
        des_FILE_ptr(n_out, out, 0);
        des_xmlDocPtr(n_doc, doc, 1);
        des_xmlNodePtr(n_cur, cur, 2);
        xmlResetLastError();
		}
    }
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlDocDumpMemoryFormatP01
	* @brief		void htmlDocDumpMemoryFormat(xmlDocPtr cur, xmlChar**mem, int *size, int format)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlDocDumpMemoryFormatP01()
{
#if defined(LIBXML_HTML_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)
    xmlDocPtr cur; /* the document */
    int n_cur;
    xmlChar ** mem; /* OUT: the memory pointer */
    int n_mem;
    int * size; /* OUT: the memory length */
    int n_size;
    int format; /* should formatting spaces been added */
    int n_format;

    for (n_cur = 0;n_cur < gen_nb_xmlDocPtr;n_cur++) {
    for (n_mem = 0;n_mem < gen_nb_xmlChar_ptr_ptr;n_mem++) {
    for (n_size = 0;n_size < gen_nb_int_ptr;n_size++) {
    for (n_format = 0;n_format < gen_nb_int;n_format++) {
        cur = gen_xmlDocPtr(n_cur, 0);
        mem = gen_xmlChar_ptr_ptr(n_mem, 1);
        size = gen_int_ptr(n_size, 2);
        format = gen_int(n_format, 3);

        htmlDocDumpMemoryFormat(cur, mem, size, format);
        //DTS_CHECK_NE_MESSAGE("htmlNodeDumpFile", out, NULL, "htmlNodeDumpFile Failes");
        call_tests++;
        des_xmlDocPtr(n_cur, cur, 0);
        des_xmlChar_ptr_ptr(n_mem, mem, 1);
        des_int_ptr(n_size, size, 2);
        des_int(n_format, format, 3);
        xmlResetLastError();
    }
    }
    }
    }
    function_tests++;
#endif
}

static void desret_htmlDocPtr(htmlDocPtr val)
{
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}
	/**
	* @test			UTchtmlNewDocP01
	* @brief		htmlDocPtr htmlNewDoc(const xmlChar *URI, const xmlChar *ExternalID)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlNewDocP01()
{
#if defined(LIBXML_HTML_ENABLED)
    htmlDocPtr ret_val;
    xmlChar * URI; /* URI for the dtd, or NULL */
    int n_URI;
    xmlChar * ExternalID; /* the external ID of the DTD, or NULL */
    int n_ExternalID;

    for (n_URI = 0;n_URI < gen_nb_const_xmlChar_ptr;n_URI++) {
    for (n_ExternalID = 0;n_ExternalID < gen_nb_const_xmlChar_ptr;n_ExternalID++) {
        URI = gen_const_xmlChar_ptr(n_URI, 0);
        ExternalID = gen_const_xmlChar_ptr(n_ExternalID, 1);

        ret_val = htmlNewDoc((const xmlChar *)URI, (const xmlChar *)ExternalID);
        if(ret_val == NULL)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlNewDoc", ret_val, NULL, "htmlNewDocFailes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlNewDoc", ret_val, NULL, "htmlNewDoc Failes");
        	}
#if 0
        ret_val = htmlNewDoc(NULL, (const xmlChar *)ExternalID);
        	MT_CHECK_MESSAGE2(NULL == ret_val, "API return value: %d", ret_val);

        ret_val = htmlNewDoc((const xmlChar *)URI, NULL);
        	MT_CHECK_MESSAGE2(NULL == ret_val, "API return value: %d", ret_val);
#endif
        desret_htmlDocPtr(ret_val);
        call_tests++;
        des_const_xmlChar_ptr(n_URI, (const xmlChar *)URI, 0);
        des_const_xmlChar_ptr(n_ExternalID, (const xmlChar *)ExternalID, 1);
        xmlResetLastError();
    }
    }
    function_tests++;
#endif
}
/**
	* @test			UTchtmlNewDocNoDtDP01
	* @brief		htmlDocPtr htmlNewDocNoDtD(const xmlChar *URI, const xmlChar *ExternalID)
	* @desc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTchtmlNewDocNoDtDP01()
{
#if defined(LIBXML_HTML_ENABLED)
    htmlDocPtr ret_val;
    xmlChar * URI; /* URI for the dtd, or NULL */
    int n_URI;
    xmlChar * ExternalID; /* the external ID of the DTD, or NULL */
    int n_ExternalID;

    for (n_URI = 0;n_URI < gen_nb_const_xmlChar_ptr;n_URI++) {
    for (n_ExternalID = 0;n_ExternalID < gen_nb_const_xmlChar_ptr;n_ExternalID++) {
        URI = gen_const_xmlChar_ptr(n_URI, 0);
        ExternalID = gen_const_xmlChar_ptr(n_ExternalID, 1);

        ret_val = htmlNewDocNoDtD((const xmlChar *)URI, (const xmlChar *)ExternalID);
        if(ret_val == NULL)
        	{
			DTS_CHECK_EQ_MESSAGE("htmlNewDoc", ret_val, NULL, "htmlNewDocFailes");
        	}
        else  // checking for success(+ve)
        	{
			DTS_CHECK_NE_MESSAGE("htmlNewDoc", ret_val, NULL, "htmlNewDoc Failes");
        	}
        desret_htmlDocPtr(ret_val);
        call_tests++;
        des_const_xmlChar_ptr(n_URI, (const xmlChar *)URI, 0);
        des_const_xmlChar_ptr(n_ExternalID, (const xmlChar *)ExternalID, 1);
        xmlResetLastError();
    }
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
	{UTchtmlIsBooleanAttrP01,2},
	//{UTchtmlDocDumpP01,3},
	{UTchtmlNodeDumpP01,4},
	//{UTchtmlNodeDumpFileFormatP01,5},
	{UTchtmlSaveFileP01,6},
	{UTchtmlNodeDumpFormatOutputP01,7},
	{UTchtmlNodeDumpOutputP01,8},
	{UTchtmlSaveFileEncP01,9},
	{UTchtmlSaveFileFormatP01,10},
	
	{UTchtmlSetMetaEncodingP01,11},
	{UTchtmlDocContentDumpFormatOutputP01,12},
	{UTchtmlDocContentDumpOutputP01,13},
	//{UTchtmlDocDumpMemoryP01,14},
	{UTchtmlGetMetaEncodingP01,15},
	//{UTchtmlNodeDumpFileP01,16},
	//{UTchtmlDocDumpMemoryFormatP01,17},
	{UTchtmlNewDocP01,18},
	{UTchtmlNewDocNoDtDP01,19},
	{ NULL, 0 },
	
};
