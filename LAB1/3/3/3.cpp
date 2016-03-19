// 3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 3;

int ReadFromFile(string nameFile, float  martix[SIZE][SIZE])
{
	ifstream inputFile;
	inputFile.open(nameFile);
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			for (size_t i = 0; i < SIZE; i++)
				for (size_t j = 0; j < SIZE; j++)
					if (!(inputFile >> martix[i][j]))
					{
						return 2;
					}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}
void MultiplicationMatrix(const float mat1[SIZE][SIZE], const float mat2[SIZE][SIZE], float resultMatrix[SIZE][SIZE])
{
	resultMatrix[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0] + mat1[0][2] * mat2[2][0];
	resultMatrix[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1] + mat1[0][2] * mat2[2][1];
	resultMatrix[0][2] = mat1[0][0] * mat2[0][2] + mat1[0][1] * mat2[1][2] + mat1[0][2] * mat2[2][2];

	resultMatrix[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0] + mat1[1][2] * mat2[2][0];
	resultMatrix[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1] + mat1[1][2] * mat2[2][1];
	resultMatrix[1][2] = mat1[1][0] * mat2[0][2] + mat1[1][1] * mat2[1][2] + mat1[1][2] * mat2[2][2];

	resultMatrix[2][0] = mat1[2][0] * mat2[0][0] + mat1[2][1] * mat2[1][0] + mat1[2][2] * mat2[2][0];
	resultMatrix[2][1] = mat1[2][0] * mat2[0][1] + mat1[2][1] * mat2[1][1] + mat1[2][2] * mat2[2][1];
	resultMatrix[2][2] = mat1[2][0] * mat2[0][2] + mat1[2][1] * mat2[1][2] + mat1[2][2] * mat2[2][2];
}

void WriteFromFile(float  resultMatrix[SIZE][SIZE])
{
	ofstream outFile;
	outFile.open("result_martix.txt");
	outFile << resultMatrix[0][0] << " " << resultMatrix[0][1] << " " << resultMatrix[0][2] << endl;
	outFile << resultMatrix[1][0] << " " << resultMatrix[1][1] << " " << resultMatrix[1][2] << endl;
	outFile << resultMatrix[2][0] << " " << resultMatrix[2][1] << " " << resultMatrix[2][2] << endl;
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
		float  martix1[SIZE][SIZE];
		float  martix2[SIZE][SIZE];
		float  resultMatrix[SIZE][SIZE];

		int checkRead1 = ReadFromFile(argv[1], martix1);
		int checkRead2 = ReadFromFile(argv[2], martix2);
		if ((checkRead1 == 1) || (checkRead2 == 1))
		{
			cout << "Erorr: Can't open file" << endl;
			return 1;
		}
		else if ((checkRead1 == 2) || (checkRead2 == 2))
		{
			cout << "size of matrix is not a 3X3" << endl;
			return 1;
		}
		else
		{
			MultiplicationMatrix(martix1, martix2, resultMatrix);
			WriteFromFile(resultMatrix);
		}
	}
    return 0;
}

