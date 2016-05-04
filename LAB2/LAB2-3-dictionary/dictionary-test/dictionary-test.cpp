// dictionary-test.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../dictionary/dictionary.h"
#include <map>

using namespace std;
BOOST_AUTO_TEST_SUITE(dictionaryTest)

	BOOST_AUTO_TEST_CASE(Tranclate)
	{
	map <string, string> dict = { {"dog", "������"}, {"cat", "�����"} };
	map <string, string> rdict = { { "������", "dog" },{ "�����", "cat" } };
	BOOST_CHECK_EQUAL(FindTranclate("dog", dict, rdict), "������");
	BOOST_CHECK_EQUAL(FindTranclate("qwerty", dict, rdict), "");
	}

	BOOST_AUTO_TEST_CASE(AddWord)
	{
	map <string, string> dict;
	map <string, string> rdict;
	map <string, string> rightDict = { { "dog", "������" } };
	AddTranslate("dog", "������", dict, rdict);
	BOOST_CHECK(dict == rightDict);
	}

	BOOST_AUTO_TEST_CASE(CheckReverseDictionary)
	{
		map <string, string> dict = { {"12", "11"} };
		map <string, string> rdict = CreatReverseDictionary(dict);
		map <string, string> rightDict = { { "11", "12" } };
	BOOST_CHECK(rdict == rightDict);
	}

BOOST_AUTO_TEST_SUITE_END()