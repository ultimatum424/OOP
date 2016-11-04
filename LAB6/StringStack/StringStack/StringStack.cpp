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

		stack.push("");
		stack.pop();
		std::cout << stack.isEmpty() << "\n";;
		std::cout <<  stack.get() << "\n";;
	}
	catch(std::exception const & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
    return 0;
}

