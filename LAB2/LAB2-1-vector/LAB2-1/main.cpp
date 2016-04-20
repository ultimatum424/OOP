// LAB2-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Lab2-1.h"

int main()
{
	vector<double> mainVector = ReadVector();
	mainVector = DivisinonArrayOnMаxElement(mainVector);
	SortVector(mainVector);
	OutVector(mainVector);
    return 0;
}

