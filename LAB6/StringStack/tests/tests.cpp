// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../StringStack/Stack.h"

struct StringStackFixture
{
	CStringStack stringStack;
};
BOOST_FIXTURE_TEST_SUITE(StringStack_tests, StringStackFixture)
BOOST_AUTO_TEST_CASE(push_string_stack)
{
	stringStack.push("qwerty");
	BOOST_CHECK(stringStack.get() == "qwerty");
}

BOOST_AUTO_TEST_CASE(check_is_empty_stringStack)
{
	BOOST_CHECK(stringStack.isEmpty() == true);
	stringStack.push("qwerty");
	BOOST_CHECK(stringStack.isEmpty() == false);
}

BOOST_AUTO_TEST_CASE(pop_element_in_stringStack)
{
	stringStack.push("qwerty");
	stringStack.pop();
	BOOST_CHECK(stringStack.isEmpty() == true);
}

BOOST_AUTO_TEST_CASE(check_get_element_in_stringStack)
{
	stringStack.push("qwerty");
	BOOST_CHECK(stringStack.get() == "qwerty");
}


BOOST_AUTO_TEST_SUITE_END()


