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

#ifdef DEBUG_MEM_LEAK
extern "C"
{
	extern void MemStartSaveCallStack(void);
	extern void MemEndSaveCallStack(void);
	extern void MemPrintCurrentIndex(void);
	extern void MemTraceAllocMemInfo(void);
}
#endif

/***************************************************************************
 * SUTsParserInternals
 ***************************************************************************/
static int inttab[12];
static xmlChar chartab[12];

#define gen_nb_xmlParserCtxtPtr 1
static xmlParserCtxtPtr gen_xmlParserCtxtPtr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(xmlNewParserCtxt());
	if (no == 1) return(xmlCreateMemoryParserCtxt("<doc/>", 6));
	return(NULL);
}
static void des_xmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, xmlParserCtxtPtr val, int nr ATTRIBUTE_UNUSED)
{
	if(val!= NULL && val->myDoc!= NULL)
		xmlFreeDoc(val->myDoc);
	if (val != NULL)
		xmlFreeParserCtxt(val);
}

#define gen_nb_int 4

static int gen_int(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(0);
	if (no == 1) return(1);
	if (no == 2) return(-1);
	if (no == 3) return(96);
	return(-1);
}
#define gen_nb_xmlEntityPtr 1
static xmlEntityPtr gen_xmlEntityPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
	return((xmlEntityPtr)"test");
}

static void desret_xmlParserInputPtr(xmlParserInputPtr val)
{
	if (val != NULL)
		xmlFreeInputStream(val);
}
#define gen_nb_filepath 7

#define gen_nb_xmlParserInputBufferPtr 7

static xmlParserInputBufferPtr gen_xmlParserInputBufferPtr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(xmlParserInputBufferCreateFilename(MISSINGXML, XML_CHAR_ENCODING_NONE));
	if (no == 1) return(xmlParserInputBufferCreateFilename("<foo/>", XML_CHAR_ENCODING_NONE));
	if (no == 2) return(xmlParserInputBufferCreateFilename("test/ent2", XML_CHAR_ENCODING_NONE));
	if (no == 3) return(xmlParserInputBufferCreateFilename(TESTRECxml19980210, XML_CHAR_ENCODING_NONE));
	if (no == 4) return(xmlParserInputBufferCreateFilename(TESTXHTML1STRICTDTD, XML_CHAR_ENCODING_NONE));
	if (no == 5) return(xmlParserInputBufferCreateFilename(REMOTE1GOOD, XML_CHAR_ENCODING_NONE));
	if (no == 6) return(xmlParserInputBufferCreateFilename(REMOTE1BAD, XML_CHAR_ENCODING_NONE));
	return(NULL);
}

static void des_xmlParserInputBufferPtr(int no ATTRIBUTE_UNUSED, xmlParserInputBufferPtr val, int nr ATTRIBUTE_UNUSED)
{
	xmlFreeParserInputBuffer(val);
}
static void des_filepath(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}
#define gen_nb_const_xmlChar_ptr 4

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((xmlChar *) "foo");
	if (no == 1) return((xmlChar *) "<foo/>");
	if (no == 2) return((xmlChar *) "none");
	if (no == 3) return((xmlChar *) " 2ab ");
	return(NULL);
}
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}
#define gen_nb_xmlParserInputPtr 1
static xmlParserInputPtr gen_xmlParserInputPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((xmlParserInputPtr) "test");
	return(NULL);
}

#define gen_nb_xmlChar_ptr_ptr 1
static xmlChar ** gen_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((xmlChar **) "f");
	return(NULL);
}

static void desret_xmlChar_ptr(xmlChar *val)
{
	if (val != NULL)
		xmlFree(val);
}

static int *gen_int_ptr(int no, int nr)
{
	memset(inttab, 0,sizeof(inttab));
	if (no == 0) return(&inttab[nr]);
	return(NULL);
}

#define gen_nb_xmlCharEncoding 2
static xmlCharEncoding gen_xmlCharEncoding(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(XML_CHAR_ENCODING_UTF8);
	if (no == 1) return(XML_CHAR_ENCODING_NONE);
	return(XML_CHAR_ENCODING_ERROR);
}

#define gen_nb_const_xmlParserNodeInfoSeqPtr 1
static xmlParserNodeInfoSeqPtr gen_const_xmlParserNodeInfoSeqPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
	return((xmlParserNodeInfoSeqPtr)"test");
}
//#define gen_nb_const_xmlParserCtxtPtr 1
//static xmlParserCtxtPtr gen_const_xmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
//{
//	return(xmlNewParserCtxt());
//}

