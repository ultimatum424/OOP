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

	BOOST_AUTO_TEST_CASE(have_iterators_begin_and_end_iterators_list)
	{
		list.PushBack("hello");
		list.PushBack("Ho-ho-ho");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "hello", "Ho-ho-ho", "goodbye" };
		size_t counter = 0;
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
			counter++;
		}
	}
	BOOST_AUTO_TEST_CASE(have_reverse_iterators_begin_and_end_iterators_list)
	{
		list.PushBack("hello");
		list.PushBack("Ho-ho-ho");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "goodbye", "Ho-ho-ho", "hello"};
		size_t counter = expectedStrings.size() - 1;
		for (auto it = list.rbegin(); it != list.rend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, expectedStrings[counter]);
			counter--;
		}
	}

	BOOST_AUTO_TEST_CASE(can_get_acsses_to_elements_from_range_based_for)
	{
		list.PushBack("hello");
		list.PushBack("Ho-ho-ho");
		list.PushBack("goodbye");
		std::vector<std::string> expectedStrings = { "hello", "Ho-ho-ho", "goodbye" };
		size_t counter = 0;
		for (auto str : list)
		{
			BOOST_CHECK_EQUAL(str, expectedStrings[counter]);
			counter++;
		}
	}

	
	BOOST_AUTO_TEST_CASE(can_insert_element_at_iterator_position)
	{
		list.PushBack("hello");
		list.PushBack("Ho-ho-ho");
		list.PushBack("goodbye");
		auto it = ++list.begin();
		list.Insert(it, "20");
		BOOST_CHECK_EQUAL(*++list.begin(), "20");

		list.Insert(list.begin(), "11");
		BOOST_CHECK_EQUAL(*list.begin(), "11");

		list.Insert(list.end(), "30");

		std::vector<std::string> expectedStrings = { "11", "hello", "20", "Ho-ho-ho", "goodbye", "30" };
		size_t i = 0;
		for (auto str : list)
		{
			BOOST_CHECK_EQUAL(str, expectedStrings[i]);
			i++;
		}

	}
	
	BOOST_AUTO_TEST_CASE(can_erase_element_at_iterator_position)
	{
		list.PushBack("hello");
		list.PushBack("Ho-ho-ho");
		list.PushBack("goodbye");
		auto it = ++list.begin();
		BOOST_CHECK_EQUAL(*it, "Ho-ho-ho");
		list.Erase(it);
		BOOST_CHECK_EQUAL(*++list.begin(), "goodbye");

		list.Erase(list.begin());
		BOOST_CHECK_EQUAL(*list.begin(), "goodbye");

		list.Erase(list.begin());
		BOOST_CHECK(list.IsEmpty());
	}
	
BOOST_AUTO_TEST_SUITE_END()