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
	std::vector<std::string> expectedStrings = { "goodbye", "Ho-ho-ho", "hello" };
	size_t counter = 0;
	for (auto it = list.crbegin(); it != list.crend(); ++it)
	{
		std::cout << (*it == expectedStrings[counter]) << std::endl;
		std::cout << *it << std::endl;
		std::cout << expectedStrings[counter] << std::endl;
		counter++;
	}
    return 0;
}

