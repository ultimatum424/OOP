// 3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const int DIMENSION = 3;

bool ReadFromFile(ifstream& inputFile, float  martix[DIMENSION][DIMENSION])
{
	while (!inputFile.eof())
	{
		for (size_t i = 0; i < DIMENSION; i++)
		{
			for (size_t j = 0; j < DIMENSION; j++)
			{
				string read;
				inputFile >> read;
				martix[i][j] = atof(read.c_str());
				if (((martix[i][j] == 0) && (read != "0")))
				{
					inputFile.close();
					return false;
				}
			}
		}
	}
	inputFile.close();
	return true;
}
void MultiplicationMatrix(float martix1[DIMENSION][DIMENSION], float martix2[DIMENSION][DIMENSION], float resultMartix[DIMENSION][DIMENSION])
{
	resultMartix[0][0] = martix1[0][0] * martix2[0][0] + martix1[0][1] * martix2[1][0] + martix1[0][2] * martix2[2][0];
	resultMartix[0][1] = martix1[0][0] * martix2[0][1] + martix1[0][1] * martix2[1][1] + martix1[0][2] * martix2[2][1];
	resultMartix[0][2] = martix1[0][0] * martix2[0][2] + martix1[0][1] * martix2[1][2] + martix1[0][2] * martix2[2][2];

	resultMartix[1][0] = martix1[1][0] * martix2[0][0] + martix1[1][1] * martix2[1][0] + martix1[1][2] * martix2[2][0];
	resultMartix[1][1] = martix1[1][0] * martix2[0][1] + martix1[1][1] * martix2[1][1] + martix1[1][2] * martix2[2][1];
	resultMartix[1][2] = martix1[1][0] * martix2[0][2] + martix1[1][1] * martix2[1][2] + martix1[1][2] * martix2[2][2];

	resultMartix[2][0] = martix1[2][0] * martix2[0][0] + martix1[2][1] * martix2[1][0] + martix1[2][2] * martix2[2][0];
	resultMartix[2][1] = martix1[2][0] * martix2[0][1] + martix1[2][1] * martix2[1][1] + martix1[2][2] * martix2[2][1];
	resultMartix[2][2] = martix1[2][0] * martix2[0][2] + martix1[2][1] * martix2[1][2] + martix1[2][2] * martix2[2][2];
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "wrong number of arguments" << endl << "Usage: <first matrix file> <second matrix file>" << endl;
		return 1;
	}
	else
	{
		ifstream inputFile1;
		ifstream inputFile2;
		ofstream outFile;
		inputFile1.open(argv[1]);
		inputFile2.open(argv[2]);
		if ((inputFile1.is_open()) && (inputFile2.is_open()))
		{
			float  martix1[DIMENSION][DIMENSION];
			float  martix2[DIMENSION][DIMENSION];
			float  resultMartix[DIMENSION][DIMENSION];
			
			if ((!ReadFromFile(inputFile1, martix1)) || (!ReadFromFile(inputFile2, martix2)))
			{
				cout << "dimension of matrix is not a 3X3";
				return 1;
			}
			MultiplicationMatrix(martix1, martix2, resultMartix);
			outFile.open("result_martix.txt");
			outFile << resultMartix[0][0] << " " << resultMartix[0][1] << " " << resultMartix[0][2] << endl;
			outFile << resultMartix[1][0] << " " << resultMartix[1][1] << " " << resultMartix[1][2] << endl;
			outFile << resultMartix[2][0] << " " << resultMartix[2][1] << " " << resultMartix[2][2] << endl;
			outFile.close();
		}
		else
		{
			cout << "Erorr: Can't open file" << endl;
			return 1;
		}
	}
    return 0;
}

