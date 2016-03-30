// LAB2-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Lab2-1.h"

int main()
{
	vector<double> mainVector = ReadVector();
	vector<double> resultVector = DivisinonArrayOnMаxElement(mainVector);
	SortVector(resultVector);
	OutVector(resultVector);
    return 0;
}

