#include "stdafx.h"
#include "../StringStack/Stack.h"

struct StringStackFixture
{
	CStringStack stringStack;
};
BOOST_FIXTURE_TEST_SUITE(String_Stack, StringStackFixture)

	BOOST_AUTO_TEST_CASE(can_push_string_to_stack)
	{
		stringStack.Push("qwerty");
		BOOST_CHECK(stringStack.Get() == "qwerty");
	}

	BOOST_AUTO_TEST_CASE(can_check_stringStack_for_empty)
	{
		BOOST_CHECK(stringStack.IsEmpty());
		stringStack.Push("qwerty");
		BOOST_CHECK(stringStack.IsEmpty() == false);
		stringStack.Clear();
		BOOST_CHECK(stringStack.IsEmpty() == true);
	}

	BOOST_AUTO_TEST_CASE(can_pop_element_in_stringStack)
	{
		stringStack.Push("qwerty");
		stringStack.Pop();
		BOOST_CHECK(stringStack.IsEmpty() == true);
		BOOST_CHECK_THROW(stringStack.Pop(), std::exception);

	}

	BOOST_AUTO_TEST_CASE(can_get_last_element_in_stringStack)
	{
		stringStack.Push("qwerty");
		BOOST_CHECK(stringStack.Get() == "qwerty");
		stringStack.Clear();
		BOOST_CHECK_THROW(stringStack.Get(), std::exception);
	}

	BOOST_AUTO_TEST_CASE(can_clear_stack)
	{
		for (size_t i = 0; i < 20; i++)
		{
			stringStack.Push("qwerty");
		}
		BOOST_CHECK(stringStack.IsEmpty() != true);
		stringStack.Clear();
		BOOST_CHECK(stringStack.IsEmpty() == true);
	}

	BOOST_AUTO_TEST_CASE(testing_for_many_push_and_pop)
	{
		for (size_t i = 0; i < 100000; i++)
		{
			stringStack.Push("qwerty");
		}
		BOOST_CHECK(stringStack.IsEmpty() != true);
		for (size_t i = 0; i < 100000; i++)
		{
			stringStack.Pop();
		}
		BOOST_CHECK(stringStack.IsEmpty() == true);
	}

BOOST_AUTO_TEST_SUITE_END()