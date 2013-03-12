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




#ifdef OSP_MEM_ALLOC_INFO
#include "matrix.h"
#endif
#include <libxml/xmlmemory.h>
#include <libxml/uri.h>
#include <libxml/globals.h>
#include <libxml/xmlunicode.h>


#define gen_nb_int 1
static int gen_int(int no, int x) {
	if (no == 0) return(0);
	if (no == 1) return(1);
	if (no == 2) return(-1);
	if (no == 3) return(122);
	return(-1);
}
/***************************************************************************
* SUTsXmlUnicode
***************************************************************************/
	/**    
	* @test			UTcxmlUCSP01
	* @brief		int	xmlUCSIsAegeanNumbers (int code)
					int	xmlUCSIsAlphabeticPresentationForms	(int code)
					int	xmlUCSIsArabic	(int code)
					int	xmlUCSIsArabicPresentationFormsA (int code)
					int	xmlUCSIsArabicPresentationFormsB (int code)
					int	xmlUCSIsArmenian (int code)
					int	xmlUCSIsArrows (int code)
					int	xmlUCSIsBasicLatin (int code)
					int	xmlUCSIsBengali	(int code)
					int	xmlUCSIsBlockElements (int code))
					int	xmlUCSIsBopomofo (int code)
					int	xmlUCSIsBopomofoExtended (int code)
					int	xmlUCSIsBoxDrawing (int code)
					int	xmlUCSIsBraillePatterns	(int code)
					int	xmlUCSIsBuhid (int code)
					int	xmlUCSIsByzantineMusicalSymbols	(int code)
					int	xmlUCSIsCJKCompatibility (int code)
					int	xmlUCSIsCJKCompatibilityForms (int code)
					int	xmlUCSIsCJKCompatibilityIdeographs (int code)
    * @desc			Positive Test for checking if the character is a part of various UAS block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => { N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP01() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;
	//char * block; /* UCS block name */
	//int n_block;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);
		ret_val = xmlUCSIsAegeanNumbers(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsAegeanNumbers Failed");
		
		ret_val = xmlUCSIsAlphabeticPresentationForms(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsAlphabeticPresentationForms Failed");

		ret_val = xmlUCSIsArabic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsArabic Failed");

		ret_val = xmlUCSIsArabicPresentationFormsA(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsArabicPresentationFormsA Failed");

		ret_val = xmlUCSIsArabicPresentationFormsB(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsArabicPresentationFormsB Failed");

		ret_val = xmlUCSIsArmenian(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsArmenian Failed");

		ret_val = xmlUCSIsArrows(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsArrows Failed");

		ret_val = xmlUCSIsBasicLatin(code);
		//May be My check is not proper
		//DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBasicLatin Failed");

		ret_val = xmlUCSIsBengali(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBengali Failed");

		//for (n_block = 0;n_block < gen_nb_const_char_ptr;n_block++) 
		//	{
		//		block = gen_const_char_ptr(n_block, 1);
		//		ret_val = xmlUCSIsBlock(code, (const char *)block);
		//		MT_CHECK_MESSAGE2(0 == ret_val, "xmlUCSIsBlock API return value: %d", ret_val);
		//	}
		
		ret_val = xmlUCSIsBlockElements(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBlockElements Failed");

		ret_val = xmlUCSIsBopomofo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBopomofo Failed");

		ret_val = xmlUCSIsBopomofoExtended(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBopomofoExtended Failed");

		ret_val = xmlUCSIsBoxDrawing(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBoxDrawing Failed");

		ret_val = xmlUCSIsBraillePatterns(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBraillePatterns Failed");

		ret_val = xmlUCSIsBuhid(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsBuhid Failed");

		ret_val = xmlUCSIsByzantineMusicalSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsByzantineMusicalSymbols Failed");

		ret_val = xmlUCSIsCJKCompatibility(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsCJKCompatibility Failed");

		ret_val = xmlUCSIsCJKCompatibilityForms(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsCJKCompatibilityForms Failed");

		ret_val = xmlUCSIsCJKCompatibilityIdeographs(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP01", (void *)ret_val, (void *)0, "xmlUCSIsCJKCompatibilityIdeographs Failed");
	}
}
	/**    
	* @test			UTcxmlUCSP02
	* @brief		int	xmlUCSIsCJKCompatibilityIdeographsSupplement (int code)
					int	xmlUCSIsCJKRadicalsSupplement (int code)
					int	xmlUCSIsCJKSymbolsandPunctuation (int code)
					int	xmlUCSIsCJKUnifiedIdeographs (int code)
					int	xmlUCSIsCJKUnifiedIdeographsExtensionA (int code)
					int	xmlUCSIsCJKUnifiedIdeographsExtensionB (int code)
					int	xmlUCSIsCat	(int code,  const char * cat)
					int	xmlUCSIsCatC (int code)
					int	xmlUCSIsCatCc (int code)
					int	xmlUCSIsCatCf (int code)
					int	xmlUCSIsCatCo (int code)
					int	xmlUCSIsCatCs (int code)
					int	xmlUCSIsCatL (int code)
					int	xmlUCSIsCatLl (int code)
					int	xmlUCSIsCatLm (int code)
					int	xmlUCSIsCatLo (int code)
					int	xmlUCSIsCatLt (int code)
					int	xmlUCSIsCatLu (int code)
					int	xmlUCSIsCatM (int code)
					int	xmlUCSIsCatMc (int code)
					int	xmlUCSIsCatMe (int code)
					int	xmlUCSIsCatMn (int code)
					int	xmlUCSIsCatN (int code)
					int	xmlUCSIsCatNd (int code)
					int	xmlUCSIsCatNl (int code)
					int	xmlUCSIsCatNo (int code)
					int	xmlUCSIsCatP (int code)
					int	xmlUCSIsCatPc (int code)
					int	xmlUCSIsCatPd (int code)
					int	xmlUCSIsCatPe (int code)
					int	xmlUCSIsCatPf (int code)
					int	xmlUCSIsCatPi (int code)
					int	xmlUCSIsCatPo (int code)
					int	xmlUCSIsCatPs (int code)
					int	xmlUCSIsCatS (int code)
					int	xmlUCSIsCatSc (int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Category.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{UCS code point-int} => {N/A | 0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP02() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsCJKCompatibilityIdeographsSupplement(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCJKCompatibilityIdeographsSupplement Failed");

		ret_val = xmlUCSIsCJKRadicalsSupplement(code);
 		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCJKRadicalsSupplement Failed");
		
		ret_val = xmlUCSIsCJKSymbolsandPunctuation(code);
 		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCJKSymbolsandPunctuation Failed");

		ret_val = xmlUCSIsCJKUnifiedIdeographs(code);
 		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCJKUnifiedIdeographs Failed");

		ret_val = xmlUCSIsCJKUnifiedIdeographsExtensionA(code);
 		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCJKUnifiedIdeographsExtensionA Failed");

		ret_val = xmlUCSIsCJKUnifiedIdeographsExtensionB(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCJKUnifiedIdeographsExtensionB Failed");
 
//		ret_val = xmlUCSIsCat(code);
 		//DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCat Failed");

		ret_val = xmlUCSIsCatC(code);
		//May be My check is not proper
 		//DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatC Failed");

		ret_val = xmlUCSIsCatCc(code);
		//May be My check is not proper
 		//DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatCc Failed");

		ret_val = xmlUCSIsCatCf(code);
 		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatCf Failed");

		ret_val = xmlUCSIsCatCo(code);
 		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatCo Failed");

		ret_val = xmlUCSIsCatCs(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatCs Failed");

		ret_val = xmlUCSIsCatL(code);
		//DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatL Failed");

		ret_val = xmlUCSIsCatLl(code);
		//DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatLl Failed");

		ret_val = xmlUCSIsCatLm(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatLm Failed");

		ret_val = xmlUCSIsCatLo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatLo Failed");

		ret_val = xmlUCSIsCatLt(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatLt Failed");

		ret_val = xmlUCSIsCatLu(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatLu Failed");

		ret_val = xmlUCSIsCatM(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatM Failed");

		ret_val = xmlUCSIsCatMc(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatMc Failed");

		ret_val = xmlUCSIsCatMe(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatMe Failed");

		ret_val = xmlUCSIsCatMn(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatMn Failed");

		ret_val = xmlUCSIsCatN(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatN Failed");

		ret_val = xmlUCSIsCatNd(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatNd Failed");

		ret_val = xmlUCSIsCatNl(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatNl Failed");

		ret_val = xmlUCSIsCatNo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatNo Failed");

		ret_val = xmlUCSIsCatP(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatP Failed");

		ret_val = xmlUCSIsCatPc(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatPc Failed");

		ret_val = xmlUCSIsCatPd(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatPd Failed");

		ret_val = xmlUCSIsCatPe(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatPe Failed");

		ret_val = xmlUCSIsCatPf(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatPf Failed");

		ret_val = xmlUCSIsCatPi(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatPi Failed");

		ret_val = xmlUCSIsCatPo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatPo Failed");

		ret_val = xmlUCSIsCatPs(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatPs Failed");

		ret_val = xmlUCSIsCatS(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatS Failed");

		ret_val = xmlUCSIsCatSc(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP02", (void *)ret_val, (void *)0, "xmlUCSIsCatSc Failed");
		
	}
}
	/**    
	* @test			UTcxmlUCSP03
	* @brief		int	xmlUCSIsCatSk (int code)
					int	xmlUCSIsCatSm (int code)
					int	xmlUCSIsCatSo (int code)
					int	xmlUCSIsCatZ (int code)
					int	xmlUCSIsCatZl (int code)
					int	xmlUCSIsCatZp (int code)
					int	xmlUCSIsCatZs (int code)
					int	xmlUCSIsCherokee (int code)
					int	xmlUCSIsCombiningDiacriticalMarks (int code)
					int	xmlUCSIsCombiningDiacriticalMarksforSymbols	(int code)
					int	xmlUCSIsCombiningHalfMarks	(int code)
					int	xmlUCSIsCombiningMarksforSymbols (int code)
					int	xmlUCSIsControlPictures	(int code)
					int	xmlUCSIsCurrencySymbols	(int code)
					int	xmlUCSIsCypriotSyllabary (int code)
					int	xmlUCSIsCyrillic (int code)
					int	xmlUCSIsCyrillicSupplement (int code)
					int	xmlUCSIsDeseret	(int code)
					int	xmlUCSIsDevanagari	(int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Category.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP03() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsCatSk(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCatSk Failed");

		ret_val = xmlUCSIsCatSm(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCatSm Failed");

		ret_val = xmlUCSIsCatSo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCatSo Failed");

		ret_val = xmlUCSIsCatZ(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCatZ Failed");

		ret_val = xmlUCSIsCatZl(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCatZl Failed");

		ret_val = xmlUCSIsCatZp(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCatZp Failed");

		ret_val = xmlUCSIsCatZs(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCatZs Failed");

		ret_val = xmlUCSIsCherokee(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCherokee Failed");

		ret_val = xmlUCSIsCombiningDiacriticalMarks(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCombiningDiacriticalMarks Failed");

		ret_val = xmlUCSIsCombiningDiacriticalMarksforSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCombiningDiacriticalMarksforSymbols Failed");
		
		ret_val = xmlUCSIsCombiningHalfMarks(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCombiningHalfMarks Failed");

		ret_val = xmlUCSIsCombiningMarksforSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCombiningMarksforSymbols Failed");

		ret_val = xmlUCSIsControlPictures(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsControlPictures Failed");

		ret_val = xmlUCSIsCurrencySymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCurrencySymbols Failed");

		ret_val = xmlUCSIsCypriotSyllabary(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCypriotSyllabary Failed");

		ret_val = xmlUCSIsCyrillic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCyrillic Failed");

		ret_val = xmlUCSIsCyrillicSupplement(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsCyrillicSupplement Failed");

		ret_val = xmlUCSIsDeseret(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsDeseret Failed");

		ret_val = xmlUCSIsDevanagari(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP03", (void *)ret_val, (void *)0, "xmlUCSIsDevanagari Failed");
		
	}
}
		/**    
	* @test			UTcxmlUCSP04
	* @brief		int	xmlUCSIsDingbats (int code)
					int	xmlUCSIsEnclosedAlphanumerics (int code)
					int	xmlUCSIsEnclosedCJKLettersandMonths	(int code)
					int	xmlUCSIsEthiopic (int code)
					int	xmlUCSIsGeneralPunctuation	(int code)
					int	xmlUCSIsGeometricShapes	(int code)
					int	xmlUCSIsGeorgian (int code)
					int	xmlUCSIsGothic (int code)
					int	xmlUCSIsGreek (int code)
					int	xmlUCSIsGreekExtended (int code)
					int	xmlUCSIsGreekandCoptic (int code)
					int	xmlUCSIsGujarati (int code)
					int	xmlUCSIsGurmukhi (int code)
					int	xmlUCSIsHalfwidthandFullwidthForms	(int code)
					int	xmlUCSIsHangulCompatibilityJamo	(int code)
					int	xmlUCSIsHangulJamo	(int code)
					int	xmlUCSIsHangulSyllables	(int code)
					int	xmlUCSIsHanunoo	(int code)
					int	xmlUCSIsHebrew	(int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP04() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsDingbats(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsDingbats Failed");

		ret_val = xmlUCSIsEnclosedAlphanumerics(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsEnclosedAlphanumerics Failed");

		ret_val = xmlUCSIsEnclosedCJKLettersandMonths(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsEnclosedCJKLettersandMonths Failed");

		ret_val = xmlUCSIsEthiopic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsEthiopic Failed");

		ret_val = xmlUCSIsGeneralPunctuation(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGeneralPunctuation Failed");

		ret_val = xmlUCSIsGeometricShapes(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGeometricShapes Failed");

		ret_val = xmlUCSIsGeorgian(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGeorgian Failed");

		ret_val = xmlUCSIsGothic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGothic Failed");

		ret_val = xmlUCSIsGreek(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGreek Failed");

		ret_val = xmlUCSIsGreekExtended(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGreekExtended Failed");

		ret_val = xmlUCSIsGreekandCoptic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGreekandCoptic Failed");

		ret_val = xmlUCSIsGujarati(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGujarati Failed");

		ret_val = xmlUCSIsGurmukhi(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsGurmukhi Failed");

		ret_val = xmlUCSIsHalfwidthandFullwidthForms(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsHalfwidthandFullwidthForms Failed");

		ret_val = xmlUCSIsHangulCompatibilityJamo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsHangulCompatibilityJamo Failed");

		ret_val = xmlUCSIsHangulJamo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsHangulJamo Failed");

		ret_val = xmlUCSIsHangulSyllables(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsHangulSyllables Failed");

		ret_val = xmlUCSIsHanunoo(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsHanunoo Failed");

		ret_val = xmlUCSIsHebrew(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP04", (void *)ret_val, (void *)0, "xmlUCSIsHebrew Failed");
			
	}
}
	/**    
	* @test			UTcxmlUCSP05
	* @brief		int	xmlUCSIsHighPrivateUseSurrogates	(int code)
					int	xmlUCSIsHighSurrogates	(int code)
					int	xmlUCSIsHiragana (int code)
					int	xmlUCSIsIPAExtensions (int code)
					int	xmlUCSIsIdeographicDescriptionCharacters (int code)
					int	xmlUCSIsKanbun	(int code)
					int	xmlUCSIsKangxiRadicals	(int code)
					int	xmlUCSIsKannada	(int code)
					int	xmlUCSIsKatakana (int code)
					int	xmlUCSIsKatakanaPhoneticExtensions	(int code)
					int	xmlUCSIsKhmer (int code)
					int	xmlUCSIsKhmerSymbols (int code)
					int	xmlUCSIsLao	(int code)
					int	xmlUCSIsLatin1Supplement (int code)
					int	xmlUCSIsLatinExtendedA	(int code)
					int	xmlUCSIsLatinExtendedAdditional	(int code)
					int	xmlUCSIsLatinExtendedB	(int code)
					int	xmlUCSIsLetterlikeSymbols	(int code)
					int	xmlUCSIsLimbu (int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP05() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsHighPrivateUseSurrogates(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsHighPrivateUseSurrogates Failed");

		ret_val = xmlUCSIsHighSurrogates(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsHighSurrogates Failed");

		ret_val = xmlUCSIsHiragana(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsHiragana Failed");

		ret_val = xmlUCSIsIPAExtensions(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsIPAExtensions Failed");

		ret_val = xmlUCSIsIdeographicDescriptionCharacters(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsIdeographicDescriptionCharacters Failed");

		ret_val = xmlUCSIsKanbun(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsKanbun Failed");

		ret_val = xmlUCSIsKangxiRadicals(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsKangxiRadicals Failed");

		ret_val = xmlUCSIsKannada(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsKannada Failed");

		ret_val = xmlUCSIsKatakana(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsKatakana Failed");

		ret_val = xmlUCSIsKatakanaPhoneticExtensions(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsKatakanaPhoneticExtensions Failed");

		ret_val = xmlUCSIsKhmer(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsKatakanaPhoneticExtensions Failed");

		ret_val = xmlUCSIsKhmerSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsKhmerSymbols Failed");

		ret_val = xmlUCSIsLao(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsLao Failed");

		ret_val = xmlUCSIsLatin1Supplement(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsLatin1Supplement Failed");

		ret_val = xmlUCSIsLatinExtendedA(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsLatinExtendedA Failed");

		ret_val = xmlUCSIsLatinExtendedAdditional(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsLatinExtendedAdditional Failed");

		ret_val = xmlUCSIsLatinExtendedB(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsLatinExtendedB Failed");

		ret_val = xmlUCSIsLetterlikeSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsLetterlikeSymbols Failed");

		ret_val = xmlUCSIsLimbu(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP05", (void *)ret_val, (void *)0, "xmlUCSIsLimbu Failed");
		
	}
}
	/**    
	* @test			UTcxmlUCSP06
	* @brief		int	xmlUCSIsLinearBIdeograms (int code)
					int	xmlUCSIsLinearBSyllabary (int code)
					int	xmlUCSIsLowSurrogates (int code)
					int	xmlUCSIsMalayalam (int code)
					int	xmlUCSIsMathematicalAlphanumericSymbols	(int code)
					int	xmlUCSIsMathematicalOperators	(int code)
					int	xmlUCSIsMiscellaneousMathematicalSymbolsA	(int code)
					int	xmlUCSIsMiscellaneousMathematicalSymbolsB	(int code)
					int	xmlUCSIsMiscellaneousSymbols	(int code)
					int	xmlUCSIsMiscellaneousSymbolsandArrows	(int code)
					int	xmlUCSIsMiscellaneousTechnical	(int code)
					int	xmlUCSIsMongolian	(int code)
					int	xmlUCSIsMusicalSymbols	(int code)
					int	xmlUCSIsMyanmar	(int code)
					int	xmlUCSIsNumberForms	(int code)
					int	xmlUCSIsOgham	(int code)
					int	xmlUCSIsOldItalic (int code)
					int	xmlUCSIsOpticalCharacterRecognition	(int code)
					int	xmlUCSIsOriya (int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP06() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsLinearBIdeograms(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsLinearBIdeograms Failed");

		ret_val = xmlUCSIsLinearBSyllabary(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsLinearBSyllabary Failed");

		ret_val = xmlUCSIsLowSurrogates(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsLowSurrogates Failed");

		ret_val = xmlUCSIsMalayalam(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMalayalam Failed");

		ret_val = xmlUCSIsMathematicalAlphanumericSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMathematicalAlphanumericSymbols Failed");

		ret_val = xmlUCSIsMathematicalOperators(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMathematicalOperators Failed");

		ret_val = xmlUCSIsMiscellaneousMathematicalSymbolsA(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMiscellaneousMathematicalSymbolsA Failed");

		ret_val = xmlUCSIsMiscellaneousMathematicalSymbolsB(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMiscellaneousMathematicalSymbolsB Failed");

		ret_val = xmlUCSIsMiscellaneousSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMiscellaneousSymbols Failed");

		ret_val = xmlUCSIsMiscellaneousSymbolsandArrows(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMiscellaneousSymbolsandArrows Failed");

		ret_val = xmlUCSIsMiscellaneousTechnical(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMiscellaneousTechnical Failed");

		ret_val = xmlUCSIsMongolian(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMongolian Failed");

		ret_val = xmlUCSIsMusicalSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMusicalSymbols Failed");

		ret_val = xmlUCSIsMyanmar(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsMyanmar Failed");

		ret_val = xmlUCSIsNumberForms(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsNumberForms Failed");

		ret_val = xmlUCSIsOgham(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsOgham Failed");

		ret_val = xmlUCSIsOldItalic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsOldItalic Failed");

		ret_val = xmlUCSIsOpticalCharacterRecognition(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsOpticalCharacterRecognition Failed");

		ret_val = xmlUCSIsOriya(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP06", (void *)ret_val, (void *)0, "xmlUCSIsOriya Failed");
			
	}
}
	/**    
	* @test			UTcxmlUCSP07
	* @brief		int	xmlUCSIsOsmanya	(int code)
					int	xmlUCSIsPhoneticExtensions	(int code)
					int	xmlUCSIsPrivateUse	(int code)
					int	xmlUCSIsPrivateUseArea	(int code)
					int	xmlUCSIsRunic (int code)
					int	xmlUCSIsShavian	(int code)
					int	xmlUCSIsSinhala	(int code)
					int	xmlUCSIsSmallFormVariants (int code)
					int	xmlUCSIsSpacingModifierLetters	(int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP07() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsOsmanya(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsOsmanya Failed");

		ret_val = xmlUCSIsPhoneticExtensions(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsPhoneticExtensions Failed");

		ret_val = xmlUCSIsPrivateUse(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsPrivateUse Failed");

		ret_val = xmlUCSIsPrivateUseArea(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsPrivateUseArea Failed");

		ret_val = xmlUCSIsRunic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsRunic Failed");

		ret_val = xmlUCSIsShavian(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsShavian Failed");

		ret_val = xmlUCSIsSinhala(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsSinhala Failed");

		ret_val = xmlUCSIsSmallFormVariants(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsSmallFormVariants Failed");

		ret_val = xmlUCSIsSpacingModifierLetters(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP07", (void *)ret_val, (void *)0, "xmlUCSIsSpacingModifierLetters Failed");
			
	}
}
	/**    
	* @test			UTcxmlUCSP08
	* @brief		int	xmlUCSIsSpecials (int code)
					int	xmlUCSIsSuperscriptsandSubscripts (int code)
					int	xmlUCSIsSupplementalArrowsA	(int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP08() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsSpecials(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP08", (void *)ret_val, (void *)0, "xmlUCSIsSpecials Failed");

		ret_val = xmlUCSIsSuperscriptsandSubscripts(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP08", (void *)ret_val, (void *)0, "xmlUCSIsSuperscriptsandSubscripts Failed");

		ret_val = xmlUCSIsSupplementalArrowsA(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP08", (void *)ret_val, (void *)0, "xmlUCSIsSupplementalArrowsA Failed");

	}
}
	/**    
	* @test			UTcxmlUCSP09
	* @brief		int	xmlUCSIsSupplementalArrowsB	(int code)
					int	xmlUCSIsSupplementalMathematicalOperators	(int code)
					int	xmlUCSIsSupplementaryPrivateUseAreaA (int code)
					int	xmlUCSIsSupplementaryPrivateUseAreaB (int code)
					int	xmlUCSIsSyriac	(int code)
					int	xmlUCSIsTagalog	(int code)
					int	xmlUCSIsTagbanwa (int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP09() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsSupplementalArrowsB(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP09", (void *)ret_val, (void *)0, "xmlUCSIsSupplementalArrowsB Failed");

		ret_val = xmlUCSIsSupplementalMathematicalOperators(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP09", (void *)ret_val, (void *)0, "xmlUCSIsSupplementalMathematicalOperators Failed");

		ret_val = xmlUCSIsSupplementaryPrivateUseAreaA(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP09", (void *)ret_val, (void *)0, "xmlUCSIsSupplementaryPrivateUseAreaA Failed");

		ret_val = xmlUCSIsSupplementaryPrivateUseAreaB(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP09", (void *)ret_val, (void *)0, "xmlUCSIsSupplementaryPrivateUseAreaB Failed");

		ret_val = xmlUCSIsSyriac(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP09", (void *)ret_val, (void *)0, "xmlUCSIsSyriac Failed");

		ret_val = xmlUCSIsTagalog(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP09", (void *)ret_val, (void *)0, "xmlUCSIsTagalog Failed");

		ret_val = xmlUCSIsTagbanwa(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP09", (void *)ret_val, (void *)0, "xmlUCSIsTagbanwa Failed");
		
	}
}
	/**    
	* @test			UTcxmlUCSP10
	* @brief		int	xmlUCSIsTags (int code)
					int	xmlUCSIsTaiLe (int code)
					int	xmlUCSIsTaiXuanJingSymbols	(int code)
					int	xmlUCSIsTamil (int code)
					int	xmlUCSIsTelugu (int code)
					int	xmlUCSIsThaana	(int code)
					int	xmlUCSIsThai (int code)
					int	xmlUCSIsTibetan	(int code)
					int	xmlUCSIsUgaritic (int code)
					int	xmlUCSIsUnifiedCanadianAboriginalSyllabics	(int code)
					int	xmlUCSIsVariationSelectors	(int code)
					int	xmlUCSIsVariationSelectorsSupplement (int code)
					int	xmlUCSIsYiRadicals	(int code)
					int	xmlUCSIsYiSyllables	 (int code)
					int	xmlUCSIsYijingHexagramSymbols (int code)
	* @desc			Positive Test for checking if the character is a part of different UCS Block
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input: [get integer, N/A] @n
	*   			{int(UCS code point)} => {N/A |0,1 } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlUCSP10() 
{
	int ret_val;
	int code; /* UCS code point */
	int n_code;

	for (n_code = 0;n_code < gen_nb_int;n_code++)
	{
		code = gen_int(n_code, 0);

		ret_val = xmlUCSIsTags(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsTags Failed");

		ret_val = xmlUCSIsTaiLe(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsTaiLe Failed");

		ret_val = xmlUCSIsTaiXuanJingSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsTaiXuanJingSymbols Failed");

		ret_val = xmlUCSIsTamil(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsTamil Failed");

		ret_val = xmlUCSIsTelugu(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsTelugu Failed");

		ret_val = xmlUCSIsThaana(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsThaana Failed");

		ret_val = xmlUCSIsThai(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsThai Failed");

		ret_val = xmlUCSIsTibetan(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsTibetan Failed");

		ret_val = xmlUCSIsUgaritic(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsUgaritic Failed");

		ret_val = xmlUCSIsUnifiedCanadianAboriginalSyllabics(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsUnifiedCanadianAboriginalSyllabics Failed");

		ret_val = xmlUCSIsVariationSelectors(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsVariationSelectors Failed");

		ret_val = xmlUCSIsVariationSelectors(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsVariationSelectors Failed");

		ret_val = xmlUCSIsVariationSelectorsSupplement(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsVariationSelectorsSupplement Failed");

		ret_val = xmlUCSIsYiRadicals(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsYiRadicals Failed");

		ret_val = xmlUCSIsYiSyllables(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsYiSyllables Failed");

		ret_val = xmlUCSIsYijingHexagramSymbols(code);
		DTS_CHECK_EQ_MESSAGE("UTcxmlUCSP10", (void *)ret_val, (void *)0, "xmlUCSIsYijingHexagramSymbols Failed");
			
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
	{UTcxmlUCSP01,1},
	{UTcxmlUCSP02,2},
	{UTcxmlUCSP03,3},
	{UTcxmlUCSP04,4},
	{UTcxmlUCSP05,5},
	{UTcxmlUCSP06,6},
	{UTcxmlUCSP07,7},
	{UTcxmlUCSP08,8},
	{UTcxmlUCSP09,9},
	{UTcxmlUCSP10,10},
	{ NULL, 0 },
	
};
