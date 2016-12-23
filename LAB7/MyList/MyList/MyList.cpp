// MyList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CMyList.h"

int main()
{
	CMyList<std::string> cmylist;
	cmylist.PushBack("1");
	cmylist.PushBack("1");
	cmylist.PushBack("1");
	CMyList<std::string> cmylist2(cmylist);
	std::string str = cmylist.GetLastElement();
    return 0;
}

