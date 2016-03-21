#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "math.h"

using namespace std;
int CalculationQuadraticEquation(float coefficients[3], vector <float>& solution)
{
	if (coefficients[0] == 0)
	{
		return 1;
	}
	if ((coefficients[0] * coefficients[0]) < (4 * coefficients[1] * coefficients[2]))
	{
		return 2;
	}
	float discriminant = (coefficients[0] * coefficients[0]) - (4 * coefficients[1] * coefficients[2]);
	if (discriminant == 0)
	{
		solution.push_back((-coefficients[1]) / 2 * coefficients[0]);
	}
	else
	{
		solution.push_back(((-coefficients[1]) + sqrt(discriminant)) / 2 * coefficients[0]);
		solution.push_back(((-coefficients[1]) - sqrt(discriminant)) / 2 * coefficients[0]);
	}
	return 0;
}
int ReadCoeff(float coefficients[3], char* argv[])
{
	coefficients[0] = float(atof(argv[1]));
	coefficients[1] = float(atof(argv[2]));
	coefficients[2] = float(atof(argv[3]));
		 
	if (((argv[1] != "0") && (coefficients[0] == 0)) || ((argv[2] != "0") && (coefficients[1] == 0))
		|| ((argv[3] != "0") && (coefficients[2] == 0)))
	{
		return 1;
	}
	return 0;
}
void OutputSolution(const vector <float> solution)
{
	for (size_t i = 0; i < solution.size(); i++)
		cout << solution[i] << endl;
}
int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "wrong number of arguments" << endl << "Enter the coefficients of the quadratic equation: a, b, c" << endl;
		return 1;
	}
	else
	{
		float coefficients[3];
		std::vector <float> solution;

		
		if (ReadCoeff(coefficients, argv))		
		{
			cout << "ERR: " << endl;
			return 1;
		}
		else
		{
			int is_not_solution = CalculationQuadraticEquation(coefficients, solution);
			if (is_not_solution == 1)
				cout << "This equation is not square" << endl;
			else if (is_not_solution == 2)
				cout << "There is no real root" << endl;
			else
			{
				OutputSolution(solution);
			}
		}
		return 0;
	}
}

