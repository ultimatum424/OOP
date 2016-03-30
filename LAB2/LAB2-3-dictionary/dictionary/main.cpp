// dictionary.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "dictionary.h"



int main()
{
	setlocale(LC_ALL, "Russian");
	string fileName;
	cout << "������� �������� ����� �� �������� <���.����������> ";
	cin >> fileName;
	InitDictonary(fileName);
	dictionaryType dictionary = ReadWorlds(fileName);
	dictionaryType reverseDictionary = CreatReverseDictionary(dictionary);
	OutDict(reverseDictionary);
	string tempString;
	string tempWord;
	bool isChange = false;
	int levelWork = 2;
	while (levelWork)
	{	
		cin >> tempString;
		if (levelWork == 1)
		{
			transform(tempString.begin(), tempString.end(), tempString.begin(), tolower);
			if (tempString == "y")
			{
				SaveDictionary(fileName, dictionary);
				levelWork = 0;
				cout << "��������� ����������";
			}
			else if (tempString == "n")
				levelWork = 0;
		}
		else if (levelWork == 2)
		{
			if (tempString == "...")
			{
				if (isChange)
				{
					cout << "��������� �������� Y/N ? ";
					levelWork--;
				}
				else if (!isChange)
					levelWork = 0;
			}	
			else
			{
				string tranclateWord = FindTranclate(tempString, dictionary, reverseDictionary);
				if (tranclateWord != "")
					cout << tranclateWord << endl;
				else
				{
					cout << "����������� ����� �" << tempString << "� .������� ������� ��� ������ ������ ��� ������." << endl;
					levelWork++;
					tempWord = tempString;
				}
			}
		}
		else if (levelWork == 3)
		{
			if (tempString == "...")
			{
				cout << "C���� " << tempWord <<  " ���������������" << endl;
				levelWork--;
			}
			else
			{
				AddTranslate(tempString, tempWord, dictionary, reverseDictionary);
				cout << "����� �" << tempString << "� ��������� � ������� ��� �" << tempWord << "�." << endl;
				levelWork--;
				isChange = true;
			}
		}
		
	}
}