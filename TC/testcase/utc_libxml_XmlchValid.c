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

#include "libxml/chvalid.h"

#include <libxml/xmlmemory.h>
#include <libxml/uri.h>
#include <libxml/globals.h>

#include "utc_libxml_include.h"

/***************************************************************************
* SUTsXmlchValid
***************************************************************************/


/**    
	* @test			UTcxmlCharInRangeP01
	* @brief		int xmlCharInRange (unsigned int val,const xmlChRangeGroup * rptr)
	* @desc			Positive Test for Doing a binary search of the range table to determine if char is valid
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ xmlChRangeGroup is created with short range (1-10), N/A]	@n
					{unsigned int(1,2,3...10),xmlChRangeGroup*(rptr)} => {N/A |1}	@n	
					input2: [ N/A, N/A]	@n
					{unsigned int(11,12,...19),xmlChRangeGroup*(rptr)} => {N/A |0}	@n
					input3: [ xmlChRangeGroup long range is modiifed to (65536,65537,...65540), N/A]	@n
					{unsigned int(65536,65537,...65540),xmlChRangeGroup*(rptr)} => {N/A |1}	@n
					input4: [ xmlChRangeGroup long range is modiifed to (65536,65537,...65540), N/A]	@n
					{unsigned int(65540),xmlChRangeGroup*(rptr)} => {N/A |0}	@n

	* @b priority	Middle
	* @b etc		none
	*/

