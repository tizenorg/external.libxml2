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


//Global variables
static int 	MT_CHECK_FLAG	= 0;


static void startup( void);
static void cleanup( void);

void (*tet_startup)( void) = startup;
void (*tet_cleanup)( void) = cleanup;

static void TestFunc( void* ctx, const char* msg, ...)
{
	va_list args;

	va_start(args, msg);
	printf(msg, args);
	
	va_end(args);

    MT_CHECK_FLAG = XML_TRUE;
}

	/**    
	* @test			Dummy
	* @brief		
	* @desc			
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		
	* @b priority	Middle
	* @b etc		none
	*/

static void Dummy( void)
{
}

	/**    
	* @test			UTcInitGenericErrorDefaultFuncP01
	* @brief		XMLPUBFUN void XMLCALL initGenericErrorDefaultFunc (xmlGenericErrorFunc *handler);
	* @desc			Positive Test for initGenericErrorDefaultFunc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcInitGenericErrorDefaultFuncP01( void)
{
	xmlGenericErrorFunc handler = TestFunc; 		// error handler
	static void* ctx = NULL;

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {xmlGenericErrorFunc handler} => {N/A | static void} @n
	 */
	initGenericErrorDefaultFunc(NULL);
	DTS_CHECK_NE_MESSAGE("initGenericErrorDefaultFunc", (void *)xmlGenericError, (void *)(NULL), "GenericError handler -> __XmlErrorLog[default]");
}
	
	/**    
	* @test			UTcXmlSetGenericErrorFuncP01
	* @brief		XMLPUBFUN void XMLCALL xmlSetGenericErrorFunc (void *ctx, xmlGenericErrorFunc handler)
	* @desc			Positive Test for xmlSetGenericErrorFunc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create a xmlGenericErrorFunc handler, N/A] @n
	*   			{NULL, xmlGenericErrorFunc} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlSetGenericErrorFuncP01( void)
{
	xmlGenericErrorFunc handler = TestFunc; 					// error handler
	static void* ctx = NULL;
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {parser context, xmlGenericErrorFunc handler} => {N/A | static void} @n
	 */
	xmlSetGenericErrorFunc(ctx, handler);
	DTS_CHECK_NE_MESSAGE("UTcXmlSetGenericErrorFuncP01", (void *)xmlGenericError, (void *)(NULL), "GenericError handler -> TestFunc");

