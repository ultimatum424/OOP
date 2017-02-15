// MyList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CMyList.h"
#include <list>
#include <vector>
#include <iostream>

int main()
{
	CMyList<std::string> list;
	list.PushBack("hello");
	list.PushBack("Ho-ho-ho");
	list.PushBack("goodbye");
	auto it = ++list.begin();
	list.Insert(it, "22");
	list.Erase(list.end());
	it = ++list.begin();
	std::cout << *it;
	CMyList<std::string> list2(list);
	std::vector<std::string> expectedStrings = { "111", "goodbye", "Ho-ho-ho", "hello" };
	size_t counter = 0;
	for (auto it = list.cbegin(); it != list2.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}
    return 0;
}

