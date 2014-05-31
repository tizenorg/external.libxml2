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


#define MAX_SIZE			100
#define MAX_ENCODE_METHODS 28

static const char *encodingMethods[MAX_ENCODE_METHODS]={"",
								 "UTF-8",
								 "UTF8",
								 "UTF-16",
								 "UTF16",
								 "ISO-10646-UCS-2",
								 "UCS-2",
								 "UCS2",
								 "ISO-10646-UCS-4",
								 "UCS-4",
								 "UCS4",
								 "ISO-8859-1",
								 "ISO-LATIN-1",
								 "ISO LATIN 1",
								 "ISO-8859-2",
								 "ISO-LATIN-2",
								 "ISO LATIN 2",
								 "ISO-8859-3",
								 "ISO-8859-4",
								 "ISO-8859-5",
								 "ISO-8859-6",
								 "ISO-8859-7",
								 "ISO-8859-8",
								 "ISO-8859-9",
								 "ISO-2022-JP",
								 "SHIFT_JIS",
								 "EUC-JP",
								 "invalid"
					};

static  const char *encodingNames[MAX_ENCODE_METHODS]={"",
											   "UTF-8",
											   "UTF-8",
											   "UTF-16",
											   "UTF-16",
											   "ISO-10646-UCS-2",
											   "ISO-10646-UCS-2",
											   "ISO-10646-UCS-2",
											   "ISO-10646-UCS-4",
											   "ISO-10646-UCS-4",
											   "ISO-10646-UCS-4",
											   "ISO-8859-1",
											   "ISO-8859-1",
											   "ISO-8859-1",
											   "ISO-8859-2",
											   "ISO-8859-2",
											   "ISO-8859-2",
											   "ISO-8859-3",
											   "ISO-8859-4",
											   "ISO-8859-5",
											   "ISO-8859-6",
											   "ISO-8859-7",
											   "ISO-8859-8",
											   "ISO-8859-9",
											   "ISO-2022-JP",
											   "Shift-JIS",
											   "EUC-JP"
										   };




