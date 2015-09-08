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

//includes

#include "utc_libxml_include.h"





static int
Compare(const void *data0, const void *data1)
{
    if (strcmp((char*)data0,(char*)data1)>0)
        return (-1);
    else if (strcmp((char*)data0,(char*)data1)==0)
	return (0);
    return (1);
}
static int
Compare1(const void *data0, const void *data1)
{
	if (strcmp((char*)data0,(char*)data1)>0)
		return (1);
	else if (strcmp((char*)data0,(char*)data1)==0)
		return (0);
	return (-1);
}
/***************************************************************************
* SUTsXmlList
***************************************************************************/
	/**    
	* @test			UTcxmlListCreateP01
	* @brief		xmlListPtr xmlListCreate (xmlListDeallocator deallocator, xmlListDataCompare compare)
	* @desc			Positive Test for creating a new list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{NULL,xmlListDataCompare(Compare1)} => {N/A |xmlListPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListCreateP01() 
{	
  /**
   * @remarks   input1: [ N/A, N/A]	@n
   *					{NULL,Compare1} => {N/A |xmlListPtr}	@n
   */
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListCreate", (void *)list, (void *)NULL, "xmlListCreate Failed");
	xmlListDelete(list);
	
	
}
/**    
	* @test			UTcxmlListSearchP01
	* @brief		void *	xmlListSearch (xmlListPtr l, void * data)
	* @desc			Positive Test for s	earching the list for an existing value of @data
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test" and "hello", N/A]	@n
	*   			{xmlListPtr(list),"hello"} => {N/A |xmlListPtr}	@n
					input2: [N/A, N/A]	@n
					{xmlListPtr (list),"noString"} => {N/A |NULL}	@n
	* @b priority	Middle
	* @b etc		none
	*/
	
