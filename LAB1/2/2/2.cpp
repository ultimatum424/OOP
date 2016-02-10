#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "math.h"

using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "wrong number of arguments" << endl;
		return 1;
	}
	else
	{
		float a = float(atof(argv[1]));
		float b = float(atof(argv[2]));
		float c = float(atof(argv[3]));
		if (a == 0)
		{
			cout << "This equation is not square" << endl;
			return 1;
		}	
		if ((sqrt(a*a)) < (4 * b*c))
		{
			cout << "There is no real root" << endl;
			return 1;
		}
		float d = sqrt((a*a) - 4 * b*c);
		if (d == 0)
		{
			float x = (-b) / 2 * a;
		}
		else
		{
			float x1 = ((-b) + sqrt(d)) / 2 * a;
			float x2 = ((-b) - sqrt(d)) / 2 * a;
			cout << x1 << endl;
			cout << x2 << endl;
		}
		return 0;
	}
}

