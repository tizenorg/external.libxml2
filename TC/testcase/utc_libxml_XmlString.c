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
#define gen_nb_const_char_ptr 4

/***************************************************************************
 * SUTsSax
 ***************************************************************************/

static int inttab[20];
static xmlChar chartab[20];

static char *gen_const_char_ptr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((char *) "foo");
	if (no == 1) return((char *) "<foo/>");
	if (no == 2) return((char *) "test/ent2");
	if (no == 3) return((char *) "test/end");
	return(NULL);
}

static void desret_xmlChar_ptr(xmlChar *val)
{
	if (val != NULL)
		xmlFree(val);
}
static void des_const_char_ptr(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}
#define gen_nb_int 3

static int gen_int(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(0);
	if (no == 1) return(1);
	if (no == 2) return(2);
	if (no == 3) return(122);
	return(-1);
}

#define gen_nb_const_unsigned_char_ptr 1
static unsigned char * gen_const_unsigned_char_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
	return((unsigned char *) "test");
}

#define gen_nb_int_ptr 2

static int *gen_int_ptr(int no, int nr)
{
	memset(inttab, 0, sizeof(inttab));
	inttab[0] = 10;
	if (no == 0) return(&inttab[nr]);
	return(NULL);
}
#define gen_nb_const_xmlChar_ptr 4

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((xmlChar *) "afoo");
	if (no == 1) return((xmlChar *) "<afoo/>");
	if (no == 2) return((xmlChar *) "nonea");
	if (no == 3) return((xmlChar *) " 2ab ");
	return(NULL);
}
#define gen_nb_xmlChar_ptr 2

static xmlChar *gen_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(&chartab[0]);
	return(NULL);
}

#define gen_nb_xmlChar 4

