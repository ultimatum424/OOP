// LAB2-1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Lab2-1.h"

int main()
{
	vector<double> mainVector = ReadVector();
	vector<double> resultVector = DivisinMassOnM�xElement(mainVector);
	OutVector(resultVector);
	system("pause");
    return 0;
}

