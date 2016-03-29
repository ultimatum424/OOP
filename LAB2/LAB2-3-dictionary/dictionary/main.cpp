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
	string tempString;
	string tempWord;
	int isWork = 1;
	while (isWork)
	{
		cin >> tempString;
		if (tempString == "...")
			isWork -= 1;
		else if (isWork == 1)
		{
			string tranclateWord = FindTranclate(tempString, dictionary, reverseDictionary);
			if (tranclateWord != "")
				cout << tranclateWord << endl;
			else
			{
				cout << "����������� ����� �" << tempString << "� .������� ������� ��� ������ ������ ��� ������." << endl;
				isWork++;
				tempWord = tempString;
			}
		}
		else if (isWork == 2)
		{
			AddTranslate(tempString, tempWord, dictionary, reverseDictionary);
			cout << "����� �" << tempString << "� ��������� � ������� ��� �" << tempWord << "�." << endl;
			isWork--;
		}		
	}
	SaveDictionary(fileName, dictionary);
}