static xmlChar gen_xmlChar(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return('a');
	if (no == 1) return(' ');
	if (no == 2) return((xmlChar) ' ');
	return(0);
}
	/**    
	* @test			UTcxmlCharStrdupP01
	* @brief			xmlChar *	xmlCharStrdup (const char * cur)
	* @desc			Positive Test for converting char to XmlChar
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A]	@n
	*				{const char *(cur)) => {N/A |xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCharStrdupP01()
{
	xmlChar * ret_val;
	char * cur;
	int n_cur;

	for (n_cur = 0;n_cur < gen_nb_const_char_ptr;n_cur++) {

		cur = gen_const_char_ptr(n_cur, 0);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{char pointer} => {N/A |xmlChar pointer}	@n
		 */
		ret_val = xmlCharStrdup((const char *)cur);
		DTS_CHECK_NE_MESSAGE("xmlCharStrdup", (void *)ret_val, (void *)NULL, "xmlCharStrdup Failed");
		/**
		     * @post delete xmlChar pointer
		     */
		desret_xmlChar_ptr(ret_val);
		des_const_char_ptr(n_cur, (const char *)cur, 0);
		xmlResetLastError();
	}
}
	/**    
	* @test			UTcxmlCharStrndupP01
	* @brief			xmlChar *	xmlCharStrndup(const char * cur,	 int len)
	* @desc			Positive Test for converting n number of char to XmlChar 
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A]	@n
	*				{const char *(cur),int(len)} => {N/A |xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlCharStrndupP01()
{
	xmlChar * ret_val;
	char * cur; /* the input char * */
	int n_cur;
	int len; /* the len of @cur */
	int n_len;
	int result;

	for (n_cur = 0;n_cur < gen_nb_const_char_ptr;n_cur++) {
		for (n_len = 0;n_len < gen_nb_int;n_len++) {

			cur = gen_const_char_ptr(n_cur, 0);
			len = gen_int(n_len, 1);
			/**
			 * @remarks   input1: [N/A, N/A]	@n
			 *					{const char pointer,len} => {N/A |xmlChar pointer}	@n
			 */
			ret_val = xmlCharStrndup((const char *)cur, len);
			DTS_CHECK_NE_MESSAGE("xmlCharStrndup", (void *)ret_val, (void *)NULL, "xmlCharStrndup Failed");
			/**
			* @post delete xmlChar pointer
			*/
			desret_xmlChar_ptr(ret_val);
			des_const_char_ptr(n_cur, (const char *)cur, 0);
			//xmlFree(cur);
			xmlResetLastError();
		}
	}
	cur = gen_const_char_ptr(0, 0);
	len = gen_int(0, 1);

	ret_val = xmlCharStrndup((const char *)cur, len);
	DTS_CHECK_NE_MESSAGE("xmlCharStrndup", (void *)ret_val, (void *)NULL, "xmlCharStrndup Failed");

	result = xmlStrPrintf(ret_val,len,ret_val,"");
	DTS_CHECK_NE_MESSAGE("xmlCharStrndup", (void *)ret_val, (void *)0, "xmlStrPrintf Failed");

	//result = xmlStrVPrintf(ret_val,len,ret_val,"xmlStrVPrintf");
	//MT_CHECK_MESSAGE2(result == 0, "xmlStrVPrintf failed\n");

	//xmlFree(ret_val);

	ret_val = xmlCharStrndup((const char *)cur, -1);
	DTS_CHECK_EQ_MESSAGE("xmlCharStrndup", (void *)ret_val, (void *)NULL, "xmlCharStrndup Failed");
	
	result = xmlStrPrintf(ret_val,len,ret_val,"");
	DTS_CHECK_EQ_MESSAGE("xmlCharStrndup", (void *)ret_val, (void *)NULL, "xmlStrPrintf Failed");
	
	//result = xmlStrVPrintf(ret_val,len,ret_val,"xmlStrVPrintf");
	// MT_CHECK_MESSAGE2(result == -1, "xmlStrVPrintf failed\n");
	cur = NULL;
	/**
	 * @remarks   input2: [N/A, N/A]	@n
	 *					{const char pointer,-1} => {N/A |NULL}	@n
	 */
	ret_val = xmlCharStrndup((const char *)cur, -1);
	DTS_CHECK_EQ_MESSAGE("xmlCharStrndup", (void *)ret_val, (void *)NULL, "xmlCharStrndup Failed");
	
}
	/**    
	* @test			UTcxmlCheckUTF8P01
	* @brief			int	xmlCheckUTF8  (const unsigned char * utf)
	* @desc			Positive Test for checking @utf for being valid UTF-8
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A]	@n
	*				{const unsigned char *(utf)} => {N/A | true}	@n
	* @b priority	Middle
	* @b etc			none
	*/
