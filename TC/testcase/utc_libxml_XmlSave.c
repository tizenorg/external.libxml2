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
#include "libxml/xmlsave.h"




#ifdef DEBUG_MEM_LEAK
extern "C" {
	extern void MemStartSaveCallStack(void);
	extern void MemEndSaveCallStack(void);
	extern void MemPrintCurrentIndex(void);
	extern void MemTraceAllocMemInfo(void);
}
#endif




static void
__Cleanup(xmlDocPtr doc)
{
	/* free up the resulting document */
	xmlFreeDoc(doc);
}



static int
__Escape(unsigned char * out, int * outlen, const unsigned char * in, int * inlen)
{
	//As of now do nothing, added for coverage
	//Callback, would be called when saving element/attribute fails for some reason
	return 0;
}



static int
__IOwrite(void * context, const char * buffer, int len)
{
	int length = 0;
	int result = -1;
	length = fwrite( buffer, 1, len  ,(FILE *)context);
	if(length == len)
		return 1;
	else 
		return -1;
}



static int
__IOclose(void * context)
{
	return fclose( (FILE *) context);
}


	/**    
	* @test			UTcXmlSaveFileP01
	* @brief		int xmlSaveFile (const char * filename, xmlDocPtr cur)
	* @desc			Positive Test for dump an XML document to a file.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const char *(UTSXMLHOME"/OP_XmlSaveFile.txt"), XmlDocPtr(cur)} => {N/A | Number of bytes written to file} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveFileP01()
{
	const char *pFilename = LIBXML2TESTXML;
	const char *pOpfilename = UTSHOME"/OP_XmlSaveFile.txt";
	xmlDocPtr doc; /* the resulting document tree used as Input */
	int result = -1;

	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	//LIBXML_TEST_VERSION

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlReadFile", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {"/Home/SUTsXml/OP_XmlSaveFile.txt", XmlDocPtr} => {N/A | Number of bytes written to file} @n
	*/	
	result = xmlSaveFile(pOpfilename, doc);
	DTS_CHECK_NE_MESSAGE("xmlReadFile", (void *)result, (void *)-1, "xmlReadFile Failed");

	__Cleanup(doc);

	//delete pFilename;
	//delete pOpfilename;
}
	/**    
	* @test			UTcXmlSaveFileToP01
	* @brief		int xmlSaveFileTo (xmlOutputBufferPtr buf, xmlDocPtr cur, const char * encoding)
	* @desc			Positive Test for dump an XML document to an I/O buffer
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlOutputBufferPtr(buf), XmlDocPtr(cur), const char *("UTF-8")} => {N/A | Number of bytes written to buffer}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveFileToP01()
{
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = "UTF-8";
	int result = -1;

	xmlOutputBufferPtr opBuf; /*The Output buffer to be used*/
	xmlDocPtr doc; /* the resulting document tree used as i/p*/



	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveFileTo", (void *)doc, (void *)NULL, "xmlReadFile Failed");
	

	opBuf = xmlOutputBufferCreateFilename(UTSHOME"/XmlSaveFileTo.txt", NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveFileTo", (void *)opBuf, (void *)NULL, "xmlOutputBufferCreateFilename Failed");
	

	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {XML Output buffer, XmlDocPtr, "UTF-8"} => {N/A | Number of bytes written to buffer}	@n
	*/	
	result = xmlSaveFileTo(opBuf, doc, pEncoding);
	DTS_CHECK_NE_MESSAGE("xmlSaveFileTo", (void *)result, (void *)-1, "xmlSaveFileTo Failed");
	

	__Cleanup(doc);
	//delete pFilename;	
}
	/**    
	* @test			UTcXmlSaveFormatFileP01
	* @brief		int xmlSaveFormatFile (const char * filename, xmlDocPtr cur, int format)
	* @desc			Positive Test for dumping an XML document to a file
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const char *(UTSXMLHOME"/OP_XmlSaveFormatFile.txt"), XmlDocPtr(cur), int(1)} => {N/A | Number of bytes written to file}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveFormatFileP01()
{
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;
	const char *pOpfilename = UTSHOME"/OP_XmlSaveFormatFile.txt";
	xmlDocPtr doc; /* the resulting document tree used as i/p*/
	int result = -1;
	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION


	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveFormatFile", (void *)doc, (void *)NULL, "xmlReadFile Failed");
	
	xmlKeepBlanksDefault(0);

	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {"/Home/SUTsXml/OP_XmlSaveFormatFile.txt", XmlDocPtr, 1} => {N/A | Number of bytes written to file}	@n
	*/	
	result = xmlSaveFormatFile(pOpfilename, doc, 1);	
	DTS_CHECK_NE_MESSAGE("xmlSaveFormatFile", (void *)result, (void *)-1, "xmlSaveFormatFile Failed");
	
	__Cleanup(doc);
	//delete pFilename;	
	//delete pOpfilename;
}
	/**    
	* @test			UTcXmlSaveFormatFileToP01
	* @brief		int xmlSaveFormatFileTo (xmlOutputBufferPtr buf, xmlDocPtr cur, const char * encoding, int format)
	* @desc			Positive Test for dumping an XML document to an I/O buffer
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlOutputBufferPtr(cur), XmlDocPtr(cur), NULL, int(1)} => {N/A | Number of bytes written to buffer}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveFormatFileToP01()
{
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;
	int result = -1;

	xmlDocPtr doc; /* the document tree used as input */
	xmlOutputBufferPtr opBuf; /*The Output buffer to be used*/

	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION


	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveFormatFileTo", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	opBuf = xmlOutputBufferCreateFilename(UTSHOME"/XmlSaveFormatFileTo.txt", NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveFormatFileTo", (void *)opBuf, (void *)NULL, "xmlReadFile Failed");

	xmlKeepBlanksDefault(0);
	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {XML O/P buffer, XmlDocPtr, NULL, 1} => {N/A | Number of bytes written to buffer}	@n
	*/	
	result = xmlSaveFormatFileTo(opBuf, doc, pEncoding, 1);	
	DTS_CHECK_NE_MESSAGE("xmlSaveFormatFileTo", (void *)result, (void *)-1, "xmlSaveFormatFileTo Failed");

	__Cleanup(doc);
	//delete pFilename;	
}
	/**    
	* @test			UTcXmlSaveFileEncP01
	* @brief		int xmlSaveFileEnc (const char * filename, xmlDocPtr cur, const char * encoding)
	* @desc			Positive Test for dumping an XML document, converting it to the given encoding
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const char *(UTSXMLHOME"/OP_XmlSaveFileEnc.txt)", xmlDocPtr(cur), NULL} => {N/A | Number of bytes written to file}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveFileEncP01()
{
	const char *pFilename = LIBXML2TESTXML;
	const char *pOpfilename = UTSHOME"/OP_XmlSaveFileEnc.txt";
	const char *pEncoding = NULL;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/
	int result = -1;

	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION




	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveFileEnc", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {"/Home/SUTsXml/OP_XmlSaveFileEnc.txt", xmlDocPtr, NULL} => {N/A | Number of bytes written to file}	@n
	*/	
	result = xmlSaveFileEnc(pOpfilename, doc, pEncoding);
	DTS_CHECK_NE_MESSAGE("xmlSaveFileEnc", (void *)result, (void *)-1, "xmlSaveFileEnc Failed");
	
	__Cleanup(doc);
	//delete pFilename;
	//delete pOpfilename;
}


	/**    
	* @test			UTcXmlSaveTreeP01
	* @brief		long xmlSaveTree (xmlSaveCtxtPtr ctxt, xmlNodePtr node)
	* @desc			Positive Test for creating a document saving context serializing to a file descriptor with the encoding and the options given
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlSaveCtxtPtr(ctxt), Pointer to node of XML tree(xmlNodePtr(node)} => {N/A | Number of bytes written}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveTreeP01()
{
	const char *pOpfilename = UTSHOME"/OP_XmlSaveTree.txt";
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;
	int result = -1;
	xmlSaveCtxtPtr ctxtPtr;
	xmlNodePtr nodePtr;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/


	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION

	ctxtPtr = xmlSaveToFilename(pOpfilename, pEncoding, 1);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)ctxtPtr, (void *)NULL, "xmlSaveToFilename Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	nodePtr = xmlDocGetRootElement(doc);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)nodePtr, (void *)NULL, "xmlDocGetRootElement Failed");

	nodePtr = nodePtr->xmlChildrenNode;
	while (nodePtr != NULL) {
		if (0 == (xmlStrcmp(nodePtr->name, (const xmlChar *)"TO"))) {
			break;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {xmlSaveCtxtPtr, Pointer to node of XML tree} => {N/A | Number of bytes written}	@n
	*/	
	result = xmlSaveTree(ctxtPtr, nodePtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)result, (void *)-1, "xmlSaveTree Failed");


	result = xmlSaveClose(ctxtPtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)result, (void *)-1, "xmlSaveClose Failed");

	__Cleanup(doc);
	//delete pOpfilename;
	//delete pFilename;
}
	/**    
	* @test			UTcXmlSaveDocP01
	* @brief		long xmlSaveDoc (xmlSaveCtxtPtr ctxt, xmlDocPtr doc)
	* @desc			Positive Test for saving a full document to a saving context TODO: The function is not fully implemented yet as it does not return the byte count but 0 instead
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlSaveCtxtPtr(ctxt), xmlDocPtr(doc)} => {N/A | Number of bytes written}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveDocP01()
{
	const char *pOpfilename = UTSHOME"/OP_XmlSaveDoc.txt";
	const char *pEncoding = NULL;
	const char *pFilename = LIBXML2TESTXML;
	int result = -1;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/
	xmlSaveCtxtPtr ctxtPtr;

	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION

	ctxtPtr = xmlSaveToFilename(pOpfilename, pEncoding, 1);
	DTS_CHECK_NE_MESSAGE("xmlSaveDoc", (void *)ctxtPtr, (void *)NULL, "xmlSaveToFilename Failed");



	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveDoc", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	/**
	* @remarks   input1: [N/A, N/A]	@n
	*					{xmlSaveCtxtPtr, xmlDocPtr} => {N/A | Number of bytes written}	@n
	*/	
	result = xmlSaveDoc(ctxtPtr, doc);
	DTS_CHECK_NE_MESSAGE("xmlSaveDoc", (void *)result, (void *)-1, "xmlSaveDoc Failed");

	result = xmlSaveClose(ctxtPtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveDoc", (void *)result, (void *)-1, "xmlSaveClose Failed");

	__Cleanup(doc);
	//delete pOpfilename;
	//delete pFilename;
}

	/**    
	* @test			UTcXmlNodeDumpP01
	* @brief		int xmlNodeDump (xmlBufferPtr buf, xmlDocPtr doc, xmlNodePtr cur,int level,int format)
	* @desc			Positive Test for dumping an XML node, recursive behaviour,children are printed too
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlBufferPtr(buf), xmlDocPtr(doc), xmlNodePtr(cur), int(level), int(format)} => {N/A | Number of bytes written}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlNodeDumpP01()
{

	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;
	int result = -1;
	xmlNodePtr nodePtr;
	xmlNodePtr tempNodePtr; // For memory leak fixes (MemLeakFix)
	xmlDocPtr doc; /* the document tree used as input */
	xmlBufferPtr buf;
	xmlOutputBufferPtr opBuf; /*The Output buffer to be used*/
	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION


	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlNodeDump", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	nodePtr = xmlDocGetRootElement(doc);
	DTS_CHECK_NE_MESSAGE("xmlNodeDump", (void *)nodePtr, (void *)NULL, "xmlDocGetRootElement Failed");
	tempNodePtr = nodePtr; 

	nodePtr = nodePtr->xmlChildrenNode;  
	
	while (nodePtr != NULL) {
		if (0 == (xmlStrcmp(nodePtr->name, (const xmlChar *)"BODY"))) {
			break;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	xmlKeepBlanksDefault(0);

	buf = xmlBufferCreate();
	DTS_CHECK_NE_MESSAGE("xmlNodeDump", (void *)buf, (void *)NULL, "xmlBufferCreate Failed");

	opBuf = xmlOutputBufferCreateFilename(UTSHOME"/XmlNodeDumpOutput.txt", NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlNodeDump", (void *)opBuf, (void *)NULL, "xmlOutputBufferCreateFilename Failed");

	// xmlNodeDump
	result = xmlNodeDump(buf, doc, nodePtr, 2, 1);
	DTS_CHECK_NE_MESSAGE("xmlNodeDump", (void *)result, (void *)-1, "xmlNodeDump Failed");

	// xmlNodeDumpOutput
	xmlNodeDumpOutput(opBuf, doc, nodePtr, 2, 1, pEncoding);


	xmlBufferFree(buf); //MemLeakFix
//	xmlFreeNodeList(tempNodePtr); //MemLeakFix
	result = xmlOutputBufferClose(opBuf); //MemLeakFix
	DTS_CHECK_NE_MESSAGE("xmlNodeDump", (void *)result, (void *)-1, "xmlOutputBufferClose Failed");
	
	__Cleanup(doc);
	//delete pFilename;	

}
	/**    
	* @test			UTcXmlDocDumpMemoryP01
	* @brief		void xmlDocDumpMemory (xmlDocPtr cur, xmlChar ** mem, int * size)
					void xmlDocDumpMemoryEnc (xmlDocPtr out_doc, xmlChar ** doc_txt_ptr, int * doc_txt_len, const char * txt_encoding)
					void	xmlDocDumpFormatMemory	(xmlDocPtr cur, xmlChar ** mem, int * size, int format)
					void	xmlDocDumpFormatMemoryEnc (xmlDocPtr out_doc, xmlChar ** doc_txt_ptr, int * doc_txt_len, const char * txt_encoding, int format)
	* @desc			Positive Test for dumping an XML document in memory and return the #xmlChar * and it's size in bytes
					Positive Test for Dumping the current DOM tree into memory using the character encoding specified by the caller
					Positive Test for Dumping an XML document in memory and return the #xmlChar * and it's size
					Positive Test for Dumping the current DOM tree into memory using the character encoding specified by the caller
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlChar *(mem), xmlDocPtr(doc), int(size)} => {N/A | Number of bytes written}	@n
					input2: [N/A, N/A] @n
	*   			{xmlChar *(mem), xmlDocPtr(out_doc), const char * (txt_encoding), int *(doc_txt_len)} => {N/A | Number of bytes written}	@n
					input3: [N/A, N/A] @n
	*   			{xmlChar *(mem), xmlDocPtr(cur), int(size), int(format)} => {N/A | Number of bytes written}	@n
					input4: [N/A, N/A] @n
	*   			{xmlChar *(mem), xmlDocPtr(out_doc), const char *(doc_txt_ptr), int(doc_txt_len), const char * txt_encoding, int(format)} => {N/A | Number of bytes written}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlDocDumpMemoryP01()
{
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;
	int result = -1;
	xmlDocPtr doc; /* the document tree used as input */
	xmlChar* pXmlArray = NULL;


	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION


	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlDocDumpMemory", (void *)doc, (void *)NULL, "xmlReadFile Failed");


	// xmlDocDumpMemory
	xmlDocDumpMemory(doc, &pXmlArray, &result);
	DTS_CHECK_NE_MESSAGE("xmlDocDumpMemory", (void *)result, (void *)-1, "xmlDocDumpMemory Failed");
	xmlFree(pXmlArray);

	// xmlDocDumpMemoryEnc
	result = -1;
	xmlDocDumpMemoryEnc(doc, &pXmlArray, &result, pEncoding);
	DTS_CHECK_NE_MESSAGE("xmlDocDumpMemory", (void *)result, (void *)-1, "xmlDocDumpMemoryEnc Failed");
	xmlFree(pXmlArray);



	// xmlDocDumpFormatMemory
	result = -1;
	xmlDocDumpFormatMemory(doc, &pXmlArray, &result, 1);
	DTS_CHECK_NE_MESSAGE("xmlDocDumpMemory", (void *)result, (void *)-1, "xmlDocDumpFormatMemory Failed");
	xmlFree(pXmlArray);


	// xmlDocDumpFormatMemoryEnc
	result = -1;
	xmlDocDumpFormatMemoryEnc(doc, &pXmlArray, &result, pEncoding, 1);
	DTS_CHECK_NE_MESSAGE("xmlDocDumpMemory", (void *)result, (void *)-1, "xmlDocDumpFormatMemoryEnc Failed");
	xmlFree(pXmlArray);
	__Cleanup(doc);
	//delete pFilename;	
}

/**    
* @test			UTcXmlDocDumpP01
* @brief		int xmlDocDump (FILE * f, xmlDocPtr cur)
* @desc			Positive Test for Dumping an XML document to an open FILE.
* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
* @b tester		Michel Anthony (michelj@samsung.com)
* @return		void
* @see			none
* @remarks		input1: [N/A, N/A]	@n
*				{FILE* (f), xmlDocPtr(cur)} => {N/A | Number of bytes written}	@n
* @b priority	Middle
* @b etc		none
*/
static void
UTcXmlDocDumpP01()
{
	FILE* fPtr = NULL;
	int result = -1;
	xmlDocPtr doc; /* the document tree used as input */
	const char *pFilename = LIBXML2TESTXML;

	fPtr = fopen(UTSXMLHOME"/XmlDocDump.txt", "w+");
	DTS_CHECK_NE_MESSAGE("xmlDocDump", (void *)fPtr, (void *)NULL, "fopen Failed");	

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlDocDump", (void *)doc, (void *)NULL, "xmlReadFile Failed");	

	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {FILE*, xmlDocPtr} => {N/A | Number of bytes written}	@n
	*/	
	result = xmlDocDump(fPtr, doc);
	DTS_CHECK_NE_MESSAGE("xmlDocDump", (void *)result, (void *)-1, "xmlDocDump Failed");
	__Cleanup(doc);
	result = fclose(fPtr);
	DTS_CHECK_EQ_MESSAGE("xmlDocDump", (void *)result, (void *)0, "fclose Failed");
	
}
/**    
* @test			UTcXmlElemDumpP01
* @brief		void xmlElemDump (FILE * f, xmlDocPtr doc, xmlNodePtr cur)
* @desc			Positive Test for Dumping an XML/HTML node, recursive behaviour, children are printed too
* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
* @b tester		Michel Anthony (michelj@samsung.com)
* @return		void
* @see			none
* @remarks		input1: [N/A, N/A]	@n
*				{FILE*(f), xmlDocPtr(doc), Pointer to node of XML tree(xmlNodePtr(cur)} => {N/A | N/A}	@n
* @b priority	Middle
* @b etc		none
*/
static void
UTcXmlElemDumpP01()
{
	FILE* fPtr = NULL;
	int result = -1;
	xmlDocPtr doc; /* the document tree used as input */
	xmlNodePtr nodePtr;

	const char *pFilename = LIBXML2TESTXML;

	fPtr = fopen(UTSXMLHOME"/XmlDocDump.txt", "w+");
	DTS_CHECK_NE_MESSAGE("xmlDocDump", (void *)fPtr, (void *)NULL, "fopen Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlElemDump", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	nodePtr = xmlDocGetRootElement(doc);
	DTS_CHECK_NE_MESSAGE("xmlElemDump", (void *)nodePtr, (void *)NULL, "xmlDocGetRootElement Failed");

	nodePtr = nodePtr->xmlChildrenNode;
	while (nodePtr != NULL) {
		if (0 == (xmlStrcmp(nodePtr->name, (const xmlChar *)"SIGN"))) {
			break;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}
	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {FILE*, xmlDocPtr, Pointer to node of XML tree} => {N/A | N/A}	@n
	*/	
	xmlElemDump(fPtr, doc, nodePtr);


	__Cleanup(doc);
	result = fclose(fPtr);
	DTS_CHECK_EQ_MESSAGE("xmlDocDump", (void *)result, (void *)0, "fclose Failed");
}
	/**    
	* @test			UTcXmlSaveSetEscapeP01
	* @brief		int xmlSaveSetEscape (xmlSaveCtxtPtr ctxt, CharEncodingOutputFunc escape)
					int xmlSaveSetAttrEscape (xmlSaveCtxtPtr ctxt, xmlCharEncodingOutputFunc escape)
					long xmlSaveTree (xmlSaveCtxtPtr ctxt, xmlNodePtr node)
					int	xmlSaveClose			(xmlSaveCtxtPtr ctxt)
	* @desc			Positive Test for Setting a custom escaping function to be used for text in element content
					Positive Test for Setting a custom escaping function to be used for text in attribute content
					Positive test for Saving a subtree starting at the node parameter to a saving context TODO
					Positive test for closing a document saving context
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlSaveCtxtPtr(ctxt), escaping function(CharEncodingOutputFunc(escape)} => {0 or -1 | N/A} @n
					input2: [N/A, N/A] @n
	*   			{xmlSaveCtxtPtr(ctxt), escaping function(xmlCharEncodingOutputFunc(escape)} => {0 or -1 | N/A} @n
					input3: [N/A, N/A] @n
					{xmlSaveCtxtPtr(ctxt), Pointer to node of XML tree(xmlNodePtr(node)} => {N/A | Number of bytes written}	@n
					input4: [N/A, N/A] @n
	*   			{xmlSaveCtxtPtr(ctxt)} => {N/A | 0 or -1} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveSetEscapeP01()
{
	const char *pOpfilename = UTSHOME"/OP_XmlSaveSetEscape.txt";
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;
	int result = -1;
	xmlSaveCtxtPtr ctxtPtr;
	xmlNodePtr nodePtr;
	xmlNodePtr tempNodePtr;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/


	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION

	ctxtPtr = xmlSaveToFilename(pOpfilename, pEncoding, 1);
	DTS_CHECK_NE_MESSAGE("xmlSaveSetEscape", (void *)ctxtPtr, (void *)NULL, "xmlSaveToFilename Failed");
	

	result = xmlSaveSetEscape(ctxtPtr, __Escape);
	DTS_CHECK_EQ_MESSAGE("xmlSaveSetEscape", (void *)result, (void *)0, "xmlSaveSetEscape Failed");

	result = xmlSaveSetAttrEscape(ctxtPtr, __Escape);
	DTS_CHECK_EQ_MESSAGE("xmlSaveSetEscape", (void *)result, (void *)0, "xmlSaveSetAttrEscape Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveSetEscape", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	nodePtr = xmlDocGetRootElement(doc);
	tempNodePtr = nodePtr;
	DTS_CHECK_NE_MESSAGE("xmlSaveSetEscape", (void *)nodePtr, (void *)NULL, "xmlDocGetRootElement Failed");

	nodePtr = nodePtr->xmlChildrenNode;
	while (nodePtr != NULL) {
		if (0 == (xmlStrcmp(nodePtr->name, (const xmlChar *)"TO"))) {
			break;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	result = xmlSaveTree(ctxtPtr, nodePtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveSetEscape", (void *)result, (void *)-1, "xmlSaveTree Failed");

	result = xmlSaveClose(ctxtPtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveSetEscape", (void *)result, (void *)-1, "xmlSaveClose Failed");


	//xmlFreeNodeList(tempNodePtr);
	__Cleanup(doc);
	//delete pOpfilename;
	//delete pFilename;
}
	/**    
	* @test			UTcXmlSaveToIOP01
	* @brief		xmlSaveCtxtPtr	xmlSaveToIO (xmlOutputWriteCallback iowrite, xmlOutputCloseCallback ioclose, void * ioctx, const char * encoding, int options)
	* @desc			Positive Test for Creating a document saving context serializing to a file descriptor with the encoding and the options given
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlOutputWriteCallback(iowrite) , xmlOutputCloseCallback(ioclose), File Pointer, NULL, int(1) } => {N/A | xmlSaveCtxtPtr pointer}	@n	
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlSaveToIOP01()
{
	const char *pOpfilename = UTSXMLHOME"/OP_XmlSaveTree.txt";
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;

	FILE * fPtr = NULL;
	int ret = -1;
	xmlSaveCtxtPtr ctxtPtr;
	xmlNodePtr nodePtr;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/

	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	//LIBXML_TEST_VERSION


	//fPtr = File_open("/Home/SUTsXml/XmlSaveToIO.txt", "w+", &e);
	xmlRegisterDefaultOutputCallbacks();

	//fPtr = (FILE *)xmlFileOpen("/Home/SUTsXml/XmlSaveToIO.txt");

	fPtr = fopen(UTSHOME"/XmlSaveToIO.txt", "w+");
	if(fPtr == NULL) {
		DTS_FAIL("xmlSaveToIO", "No memory");		
		return;
	}
	/**
	* @remarks   input1: [N/A, N/A]	@n
	* {xmlOutputWriteCallback , xmlOutputCloseCallback, File Pointer, NULL, 1 } => {N/A | xmlSaveCtxtPtr pointer}	@n
	*/	
	ctxtPtr = xmlSaveToIO(__IOwrite, __IOclose, fPtr, pEncoding, 1);
	DTS_CHECK_NE_MESSAGE("xmlSaveToIO", (void *)ctxtPtr, (void *)NULL, "xmlSaveToIO Failed");	

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveToIO", (void *)doc, (void *)NULL, "xmlReadFile Failed");	

	nodePtr = xmlDocGetRootElement(doc);
	DTS_CHECK_NE_MESSAGE("xmlSaveToIO", (void *)nodePtr, (void *)NULL, "xmlDocGetRootElement Failed");

	nodePtr = nodePtr->xmlChildrenNode;
	while (nodePtr != NULL) {
		if (0 == (xmlStrcmp(nodePtr->name, (const xmlChar *)"TO"))) {
			break;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	ret = xmlSaveTree(ctxtPtr, nodePtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveToIO", (void *)ret, (void *)-1, "xmlSaveTree Failed");


	//result = xmlSaveFlush(ctxtPtr);
	//MT_CHECK_MESSAGE2(-1 != result,"A non-negative number is expected, actual = %d", result);

	if (NULL != ctxtPtr)
	{
		xmlSaveClose(ctxtPtr);
	}

	__Cleanup(doc);
}


static void
UTcXmlNsListDumpOutputP01()
{
	const char *pOpfilename = UTSXMLHOME"/OP_XmlSaveTree.txt";
	const char *pFilename = UTSXMLHOME"/libXml2Test_NS.xml";
	int result = -1;
	xmlOutputBufferPtr opBuf; /*The Output buffer to be used*/
	xmlNodePtr nodePtr;
	xmlDocPtr doc; /* the resulting document tree used as i/p*/
	xmlNsPtr* pNsPtr;


	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION

	opBuf = xmlOutputBufferCreateFilename(UTSXMLHOME"/XmlNsListDumpOutput.txt", NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlNsListDumpOutput", (void *)opBuf, (void *)NULL, "xmlOutputBufferCreateFilename Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlNsListDumpOutput", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	nodePtr = xmlDocGetRootElement(doc);
	DTS_CHECK_NE_MESSAGE("xmlNsListDumpOutput", (void *)nodePtr, (void *)NULL, "xmlDocGetRootElement Failed");

	nodePtr = nodePtr->xmlChildrenNode;
	while (nodePtr != NULL) {
		if (0 == (xmlStrcmp(nodePtr->name, (const xmlChar *)"TO"))) {
			pNsPtr = xmlGetNsList(doc, nodePtr);
			break;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	xmlNsListDumpOutput(opBuf, pNsPtr[0]);

	__Cleanup(doc);
}

static void
UTcXmlSaveTreeP02()
{
	const char *pFilename = LIBXML2TESTXML;
	const char *pEncoding = NULL;
	FILE* fPtr = NULL;
	int result = -1;
	xmlSaveCtxtPtr ctxtPtr;
	xmlNodePtr nodePtr;
	xmlDocPtr doc; /* the resulting document tree used as ip*/

	fPtr = fopen(UTSXMLHOME"/XmlDocDump.txt", "w+");
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)fPtr, (void *)NULL, "fopen Failed");

	/*
	* this initialize the library and check potential ABI mismatches
	* between the version it was compiled for and the actual shared
	* library used.
	*/
	LIBXML_TEST_VERSION

	ctxtPtr = xmlSaveToFd(fPtr, pEncoding, 1);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)ctxtPtr, (void *)NULL, "xmlSaveToFd Failed");

	doc = xmlReadFile(pFilename, NULL, 0);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)doc, (void *)NULL, "xmlReadFile Failed");

	nodePtr = xmlDocGetRootElement(doc);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)nodePtr, (void *)NULL, "xmlDocGetRootElement Failed");

	nodePtr = nodePtr->xmlChildrenNode;
	while (nodePtr != NULL) {
		if (0 == (xmlStrcmp(nodePtr->name, (const xmlChar *)"TO"))) {
			break;
		}
		else {
			nodePtr = nodePtr->next;
		}
	}

	result = xmlSaveTree(ctxtPtr, nodePtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)result, (void *)-1, "xmlSaveTree Failed");


	result = xmlSaveFlush(ctxtPtr);
	DTS_CHECK_NE_MESSAGE("xmlSaveTree", (void *)result, (void *)-1, "xmlSaveFlush Failed");

	__Cleanup(doc);

	result = fclose(fPtr);
	DTS_CHECK_EQ_MESSAGE("xmlSaveTree", (void *)result, (void *)0, "fclose Failed");

	
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
	{UTcXmlSaveFileP01,1},
	{UTcXmlSaveFileToP01,2},
	{UTcXmlSaveFormatFileP01,3},
	{UTcXmlSaveFormatFileToP01,4},
	{UTcXmlSaveFileEncP01,5},
	{UTcXmlSaveTreeP01,6},
	{UTcXmlSaveDocP01,7},
	{UTcXmlNodeDumpP01,8},
	{UTcXmlDocDumpMemoryP01,9},
	{UTcXmlSaveSetEscapeP01,10},
	{UTcXmlSaveToIOP01,11},
	{ NULL, 0 },
	
};

