// dictionary-test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../dictionary/Cdictonary.h"


using namespace std;
struct Cdictonary_
{
	CDictonary dict;
};
typedef std::map<std::string, std::string> dictionaryType;
BOOST_FIXTURE_TEST_SUITE(dictt, Cdictonary_)

	BOOST_AUTO_TEST_CASE(Tranclate)
	{
		dict.SetDictionary({ {"dog", "собака"}, {"cat", "кошка"} });
		dict.SetReverseDictionary({ { "собака", "dog" },{ "кошка", "cat" } });
		BOOST_CHECK(dict.GetTranclate("dog") == "собака");
		BOOST_CHECK(dict.GetTranclate("qwery") == "");
	}

	BOOST_AUTO_TEST_CASE(AddWord)
	{
		dictionaryType rightDict = { { "dog", "собака" } };
		dict.AddTranslate("dog", "собака");
		BOOST_CHECK(dict.GetDictionary() == rightDict);
	}

	BOOST_AUTO_TEST_CASE(CheckReverseDictionary)
	{
		dict.SetDictionary( { { "12", "11" } });
		dict.CreateReverseDictionary();
		dictionaryType rightDict = { { "11", "12" } };
		BOOST_CHECK(dict.GetReverseDictionary() == rightDict);
	}
BOOST_AUTO_TEST_SUITE_END()