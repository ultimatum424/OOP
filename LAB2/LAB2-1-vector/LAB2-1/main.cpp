// LAB2-1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Lab2-1.h"

int main()
{
	vector<double> mainVector = ReadVector();
	mainVector = DivisinonArrayOnM�xElement(mainVector);
	SortVector(mainVector);
	OutVector(mainVector);
    return 0;
}