/**    
	* @test			UTcxmlIsLetterP01
	* @brief		XMLPUBFUN int XMLCALL xmlIsLetter (int c)
	* @desc			Positive Test for xmlIsLetter 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(0)} => {N/A | 1} @n
	* 				input2: [N/A, N/A] @n
	*   			{int('c')} => {N/A | 1} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlIsLetterP01()
{
	int ret_val;

	/**
	 * @remarks   input1: [N/A, N/A]	@n
	 *					{0} => {N/A |0}	@n
	 */
	ret_val = xmlIsLetter(0);
	DTS_CHECK_EQ_MESSAGE("xmlIsLetter", (void *)ret_val, (void *)0, "xmlIsLetter Failes");	

	/**
	 * @remarks   input2: [N/A, N/A]	@n
	 *					{'a'} => {N/A |1}	@n
	 */
	ret_val = xmlIsLetter('a');
	DTS_CHECK_EQ_MESSAGE("xmlIsLetter", (void *)ret_val, (void *)1, "xmlIsLetter Failes");	
}
/**    
	* @test			UTcxmlNewEntityInputStreamP01
	* @brief		XMLPUBFUN xmlParserInputPtr XMLCALL	xmlNewEntityInputStream	(xmlParserCtxtPtr ctxt, xmlEntityPtr entity)
	* @desc			Positive Test for xmlNewEntityInputStream	
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlParserCtxtPtr(ctxt) is created, Free all the memory used by a parser context] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlEntityPtr("test")} => {N/A | != NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNewEntityInputStreamP01()
{
	xmlParserInputPtr ret_val;
	xmlErrorPtr				pError;
	xmlResetLastError();
	xmlParserCtxtPtr ctx = xmlNewParserCtxt();

	/**
	     * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	     *					{ctxt,entity} => {N/A |xmlParserInputPtr}	@n
	     */
	//ret_val = xmlNewEntityInputStream(ctx,(xmlEntityPtr)"test");
	ret_val = xmlNewEntityInputStream(ctx,NULL);
	DTS_CHECK_EQ_MESSAGE("xmlNewEntityInputStream", (void *)ret_val, (void *)NULL, "xmlNewEntityInputStream Failes");	
	pError = xmlGetLastError();
	DTS_CHECK_NE_MESSAGE("xmlNewEntityInputStream", (void *)pError, (void *)NULL, "xmlGetLastError Failes");	

	/**
	     * @post delete xmlParserInputPtr objects
	     */
	//xmlMemFree(ret_val);
	xmlFreeParserCtxt(ctx);
	//if (pError != NULL)// Syam->Assertion occured
	//	delete pError;
}
/**    
	* @test			UTcxmlNewInputFromFileP01
	* @brief		XMLPUBFUN xmlParserInputPtr XMLCALL	xmlNewInputFromFile	(xmlParserCtxtPtr ctxt, const char *filename)
	* @desc			Positive Test for xmlNewInputFromFile	
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlParserCtxtPtr(ctxt) is created, Free all the memory used by a parser context] @n
	*   			{xmlParserCtxtPtr(ctxt), char*(LIBXML2TESTXML)} => {N/A | != NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNewInputFromFileP01()
{
	xmlParserInputPtr ret_val;
	const char *pFilename = LIBXML2TESTXML;
	
	xmlErrorPtr				pError;
	xmlResetLastError();
	int result = -1;
	xmlParserCtxtPtr ctx = xmlNewParserCtxt();

	/**
	 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	 *					{ctxt,LIBXML2TESTXML} => {N/A |xmlParserInputPtr}	@n
	 */

	ret_val = xmlNewInputFromFile(ctx, pFilename);
	DTS_CHECK_NE_MESSAGE("xmlNewInputFromFile", (void *)ret_val, (void *)NULL, "xmlNewInputFromFile Failes");	
	
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlNewInputFromFile", (void *)pError, (void *)NULL, "xmlGetLastError Failes");		
#if 0
	result = xmlParserInputRead(ret_val, 4);
	DTS_CHECK_EQ_MESSAGE("xmlNewInputFromFile", (void *)ret_val, (void *)4, "xmlParserInputRead Failes");	
	
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlNewInputFromFile", (void *)pError, (void *)NULL, "xmlGetLastError Failes");	
	