/**    
	* @test			UTcxmlEncodingP01
	* @brief		int xmlAddEncodingAlias (const char * name, const char * alias)
					int	xmlDelEncodingAlias	(const char * alias)
					const char * xmlGetEncodingAlias (const char * alias)
	* @desc			Positive Test for Registering an alias @alias for an encoding named @name
					Positive Test for Unregistering an encoding alias @alias
					Positive Test for Lookuping an encoding name for the given alias.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const char *(name)} => { N/A | 0 or -1 } @n
					input2: [N/A, N/A] @n
	*   			{const char *(alias))} => {N/A | 0 or -1 } @n
					input3: [N/A, N/A] @n
	*   			{const char *(alias)} => {N/A | NULL or original name } @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcxmlEncodingP01()
{
	const char *pName =  "<foo/>";
	const char *pAlias =  "foo";

	int resultVal = xmlAddEncodingAlias(pName, pAlias);
	DTS_CHECK_EQ_MESSAGE("xmlGetEncodingAlias", (void *)resultVal, (void *)0, "xmlAddEncodingAlias 1 Failed");

	const char *pResultName = xmlGetEncodingAlias(pAlias);
	DTS_CHECK_EQ_MESSAGE("xmlGetEncodingAlias", (void *)(strcmp(pResultName, pName)), (void *)0, "xmlGetEncodingAlias 2 Failed");

	resultVal = xmlDelEncodingAlias(pAlias);
	DTS_CHECK_EQ_MESSAGE("xmlGetEncodingAlias", (void *)resultVal, (void *)-1, "xmlDelEncodingAlias 3 Failed");

	xmlCleanupEncodingAliases();
	const char *pInvalidName = xmlGetEncodingAlias(pAlias);
	DTS_CHECK_EQ_MESSAGE("xmlGetEncodingAlias", (void *)pInvalidName, (void *)NULL, "xmlCleanupEncodingAliases 4 Failed");	
}
/**    
	* @test			UTcxmlEncodingP02
	* @brief		const char *	xmlGetCharEncodingName	(xmlCharEncoding enc)
	* @desc			Positive Test for XML encoding
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Parse and Get encoding name, N/A] @n
	*   			{xmlCharEncoding(enc)} => {N/A | canonical name for the given encoding} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlEncodingP02()
{
	int				count = 0;
	const char		*pEncodeName = NULL;
	xmlCharEncoding encode;

	encode = xmlParseCharEncoding(encodingMethods[0]);
	pEncodeName = xmlGetCharEncodingName(encode);
	DTS_CHECK_EQ_MESSAGE("xmlGetCharEncodingName", (void *)pEncodeName, (void *)NULL, "xmlGetCharEncodingName Failed");	

	encode = xmlParseCharEncoding(encodingMethods[MAX_ENCODE_METHODS - 1]);
	pEncodeName = xmlGetCharEncodingName(encode);
	DTS_CHECK_EQ_MESSAGE("xmlGetCharEncodingName", (void *)pEncodeName, (void *)NULL, "xmlGetCharEncodingName Failed");	

	for(count = 1; count <= (MAX_ENCODE_METHODS - 2); count++){
		xmlCharEncoding encode = xmlParseCharEncoding(encodingMethods[count]);
		pEncodeName = xmlGetCharEncodingName(encode);
		DTS_CHECK_EQ_MESSAGE("xmlGetEncodingAlias", (void *)(strcmp(pEncodeName, encodingNames[count])), (void *)0, "xmlGetEncodingAlias Failed");	
	}
}
/**    
	* @test			UTcxmlEncodingP03
	* @brief		int xmlCharEncInFunc (xmlCharEncodingHandler * handler, xmlBufferPtr out, xmlBufferPtr in)
					int	xmlCharEncCloseFunc		(xmlCharEncodingHandler * handler)
	* @desc			Positive Test for xmlCharEncInFunc
					Positive Test for xmlCharEncCloseFunc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [get buffer char, free buffer pointer] @n
	*   			{xmlCharEncodingHandler*(handler), xmlBufferPtr(out), xmlBufferPtr(in)} => {N/A | Number of bytes written} @n
					input2: [get buffer char, free buffer pointer] @n
	*   			{xmlCharEncodingHandler*(handler)} => {0 or -1 |N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlEncodingP03()
{
	//xmlErrorPtr pError;

 	xmlInitCharEncodingHandlers();
	//pError = xmlGetLastError();
	//MT_ASSERT_MESSAGE("checking the result for xmlCleanupCharEncodingHandlers", pError == NULL);
	xmlRegisterCharEncodingHandler(NULL);
	//xmlResetLastError();
	//xmlCleanupCharEncodingHandlers();

	xmlBufferPtr pBuffer = xmlBufferCreateSize(MAX_SIZE);
	xmlBufferPtr pOut = xmlBufferCreateSize(MAX_SIZE);
	xmlBufferAdd(pBuffer, (const xmlChar *)"0041", 4);

	xmlCharEncodingHandlerPtr pHandler = xmlGetCharEncodingHandler(XML_CHAR_ENCODING_UTF16LE);

	//xmlRegisterCharEncodingHandler(pHandler);
	xmlCharEncodingHandlerPtr pCharhandler = xmlFindCharEncodingHandler("UTF16");
	DTS_CHECK_NE_MESSAGE("xmlFindCharEncodingHandler", (void *)pCharhandler, (void *)NULL, "xmlFindCharEncodingHandler Failed");

	int resultVal = xmlCharEncInFunc(pCharhandler, pOut, pBuffer);
	DTS_CHECK_GT_MESSAGE("xmlFindCharEncodingHandler", (void *)resultVal, (void *)0, "xmlFindCharEncodingHandler Failed");

	resultVal = xmlCharEncCloseFunc(pCharhandler);
	DTS_CHECK_EQ_MESSAGE("xmlFindCharEncodingHandler", (void *)resultVal, (void *)0, "xmlFindCharEncodingHandler Failed");

	resultVal = xmlCharEncCloseFunc(pHandler);
	DTS_CHECK_EQ_MESSAGE("xmlFindCharEncodingHandler", (void *)resultVal, (void *)0, "xmlFindCharEncodingHandler Failed");
	//xmlResetLastError();

	xmlBufferFree(pBuffer);
	xmlBufferFree(pOut);
	//xmlCleanupCharEncodingHandlers();
	//pError = xmlGetLastError();
	//MT_CHECK_MESSAGE("checking the result for xmlCleanupCharEncodingHandlers", pError == NULL);
}

/**    
	* @test			UTcxmlEncodingP04
	* @brief		int xmlCharEncOutFunc (xmlCharEncodingHandler * handler, xmlBufferPtr out, xmlBufferPtr in)
					int xmlCharEncFirstLine	(xmlCharEncodingHandler * handler, xmlBufferPtr out, xmlBufferPtr in)
					int	xmlCharEncCloseFunc	(xmlCharEncodingHandler * handler)
	* @desc			Positive Test for xmlCharEncOutFunc
					Positive test for checking Front-end for the encoding handler input function, but handle only the very first line
					Positive test for checking Generic front-end for encoding handler close function
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [get buffer, free buffer] @n
	*   			{xmlCharEncodingHandler*(handler), xmlBufferPtr(out), xmlBufferPtr(in)} => {N/A | Number of byte written} @n
					input2: [get buffer, free buffer] @n
	*   			{xmlCharEncodingHandler*(handler), xmlBufferPtr(out), xmlBufferPtr(in)} => {N/A | Number of byte written} @n
					input3: [get buffer, free buffer] @n
	*   			{xmlCharEncodingHandler*(handler)} => {0 or -1 | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlEncodingP04()
{
 	xmlInitCharEncodingHandlers();
	xmlBufferPtr pBuffer = xmlBufferCreateSize(MAX_SIZE);
	xmlBufferPtr pOut = xmlBufferCreateSize(MAX_SIZE);
	xmlBufferPtr pOutBuffer = xmlBufferCreateSize(MAX_SIZE);
	xmlBufferAdd(pBuffer, (const xmlChar *)"41", 2);

	xmlCharEncodingHandlerPtr pHandler = xmlGetCharEncodingHandler(XML_CHAR_ENCODING_UTF16LE);
	//xmlRegisterCharEncodingHandler(pHandler);
	xmlCharEncodingHandlerPtr pCharhandler = xmlFindCharEncodingHandler("UTF16");
	DTS_CHECK_NE_MESSAGE("xmlFindCharEncodingHandler", (void *)pCharhandler, (void *)NULL, "xmlFindCharEncodingHandler1 Failed");
	
	int resultVal = xmlCharEncOutFunc(pCharhandler, pOut, pBuffer);
	DTS_CHECK_GTE_MESSAGE("xmlFindCharEncodingHandler", (void *)resultVal, (void *)0, "xmlFindCharEncodingHandler2 Failed");

	xmlBufferFree(pBuffer);
	pBuffer = xmlBufferCreateSize(MAX_SIZE);
	xmlBufferAdd(pBuffer, (const xmlChar *)"0041", 4);
	resultVal = xmlCharEncFirstLine(pCharhandler, pOutBuffer, pBuffer);
	DTS_CHECK_GTE_MESSAGE("xmlFindCharEncodingHandler", (void *)resultVal, (void *)0, "xmlFindCharEncodingHandler3 Failed");

	resultVal = xmlCharEncCloseFunc(pHandler);
	DTS_CHECK_EQ_MESSAGE("xmlFindCharEncodingHandler", (void *)resultVal, (void *)0, "xmlFindCharEncodingHandler4 Failed");

	xmlBufferFree(pBuffer);
	xmlBufferFree(pOut);
	xmlBufferFree(pOutBuffer);
	//xmlCleanupCharEncodingHandlers();
}
/**    
	* @test			UTcxmlEncodingP05
	* @brief		int isolat1ToUTF8 (unsigned char * out, int * outlen, const unsigned char * in,int * inlen)
					int UTF8Toisolat1 (unsigned char * out, int * outlen,  const unsigned char * in,int * inlen)
	* @desc			Positive Test for convert a block of ISO Latin 1 chars to an UTF-8 block of chars out
					Positive Test for convert a block of  UTF-8 block chars to an ISO Latin 1of chars out
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char *(out), int*(outlen), unsigned char* (in), int*(inlen)} => {N/A | number of bytes written} @n
					input2: [N/A, N/A] @n
	*   			{char *(out), int*(outlen), unsigned char* (in), int*(inlen)} => {N/A | number of bytes written} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlEncodingP05()
{
	unsigned char			*pOut = NULL;
	char					*pIn = "abcd";
	char					*pInUTF8 = "0041";
	int						outSize = MAX_SIZE;
	int						*pOutSize = &outSize;
	int						inSize = 4;
	int						*pInSize = &inSize;


	pOut = (unsigned char *) malloc(MAX_SIZE);
	int resultVal = isolat1ToUTF8(pOut, pOutSize, (const unsigned char*)pIn, pInSize);
	DTS_CHECK_EQ_MESSAGE("isolat1ToUTF8", (void *)resultVal, (void *)inSize, "isolat1ToUTF8 1 Failed");	

	free(pOut);
	pOut = NULL;

	pOut = (unsigned char *) malloc(MAX_SIZE);
	resultVal = UTF8Toisolat1(pOut, pOutSize, (const unsigned char*)pInUTF8, pInSize);
	DTS_CHECK_EQ_MESSAGE("isolat1ToUTF8", (void *)resultVal, (void *)inSize, "isolat1ToUTF8 2 Failed");	
	
	free(pOut);
	pOut = NULL;
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
	{UTcxmlEncodingP01,1},
   	{UTcxmlEncodingP02,2},
  	{UTcxmlEncodingP03,3},
   	{UTcxmlEncodingP04,5},
   	{UTcxmlEncodingP05,6},
	{ NULL, 0 },
	
};
