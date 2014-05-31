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


#define INPUT_XML	LIBXML2TESTXML
#define INPUT_TXT	IOTESTTXT
#define INPUTIO_TXT IOTEST1TXT

int 
writeFunction (void * context, const char * buffer, int len)
{
	//Dummy Callbacks for registration
	return 0;
}

int 
closeFunction (void * context)
{
	//Dummy Callbacks for registration
	return 0;
}

int 
readFunction (void * context, char * buffer, int len)
{
	//Dummy Callbacks for registration
	return 0;
}

int 
matchFunction (char const *filename)
{
	//Dummy Callbacks for registration
	return 0;
}

void *
openFunction (char const *filename)
{
	//Dummy Callbacks for registration
	return NULL;
}

// namespace
//using namespace Osp::Base;

#ifdef LIBXML_XINCLUDE_ENABLED
/**    
	* @test			UTcxmlIOP01
	* @brief		int	xmlXIncludeProcess	(xmlDocPtr doc)
	* @desc			Positive Test for implementing the XInclude substitution on the XML document @doc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Read Xml File, Free Doc] @n
	*   			{xmlDocPtr(doc)} => { N/A |0 or -1} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlIOP01()
{
	xmlDocPtr doc;
	int resultOp;

	xmlRegisterDefaultInputCallbacks();
    	doc = xmlReadFile(INPUT_XML, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlReadFile", (void *)doc, (void *)NULL, "xmlReadFile Failed");
	resultOp = xmlXIncludeProcess(doc);
	DTS_CHECK_GTE_MESSAGE("xmlReadFile", (void *)resultOp, (void *)0, "xmlXIncludeProcess Failed");
	xmlFreeDoc(doc);
    xmlCleanupParser();
    xmlMemoryDump();
}
#endif
/**    
	* @test			UTcxmlIOP02
	* @brief		int xmlSaveFile (const char * filename, xmlDocPtr cur)
	* @desc			Positive Test for Dumping an XML document to a file
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Read the file, Free the doc] @n
	*   			{xmlDocPtr(cur), const char *(filename)} => {N/A | Number of bytes written} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlIOP02()
{
    xmlDocPtr		doc = NULL;
   
    /*
    * Create the document.
    */
	doc = xmlReadFile(INPUT_XML, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlReadFile", (void *)doc, (void *)NULL, "xmlReadFile Failed");
	int data = xmlSaveFile(INPUT_TXT, doc);
	DTS_CHECK_GT_MESSAGE("xmlReadFile", (void *)data, (void *)0, "xmlSaveFile Failed");
   
    /*
    * Free associated memory.
    */
    xmlFreeDoc(doc);
}
/**    
	* @test			UTcxmlIOP03
	* @brief		int xmlParserInputBufferRead (xmlParserInputBufferPtr in, int len)
	* @desc			Positive Test for refreshing the content of the input buffer, the old data are considered consumed This routine handle the I18N transcoding to internal UTF-8
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create a buffer parser input, Free parser input buffer] @n
	*   			{xmlParserInputBufferPtr(in), int(len)} => {N/A | Number of chars read or stored in the buffer} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlIOP03()
{
    int						retval = 0;
    xmlParserInputBufferPtr input; 

    input = xmlParserInputBufferCreateFilename(INPUT_XML, XML_CHAR_ENCODING_NONE);
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateFilename", (void *)input, (void *)0, "xmlParserInputBufferCreateFilename Failed");
	
	retval = xmlParserInputBufferRead(input, 1);
	DTS_CHECK_GT_MESSAGE("xmlParserInputBufferRead", (void *)retval, (void *)0, "xmlParserInputBufferRead Failed");
	

	xmlFreeParserInputBuffer(input);
}

	/**    
	* @test			UTcxmlIOP04
	* @brief		void xmlSetExternalEntityLoader	(xmlExternalEntityLoader f)
	* @desc			Positive Test for Changing the defaultexternal entity resolver function for the application
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Get the entity loader, N/A] @n
	*   			{xmlExternalEntityLoader(f)} => {N/A | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlIOP04()
{
	xmlExternalEntityLoader defaultLoader = NULL;

	defaultLoader = xmlGetExternalEntityLoader();
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferRead", (void *)defaultLoader, (void *)NULL, "xmlParserInputBufferRead Failed");
	xmlSetExternalEntityLoader(defaultLoader);
}

#ifdef STDIO_FILE
static void
UTcxmlIOP05()
{
	// Source fix needs to be done: other wise its crashes

	FILE *		pFptr = NULL;

	pFptr = fopen(INPUT_TXT, "w+");
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateFd", (void *)pFptr, (void *)NULL, "fopen Failed");
	
	xmlParserInputBufferPtr pBuffer = xmlParserInputBufferCreateFd((int)pFptr, XML_CHAR_ENCODING_UTF8);
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateFd", (void *)pBuffer, (void *)NULL, "xmlParserInputBufferCreateFd Failed");

	xmlOutputBufferPtr pOutBuffer = xmlOutputBufferCreateFd((int)pFptr, NULL);
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateFd", (void *)pBuffer, (void *)NULL, "xmlParserInputBufferCreateFd Failed");
	
	int retval = xmlOutputBufferClose(pOutBuffer);

    	xmlFreeParserInputBuffer(pBuffer);

	//File_close(pFptr, &e);
}
#endif
/**    
	* @test			UTcxmlIOP06
	* @brief		xmlCharEncodingHandlerPtr	xmlGetCharEncodingHandler	(xmlCharEncoding enc)
					xmlOutputBufferPtr xmlOutputBufferCreateIO	(xmlOutputWriteCallback iowrite, xmlOutputCloseCallback ioclose, void * ioctx, xmlCharEncodingHandlerPtr encoder)
					xmlParserInputBufferPtr	xmlParserInputBufferCreateIO	(xmlInputReadCallback ioread, xmlInputCloseCallback ioclose, void * ioctx, xmlCharEncoding enc)
	* @desc			Positive Test for Searching in the registered set the handler able to read/write that encoding.
					Positive test for Creating a buffered output for the progressive saving to an I/O handler
					Positive test for Creating a buffered parser input for the progressive parsing for the input from an I/O handler
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Initialize and register encoding handlers, Free parser input buffer] @n
	*   			{xmlCharEncoding(enc)} => {N/A | N/A} @n
					input2: [Initialize and register encoding handlers, Free parser input buffer] @n
	*   			{xmlOutputWriteCallback(iowrite), xmlOutputCloseCallback(ioclose), xmlCharEncodingHandlerPtr(encoder)} => {N/A | N/A} @n
					input3: [Initialize and register encoding handlers, Free parser input buffer] @n
	*   			{xmlInputReadCallback(ioread), xmlOutputCloseCallback(ioclose), XML_CHAR_ENCODING_UTF8(xmlCharEncoding (enc))} => {N/A | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlIOP06()
{
	xmlOutputWriteCallback outwrite;
	xmlOutputCloseCallback outclose;
	xmlInputReadCallback   inread;

	outwrite = writeFunction;
	outclose = closeFunction;
	inread = readFunction;
 	xmlInitCharEncodingHandlers();
	xmlRegisterCharEncodingHandler(NULL);
	xmlCharEncodingHandlerPtr pHandler = xmlGetCharEncodingHandler(XML_CHAR_ENCODING_UTF16LE);
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateIO", (void *)pHandler, (void *)NULL, "xmlGetCharEncodingHandler Failed");

	xmlOutputBufferPtr pBuf = xmlOutputBufferCreateIO(outwrite, outclose, NULL, pHandler);
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateIO", (void *)pBuf, (void *)NULL, "xmlParserInputBufferCreateIO Failed");

	xmlParserInputBufferPtr pInputBuf = xmlParserInputBufferCreateIO(inread, outclose, NULL, XML_CHAR_ENCODING_UTF8);
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateIO", (void *)pInputBuf, (void *)NULL, "xmlParserInputBufferCreateIO Failed");
	
	xmlFreeParserInputBuffer(pInputBuf);
	int retval = xmlOutputBufferClose(pBuf);

	//xmlCleanupCharEncodingHandlers();
}
/**    
	* @test			UTcxmlPopInputCallbacksP01
	* @brief		int	xmlPopInputCallbacks (void)
	* @desc			Positive Test for Clearing the top input callback from the input stack
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Register one input callback, N/A] @n
	*				{ void } => { N/A | 1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlPopInputCallbacksP01()
{
	xmlOutputCloseCallback	outclose;
	xmlInputReadCallback	inread;
	xmlInputMatchCallback	match;
	xmlInputOpenCallback	inopen;

	outclose = closeFunction;
	inread = readFunction;
	match = matchFunction;
	inopen = openFunction;

	xmlRegisterDefaultInputCallbacks();
	int resultVal = xmlRegisterInputCallbacks(match, inopen, inread, outclose);
	DTS_CHECK_GT_MESSAGE("xmlPopInputCallbacks", (void *)resultVal, (void *)0, "xmlRegisterInputCallbacks Failed");

	/**
	* @remarks   input1: [Register one input callback, N/A] @n
	*            { void } => { N/A | 1 } @n
	*/
	resultVal = xmlPopInputCallbacks();
	DTS_CHECK_EQ_MESSAGE("xmlPopInputCallbacks", (void *)resultVal, (void *)4, "xmlPopInputCallbacks Failed");
}
/**    
	* @test			UTcxmlOutputBufferCreateFilenameP01
	* @brief		xmlOutputBufferPtr xmlOutputBufferCreateFilename (const char * URI, xmlCharEncodingHandlerPtr encoder, int compression)
	* @desc			Positive Test for Creating a buffered output for the progressive saving of a file If filename is "-' then we use stdout as the output
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*				{const char *( UTSXMLHOME"/IoTest1.txt"), NULL, int(0) } => { N/A | xmlOutputBufferPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlOutputBufferCreateFilenameP01()
{

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { INPUTIO_TXT, NULL, 0 } => { N/A | xmlOutputBufferPtr pointer } @n
	*/
	xmlOutputBufferPtr pBuffer =  xmlOutputBufferCreateFilename(INPUTIO_TXT, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlPopInputCallbacks", (void *)pBuffer, (void *)NULL, "xmlPopInputCallbacks Failed");
	
	int retval = xmlOutputBufferClose(pBuffer);
	xmlResetLastError();
}
/**    
	* @test			UTcxmlParserInputBufferCreateStaticP01
	* @brief		xmlParserInputBufferPtr	xmlParserInputBufferCreateStatic (const char * mem, int size, xmlCharEncoding enc)
	* @desc			Positive Test for Creating a buffered parser input for the progressive parsing for the input from an immutable memory area
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*			    { const char * ("name"), int(4), int(1) } => { N/A | xmlParserInputBufferPtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlParserInputBufferCreateStaticP01()
{
	char *pName = "name";

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { "name", 4, XML_CHAR_ENCODING_UTF8 } => { N/A | xmlParserInputBufferPtr pointer } @n
	*/
	xmlParserInputBufferPtr pBuffer = xmlParserInputBufferCreateStatic(pName, sizeof(pName), XML_CHAR_ENCODING_UTF8);
	DTS_CHECK_NE_MESSAGE("xmlParserInputBufferCreateStatic", (void *)pBuffer, (void *)NULL, "xmlParserInputBufferCreateStatic Failed");
	
	xmlFreeParserInputBuffer(pBuffer);

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
	#ifdef LIBXML_XINCLUDE_ENABLED
  	{UTcxmlIOP01, 1},
	#endif
   	{UTcxmlIOP02,2},
   	{UTcxmlIOP03,3},
   	{UTcxmlIOP04,4},
   	#ifdef STDIO_FILE
	{UTcxmlIOP05,5},
	#endif
   	{UTcxmlIOP06,6},
   	{UTcxmlPopInputCallbacksP01,7},
   	{UTcxmlOutputBufferCreateFilenameP01,8},
  	{UTcxmlParserInputBufferCreateStaticP01,9},
	{ NULL, 0 },
	
};