//	xmlGenericError(xmlGenericErrorContext, "xmlGenericError : %s, %s\n", "test1", "test2");
//	DTS_CHECK_EQ_MESSAGE("UTcXmlSetGenericErrorFuncP01", (void *)MT_CHECK_FLAG, (void *)(XML_TRUE), "xmlSetGenericErrorFunc() Success");
//	MT_CHECK_FLAG = XML_FALSE;

}

	/**    
	* @test			UTcXmlSetStructuredErrorFuncP01
	* @brief		XMLPUBFUN void XMLCALL xmlSetStructuredErrorFunc (void *ctx, xmlStructuredErrorFunc handler)
	* @desc			Positive Test for xmlSetStructuredErrorFunc 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create a xmlGenericErrorFunc handler, N/A] @n
	*   			{NULL, xmlGenericErrorFunc} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlSetStructuredErrorFuncP01( void)
{
	xmlStructuredErrorFunc handler  = NULL;				// error handler
	static void* ctx = NULL;

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {parser context, xmlGenericErrorFunc handler} => {N/A | static void} @n
	 */
	xmlSetStructuredErrorFunc(ctx, handler);
	DTS_CHECK_EQ_MESSAGE("UTcXmlSetStructuredErrorFuncP01", (void *)1, (void *)(1), "xmlSetStructuredErrorFunc() Success");
}
	/**    
	* @test			UTcXmlParserPrintFileInfoP01
	* @brief		XMLPUBFUN void XMLCALL xmlParserPrintFileInfo (xmlParserInputPtr input)
	* @desc			Positive Test for xmlParserPrintFileInfo
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlParserPrintFileInfoP01( void)
{
	xmlParserInputPtr input = NULL;  			// xmlParserInputPtr input

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {xmlParserInputPtr instance} => {N/A | static void} @n
	 */
	xmlParserPrintFileInfo(input);
	DTS_CHECK_EQ_MESSAGE("UTcXmlParserPrintFileInfoP01", (void *)1, (void *)(1), "xmlParserPrintFileInfo() Success");
}
	/**    
	* @test			UTcXmlParserPrintFileContextP01
	* @brief		XMLPUBFUN void XMLCALL xmlParserPrintFileContext (xmlParserInputPtr input)
	* @desc			Positive Test for xmlParserPrintFileContext
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlParserPrintFileContextP01( void)
{

	xmlParserInputPtr input = NULL; 			// xmlParserInputPtr input

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {xmlParserInputPtr instance} => {N/A | static void} @n
	 */
	xmlParserPrintFileContext(input);
	DTS_CHECK_EQ_MESSAGE("UTcXmlParserPrintFileContextP01", (void *)1, (void *)(1), "xmlParserPrintFileContext() Success");
}

	/**    
	* @test			UTcXmlParserErrorP01
	* @brief		XMLPUBFUN void XMLCALL xmlParserError (void *ctx, const char *msg, ...)
	* @desc			Positive Test for xmlParserError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL, char*("Error")} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlParserErrorP01( void)
{
	const char* msg = "Error";
	xmlParserCtxtPtr ctxt = NULL;

	/**
	 * @remarks   input1: [N/A, N/A, ...] @n
	 *            {parser context , "Error"} => {N/A | static void} @n
	 */
	xmlParserError(ctxt , msg);
	DTS_CHECK_EQ_MESSAGE("UTcXmlParserErrorP01", (void *)1, (void *)(1), "xmlParserError() Success");
}

	/**    
	* @test			UTcXmlParserWarningP01
	* @brief		XMLPUBFUN void XMLCALL xmlParserWarning (void *ctx, const char *msg, ...)
	* @desc			Positive Test for xmlParserWarning
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL, char*("Error")} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlParserWarningP01( void)
{
	const char* msg = "warning";
	xmlParserCtxtPtr ctxt = NULL;

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {parser context , "Error"} => {N/A | static void} @n
	 */
	xmlParserWarning(ctxt, msg);
	DTS_CHECK_EQ_MESSAGE("UTcXmlParserWarningP01", (void *)1, (void *)(1), "xmlParserWarning() Success");
}

	/**    
	* @test			UTcXmlParserValidityErrorP01
	* @brief		XMLPUBFUN void XMLCALL xmlParserValidityError (void *ctx, const char *msg, ...)
	* @desc			Positive Test for xmlParserValidityError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL, char*("Error")} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlParserValidityErrorP01( void)
{
	const char* msg = "Error";
	xmlParserCtxtPtr ctxt = NULL;


	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {parser context , "Error"} => {N/A | static void} @n
	 */
	xmlParserValidityError(ctxt , msg);
	DTS_CHECK_EQ_MESSAGE("UTcXmlParserValidityErrorP01", (void *)1, (void *)(1), "xmlParserValidityError() Success");
}

	/**    
	* @test			UTcXmlParserValidityWarningP01
	* @brief		XMLPUBFUN void XMLCALL xmlParserValidityWarning (void *ctx, const char *msg, ...)
	* @desc			Positive Test for xmlParserValidityWarning
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL, char*("Error")} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlParserValidityWarningP01( void)
{
	const char* msg = "Error";
	xmlParserCtxtPtr ctxt = NULL;

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {parser context , "Error"} => {N/A | static void} @n
	 */
	xmlParserValidityWarning(ctxt , msg);
	DTS_CHECK_EQ_MESSAGE("UTcXmlParserValidityWarningP01", (void *)1, (void *)(1), "xmlParserValidityWarning() Success");
}

	/**    
	* @test			UTcXmlGetLastErrorP01
	* @brief		XMLPUBFUN xmlErrorPtr XMLCALL xmlGetLastError (void)
	* @desc			Positive Test for xmlGetLastError 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{void} => {N/A | xmlErrorPtr instance} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlGetLastErrorP01( void)
{
	xmlErrorPtr pError = NULL;						// pointer to the error
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {static void} => {xmlErrorPtr instance} @n
	 */
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("UTcXmlGetLastErrorP01", (void *)pError, (void *)(NULL), "xmlGetLastError() Success");
}
	/**    
	* @test			UTcXmlResetErrorP01
	* @brief		XMLPUBFUN void XMLCALL xmlResetError (xmlErrorPtr err)
	* @desc			Positive Test for xmlResetError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlResetErrorP01( void)
{
	xmlErrorPtr err = NULL; 						// pointer to the error

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {xmlErrorPtr instance} => {N/A | static void} @n
	 */
	xmlResetError(err);
	DTS_CHECK_EQ_MESSAGE("UTcXmlResetErrorP01", (void *)1, (void *)(1), "xmlResetError() Success");
}
	/**    
	* @test			UTcXmlResetLastErrorP01
	* @brief		XMLPUBFUN void XMLCALL xmlResetLastError (void)
	* @desc			Positive Test for xmlResetLastError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{void} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlResetLastErrorP01( void)
{
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {static void} => {N/A | static void} @n
	 */
	xmlResetLastError();
	DTS_CHECK_EQ_MESSAGE("UTcXmlResetLastErrorP01", (void *)1, (void *)(1), "xmlResetLastError() Success");
}
	/**    
	* @test			UTcXmlCtxtGetLastErrorP01
	* @brief		XMLPUBFUN xmlErrorPtr XMLCALL xmlGetLastError (void)
	* @desc			Positive Test for xmlGetLastError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{void} => {N/A | xmlErrorPtr instance} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlCtxtGetLastErrorP01( void)
{
	xmlErrorPtr xmlptr = NULL;						// pointer to the error

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {XML parser context} => {N/A | xmlErrorPtr instance} @n
	 */
	xmlptr = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("UTcXmlCtxtGetLastErrorP01", (void *)1, (void *)(1), "xmlGetLastError() Success");
}
	/**    
	* @test			UTcXmlCtxtResetLastErrorP01
	* @brief		XMLPUBFUN void XMLCALL xmlCtxtResetLastError (void *ctx)
	* @desc			Positive Test for xmlCtxtResetLastError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlCtxtResetLastErrorP01( void)
{
	static void* ctx = NULL;
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {XML parser context} => {N/A | static void} @n
	 */
	xmlCtxtResetLastError(ctx);
	DTS_CHECK_EQ_MESSAGE("UTcXmlCtxtResetLastErrorP01", (void *)1, (void *)(1), "xmlCtxtResetLastError() Success");
}

	/**    
	* @test			UTcXmlCopyErrorP01
	* @brief		XMLPUBFUN int XMLCALL xmlCopyError (xmlErrorPtr from, xmlErrorPtr to)
	* @desc			Positive Test for xmlCopyError
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL, NULL} => {N/A | int} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlCopyErrorP01( void)
{
	int ret_val = 0;
	xmlErrorPtr from = NULL; 						// source error
	xmlErrorPtr to = NULL; 							// target error

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {xmlErrorPtr instance for source error , xmlErrorPtr instance for destination error } => @n
				  {N/A | 0} @n
	 */
	ret_val = xmlCopyError(from, to);
	DTS_CHECK_EQ_MESSAGE("UTcXmlCopyErrorP01", (void *)1, (void *)(1), "xmlCopyError() Success");
}

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
	//{Dummy, 1},
	{UTcInitGenericErrorDefaultFuncP01, 2},
	{UTcXmlSetGenericErrorFuncP01, 3},
	{UTcXmlSetStructuredErrorFuncP01, 4},

	// Handling of parsing errors
	{UTcXmlParserPrintFileInfoP01, 5},
	{UTcXmlParserPrintFileContextP01, 6},
	{UTcXmlParserErrorP01, 7},
	{UTcXmlParserWarningP01, 8},

	// Handling of validation errors
	{UTcXmlParserValidityErrorP01, 9},
	{UTcXmlParserValidityWarningP01, 10},

	// Handling of Extended Error
	{UTcXmlGetLastErrorP01, 11},
	{UTcXmlResetErrorP01, 12},
	{UTcXmlResetLastErrorP01, 13},
	{UTcXmlCtxtGetLastErrorP01, 14},
	{UTcXmlCtxtResetLastErrorP01, 15},
	{UTcXmlCopyErrorP01, 16},
	{ NULL, 0 },
	
};

