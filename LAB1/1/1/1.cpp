// 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		return 1;
	}
	else
	{
		ifstream file;
		
		string line;
		string search_line;
		int i;
		file.open((argv[1]));

		search_line = gets_s(argv[2], i);
		if (file.is_open())
		{
			int p2 = 0;
			int i = 0;
			while (!file.eof())
			{
				getline(file, line);
				int p = line.find(search_line);
				if (p != -1)
				{
					p2 = 1;
					//out_file << i;
					cout << i << endl;
				}
				i++;
			}
			if (p2 == 0)
				return 1;
			file.close();
		}
		else
			return  1;
	}
    return 0;
}

