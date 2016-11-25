// StringStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Stack.h"

int main()
{
	try
	{
		CStringStack stack;
		CStringStack stack2;

		stack.Push("");
		//stack.Pop();
		std::cout << stack.IsEmpty() << "\n";;
		std::cout <<  stack.Get() << "\n";;
	}
	catch(std::exception const & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
    return 0;
}

