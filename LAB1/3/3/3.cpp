// 3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const int DIMENSION = 3;

int ReadFile(ifstream& input_file, float  martix[DIMENSION][DIMENSION])
{
	while (!input_file.eof())
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			for (int j = 0; j < DIMENSION; j++)
			{
				string check_string;
				input_file >> check_string;
				martix[i][j] = atof(check_string.c_str());
				if (((martix[i][j] == 0) && (check_string != "0")))
				{
					cout << "!!!!!";
					input_file.close();
					return 1;
				}
			}
		}
	}
	input_file.close();
	return 0;
}
void MultiplicationMatrix(float  martix1[DIMENSION][DIMENSION], float  martix2[DIMENSION][DIMENSION], float  result_martix[DIMENSION][DIMENSION])
{
	result_martix[0][0] = martix1[0][0] * martix2[0][0] + martix1[0][1] * martix2[1][0] + martix1[0][2] * martix2[2][0];
	result_martix[0][1] = martix1[0][0] * martix2[0][1] + martix1[0][1] * martix2[1][1] + martix1[0][2] * martix2[2][1];
	result_martix[0][2] = martix1[0][0] * martix2[0][2] + martix1[0][1] * martix2[1][2] + martix1[0][2] * martix2[2][2];

	result_martix[1][0] = martix1[1][0] * martix2[0][0] + martix1[1][1] * martix2[1][0] + martix1[1][2] * martix2[2][0];
	result_martix[1][1] = martix1[1][0] * martix2[0][1] + martix1[1][1] * martix2[1][1] + martix1[1][2] * martix2[2][1];
	result_martix[1][2] = martix1[1][0] * martix2[0][2] + martix1[1][1] * martix2[1][2] + martix1[1][2] * martix2[2][2];

	result_martix[2][0] = martix1[2][0] * martix2[0][0] + martix1[2][1] * martix2[1][0] + martix1[2][2] * martix2[2][0];
	result_martix[2][1] = martix1[2][0] * martix2[0][1] + martix1[2][1] * martix2[1][1] + martix1[2][2] * martix2[2][1];
	result_martix[2][2] = martix1[2][0] * martix2[0][2] + martix1[2][1] * martix2[1][2] + martix1[2][2] * martix2[2][2];
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "wrong number of arguments" << endl << "Enter the files 1matrix, 2matrix " << endl;
		return 1;
	}
	else
	{
		ifstream input_file1;
		ifstream input_file2;
		ofstream out_file;
		input_file1.open(argv[1]);
		input_file2.open(argv[2]);
		if ((input_file1.is_open()) && (input_file2.is_open()))
		{
			float  martix1[DIMENSION][DIMENSION];
			float  martix2[DIMENSION][DIMENSION];
			float  result_martix[DIMENSION][DIMENSION];
			
			bool check_correctness_matrix1 = ReadFile(input_file1, martix1);
			bool check_correctness_matrix2 = ReadFile(input_file2, martix2);
			if ((check_correctness_matrix1) || (check_correctness_matrix2))
			{
				cout << "matrix format is not a 3X3";
				return 1;
			}
			cout << "!!!!!!!!!";
			MultiplicationMatrix(martix1, martix2, result_martix);
			out_file.open("result_martix.txt");
			out_file << result_martix[0][0] << " " << result_martix[0][1] << " " << result_martix[0][2] << endl;
			out_file << result_martix[1][0] << " " << result_martix[1][1] << " " << result_martix[1][2] << endl;
			out_file << result_martix[2][0] << " " << result_martix[2][1] << " " << result_martix[2][2] << endl;
			out_file.close();
		}
		else
		{
			cout << "Error opening file " << endl;
			return 1;
		}
	}
    return 0;
}