static void UTcxmlCharInRangeP01() 
{
	int ret_val = 0;
	int i = 0;
	static xmlChSRange xmlIsExtender_srng[] = {1,2,3,4,5,6,7,8,9,10};
	xmlChRangeGroup xmlIsExtenderGroup ={10, 0, xmlIsExtender_srng, (xmlChLRangePtr)0};
  /**
   * @remarks   input1: [ xmlChRangeGroup is created with short range (1-10), N/A]	@n
   *					{(1,2,3...10),xmlChRangeGroup} => {N/A |1}	@n
   */
	for(i =1;i<11;i++){
		ret_val = xmlCharInRange(i,&xmlIsExtenderGroup);
		DTS_CHECK_EQ("xmlCharInRange", (void *)ret_val, (void *) 1);
	}
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{(11,12,...19),xmlChRangeGroup} => {N/A |0}	@n
   */
	for(i =11;i<20;i++){
		ret_val = xmlCharInRange(i,&xmlIsExtenderGroup);
		DTS_CHECK_EQ("xmlCharInRange", (void *)ret_val, (void *) 0);
	}
	
	static xmlChLRange xmlIsExtender_Lngsrng[] = {65536,65537,65538,65539,65540};
	xmlChRangeGroup xmlIsExtenderGroup2 ={10, 5, xmlIsExtender_srng, (xmlChLRangePtr)xmlIsExtender_Lngsrng};
  /**
   * @remarks   input3: [ xmlChRangeGroup long range is modiifed to (65536,65537,...65540), N/A]	@n
   *					{(65536,65537,...65540),xmlChRangeGroup} => {N/A |1}	@n
   */
	for(i =65536;i<65540;i++){
		ret_val = xmlCharInRange(i,&xmlIsExtenderGroup2);
		DTS_CHECK_EQ("xmlCharInRange", (void *)ret_val, (void *) 1);
	}

	xmlChRangeGroup xmlIsExtenderGroup3 ={0, 0, 0, (xmlChLRangePtr)0};
  /**
   * @remarks   input3: [ xmlChRangeGroup long range is modiifed to (65536,65537,...65540), N/A]	@n
   *					{(65540),xmlChRangeGroup} => {N/A |0}	@n
   */
	ret_val = xmlCharInRange(65540,&xmlIsExtenderGroup3);
	DTS_CHECK_EQ("xmlCharInRange", (void *)ret_val, (void *) 0);
	
	ret_val = xmlCharInRange(0,&xmlIsExtenderGroup3);
	DTS_CHECK_EQ("xmlCharInRange", (void *)ret_val, (void *) 0);
	
}	
/**    
	* @test			UTcxmlIsBaseCharP01
	* @brief		int	xmlIsBaseChar (unsigned int ch)
	* @desc			Positive Test for xmlIsBaseChar
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ N/A, N/A]	@n
					{unsigned int(65,66,..90)} => {N/A |1}	@n
					input2: [ N/A, N/A]	@n
					{unsigned int(97,98,..122)} => {N/A |1}	@n
					input3: [ N/A, N/A]	@n
					{unsigned int(0,1,..65)} => {N/A |0}	@n			
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsBaseCharP01() 
{
	int ret_val;
	int i = 0;
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{(65,66,..90)} => {N/A |1}	@n
   */
	for(i =65;i<91;i++){
		ret_val = xmlIsBaseChar(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsBaseChar", (void *)ret_val, (void *)1, "xmlIsBaseChar Failed");
	}
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{(97,98,..122)} => {N/A |1}	@n
   */
	for(i =97;i<123;i++){
		ret_val = xmlIsBaseChar(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsBaseChar", (void *)ret_val, (void *)1, "xmlIsBaseChar Failed");
	}
  /**
   * @remarks   input3: [ N/A, N/A]	@n
   *					{(0,1,..65)} => {N/A |0}	@n
   */
	for(i =0;i<65;i++){
		ret_val = xmlIsBaseChar(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsBaseChar", (void *)ret_val, (void *)0, "xmlIsBaseChar Failed");
	}
}
	/**    
	* @test			UTcxmlIsBlankP01
	* @brief		int	xmlIsBlank	(unsigned int ch)
	* @desc			Positive Test for xmlIsBlank
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ N/A, N/A]	@n
					{unsigned int(' ')} => {N/A |1}	@n
					input2: [ N/A, N/A]	@n
					{unsigned int(33,34..127)} => {N/A |0}	@n	
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsBlankP01() 
{
	int ret_val;
	char val;
	int i = 0;
	val = ' ';
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{' '} => {N/A |1}	@n
   */
	ret_val = xmlIsBlank(val);
	DTS_CHECK_EQ("xmlIsBlank", (void *)ret_val, (void *) 1);
  
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{(33,34..127)} => {N/A |0}	@n
   */
	for(i =33;i<128;i++){
		val = i;
		ret_val = xmlIsBlank(val);
		DTS_CHECK_EQ_MESSAGE("xmlIsBlank", (void *)ret_val, (void *)0, "xmlIsBlank Failed");
	}
}
/**    
	* @test			UTcxmlIsCharP01
	* @brief		int	xmlIsChar (unsigned int ch)
	* @desc			Positive Test for xmlIsChar
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{unsigned int(32,33,...127)} => {N/A |1}	@n
					input2: [ N/A, N/A]	@n
					{unsigned int('abc')} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsCharP01() 
{
	int ret_val;
	unsigned int i = 0;
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{(32,33,...127)} => {N/A |1}	@n
   */
	for(i =32;i<128;i++){
		ret_val = xmlIsChar(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsChar", (void *)ret_val, (void *)1, "xmlIsChar Failed");
	}
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{'abc'} => {N/A |0}	@n
   */
	ret_val = xmlIsChar('abc');
	DTS_CHECK_EQ("xmlIsChar", (void *)ret_val, (void *) 0);


}
/**    
	* @test			UTcxmlIsCombiningP01
	* @brief		int	xmlIsCombining (unsigned int ch)
	* @desc			Positive Test for xmlIsCombining
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{unsigned int(768,769,...799)} => {N/A |1}	@n
					input2: [N/A, N/A] @n
	*   			{unsigned int (0,1,...255)} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsCombiningP01() 
{

    int ret_val;
	unsigned int i = 0;
	//Combining Diacritical Marks range(0300?36F)
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{(768,769,...799)} => {N/A |1}	@n
   */
	for(i = 768;i<770;i++){
		ret_val = xmlIsCombining(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsCombining", (void *)ret_val, (void *)1, "xmlIsCombining Failed");
	}
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{(0,1,...255)} => {N/A |0}	@n
   */
	for(i = 0;i<2;i++){
		ret_val = xmlIsCombining(i);
		DTS_CHECK_EQ("xmlIsCombining", (void *)ret_val, (void *)0 );
	}
}
/**    
	* @test			UTcxmlIsDigitP01
	* @brief		int	xmlIsDigit (unsigned int ch)
	* @desc			Positive Test for xmlIsDigit
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{unsigned int(48,49,...57)} => {N/A |1}	@n
					input2: [N/A, N/A] @n
	*   			{unsigned int(59,60,...127)} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsDigitP01() 
{
	int ret_val;
	unsigned int i = 0;
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{(48,49,...57)} => {N/A |1}	@n
   */
	for(i =48;i<58;i++){
		ret_val = xmlIsDigit(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsDigit", (void *)ret_val, (void *)1, "xmlIsDigit Failed");
	}
	/**
	* @remarks   input2: [ N/A, N/A]	@n
	*					{(59,60,...127)} => {N/A |0}	@n
	*/
	for(i =59;i<68;i++){
		ret_val = xmlIsDigit(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsDigit", (void *)ret_val, (void *)0, "xmlIsDigit Failed");
	}
	
}
/**    
	* @test			UTcxmlIsExtenderP01
	* @brief		int	xmlIsExtender (unsigned int ch)
	* @desc			Positive Test for xmlIsExtender
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{unsigned int(183)} => {N/A |1}	@n
					input2: [N/A, N/A] @n
	*   			{unsigned int (0,1,...127)} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsExtenderP01() 
{
	int ret_val;
	unsigned int i = 0;
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{183} => {N/A |1}	@n
   */
		ret_val = xmlIsExtender(183);//corresponds to'.'
		DTS_CHECK_EQ_MESSAGE("xmlIsExtender", (void *)ret_val, (void *)1, "xmlIsExtender Failed");

  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{(0,1,...127)} => {N/A |0}	@n
   */	
	for(i =0;i<2;i++){
		ret_val = xmlIsExtender(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsExtender", (void *)ret_val, (void *)0, "xmlIsExtender Failed");
	}
}
/**    
	* @test			UTcxmlIsIdeographicP01
	* @brief		int	xmlIsIdeographic (unsigned int ch)
	* @desc			Positive Test for xmlIsIdeographic
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{unsigned int(19968,19969...20223} => {N/A |1}	@n
					input2: [N/A, N/A] @n
	*   			{unsigned int(0,1...256} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsIdeographicP01() 
{
	int ret_val;
	unsigned int i = 0;
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{19968,19969...20223} => {N/A |1}	@n
   */
	for(i =19968;i<19970;i++){
		ret_val = xmlIsIdeographic(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsIdeographic", (void *)ret_val, (void *)1, "xmlIsIdeographic Failed");
	}
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{0,1...256} => {N/A |0}	@n
   */
	for(i =0;i<2;i++){
		ret_val = xmlIsIdeographic(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsIdeographic", (void *)ret_val, (void *)0, "xmlIsIdeographic Failed");
	}
}
/**    
	* @test			UTcxmlIsPubidCharP01
	* @brief		int	xmlIsPubidChar (unsigned int ch)
	* @desc			Positive Test for xmlIsPubidChar
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{unsigned int(65,66...90} => {N/A |1}	@n
					input2: [N/A, N/A] @n
	*   			{unsigned int(97,98...122} => {N/A |1}	@n
					input3: [N/A, N/A] @n
	*   			{unsigned int('-','=','()','+',',','.','/',':','=','?',';','!','*','#','@','$','_','%'} => {N/A |1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlIsPubidCharP01() 
{
	int ret_val;
	unsigned int i = 0;
	char chArray[] = {'-','=','+',',','.','/',':','=','?',';','!','*','#','@','$','_','%'};
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{65,66...90} => {N/A |1}	@n
   */
	for(i =65;i<70;i++){
		ret_val = xmlIsPubidChar(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsPubidChar", (void *)ret_val, (void *)1, "xmlIsPubidChar Failed");
	}
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{97,98...122} => {N/A |1}	@n
   */
	for(i =97;i<100;i++){
		ret_val = xmlIsPubidChar(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsPubidChar", (void *)ret_val, (void *)1, "xmlIsPubidChar Failed");
	}
  /**
   * @remarks   input3: [ N/A, N/A]	@n
   * {'-','=','()','+',',','.','/',':','=','?',';','!','*','#','@','$','_','%'} => {N/A |1}	@n
   */
	for (i = 0;i<2;i++){
		ret_val = xmlIsPubidChar(chArray[i]);
		DTS_CHECK_EQ_MESSAGE("xmlIsPubidChar", (void *)ret_val, (void *)1, "xmlIsPubidChar Failed");
	}

	for(i =0;i<15;i++){
		if (i == 13 || i == 10)
				continue;
		ret_val = xmlIsPubidChar(i);
		DTS_CHECK_EQ_MESSAGE("xmlIsPubidChar", (void *)ret_val, (void *)0, "xmlIsPubidChar Failed");
			
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
	{UTcxmlCharInRangeP01,1},
	{UTcxmlIsBaseCharP01,2},
	{UTcxmlIsBlankP01,3},
	{UTcxmlIsCharP01,4},
	{UTcxmlIsCombiningP01,5},
	{UTcxmlIsDigitP01,6},
	{UTcxmlIsExtenderP01,7},
	{UTcxmlIsIdeographicP01,8},
	{UTcxmlIsPubidCharP01,9},
	{NULL, 0},
	
};
