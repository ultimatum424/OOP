#include "stdafx.h"
#include "../MyList/CMyList.h"

struct StringList
{
	CMyList<std::string> list;
};


BOOST_FIXTURE_TEST_SUITE(MyList, StringList)
	BOOST_AUTO_TEST_CASE(have_copy_constructor)
	{
		list.PushBack("1");
		list.PushBack("2");
		list.PushBack("3");
		CMyList<std::string> list1(list);
		std::vector<std::string> expectedStrings = { "1", "2", "3" };
		size_t counter = 0;
		for (auto it = list1.begin(); it != list1.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
			counter++;
		}
	}
	BOOST_AUTO_TEST_CASE(can_check_for_empty_list)
	{
		BOOST_CHECK(list.IsEmpty());
		list.PushFront("qwerty");
		list.PushBack("qwerty");
		BOOST_CHECK(list.IsEmpty() == false);
	}
	BOOST_AUTO_TEST_CASE(can_cler_list)
	{
		list.Clear();
		list.PushFront("qwerty");
		list.PushFront("qwerty2");
		list.Clear();
		BOOST_CHECK(list.IsEmpty());

	}
	BOOST_AUTO_TEST_CASE(can_get_size_list)
	{
		BOOST_CHECK(list.GetSize() == 0);
		list.PushFront("qwerty");
		list.PushFront("qwerty");
		BOOST_CHECK(list.GetSize() == 2);
		list.Clear();
		BOOST_CHECK(list.GetSize() == 0);
	}
	BOOST_AUTO_TEST_CASE(can_push_front_to_list)
	{
		list.PushFront("12345");
		list.PushFront("qwerty");
		BOOST_CHECK(list.GetFirstElement() == "qwerty");
	}
	BOOST_AUTO_TEST_CASE(can_push_back_to_list)
	{
		list.PushBack("qwerty");
		list.PushBack("12345");
		BOOST_CHECK(list.GetLastElement() == "12345");
	}
	BOOST_AUTO_TEST_CASE(can_get_last_element_of_the_list)
	{
		BOOST_CHECK_THROW(list.GetLastElement(), std::logic_error);
		list.PushBack("Dog");
		list.PushBack("Car");
		list.PushBack("Cat");
		BOOST_CHECK(list.GetLastElement() == "Cat");
		list.Clear();
		BOOST_CHECK_THROW(list.GetLastElement(), std::logic_error);
	}
	BOOST_AUTO_TEST_CASE(can_get_first_element_of_the_list)
	{
		BOOST_CHECK_THROW(list.GetFirstElement(), std::logic_error);
		list.PushBack("Dog");
		list.PushBack("Car");
		list.PushBack("Cat");
		BOOST_CHECK(list.GetFirstElement() == "Dog");
		list.Clear();
		BOOST_CHECK_THROW(list.GetFirstElement(), std::logic_error);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(Iterators_tests, StringList)
	
	BOOST_AUTO_TEST_CASE(have_iterators_begin_and_end_iterators_list)
	{
		list.PushBack("alpha");
		list.PushBack("beta");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "alpha", "beta", "goodbye" };
		size_t counter = 0;
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
			counter++;
		}
	}

	BOOST_AUTO_TEST_CASE(have_const_iterators_begin_and_end_iterators_list)
	{
		list.PushBack("alpha");
		list.PushBack("beta");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "alpha", "beta", "goodbye" };
		size_t counter = 0;
		for (auto it = list.cbegin(); it != list.cend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
			counter++;
		}
	}

	BOOST_AUTO_TEST_CASE(have_reverse_iterators_begin_and_end_iterators_list)
	{
		list.PushBack("alpha");
		list.PushBack("beta");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "goodbye", "beta", "alpha" };
		size_t counter = expectedStrings.size() - 1;
		for (auto it = list.rbegin(); it != list.rend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
			counter--;
		}
	}

	BOOST_AUTO_TEST_CASE(have_const_reverse_iterators_begin_and_end_iterators_list)
	{
		list.PushBack("alpha");
		list.PushBack("beta");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "goodbye", "beta", "alpha" };
		size_t counter = 0;
		for (auto it = list.crbegin(); it != list.crend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
			counter++;
		}
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(MyList, StringList)

	BOOST_AUTO_TEST_CASE(can_get_acsses_to_elements_from_range_based_for)
	{
		list.PushBack("alpha");
		list.PushBack("beta");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "alpha", "beta", "goodbye" };
		size_t counter = 0;
		for (auto str : list)
		{
			BOOST_CHECK_EQUAL(str, expectedStrings[counter]);
			counter++;
		}
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(can_insert_element_at_iterator_position, StringList)
	BOOST_AUTO_TEST_CASE(insert_element_in_empty_list)
	{
	list.Insert(list.begin(),"start");
	BOOST_CHECK_EQUAL(list.GetFirstElement(), "start");
	}

	BOOST_AUTO_TEST_CASE(insert_element_in_begining_list)
	{
		list.PushBack("1");
		list.PushBack("2");
		list.PushBack("3");
		list.Insert(list.begin(), "start");
		BOOST_CHECK_EQUAL(list.GetFirstElement(), "start");
	}

	BOOST_AUTO_TEST_CASE(insert_element_in_ending_list)
	{
		list.PushBack("1");
		list.PushBack("2");
		list.PushBack("3");
		list.Insert(list.end(), "start");
		BOOST_CHECK_EQUAL(list.GetLastElement(), "start");
	}

	BOOST_AUTO_TEST_CASE(insert_element_in_middle_of_the_list)
	{
		list.PushBack("1");
		list.PushBack("2");
		list.PushBack("3");
		auto it = ++list.begin();
		list.Insert(it, "start");
		it = ++list.begin();
		BOOST_CHECK_EQUAL(list.GetFirstElement(), "1");
		BOOST_CHECK_EQUAL(*it, "start");
	}

BOOST_AUTO_TEST_SUITE_END()
	
BOOST_FIXTURE_TEST_SUITE(can_erase_element_at_iterator_position, StringList)
	BOOST_AUTO_TEST_CASE(erase_element_on_middle_of_the_list)
{
	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");
	auto it = ++list.begin();
	list.Erase(it);
	it = ++list.begin();
	BOOST_CHECK_EQUAL(*it, "3");
}

	BOOST_AUTO_TEST_CASE(erase_element_on_begining_of_the_list)
{
	list.PushBack("1");
	list.PushBack("2");
	list.PushBack("3");
	list.Erase(list.begin());
	BOOST_CHECK_EQUAL(*list.begin(), "2");
}

	BOOST_AUTO_TEST_CASE(erase_element_if_list_have_one_element)
	{
		list.PushBack("1");
		list.Erase(list.begin());
		BOOST_CHECK(list.IsEmpty());
	}
BOOST_AUTO_TEST_SUITE_END()
	
