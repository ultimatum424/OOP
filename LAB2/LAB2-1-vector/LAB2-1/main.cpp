// LAB2-1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Lab2-1.h"

int main()
{
	vector<double> mainVector = ReadVector();
	vector<double> resultVector = DivisinonArrayOnM�xElement(mainVector);
	SortVector(resultVector);
	OutVector(resultVector);
    return 0;
}