static void
UTcxmlCheckUTF8P01()
{
	xmlChar * utf; /* the input UTF8 * */
	int ret_val;

	utf = gen_const_xmlChar_ptr(0, 0);
	/**
	     * @remarks   input1: [N/A, N/A]	@n
	     *					{const xmlChar pointer} => {N/A | true}	@n
	     */
	ret_val = xmlCheckUTF8((const xmlChar *)utf);
	DTS_CHECK_EQ_MESSAGE("xmlCheckUTF8", (void *)ret_val, (void *)1, "xmlCheckUTF8 Failed");
}
	/**    
	* @test			UTcxmlGetUTF8CharP01
	* @brief			int	xmlGetUTF8Char (const unsigned char * utf, int * len)
	* @desc			Positive Test for reading the first UTF8 character from @utf
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Get Sequence of UTF-8 encoded bytes, N/A]	@n
	*				{unsigned char pointer(utf),int(len)} => {N/A | non zero}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlGetUTF8CharP01()
{
	int ret_val;
	unsigned char * utf; /* a sequence of UTF-8 encoded bytes */
	int * len; /* a pointer to the minimum number of bytes present in the sequence.  This is used to assure the next character is completely contained within the sequence. */

	utf = gen_const_unsigned_char_ptr(0, 0);
	len = gen_int_ptr(0,0);

	/**
	 * @remarks   input1: [N/A, N/A]	@n
	 *					{unsigned char pointer,len} => {N/A | non zero}	@n
	 */
	ret_val = xmlGetUTF8Char(utf,len);
	DTS_CHECK_GT_MESSAGE("xmlGetUTF8Char", (void *)ret_val, (void *)0, "xmlGetUTF8Char Failed");
}
	/**    
	* @test			UTcxmlStrEqualP01
	* @brief			int xmlStrEqual (const xmlChar * str1,  const xmlChar * str2)
	* @desc			Positive Test for checking if both strings are equal of have same content.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [ger first and second XML strings, N/A]	@n
	*				{const xmlChar pointer (str1),const xmlChar pointer(str2} => {N/A | 1}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrEqualP01()
{
	int ret_val;
	xmlChar * str1; /* the first xmlChar * */
	int n_str1;
	xmlChar * str2; /* the second xmlChar * */

	for (n_str1 = 0;n_str1 < gen_nb_const_xmlChar_ptr;n_str1++) {
		str1 = gen_const_xmlChar_ptr(n_str1, 0);
		str2 = gen_const_xmlChar_ptr(n_str1, 0);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer,const xmlChar pointer} => {N/A | 1}	@n
		 */
		ret_val = xmlStrEqual((const xmlChar *)str1, (const xmlChar *)str2);
		DTS_CHECK_EQ_MESSAGE("xmlStrEqual", (void *)ret_val, (void *)1, "xmlStrEqual Failed");

	}
}
	/**    
	* @test			UTcxmlStrcasecmpP01
	* @brief			int xmlStrcasecmp	(const xmlChar * str1, const xmlChar * str2)
	* @desc			Positive Test for strcasecmp for xmlChar's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [get 2 XmlChar strings, N/A]	@n
	*				{const xmlChar pointer(str1),const xmlChar pointer(str2)} => {N/A | 0}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrcasecmpP01()
{
	int ret_val;
	xmlChar * str1; /* the first xmlChar * */
	int n_str1;
	xmlChar * str2; /* the second xmlChar * */

	for (n_str1 = 0;n_str1 < gen_nb_const_xmlChar_ptr;n_str1++) {
		str1 = gen_const_xmlChar_ptr(n_str1, 0);
		str2 = gen_const_xmlChar_ptr(n_str1, 1);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer,const xmlChar pointer} => {N/A | 0}	@n
		 */
		ret_val = xmlStrcasecmp((const xmlChar *)str1, (const xmlChar *)str2);
		DTS_CHECK_EQ_MESSAGE("xmlStrcasecmp", (void *)ret_val, (void *)0, "xmlStrcasecmp Failed");
	}
}
	/**    
	* @test			UTcxmlStrcasestrP01
	* @brief			const xmlChar * xmlStrcasestr	(const xmlChar * str,const xmlChar * val)
	* @desc			Positive Test for case-ignoring strstr for xmlChar's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [get an Xml array of characters, N/A]	@n
	*				{const xmlChar pointer(str),const xmlChar *(val)} => {N/A | xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrcasestrP01()
{
	const xmlChar * ret_val;
	xmlChar * str; /* the xmlChar * array (haystack) */
	int n_str;
	xmlChar * val; /* the xmlChar to search (needle) */

	for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr;n_str++) {
		str = gen_const_xmlChar_ptr(n_str, 0);
		val = gen_xmlChar_ptr(0, 1);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer,xmlChar pointer} => {N/A | xmlChar pointer}	@n
		 */
		ret_val = xmlStrcasestr((const xmlChar *)str, val);
		DTS_CHECK_NE_MESSAGE("xmlStrcasestr", (void *)ret_val, (void *)NULL, "xmlStrcasestr Failed");
		//if (ret_val != NULL)
		//	delete ret_val;
	}
}
	/**    
	* @test			UTcxmlStrchrP01
	* @brief			const xmlChar *xmlStrchr (const xmlChar * str,  xmlChar val)
	* @desc			Positive Test for strchr operation for xmlChar's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Xml character array and string to search, N/A]	@n
	*				{const xmlChar pointer(str),xmlChar (val)} => {N/A |const xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrchrP01()
{
	const xmlChar * ret_val;
	xmlChar * str; /* the xmlChar * array */
	int n_str;
	xmlChar val; /* the xmlChar to search */
	int n_val=0;

	for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr;n_str++) {

		str = gen_const_xmlChar_ptr(n_str, 0);
		val = 'a';
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer,xmlChar pointer} => {N/A |const xmlChar pointer}	@n
		 */
		ret_val = xmlStrchr((const xmlChar *)str, val);
		DTS_CHECK_NE_MESSAGE("xmlStrchr", (void *)ret_val, (void *)NULL, "xmlStrchr Failed");
	}
}
	/**    
	* @test			UTcxmlStrcmpP01
	* @brief			int	xmlStrcmp (const xmlChar * str1, const xmlChar * str2)
	* @desc			Positive Test for strcmp operation for xmlChar's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
 	* @remarks   		input1: [two xml strings, N/A]	@n
	*				{const xmlChar pointer(str1),xmlChar pointer(str2)} => {N/A |0}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrcmpP01()
{
	int ret_val;
	xmlChar * str1; /* the first xmlChar * */
	int n_str1;
	xmlChar * str2; /* the second xmlChar * */

	for (n_str1 = 0;n_str1 < gen_nb_const_xmlChar_ptr;n_str1++) {

		str1 = gen_const_xmlChar_ptr(n_str1, 0);
		str2 = gen_const_xmlChar_ptr(n_str1, 1);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer,xmlChar pointer} => {N/A |0}	@n
		 */
		ret_val = xmlStrcmp((const xmlChar *)str1, (const xmlChar *)str2);
		DTS_CHECK_EQ_MESSAGE("xmlStrcmp", (void *)ret_val, (void *)0, "xmlStrcmp Failed");
	}
}
	/**    
	* @test			UTcxmlStrdupP01
	* @brief			xmlChar *xmlStrdup (const xmlChar * cur)
	* @desc			Positive Test for strdup operation for array of xmlChar's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Xml string, N/A]	@n
	*				{const xmlChar pointer(cur)} => {N/A | xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrdupP01()
{
	xmlChar * ret_val;
	xmlChar * cur; /* the input xmlChar * */
	int n_cur;

	for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr;n_cur++) {
		cur = gen_const_xmlChar_ptr(n_cur, 0);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer} => {N/A | xmlChar pointer}	@n
		 */
		ret_val = xmlStrdup((const xmlChar *)cur);
		DTS_CHECK_NE_MESSAGE("xmlStrdup", (void *)ret_val, (void *)NULL, "xmlStrdup Failed");

		desret_xmlChar_ptr(ret_val);
	}
}
	/**    
	* @test			UTcxmlStrstrP01
	* @brief			const xmlChar * xmlStrstr	(const xmlChar * str, const xmlChar * val)
	* @desc			Positive Test for strstr operation for xmlChar's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [main string and sub string, N/A]	@n
	*				{const xmlChar pointer(str) , const xmlChar pointer(val)} => {N/A |const xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrstrP01()
{
	const xmlChar * ret_val;
	xmlChar * str; /* the xmlChar * array (haystack) */
	int n_str;
	xmlChar * val; /* the xmlChar to search (needle) */
	int n_val=0;

	for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr;n_str++) {
		str = gen_const_xmlChar_ptr(n_str, 0);
		val = gen_const_xmlChar_ptr(n_str, 1);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer , const xmlChar pointer} => {N/A |const xmlChar pointer}	@n
		 */
		ret_val = xmlStrstr((const xmlChar *)str, (const xmlChar *)val);
		DTS_CHECK_NE_MESSAGE("xmlStrstr", (void *)ret_val, (void *)NULL, "xmlStrstr Failed");
	}
}
	/**    
	* @test			UTcxmlStrsubP01
	* @brief			xmlChar * xmlStrsub (const xmlChar * str, int start, int len )
	* @desc			Positive Test for extraction of a substring of a given string
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [Xml String with index and length, N/A]	@n
	*				{const xmlChar pointer(str) ,int(start),int(len) }=> {N/A | xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrsubP01()
{
	xmlChar * ret_val;
	xmlChar * str; /* the xmlChar * array (haystack) */
	int n_str;
	int start; /* the index of the first char (zero based) */
	int n_start;
	int len; /* the length of the substring */
	int n_len = 0;

	for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr;n_str++) {
		for (n_start = 0;n_start < gen_nb_int;n_start++) {

			str = gen_const_xmlChar_ptr(n_str, 0);
			start = gen_int(n_start, 1);
			len = gen_int(n_len, 2);
			/**
			 * @remarks   input1: [N/A, N/A]	@n
			 *					{const xmlChar pointer ,start,len }=> {N/A | xmlChar pointer}	@n
			 */
			ret_val = xmlStrsub((const xmlChar *)str, start, len);
			DTS_CHECK_NE_MESSAGE("xmlStrsub", (void *)ret_val, (void *)NULL, "xmlStrsub Failed");
			desret_xmlChar_ptr(ret_val);
		}
	}
}
	/**    
	* @test			UTcxmlStrncatNewP01
	* @brief			xmlChar *	xmlStrncatNew (const xmlChar * str1, const xmlChar * str2, int len)
	* @desc			Positive Test for xmlStrncat operation on xml strings
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A]	@n
	*				{const xmlChar pointer(str1) ,const xmlChar pointer(str2),int(len) }=> {N/A | xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrncatNewP01()
{
	xmlChar * ret_val;

	/**
	 * @remarks   input1: [N/A, N/A]	@n
	 *					{const xmlChar pointer ,const xmlChar pointer,len }=> {N/A | xmlChar pointer}	@n
	 */
	ret_val = xmlStrncatNew((const xmlChar *)"<test>", (const xmlChar *)"</test>", 7);
	DTS_CHECK_NE_MESSAGE("xmlStrncatNew", (void *)ret_val, (void *)NULL, "xmlStrncatNewFailed");
	desret_xmlChar_ptr(ret_val);
}
	/**    
	* @test			UTcxmlStrncatP01
	* @brief			xmlChar *xmlStrncat (xmlChar * cur, const xmlChar * add, int len)
	* @desc			Positive Test for strncat for array of xmlChar's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   				{xmlChar pointer(cur) ,const xmlChar pointer(add),int(len) }=> {N/A | xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlStrncatP01()
{
	xmlChar* pRet = NULL;
	xmlChar* pSrc = xmlCharStrdup("Hello");

	pRet = xmlStrncat(pSrc, (const xmlChar *)" world", sizeof(" world"));
	DTS_CHECK_EQ_MESSAGE("xmlStrncat", (void *)(pRet != NULL && xmlStrcmp(pRet, (const xmlChar*)"Hello world")), (void *)0, "xmlStrncat Failed");

	desret_xmlChar_ptr(pRet);
}
	/**    
	* @test			UTcxmlUTF8CharcmpP01
	* @brief			int	xmlUTF8Charcmp (const xmlChar * utf1, const xmlChar * utf2)
	* @desc			Positive Test to compare the two UCS4 values
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [two UTF strings, N/A]	@n
	*				{const xmlChar pointer(utf1) ,const xmlChar pointer(utf2) }=> {N/A |0}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUTF8CharcmpP01()
{

	int ret_val;
	xmlChar * utf1; /* pointer to first UTF8 char */
	int n_utf1;
	xmlChar * utf2; /* pointer to second UTF8 char */

	for (n_utf1 = 0;n_utf1 < gen_nb_const_xmlChar_ptr;n_utf1++) {

		utf1 = gen_const_xmlChar_ptr(n_utf1, 0);
		utf2 = gen_const_xmlChar_ptr(n_utf1, 1);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer ,const xmlChar pointer }=> {N/A |0}	@n
		 */
		ret_val = xmlUTF8Charcmp((const xmlChar *)utf1, (const xmlChar *)utf2);
		DTS_CHECK_EQ_MESSAGE("xmlUTF8Charcmp", (void *)ret_val, (void *)0, "xmlUTF8Charcmp Failed");
	}

}

	/**    
	* @test			UTcxmlUTF8SizeP01
	* @brief			int	xmlUTF8Size (const xmlChar * utf)
	* @desc			Positive Test for calculating the internal size of a UTF8 character
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A]	@n
	*				{const xmlChar pointer(utf) }=> {N/A |non zero}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUTF8SizeP01()
{

	int ret_val;
	xmlChar * utf; /* pointer to the UTF8 character */
	int n_utf;

	for (n_utf = 0;n_utf < gen_nb_const_xmlChar_ptr;n_utf++) {

		utf = gen_const_xmlChar_ptr(n_utf, 0);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer }=> {N/A |non zero}	@n
		 */
		ret_val = xmlUTF8Size((const xmlChar *)utf);
		//(ret_val > 0, "xmlUTF8Charcmp failed\n");
		DTS_CHECK_GT_MESSAGE("xmlUTF8Size", (void *)ret_val, (void *)0, "xmlUTF8Size Failed");
	}
}
	/**    
	* @test			UTcxmlUTF8StrlenP01
	* @brief			int	xmlUTF8Strlen	 (const xmlChar * utf)
	* @desc			Positive Test for computing the length of an UTF8 string, it doesn't do a full UTF8 checking of the content of the string.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [sequence of UTF encoded bytes, N/A]	@n
	*				{const xmlChar pointer(utf)} => {N/A |non zero}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUTF8StrlenP01()
{
	int ret_val;
	xmlChar * utf; /* a sequence of UTF-8 encoded bytes */
	int n_utf;

	for (n_utf = 0;n_utf < gen_nb_const_xmlChar_ptr;n_utf++) {

		utf = gen_const_xmlChar_ptr(n_utf, 0);
		/**
		 * @remarks   input1: [N/A, N/A]	@n
		 *					{const xmlChar pointer} => {N/A |non zero}	@n
		 */
		ret_val = xmlUTF8Strlen((const xmlChar *)utf);
		DTS_CHECK_GT_MESSAGE("xmlUTF8Strlen", (void *)ret_val, (void *)0, "xmlUTF8Strlen Failed");
	}

}
	/**    
	* @test			UTcxmlUTF8StrlocP01
	* @brief			int	xmlUTF8Strloc	 (const xmlChar * utf, const xmlChar * utfchar)
	* @desc			Positive Test to provide the relative location of a UTF8 char
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [UTF8 and character to be found, N/A]	@n
	*				{const xmlChar pointer(utf) ,const xmlChar pointer(utfchar)}=> {N/A |non zero}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUTF8StrlocP01()
{
	int ret_val;
	xmlChar * utf; /* the input UTF8 * */
	xmlChar * utfchar; /* the UTF8 character to be found */

	utf = gen_const_xmlChar_ptr(1, 0);
	utfchar = gen_const_xmlChar_ptr(0, 1);
	/**
	 * @remarks   input1: [N/A, N/A]	@n
	 *					{const xmlChar pointer ,const xmlChar pointer}=> {N/A |non zero}	@n
	 */
	ret_val = xmlUTF8Strloc((const xmlChar *)utf, (const xmlChar *)utfchar);
	DTS_CHECK_GT_MESSAGE("xmlUTF8Strloc", (void *)ret_val, (void *)0, "xmlUTF8Strloc Failed");

}
	/**    
	* @test			UTcxmlUTF8StrndupP01
	* @brief			xmlChar * xmlUTF8Strndup (const xmlChar * utf, int len)
	* @desc			Positive Test for strndup operatin for array of UTF8's
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A]	@n
	*				{const xmlChar pointer(utf) ,int(len)} => {N/A |xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUTF8StrndupP01()
{

	xmlChar * ret_val;
	xmlChar * utf; /* the input UTF8 * */
	int n_utf;
	int len; /* the len of @utf (in chars) */
	int n_len;

	for (n_utf = 0;n_utf < gen_nb_const_xmlChar_ptr;n_utf++) {
		for (n_len = 0;n_len < gen_nb_int;n_len++) {

			utf = gen_const_xmlChar_ptr(n_utf, 0);
			len = gen_int(n_len, 1);
			/**
			 * @remarks   input1: [N/A, N/A]	@n
			 *					{const xmlChar pointer ,len} => {N/A |xmlChar pointer}	@n
			 */
			ret_val = xmlUTF8Strndup((const xmlChar *)utf, len);
			DTS_CHECK_NE_MESSAGE("xmlUTF8Strndup", (void *)ret_val, (void *)NULL, "xmlUTF8Strndup Failed");

			desret_xmlChar_ptr(ret_val);
		}
	}

}
	/**    
	* @test			UTcxmlUTF8StrposP01
	* @brief			const xmlChar *	xmlUTF8Strpos (const xmlChar * utf, int pos)
	* @desc			Positive Test to provide the equivalent of fetching a character from a string array
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A]	@n
	*				{const xmlChar pointer(utf) ,int(pos)} => {N/A |xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUTF8StrposP01()
{

	const xmlChar * ret_val;
	xmlChar * utf; /* the input UTF8 * */
	int n_utf;
	int pos; /* the position of the desired UTF8 char (in chars) */
	int n_pos;

	for (n_utf = 0;n_utf < gen_nb_const_xmlChar_ptr;n_utf++) {
		for (n_pos = 0;n_pos < 3;n_pos++) {

			utf = gen_const_xmlChar_ptr(n_utf, 0);
			pos = gen_int(n_pos, 1);
			/**
			 * @remarks   input1: [N/A, N/A]	@n
			 *					{const xmlChar pointer ,pos} => {N/A |xmlChar pointer}	@n
			 */
			ret_val = xmlUTF8Strpos((const xmlChar *)utf, pos);
			DTS_CHECK_NE_MESSAGE("xmlUTF8Strpos", (void *)ret_val, (void *)NULL, "xmlUTF8Strpos Failed");


		}
	}
}
	/**    
	* @test			UTcxmlUTF8StrsubP01
	* @brief			xmlChar *xmlUTF8Strsub (const xmlChar * utf, int start, int len)
	* @desc			Positive Test to create a substring from a given UTF-8 string
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks   		input1: [N/A, N/A]	@n
	*				{const xmlChar pointer(utf) , int(start), int(len)} => {N/A |xmlChar pointer}	@n
	* @b priority		Middle
	* @b etc			none
	*/