#endif
	/**
	 * @post delete xmlParserInputPtr objects
	 */
	xmlFreeInputStream(ret_val);
	xmlFreeParserCtxt(ctx);
	//xmlCleanupParser();
	//if (pError != NULL)// Syam->Assertion occured
	//	delete pError;
}
/**    
	* @test			UTcxmlNewInputStreamP01
	* @brief		XMLPUBFUN xmlParserInputPtr XMLCALL xmlNewInputStream (xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for xmlNewInputStream 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlParserCtxtPtr(ctxt) is created, Free all the memory used by a parser context] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | != NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNewInputStreamP01()
{
	xmlParserInputPtr ret_val;
	xmlErrorPtr				pError;
	xmlResetLastError();
	xmlParserCtxtPtr ctx = xmlNewParserCtxt();
	/**
	 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	 *					{ctxt} => {N/A |xmlParserInputPtr}	@n
	 */
	ret_val = xmlNewInputStream(ctx);
	DTS_CHECK_NE_MESSAGE("xmlNewInputStream", (void *)ret_val, (void *)NULL, "xmlNewInputStream Failes");
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlNewInputStream", (void *)pError, (void *)NULL, "xmlGetLastError Failes");
	/**
	 * @post delete xmlParserInputPtr objects
	 */
	xmlFreeInputStream(ret_val);
	xmlFreeParserCtxt(ctx);
	//if (pError != NULL)// Syam->Assertion occured
	//	delete pError;
}
/**    
	* @test			UTcxmlNewStringInputStreamP01
	* @brief		XMLPUBFUN xmlParserInputPtr XMLCALL xmlNewStringInputStream	(xmlParserCtxtPtr ctxt, const xmlChar *buffer)
	* @desc			Positive Test for xmlNewStringInputStream	
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlParserCtxtPtr(ctxt) is created, Free all the memory used by a parser context] @n
	*   			{xmlParserCtxtPtr(ctxt), char*("parser")} => {N/A | != NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNewStringInputStreamP01()
{
	xmlParserInputPtr ret_val;
	xmlParserCtxtPtr ctxt; /* an XML parser context */
	ctxt = xmlCreateMemoryParserCtxt("<doc>Parsers</doc>", 18);
	xmlErrorPtr				pError;
	xmlResetLastError();
	/**
	     * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	     *					{ctxt,buffer} => {N/A |xmlParserInputPtr}	@n
	     */

	ret_val = xmlNewStringInputStream(ctxt, (const xmlChar *)"parser");
	DTS_CHECK_NE_MESSAGE("xmlNewStringInputStream", (void *)ret_val, (void *)NULL, "xmlNewStringInputStream Failes");
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlNewStringInputStream", (void *)pError, (void *)NULL, "xmlGetLastError Failes");
	/**
	 * @post delete xmlParserInputPtr objects
	 */
	if (ret_val != NULL)
		xmlFreeInputStream(ret_val);
	if (ctxt != NULL)
	{
		xmlFreeParserCtxt(ctxt);
		ctxt = NULL;
	}
	//xmlCleanupParser();
	/**
	 * @remarks   input2: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	 *					{ctxt,NULL} => {N/A |NULL}	@n
	 */
	ctxt = xmlNewParserCtxt();
	ret_val = xmlNewStringInputStream(ctxt,NULL);
	DTS_CHECK_EQ_MESSAGE("xmlNewStringInputStream", (void *)ret_val, (void *)NULL, "xmlNewStringInputStream Failes");
	
	pError = xmlGetLastError();
	DTS_CHECK_NE_MESSAGE("xmlNewStringInputStream", (void *)pError, (void *)NULL, "xmlGetLastError Failes");
	

	if (ctxt != NULL)
		xmlFreeParserCtxt(ctxt);
	xmlResetError(pError);
}
/**    
	* @test			UTcxmlNextCharP01
	* @brief		XMLPUBFUN void XMLCALL xmlNextChar (xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for xmlNextChar
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNextCharP01()
{
	xmlParserCtxtPtr ctxt; /* the XML parser context */
	int result;
	int *pLen ;

	xmlErrorPtr				pError;
	xmlSAXHandler *saxHandler;
	saxHandler =(xmlSAXHandler *) xmlMemMalloc(sizeof(xmlSAXHandler));
	char xmlIn[] =
	        "<test:Plan xmlns:test='http://test.org/schema'>"
	        "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
	        "</test:Case>"
	        "</test:Plan>";

	/**
	* @pre Initialise xmlSAXHandler
	*/
	xmlSAX2InitDefaultSAXHandler(saxHandler,0);
	DTS_CHECK_NE_MESSAGE("xmlCurrentChar", (void *)saxHandler, (void *)NULL, "xmlSAX2InitDefaultSAXHandler Failes");

	ctxt = xmlCreatePushParserCtxt(saxHandler,(void *)"test:case",(const char *)"test", strlen(xmlIn) , xmlIn );
	DTS_CHECK_NE_MESSAGE("xmlCurrentChar", (void *)ctxt, (void *)NULL, "xmlCreatePushParserCtxt Failes");

	xmlResetLastError();
	xmlSAX2StartDocument(ctxt);
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlCurrentChar", (void *)pError, (void *)NULL, "xmlGetLastError Failes");

	pLen = gen_int_ptr(0, 1);

	result = xmlCurrentChar(ctxt,pLen);
	DTS_CHECK_GT_MESSAGE("xmlCurrentChar", (void *)result, (void *)0, "xmlCurrentChar Failes");

	xmlResetLastError();
	/**
	 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	 *					{ctxt} => {N/A |N/A}	@n
	 */
	xmlNextChar(ctxt);
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlCurrentChar", (void *)pError, (void *)NULL, "xmlGetLastError Failes");


	result = xmlCurrentChar(ctxt,pLen);
	DTS_CHECK_GT_MESSAGE("xmlCurrentChar", (void *)result, (void *)0, "xmlCurrentChar Failes");

	xmlSAX2EndDocument(ctxt);
	/**
	 * @post delete xmlParserCtxtPtr
	 */

	if(ctxt->myDoc!= NULL)
		xmlFreeDoc(ctxt->myDoc);
	//if (pLen != NULL)// Syam->Assertion occured
	//	delete pLen;
	if (ctxt != NULL)
		xmlFreeParserCtxt(ctxt);
	xmlMemFree(saxHandler);
	//xmlCleanupParser();
	xmlResetLastError();
}
	/**    
	* @test			UTcxmlParserInputShrinkP01
	* @brief		XMLPUBFUN void XMLCALL xmlParserInputShrink (xmlParserInputPtr in);
	* @desc			Positive Test for xmlParserInputShrink 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlParserInputShrinkP01()
{
	xmlParserCtxtPtr ctxt;
	xmlErrorPtr		pError;
	xmlParserInputPtr parseInputPtr; /* an XML parser input */
	xmlSAXHandler *saxHandler;
	saxHandler =(xmlSAXHandler *) xmlMemMalloc(sizeof(xmlSAXHandler));
	char xmlIn[] =
	        "<test:Plan xmlns:test='http://test.org/schema'>"
	        "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
	        "</test:Case>"
	        "</test:Plan>";

	xmlSAX2InitDefaultSAXHandler(saxHandler,0);
	DTS_CHECK_NE_MESSAGE("xmlParserInputShrink", (void *)saxHandler, (void *)NULL, "xmlSAX2InitDefaultSAXHandler Failes");

	ctxt = xmlCreatePushParserCtxt(saxHandler,(void *)"test:case",(const char *)"test", strlen(xmlIn) , xmlIn);
	DTS_CHECK_NE_MESSAGE("xmlParserInputShrink", (void *)ctxt, (void *)NULL, "xmlSAX2InitDefaultSAXHandler Failes");

	xmlSAX2StartDocument(ctxt);

	parseInputPtr = xmlNewInputStream(ctxt);
	xmlResetLastError();
	/**
	 * @remarks   input1: [1.xmlParserInputPtr is created, N/A]	@n
	 *					{parseInputPtr} => {N/A |N/A}	@n
	 */
	if(parseInputPtr!=NULL) xmlParserInputShrink(parseInputPtr);
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlParserInputShrink", (void *)pError, (void *)NULL, "xmlSAX2InitDefaultSAXHandler Failes");

	xmlSAX2EndDocument(ctxt);
	/**
	 * @post Cleanup function for the XML library.
	 */
	if(ctxt->myDoc!= NULL)
		xmlFreeDoc(ctxt->myDoc);
	if (ctxt != NULL)
		xmlFreeParserCtxt(ctxt);
	if (parseInputPtr != NULL)
		xmlFreeInputStream(parseInputPtr);
	xmlMemFree(saxHandler);
}
/**    
	* @test			UTcxmlStringCurrentCharP01
	* @brief		XMLPUBFUN int XMLCALL xmlStringCurrentChar (xmlParserCtxtPtr ctxt, const xmlChar *cur, int *len)
	* @desc			Positive Test for xmlStringCurrentChar
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlStringCurrentCharP01()
{
	int ret_val;
	xmlParserCtxtPtr ctxt; /* the XML parser context */
	xmlErrorPtr				pError;
	xmlResetLastError();
	ctxt = xmlNewParserCtxt();

	/**
	 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	 *					{ctxt,cur,len} => {N/A |ret_val}	@n
	 */

	ret_val = xmlStringCurrentChar(ctxt, (const xmlChar *)"test", &inttab[0]);
	DTS_CHECK_GT_MESSAGE("xmlStringCurrentChar", (void *)ret_val, (void *)0, "xmlStringCurrentChar Failes");
	
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlStringCurrentChar", (void *)pError, (void *)NULL, "xmlGetLastError Failes");

	/**
	 * @post delete xmlParserCtxtPtr
	     */
	if (ctxt != NULL)
		xmlFreeParserCtxt(ctxt);
	//xmlCleanupParser();
	//if (pError != NULL)// Syam->Assertion occured
	//	delete pError;
}
/**    
	* @test			UTcxmlCopyCharP01
	* @brief		XMLPUBFUN int XMLCALL xmlCopyChar (int len, xmlChar *out, int val)
	* @desc			Positive Test for xmlCopyChar 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(1), xmlChar, int(1) } => {N/A | > 0} @n
	* 				input2: [N/A, N/A] @n
	*   			{int(1), xmlChar, int(1024) } => {N/A | > 0} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlCopyCharP01()
{
	int ret_val;
	xmlErrorPtr				pError;
	xmlResetLastError();

	/**
	 * @remarks   input1: [N/A , N/A]	@n
	 *					{1,chartab[0],1} => {N/A |ret_val}	@n
	 */
	ret_val = xmlCopyChar(1, &chartab[0], 1);
	DTS_CHECK_GT_MESSAGE("xmlCopyChar", (void *)ret_val, (void *)0, "xmlCopyChar Failes");
	
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlCopyChar", (void *)pError, (void *)NULL, "xmlGetLastError Failes");

	/**
	 * @remarks   input2: [N/A , N/A]	@n
	 *					{1,chartab[0],1024} => {N/A |ret_val}	@n
	 */
	ret_val = xmlCopyChar(1, &chartab[0], 1024);
	DTS_CHECK_GT_MESSAGE("xmlCopyChar", (void *)ret_val, (void *)0, "xmlCopyChar Failes");
	
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlCopyChar", (void *)pError, (void *)NULL, "xmlGetLastError Failes");

	//if (pError != NULL)// Syam->Assertion occured
	//	delete pError;
}
/**    
	* @test			UTcxmlCopyCharMultiByteP01
	* @brief		XMLPUBFUN int XMLCALL xmlCopyCharMultiByte (xmlChar *out, int val)
	* @desc			Positive Test for xmlCopyCharMultiByte
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlChar, int(1) } => {N/A | > 0} @n
	* 				input2: [N/A, N/A] @n
	*   			{xmlChar*("test"), int(1214112) } => {N/A | > 0} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlCopyCharMultiByteP01()
{
	int ret_val;
	xmlErrorPtr				pError;
	xmlResetLastError();

	/**
	 * @remarks   input1: [N/A , N/A]	@n
	 *					{out,val} => {N/A |ret_val}	@n
	 */
	ret_val = xmlCopyCharMultiByte(&chartab[0], 1);
	DTS_CHECK_GT_MESSAGE("xmlCopyCharMultiByte", (void *)ret_val, (void *)0, "xmlCopyCharMultiByte Failes");
	
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlCopyCharMultiByte", (void *)pError, (void *)NULL, "xmlGetLastError Failes");
	/**
	 * @remarks   input2: [N/A , N/A]	@n
	 *					{"test",1214112} => {N/A |0}	@n
	 */
	ret_val = xmlCopyCharMultiByte((xmlChar *) "test", 1214112);
	DTS_CHECK_EQ_MESSAGE("xmlCopyCharMultiByte", (void *)ret_val, (void *)0, "xmlCopyCharMultiByte Failes");
	
	pError = xmlGetLastError();
	DTS_CHECK_NE_MESSAGE("xmlCopyCharMultiByte", (void *)pError, (void *)NULL, "xmlGetLastError Failes");
	
	xmlResetLastError();
	//if (pError != NULL) // Syam->Assertion occured
	//	delete pError;
}
	/**    
	* @test			UTcxmlNewIOInputStreamP01
	* @brief		xmlParserInputPtr xmlNewIOInputStream(xmlParserCtxtPtr ctxt, xmlParserInputBufferPtr input, xmlCharEncoding enc)
	* @desc			Positive Test for xmlNewIOInputStream
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr AND create xmlParserInputBufferPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr, xmlParserInputBufferPtr, xmlCharEncoding} => {N/A | != NULL} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlNewIOInputStreamP01()
{
	xmlParserInputPtr ret_val;
	xmlParserCtxtPtr ctxt; /* an XML parser context */
	int n_ctxt;
	xmlParserInputBufferPtr input; /* an I/O Input */
	int n_input;
	xmlCharEncoding enc; /* the charset encoding if known */
	int n_enc;
	char xmlIn[] =
	        "<test:Plan xmlns:test='http://test.org/schema'>"
	        "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
	        "</test:Case>"
	        "</test:Plan>";
	LIBXML_TEST_VERSION

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlParserCtxtPtr;n_ctxt++) {
		for (n_input = 0;n_input < gen_nb_xmlParserInputBufferPtr;n_input++) {
			for (n_enc = 0;n_enc < gen_nb_xmlCharEncoding;n_enc++) {

				ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
				//input = gen_xmlParserInputBufferPtr(n_input, 1);
				enc = gen_xmlCharEncoding(n_enc, 2);
				input = xmlParserInputBufferCreateMem(xmlIn , strlen (xmlIn), enc);
				/**
				 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
				 *					{ctxt, input, enc} => {N/A |xmlParserInputPtr}	@n
				 */
				ret_val = xmlNewIOInputStream(ctxt, input, enc);
				DTS_CHECK_NE_MESSAGE("xmlNewIOInputStream", (void *)ret_val, (void *)NULL, "xmlNewIOInputStream Failes");
				
				if (ret_val != NULL)
					input = NULL;
				/**
				 * @post delete xmlParserInputPtr
				 */
				desret_xmlParserInputPtr(ret_val);

				des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
				des_xmlParserInputBufferPtr(n_input, input, 1);
				xmlResetLastError();
				//xmlCleanupParser();

			}
		}
	}

}
/**    
	* @test			UTcxmlParserAddNodeInfoP01
	* @brief		void xmlParserAddNodeInfo(xmlParserCtxtPtr ctxt, const xmlParserNodeInfoPtr info)
	* @desc			Positive Test for xmlParserAddNodeInfo
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr, xmlParserNodeInfoPtr("test")} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlParserAddNodeInfoP01()
{

	xmlParserCtxtPtr ctxt; /* an XML parser context */
	xmlErrorPtr				pError;
	xmlResetLastError();
	ctxt = xmlNewParserCtxt();

	/**
	 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	 *					{ctxt,"test"} => {N/A |N/A}	@n
	 */
	xmlParserAddNodeInfo(ctxt, (xmlParserNodeInfoPtr)"test");
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlParserAddNodeInfo", (void *)pError, (void *)NULL, "xmlParserAddNodeInfo Failes");

	/**
	 * @post delete xmlParserCtxtPtr
	 */
	if (ctxt != NULL)
	{
		xmlFreeParserCtxt(ctxt);
	}
	//xmlCleanupParser();
	//if (pError != NULL)// Syam->Assertion occured
	//	delete pError;
}
/**    
	* @test			UTcxmlParserFindNodeInfoP01
	* @brief		const xmlParserNodeInfo * xmlParserFindNodeInfo(const xmlParserCtxtPtr ctx, const xmlNodePtr node)
	* @desc			Positive Test for xmlParserFindNodeInfo
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr, NULL} => {N/A | NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlParserFindNodeInfoP01(void)
{
	const xmlParserNodeInfo * ret_val=NULL;
	xmlParserCtxtPtr ctx; /* an XML parser context */
	int n_ctx;

	for (n_ctx = 0;n_ctx < gen_nb_xmlParserCtxtPtr;n_ctx++) {
		ctx = gen_xmlParserCtxtPtr(n_ctx, 0);
		/**
		 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
		 *					{ctxt,node} => {N/A |N/A}	@n
		 */
		ret_val = xmlParserFindNodeInfo((const xmlParserCtxtPtr)ctx, NULL);
		DTS_CHECK_EQ_MESSAGE("xmlParserFindNodeInfo", (void *)ret_val, (void *)NULL, "xmlParserFindNodeInfo Failes");


		//xmlClearParserCtxt(ctx);
		if (ctx != NULL)
			xmlFreeParserCtxt(ctx);
	}
	/**
	 * @post Cleanup function for the XML library.
	 */

	//xmlCleanupParser();
}
/**    
	* @test			UTcxmlParserFindNodeInfoIndexP01
	* @brief		unsigned long xmlParserFindNodeInfoIndex(const xmlParserNodeInfoSeqPtr seq, const xmlNodePtr node)
	* @desc			Positive Test for xmlParserFindNodeInfoIndex
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create pxmlParserNodeInfoSeqPtr, N/A] @n
	*   			{pxmlParserNodeInfoSeqPtr, xmlNodePtr(NULL)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlParserFindNodeInfoIndexP01()
{
	unsigned long ret_val;
	xmlErrorPtr				pError;
	xmlResetLastError();
	xmlParserNodeInfoSeq *pxmlParserNodeInfoSeqPtr = (xmlParserNodeInfoSeq *) malloc(sizeof(xmlParserNodeInfoSeq) );	
	//MT_CHECK_MESSAGE2(pxmlParserNodeInfoSeqPtr != NULL, "checking pxmlParserNodeInfoSeqPtr allocation \n");
	DTS_CHECK_NE_MESSAGE("xmlParserFindNodeInfoIndex", (void *)pxmlParserNodeInfoSeqPtr, (void *)NULL, "malloc Failes");
	
	pxmlParserNodeInfoSeqPtr->length = 10;
	pxmlParserNodeInfoSeqPtr->maximum = 10;
	pxmlParserNodeInfoSeqPtr->buffer = (xmlParserNodeInfo*)"<item>test</item>";
	/**
	 * @remarks   input1: [N/A, N/A]	@n
	 *					{seq,node} => {N/A |0}	@n
	 */
	ret_val = xmlParserFindNodeInfoIndex(pxmlParserNodeInfoSeqPtr,(const xmlNodePtr)NULL);
	DTS_CHECK_NE_MESSAGE("xmlParserFindNodeInfoIndex", (void *)ret_val, (void *)NULL, "xmlParserFindNodeInfoIndex Failes");
	
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlParserFindNodeInfoIndex", (void *)pError, (void *)NULL, "xmlParserFindNodeInfo Failes");
	
	if(pxmlParserNodeInfoSeqPtr != NULL) {
		free(pxmlParserNodeInfoSeqPtr);
		pxmlParserNodeInfoSeqPtr = NULL;
	}
	/**
	 * @post Cleanup function for the XML library.
	 */
	//if (pError != NULL)// Syam->Assertion occured
	//	delete pError;
	//xmlCleanupParser();
}
/**    
	* @test			UTcxmlKeepBlanksDefaultP01
	* @brief		int xmlKeepBlanksDefault(int val)
	* @desc			Positive Test for xmlKeepBlanksDefault
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(0)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlKeepBlanksDefaultP01(void)
{
	int ret_val;
	int val; /* int 0 or 1 */
	int n_val;
	for (n_val = 0;n_val < gen_nb_int;n_val++) {

		val = gen_int(n_val, 0);

		ret_val = xmlKeepBlanksDefault(val);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{val} => {N/A |val}	@n
		 */
		ret_val = xmlKeepBlanksDefault(val);
		DTS_CHECK_EQ_MESSAGE("xmlKeepBlanksDefault", (void *)ret_val, (void *)val, "xmlKeepBlanksDefault Failes");
		xmlResetLastError();
	}
}
/**    
	* @test			UTcxmlLineNumbersDefaultP01
	* @brief		int xmlLineNumbersDefault(int val)
	* @desc			Positive Test for xmlLineNumbersDefault
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(0)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlLineNumbersDefaultP01(void)
{
	int ret_val;
	int val;
	int n_val;

	for (n_val = 0;n_val < gen_nb_int;n_val++) {

		val = gen_int(n_val, 0);

		ret_val = xmlLineNumbersDefault(val);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{val} => {N/A |val}	@n
		 */
		ret_val = xmlLineNumbersDefault(val);
		DTS_CHECK_EQ_MESSAGE("xmlLineNumbersDefault", (void *)ret_val, (void *)val, "xmlLineNumbersDefault Failes");
	}
}
/**    
	* @test			UTcxmlPedanticParserDefaultP01
	* @brief		int xmlPedanticParserDefault(int val)
	* @desc			Positive Test for xmlPedanticParserDefault
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(0)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlPedanticParserDefaultP01(void)
{

	int ret_val;
	int val;
	int n_val;

	for (n_val = 0;n_val < gen_nb_int;n_val++) {
		val = gen_int(n_val, 0);

		ret_val = xmlPedanticParserDefault(val);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{val} => {N/A |val}	@n
		 */
		ret_val = xmlPedanticParserDefault(val);
		DTS_CHECK_EQ_MESSAGE("xmlPedanticParserDefault", (void *)ret_val, (void *)val, "xmlPedanticParserDefault Failes");
	}
}
/**    
	* @test			UTcxmlSubstituteEntitiesDefaultP01
	* @brief		int xmlSubstituteEntitiesDefault(int val)
	* @desc			Positive Test for xmlSubstituteEntitiesDefault
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{int(0)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlSubstituteEntitiesDefaultP01(void)
{
	int ret_val;
	int val;
	int n_val;

	for (n_val = 0;n_val < gen_nb_int;n_val++) {

		val = gen_int(n_val, 0);

		ret_val = xmlSubstituteEntitiesDefault(val);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{val} => {N/A |val}	@n
		 */
		ret_val = xmlSubstituteEntitiesDefault(val);
		DTS_CHECK_EQ_MESSAGE("xmlSubstituteEntitiesDefault", (void *)ret_val, (void *)val, "xmlSubstituteEntitiesDefault Failes");
	}
}
/**    
	* @test			UTcxmlSwitchEncodingP01
	* @brief		XMLPUBFUN int XMLCALL xmlSwitchEncoding	(xmlParserCtxtPtr ctxt, xmlCharEncoding enc)
	* @desc			Positive Test for xmlSwitchEncoding
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr, xmlCharEncoding} => {N/A | int(0) } @n
	* 				input2: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr, xmlCharEncoding(-1)} => {N/A | int(-1) } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlSwitchEncodingP01()
{
	int ret_val;
	xmlParserCtxtPtr ctxt; /* the parser context */
	int n_ctxt;
	xmlCharEncoding enc; /* the encoding value (number) */
	int n_enc;
	xmlResetLastError();

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlParserCtxtPtr;n_ctxt++) {
		for (n_enc = 0;n_enc < 2;n_enc++) {

			ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
			enc = gen_xmlCharEncoding(n_enc, 1);
			/**
			 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
			 *					{ctxt, enc} => {N/A |0}	@n
			 */
			ret_val = xmlSwitchEncoding(ctxt, enc);
			DTS_CHECK_EQ_MESSAGE("xmlSwitchEncoding", (void *)ret_val, (void *)0, "xmlSwitchEncoding Failes");
			/**
			 * @post delete xmlParserCtxtPtr
			 */
			xmlResetLastError();
			des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
			//xmlCleanupParser();
		}
	}
	/**
	 * @remarks   input2: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
	 *					{ctxt, XML_CHAR_ENCODING_ERROR} => {N/A |0}	@n
	 */
	ctxt = xmlNewParserCtxt();
	ret_val = xmlSwitchEncoding(ctxt, XML_CHAR_ENCODING_ERROR);
	DTS_CHECK_EQ_MESSAGE("xmlSwitchEncoding", (void *)ret_val, (void *)-1, "xmlSwitchEncoding Failes");
	xmlResetLastError();
	/**
	 * @post Cleanup function for the XML library.
	 */
	if (ctxt != NULL)
		xmlFreeParserCtxt(ctxt);
	//xmlCleanupParser();
}
/**    
	* @test			UTcxmlSwitchInputEncodingP01
	* @brief		XMLPUBFUN int XMLCALL xmlSwitchInputEncoding (xmlParserCtxtPtr ctxt, xmlParserInputPtr input, xmlCharEncodingHandlerPtr handler)
	* @desc			Positive Test for xmlSwitchInputEncoding 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr, xmlParserInputPtr("test"), NULL} => {N/A | int(-1) } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlSwitchInputEncodingP01()
{
	int ret_val;
	xmlParserCtxtPtr ctxt; /* the parser context */
	int n_ctxt;

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlParserCtxtPtr;n_ctxt++) {

		ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);

		/**
		 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
		 *					{ctxt, input, handler} => {N/A |-1}	@n
		 */
		ret_val = xmlSwitchInputEncoding(ctxt, (xmlParserInputPtr) "test", NULL);
		DTS_CHECK_EQ_MESSAGE("xmlSwitchInputEncoding", (void *)ret_val, (void *)-1, "xmlSwitchInputEncoding Failes");
		xmlResetLastError();
		/**
		 * @post delete xmlParserCtxtPtr
		 */
		des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
		//xmlCleanupParser();
	}
}
/**    
	* @test			UTcxmlSwitchToEncodingP01
	* @brief		XMLPUBFUN int XMLCALL xmlSwitchToEncoding (xmlParserCtxtPtr ctxt, xmlCharEncodingHandlerPtr handler)
	* @desc			Positive Test for xmlSwitchToEncoding 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlParserInputPtr, Free all the memory used by a parser context] @n
	*   			{xmlParserInputPtr, NULL} => {N/A | int(-1) } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlSwitchToEncodingP01()
{
	int ret_val;
	xmlParserCtxtPtr ctxt; /* the parser context */
	int n_ctxt;

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlParserCtxtPtr;n_ctxt++) {

		ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		/**
		 * @remarks   input1: [1.xmlParserCtxtPtr(ctxt) is created, N/A]	@n
		 *					{ctxt, handler} => {N/A |-1}	@n
		 */
		ret_val = xmlSwitchToEncoding(ctxt, NULL);
		DTS_CHECK_EQ_MESSAGE("xmlSwitchToEncoding", (void *)ret_val, (void *)-1, "xmlSwitchToEncoding Failes");
		xmlResetLastError();
		/**
		 * @post delete xmlParserCtxtPtr
		 */

		des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
		xmlResetLastError();
		//xmlCleanupParser();
	}
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
	{UTcxmlIsLetterP01,1},
	{UTcxmlNewEntityInputStreamP01,2},
	{UTcxmlNewInputFromFileP01,3},
	{UTcxmlNewInputStreamP01,4},
	{UTcxmlNewStringInputStreamP01,5},
	{UTcxmlNextCharP01,6},
	{UTcxmlParserInputShrinkP01,7},
	{UTcxmlStringCurrentCharP01,8},
	{UTcxmlSwitchEncodingP01,9},
	{UTcxmlSwitchInputEncodingP01,10},
	
	{UTcxmlSwitchToEncodingP01,11},
	{UTcxmlCopyCharP01,12},
	{UTcxmlCopyCharMultiByteP01,13},
	{UTcxmlParserAddNodeInfoP01,14},
	{UTcxmlParserFindNodeInfoIndexP01,15},
	{UTcxmlNewIOInputStreamP01,16},
	{UTcxmlLineNumbersDefaultP01,17},
	{UTcxmlKeepBlanksDefaultP01,18},
	{UTcxmlPedanticParserDefaultP01,19},
	{UTcxmlParserFindNodeInfoP01,20},
	
	{UTcxmlSubstituteEntitiesDefaultP01,21},
	{ NULL, 0 },
	
};
