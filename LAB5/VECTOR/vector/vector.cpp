// vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Vector3D.h"

using namespace std;

int main()
{		
	CVector3D v1(25, 125, 10);
	CVector3D v11(0, 0, 1);
	CVector3D v22(0, 1, 0);
	v11 != v22;
	CVector3D v2(1, 0, 0);
	v2 -= v1;
	cout << v2 << std::endl;
	cin >> v2;
	cout << v2 << std::endl;
    return 0;
}