static void
UTcxmlUTF8StrsubP01()
{

	xmlChar * ret_val;

	/**
	 * @remarks   input1: [N/A, N/A]	@n
	 *					{const xmlChar pointer , start, len} => {N/A |xmlChar pointer}	@n
	 */
	ret_val = xmlUTF8Strsub((const xmlChar *)"<test/>", 1, 5);
	DTS_CHECK_NE_MESSAGE("xmlUTF8Strsub", (void *)ret_val, (void *)NULL, "xmlUTF8Strsub Failed");

	desret_xmlChar_ptr(ret_val);
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
	{UTcxmlCharStrdupP01,1},
	{UTcxmlCharStrndupP01,2},
	{UTcxmlCheckUTF8P01,3},
	{UTcxmlGetUTF8CharP01,4},
	{UTcxmlStrEqualP01,5},
	{UTcxmlStrcasecmpP01,6},
	{UTcxmlStrcasestrP01,7},
	{UTcxmlStrchrP01,8},
	{UTcxmlStrcmpP01,9},
	{UTcxmlStrdupP01,10},
	
	{UTcxmlStrstrP01,11},
	{UTcxmlStrsubP01,12},
	{UTcxmlStrncatNewP01,13},
	{UTcxmlStrncatP01,14},
	{UTcxmlUTF8CharcmpP01,15},
	{UTcxmlUTF8SizeP01,16},
	{UTcxmlUTF8StrlenP01,17},
	{UTcxmlUTF8StrlocP01,18},
	{UTcxmlUTF8StrndupP01,19},
	{UTcxmlUTF8StrposP01,20},
	
	{UTcxmlUTF8StrsubP01,21},
	{ NULL, 0 },
	
};