static void UTcxmlListSearchP01() 
{
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListSearch", (void *)list, (void *)NULL, "xmlListCreate Failed");
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	void* ch2 = (void*)("noString");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListSearch", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListSearch", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListSearch", (void *)ret_value, (void *)0, "xmlListAppend Failed");
//list ----   test->hello->test
  
  /**
   * @remarks   input1: [ List(list) is created having values "test" and "hello", N/A]	@n
   *					{list,"hello"} => {N/A |xmlListPtr}	@n
   */
	xmlListPtr val = (xmlListPtr)(xmlListSearch(list,ch));
	DTS_CHECK_NE_MESSAGE("xmlListSearch", (void *)val, (void *)NULL, "xmlListAppend Failed");
  /**
   * @remarks   input2: [N/A, N/A]	@n
   *					{list,"noString"} => {N/A |NULL}	@n
   */
	val = (xmlListPtr)(xmlListSearch(list,ch2));
	DTS_CHECK_EQ_MESSAGE("xmlListSearch", (void *)val, (void *)NULL, "xmlListAppend Failed");
	
	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListReverseSearchP01
	* @brief		void *	xmlListReverseSearch (xmlListPtr l, void * data)
	* @desc			Positive Test for searching the list in reverse order for an existing value of @data
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test" and "hello", N/A]	@n
					{xmlListPtr(list),"hello"} => {N/A |xmlListPtr}	@n
					input2: [N/A, N/A]	@n
					{xmlListPtr(list),"noString"} => {N/A |NULL}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListReverseSearchP01() 
{
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListReverseSearch", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	void* ch2 = (void*)("noString");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListReverseSearch", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListReverseSearch", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListReverseSearch", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "test" and "hello", N/A]	@n
   *					{list,"hello"} => {N/A |xmlListPtr}	@n
   */
	char* out = (char*)(xmlListReverseSearch(list,ch));
	DTS_CHECK_EQ_MESSAGE("xmlListReverseSearch", (void *)(strcmp(out,"hello")), (void *)0, "xmlListReverseSearch Failed");
  /**
   * @remarks   input2: [N/A, N/A]	@n
   *					{list,"noString"} => {N/A |NULL}	@n
   */
	out = (char*)(xmlListReverseSearch(list,ch2));
	DTS_CHECK_EQ_MESSAGE("xmlListReverseSearch", (void *)out, (void *)NULL, "xmlListReverseSearch Failed");
	
	xmlListDelete(list);
	
}
	/**    
	* @test			UTcxmlListInsertP01
	* @brief		int xmlListInsert (xmlListPtr l, void * data)
	* @desc			Positive Test for Inserting data in the ordered list at the beginning for this value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "5" ,"3","3", N/A]	@n
					{xmlListPtr(list),"1"} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListInsertP01() 
{
	xmlListPtr list = xmlListCreate(NULL,Compare);
	DTS_CHECK_NE_MESSAGE("xmlListInsert", (void *)list, (void *)NULL, "xmlListCreate Failed");
	void* ch = (void*)("5");
	void* ch1 = (void*)("3");
	void* ch2 = (void*)("1");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListInsert", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListInsert", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListInsert", (void *)ret_value, (void *)0, "xmlListAppend Failed");
  
  /**
   * @remarks   input1: [ List(list) is created having values "5" ,"3","3", N/A]	@n
   *					{list,"1"} => {N/A |0}	@n
   */
	ret_value = xmlListInsert(list,ch2);
	DTS_CHECK_EQ_MESSAGE("xmlListInsert", (void *)ret_value, (void *)0, "xmlListInsert Failed");
	
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListInsert", (void *)((strcmp(ret,"1"))), (void *)0, "xmlListEnd Failed");

	
	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListAppendP01
	* @brief		int xmlListAppend (xmlListPtr l, void * data)
	* @desc			Positive Test for Inserting data in the ordered list at the end for this value
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		 input1: [ List(list) is created, N/A]	@n
					{xmlListPtr(list),"hello"} => {N/A |1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListAppendP01() 
{
	
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListAppend", (void *)list, (void *)NULL, "xmlListCreate Failed");
	char* ch = "hello";
  /**
   * @remarks   input1: [ List(list) is created, N/A]	@n
   *					{list,"hello"} => {N/A |1}	@n
   */
	int ret_value = xmlListAppend(list,(void*)(ch));
	DTS_CHECK_EQ_MESSAGE("xmlListAppend", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	xmlListDelete(list);
	
}
	/**    
	* @test			UTcxmlListDeleteP01
	* @brief		void xmlListDelete (xmlListPtr l)
	* @desc			Positive Test for Deleting the list and its associated data
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "hello","test", N/A]	@n
					{xmlListPtr(list)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListDeleteP01() 
{
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListAppend", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListAppend", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListAppend", (void *)ret_value, (void *)0, "xmlListAppend Failed");
  /**
   * @remarks   input1: [ List(list) is created having values "hello","test", N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */
	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListRemoveFirstP01
	* @brief		int xmlListRemoveFirst (xmlListPtr l, void * data)
	* @desc			Positive Test for Removing the first instance associated to data in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello","test", N/A]	@n
    				{list,"test"} => {N/A |1}	@n
					input2: [ N/A, N/A]	@n
   		     		{xmlListPtr(list),"test"} => {N/A |1}	@n
					input3: [ N/A, N/A]	@n
					{xmlListPtr(list),"test"} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListRemoveFirstP01() 
{
	xmlListPtr list = xmlListCreate(NULL,Compare);
	DTS_CHECK_NE_MESSAGE("xmlListRemoveFirst", (void *)list, (void *)NULL, "xmlListCreate Failed");
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveFirst", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveFirst", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveFirst", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
//list ----   test->hello->test
  
  /**
   * @remarks   input1: [ List(list) is created having values "test","hello","test", N/A]	@n
   *					{list,"test"} => {N/A |1}	@n
   */
	ret_value = xmlListRemoveFirst(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveFirst", (void *)ret_value, (void *)1, "xmlListRemoveFirst Failed");
	
	xmlLinkPtr val = xmlListFront(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveFirst", (void *)(strcmp(ret,"test")), (void *)0, "xmlListFront Failed");
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{list,"test"} => {N/A |1}	@n
   */
	ret_value = xmlListRemoveFirst(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveFirst", (void *)ret_value, (void *)1, "xmlListRemoveFirst Failed");

  /**
   * @remarks   input3: [ N/A, N/A]	@n
   *					{list,"test"} => {N/A |0}	@n
   */
	ret_value = xmlListRemoveFirst(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveFirst", (void *)ret_value, (void *)0, "xmlListRemoveFirst Failed");

	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListRemoveLastP01
	* @brief		int xmlListRemoveLast (xmlListPtr l, void * data)
	* @desc			Positive Test for Removing the last instance associated to data in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "2","1","2","1", N/A]	@n
    				{xmlListPtr(list),"1"} => {N/A |1}	@n
					input2: [ N/A, N/A]	@n
    				{xmlListPtr(list),"1"} => {N/A |1}	@n
					input3: [ N/A, N/A]	@n
    				{xmlListPtr(list),"1"} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListRemoveLastP01() 
{
	void* ch = (void*)("2");
	void* ch1 = (void*)("1");
	xmlListPtr list = xmlListCreate(NULL,Compare);
	DTS_CHECK_NE_MESSAGE("xmlListRemoveLast", (void *)list, (void *)NULL, "xmlListCreate Failed");

	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "2","1","2","1", N/A]	@n
   *					{list,"1"} => {N/A |1}	@n
   */
	ret_value = xmlListRemoveLast(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)ret_value, (void *)1, "xmlListRemoveLast Failed");
	
	//if last instance is removed then the last element is changed to "1"
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
  	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)(strcmp(ret,"1")), (void *)0, "xmlListEnd Failed");
	
  /**
   * @remarks   input2: [ N/A, N/A]	@n
   *					{list,"1"} => {N/A |1}	@n
   */
	ret_value = xmlListRemoveLast(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)ret_value, (void *)1, "xmlListRemoveLast Failed");
	
	val = xmlListEnd(list);	
	ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)(strcmp(ret,"2")), (void *)0, "xmlListEnd Failed");
	
  /**
   * @remarks   input3: [ N/A, N/A]	@n
   *					{list,"1"} => {N/A |0}	@n
   */
	ret_value = xmlListRemoveLast(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveLast", (void *)ret_value, (void *)0, "xmlListRemoveLast Failed");
	
	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListRemoveAllP01
	* @brief		int xmlListRemoveAll (xmlListPtr l, void * data)
	* @desc			Positive Test for Removing the all instance associated to data in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello","test", N/A]	@n
    				{xmlListPtr(list),"test"} => {N/A |1}	@n
					input2: [N/A , N/A]	@n
					{xmlListPtr(list),"test"} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListRemoveAllP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListRemoveAll", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveAll", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveAll", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveAll", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	

  /**
   * @remarks   input1: [ List(list) is created having values "test","hello","test", N/A]	@n
   *					{list,"test"} => {N/A |1}	@n
   */
	ret_value = xmlListRemoveAll(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveAll", (void *)ret_value, (void *)2, "xmlListRemoveAll Failed");
	
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveAll", (void *)(strcmp(ret,"hello")), (void *)0, "xmlListEnd Failed");

  /**
   * @remarks   input2: [N/A , N/A]	@n
   *					{list,"test"} => {N/A |0}	@n
   */
	ret_value = xmlListRemoveAll(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListRemoveAll", (void *)ret_value, (void *)0, "xmlListRemoveAll Failed");

	xmlListDelete(list);
	
}
	/**    
	* @test			UTcxmlListClearP01
	* @brief		void xmlListClear (xmlListPtr l)
	* @desc			Positive Test for Removing the all data in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello","test", N/A]	@n
					{xmlListPtr(list)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListClearP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListClear", (void *)list, (void *)NULL, "xmlListCreate Failed");

	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListClear", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListClear", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListClear", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "test","hello","test", N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */
	xmlListClear(list);
	ret_value = xmlListEmpty(list);
	DTS_CHECK_EQ_MESSAGE("xmlListClear", (void *)ret_value, (void *)1, "xmlListEmpty Failed");

	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListEmptyP01
	* @brief		int	xmlListEmpty (xmlListPtr l)
	* @desc			Positive Test to check if the list is empty
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello","test", N/A]	@n
					{xmlListPtr(list)} => {N/A |0}	@n
					input2: [ List(list) is cleared, N/A]	@n
					{xmlListPtr(list)} => {N/A |1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
void UTcxmlListEmptyP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListEmpty", (void *)list, (void *)NULL, "xmlListCreate Failed");

	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListEmpty", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListEmpty", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListEmpty", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "test","hello","test", N/A]	@n
   *					{list} => {N/A |0}	@n
   */
	ret_value = xmlListEmpty(list);
	DTS_CHECK_EQ_MESSAGE("xmlListEmpty", (void *)ret_value, (void *)0, "xmlListEmpty Failed");

	xmlListClear(list);
  /**
   * @remarks   input2: [ List(list) is cleared, N/A]	@n
   *					{list} => {N/A |1}	@n
   */
	ret_value = xmlListEmpty(list);
	DTS_CHECK_EQ_MESSAGE("xmlListEmpty", (void *)ret_value, (void *)1, "xmlListEmpty Failed");

	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListFrontP01
	* @brief		xmlLinkPtr	xmlListFront (xmlListPtr l)
	* @desc			Positive Test for Getting the first element in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
					{xmlListPtr(list)} => {N/A |xmlLinkPtr}	@n
					input2: [N/A, N/A]	@n
					{xmlListPtr(list)} => {N/A |xmlLinkPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListFrontP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	xmlListPtr list = xmlListCreate(NULL,Compare);
	DTS_CHECK_NE_MESSAGE("xmlListFront", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");

  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list} => {N/A |xmlLinkPtr}	@n
   */	
	xmlLinkPtr val = xmlListFront(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListFront", (void *)(strcmp(ret,"test")), (void *)0, "xmlListFront Failed");

	ret_value = xmlListRemoveAll(list,ch);
  /**
   * @remarks   input2: [N/A, N/A]	@n
   *					{list} => {N/A |xmlLinkPtr}	@n
   */	
	val = xmlListFront(list);
	char* ret1 = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListFront", (void *)(strcmp(ret1,"test")), (void *)0, "xmlListFront Failed");
	
	//clear list
	xmlListClear(list);
	ret_value = xmlListEmpty(list);
	DTS_CHECK_EQ_MESSAGE("xmlListFront", (void *)ret_value, (void *)1, "xmlListClear Failed");

	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListEndP01
	* @brief		xmlLinkPtr	xmlListEnd	(xmlListPtr l)
	* @desc			Positive Test for Getting the last element in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
					{xmlListPtr(list)} => {N/A |xmlLinkPtr}	@n
					input2: [N/A, N/A]	@n
					{xmlListPtr(list)} => {N/A |xmlLinkPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListEndP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	xmlListPtr list = xmlListCreate(NULL,Compare);
	DTS_CHECK_NE_MESSAGE("xmlListEnd", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListEnd", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListEnd", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list} => {N/A |xmlLinkPtr}	@n
   */		
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListEnd", (void *)(strcmp(ret,"hello")), (void *)0, "xmlListEnd Failed");

	ret_value = xmlListRemoveAll(list,ch1);
  /**
   * @remarks   input2: [N/A, N/A]	@n
   *					{list} => {N/A |xmlLinkPtr}	@n
   */	
	val = xmlListEnd(list);
	char* ret1 = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListEnd", (void *)(strcmp(ret1,"hello")), (void *)0, "xmlListEnd Failed");
	
	//clear list
	xmlListClear(list);
	ret_value = xmlListEmpty(list);
	DTS_CHECK_EQ_MESSAGE("xmlListEnd", (void *)ret_value, (void *)1, "xmlListClear Failed");
	xmlListDelete(list);
}
	/**    
	* @test			UTcxmlListSizeP01
	* @brief		int	xmlListSize	(xmlListPtr l)
	* @desc			Positive Test for Getting the number of elements in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
					{xmlListPtr(list)} => {N/A |2}	@n
					input2: [ List(list) is cleared, N/A]	@n
					{xmlListPtr(list)} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListSizeP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListSize", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListSize", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListSize", (void *)ret_value, (void *)0, "xmlListAppend Failed");

  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list} => {N/A |2}	@n
   */		
	ret_value = xmlListSize(list);
	DTS_CHECK_EQ_MESSAGE("xmlListSize", (void *)ret_value, (void *)2, "xmlListSize Failed");
	
	//clear list
	xmlListClear(list);
  /**
   * @remarks   input2: [ List(list) is cleared, N/A]	@n
   *					{list} => {N/A |0}	@n
   */	
	ret_value = xmlListSize(list);
	DTS_CHECK_EQ_MESSAGE("xmlListSize", (void *)ret_value, (void *)0, "xmlListSize Failed");

	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListPopBackP01
	* @brief		void xmlListPopBack (xmlListPtr l)
	* @desc			Positive Test for Removing the last element in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
    				{xmlListPtr(list)} => {N/A |N/A}	@n
					input2: [ List(list) is cleared , N/A]	@n
    				{xmlListPtr(list)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/

static void UTcxmlListPopFrontP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListPopFront", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListPopFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListPopFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
//pop

  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */	
	xmlListPopFront(list);
	
	xmlLinkPtr val = xmlListFront(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListPopFront", (void *)(strcmp(ret,"2")), (void *)0, "xmlListAppend Failed");
	
	//clear list
	xmlListClear(list);
  /**
   * @remarks   input2: [ List(list) is cleared , N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */	
	xmlListPopFront(list);

	xmlListDelete(list);
}
/**    
	* @test			UTcxmlListPopBackP01
	* @brief		void xmlListPopBack (xmlListPtr l)
	* @desc			Positive Test for Removing the last element in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
    				{xmlListPtr(list)} => {N/A |N/A}	@n
					input2: [ List(list) is cleared , N/A]	@n
    				{xmlListPtr(list)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListPopBackP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListPopFront", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListPopFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListPopFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
//pop
  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */	
	xmlListPopBack(list);
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListPopFront", (void *)(strcmp(ret,"1")), (void *)0, "xmlListAppend Failed");

//clear list
	xmlListClear(list);
  /**
   * @remarks   input2: [ List(list) is cleared , N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */	
	xmlListPopBack(list);

	xmlListDelete(list);
	
}
	/**    
	* @test			UTcxmlListPushFrontP01
	* @brief		int xmlListPushFront (xmlListPtr l, void * data)
	* @desc			Positive Test for adding the new data at the beginning of the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
					{xmlListPtr(list),"first"} => {N/A |1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListPushFrontP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	void* ch2 = (void*)("first");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListPushFront", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListPushFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListPushFront", (void *)ret_value, (void *)0, "xmlListAppend Failed");

  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list,"first"} => {N/A |1}	@n
   */	
	ret_value = xmlListPushFront(list,ch2);
	DTS_CHECK_EQ_MESSAGE("xmlListPushFront", (void *)ret_value, (void *)1, "xmlListAppend Failed");
	
	
	xmlLinkPtr val = xmlListFront(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListPushFront", (void *)(strcmp(ret,"first")), (void *)0, "xmlListAppend Failed");

	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListPushBackP01
	* @brief		int xmlListPushBack (xmlListPtr l, void * data)
	* @desc			Positive Test for adding the new data at the end of the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
					{xmlListPtr(list),"last"} => {N/A |1}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListPushBackP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	void* ch2 = (void*)("last");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListPushBack", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListPushBack", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListPushBack", (void *)ret_value, (void *)0, "xmlListAppend Failed");

  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list,"last"} => {N/A |1}	@n
   */	
	ret_value = xmlListPushBack(list,ch2);
	DTS_CHECK_EQ_MESSAGE("xmlListPushBack", (void *)ret_value, (void *)1, "xmlListPushBack Failed");
	
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListPushBack", (void *)(strcmp(ret,"last")), (void *)0, "xmlListEnd Failed");

	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlLinkGetDataP01
	* @brief		void *	xmlLinkGetData	(xmlLinkPtr lk)
	* @desc			Positive Test to see returns
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having value "hello", N/A]	@n
					{xmlLinkPtr(lk)} => {N/A |"hello"}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlLinkGetDataP01() 
{
	void* ch = (void*)("hello");
	void* ch1 = (void*)("test");
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlLinkGetData", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlLinkGetData", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	xmlLinkPtr val = xmlListEnd(list);
  /**
   * @remarks   input1: [ List(list) is created having value "hello", N/A]	@n
   *					{xmlLinkPtr of "hello"} => {N/A |"hello"}	@n
   */	
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlLinkGetData", (void *)(strcmp(ret,"hello")), (void *)0, "xmlLinkGetData Failed");
	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListReverseP01
	* @brief		void xmlListReverse (xmlListPtr l)
	* @desc			Positive Test for Reversing the order of the elements in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "test","hello", N/A]	@n
					{xmlListPtr(list)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListReverseP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");

	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListReverse", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListReverse", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListReverse", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "test","hello", N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */	
	xmlListReverse(list);
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListReverse", (void *)(strcmp(ret,"1")), (void *)0, "xmlListReverse Failed");
	
	val = xmlListFront(list);
	ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListReverse", (void *)(strcmp(ret,"2")), (void *)0, "xmlListFront Failed");

	xmlListDelete(list);





}
	/**    
	* @test			UTcxmlListSortP01
	* @brief		void xmlListSort	(xmlListPtr l)
	* @desc			Positive Test for Sorting all the elements in the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "3","2","4","1", N/A]	@n
					{xmlListPtr(list)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListSortP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");
	void* ch2 = (void*)("3");
	void* ch3 = (void*)("4");

	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListSort", (void *)list, (void *)NULL, "xmlListCreate Failed");

	int ret_value = xmlListAppend(list,ch2);
	DTS_CHECK_EQ_MESSAGE("xmlListSort", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListSort", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch3);
	DTS_CHECK_EQ_MESSAGE("xmlListSort", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListSort", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "3","2","4","1", N/A]	@n
   *					{list} => {N/A |N/A}	@n
   */	
	xmlListSort(list);
	
	xmlLinkPtr val = xmlListEnd(list);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListSort", (void *)(strcmp(ret,"4")), (void *)0, "xmlListSort Failed");
	
	xmlListDelete(list);

}

static int count = 0;
int copy (const void *data, const void *user){

	count++;
	return count;
}
	/**    
	* @test			UTcxmlListWalkP01
	* @brief		void xmlListWalk (xmlListPtr l, xmlListWalker walker, const void * user)
	* @desc			Positive Test to Walk all the element of the first from first to last and apply the walker function to it
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "3","2","4","1" \n Function copy that counts the number of elements, N/A]	@n
					{xmlListPtr(list),xmlListWalker(walker),const void *(user)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListWalkP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");	
	void* ch2 = (void*)("3");
	void* ch3 = (void*)("4");

	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListWalk", (void *)list, (void *)NULL, "xmlListCreate Failed");

	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListWalk", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListWalk", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	xmlListPtr dupList = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListWalk", (void *)dupList, (void *)NULL, "xmlListAppend Failed");
  /**
   * @remarks   input1: [ List(list) is created having values "3","2","4","1" \n Function copy that counts the number of elements, N/A]	@n
   *					{list,copy,dupList} => {N/A |N/A}	@n
   */	
    //reset count
	count = 0;

	xmlListWalk(list,copy,(void*)dupList);
	DTS_CHECK_EQ_MESSAGE("xmlListWalk", (void *)count, (void *)2, "xmlListAppend Failed");
	
	xmlListDelete(list);
	xmlListDelete(dupList);
	
}
	/**    
	* @test			UTcxmlListReverseWalkP01
	* @brief		void xmlListReverseWalk (xmlListPtr l,xmlListWalker walker, const void * user)
	* @desc			Positive Test to Walk all the element of the list in reverse order and apply the walker function to it
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "3","2","4","1" \n Function copy that counts the number of elements, N/A]	@n
					{xmlListPtr(list),xmlListWalker(walker),const void * (user)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListReverseWalkP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");	
	void* ch2 = (void*)("3");
	void* ch3 = (void*)("4");

	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListReverseWalk", (void *)list, (void *)NULL, "xmlListCreate Failed");

	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListReverseWalk", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListReverseWalk", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListReverseWalk", (void *)ret_value, (void *)0, "xmlListAppend Failed");


	//set count to 0
	count = 0;
	xmlListPtr dupList = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListReverseWalk", (void *)dupList, (void *)NULL, "xmlListCreate Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "3","2","4","1" \n Function copy that counts the number of elements, N/A]	@n
   *					{list,copy,dupList} => {N/A |N/A}	@n
   */	
	xmlListReverseWalk(list,copy,(void*)dupList);
	DTS_CHECK_EQ_MESSAGE("xmlListReverseWalk", (void *)count, (void *)3, "xmlListReverseWalk Failed");
	

	xmlListDelete(list);
	xmlListDelete(dupList);
		
}
	/**    
	* @test			UTcxmlListMergeP01
	* @brief		void xmlListMerge (xmlListPtr l1, xmlListPtr l2)
	* @desc			Positive Test for including all the elements of the second list in the first one and clear the second list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "1","2" \n 
					List(list2) is created having values "3","4" , N/A]	@n
					{xmlListPtr(list),xmlListPtr(list2)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListMergeP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");	
	void* ch2 = (void*)("3");
	void* ch3 = (void*)("4");

	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListMerge", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListMerge", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListMerge", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	xmlListPtr list2 = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListMerge", (void *)list2, (void *)NULL, "xmlListCreate Failed");
	
	ret_value = xmlListAppend(list2,ch2);
	DTS_CHECK_EQ_MESSAGE("xmlListMerge", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list2,ch3);
	DTS_CHECK_EQ_MESSAGE("xmlListMerge", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
 /**
   * @remarks   input1: [ List(list) is created having values "1","2" \n 
   *					  List(list2) is created having values "3","4" , N/A]	@n
   *					{list,list2} => {N/A |N/A}	@n
   */	
	xmlListMerge(list,list2);
	ret_value = xmlListSize(list);
	DTS_CHECK_EQ_MESSAGE("xmlListMerge", (void *)ret_value, (void *)4, "xmlListAppend Failed");
	
	ret_value = xmlListSize(list2);
	DTS_CHECK_EQ_MESSAGE("xmlListMerge", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	xmlListDelete(list);
	xmlListDelete(list2);


}
	/**    
	* @test			UTcxmlListDupP01
	* @brief		xmlListPtr	xmlListDup (const xmlListPtr old)>
	* @desc			Positive Test for duplicating the list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "1","2", N/A]	@n
					{xmlListPtr(list)} => {N/A |xmlListPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListDupP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");	
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListDup", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListDup", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListDup", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
  /**
   * @remarks   input1: [ List(list) is created having values "1","2", N/A]	@n
   *					{list} => {N/A |xmlListPtr}	@n
   */	
	xmlListPtr dupList = xmlListDup(list);
	ret_value = xmlListSize(list);
	DTS_CHECK_EQ_MESSAGE("xmlListDup", (void *)ret_value, (void *)2, "xmlListAppend Failed");
	
	xmlLinkPtr val = xmlListEnd(dupList);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListDup", (void *)(strcmp(ret,"2")), (void *)0, "xmlListAppend Failed");

	val = xmlListFront(dupList);
	ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListDup", (void *)(strcmp(ret,"1")), (void *)0, "xmlListAppend Failed");

	xmlListDelete(dupList);
	xmlListDelete(list);

}
	/**    
	* @test			UTcxmlListCopyP01
	* @brief		int xmlListCopy (xmlListPtr cur, const xmlListPtr old)
	* @desc			Positive Test for Moving all the element from the old list in the new list
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [ List(list) is created having values "1","2"\n
					List(list2)is created with NULL value , N/A]	@n
					{xmlListPtr(list2),xmlListPtr(list)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcxmlListCopyP01() 
{
	void* ch = (void*)("1");
	void* ch1 = (void*)("2");	
	xmlListPtr list = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListCopy", (void *)list, (void *)NULL, "xmlListCreate Failed");
	
	int ret_value = xmlListAppend(list,ch);
	DTS_CHECK_EQ_MESSAGE("xmlListCopy", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	ret_value = xmlListAppend(list,ch1);
	DTS_CHECK_EQ_MESSAGE("xmlListCopy", (void *)ret_value, (void *)0, "xmlListAppend Failed");

	xmlListPtr list2 = xmlListCreate(NULL,Compare1);
	DTS_CHECK_NE_MESSAGE("xmlListCopy", (void *)list2, (void *)NULL, "xmlListCreate Failed");
  /**
   * @remarks   input1: [ List(list) is created having values "1","2"\n
   *					  List(list2)is created with NULL value , N/A]	@n
   *					{list2,list} => {N/A |N/A}	@n
   */	
	ret_value = xmlListCopy(list2,list);
	DTS_CHECK_EQ_MESSAGE("xmlListCopy", (void *)ret_value, (void *)0, "xmlListAppend Failed");
	
	xmlLinkPtr val = xmlListEnd(list2);
	char* ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListCopy", (void *)(strcmp(ret,"2")), (void *)0, "xmlListAppend Failed");

	val = xmlListFront(list2);
	ret = (char*)xmlLinkGetData(val);
	DTS_CHECK_EQ_MESSAGE("xmlListCopy", (void *)(strcmp(ret,"1")), (void *)0, "xmlListAppend Failed");

	xmlListDelete(list2);
	xmlListDelete(list);
	
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
	{UTcxmlListCreateP01,1},
	{UTcxmlListSearchP01,2},
	{UTcxmlListReverseSearchP01,3},
	{UTcxmlListInsertP01,4},
	{UTcxmlListAppendP01,5},
	{UTcxmlListDeleteP01,6},
	{UTcxmlListRemoveFirstP01,7},
	{UTcxmlListRemoveLastP01,8},
	{UTcxmlListRemoveAllP01,9},
	{UTcxmlListClearP01,10},
	
	{UTcxmlListEmptyP01,11},
	{UTcxmlListFrontP01,12},
	{UTcxmlListEndP01,13},
	{UTcxmlListSizeP01,14},
	{UTcxmlListPopFrontP01,15},
	{UTcxmlListPopBackP01,16},
	{UTcxmlListPushFrontP01,17},
	{UTcxmlListPushBackP01,18},
	{UTcxmlLinkGetDataP01,19},
	{UTcxmlListReverseP01,20},
	
	{UTcxmlListSortP01,21},
	{UTcxmlListWalkP01,22},
	{UTcxmlListReverseWalkP01,23},
	{UTcxmlListMergeP01,24},
	{UTcxmlListDupP01,25},
	{UTcxmlListCopyP01,26},
	{ NULL, 0 },
	
};
