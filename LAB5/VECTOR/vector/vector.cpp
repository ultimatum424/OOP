// vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Vector3D.h"

using namespace std;

int main()
{		
	CVector3D v1(25, 125, 10);
	v1 = -v1;
	cout << v1 << std::endl;
    return 0;
}

