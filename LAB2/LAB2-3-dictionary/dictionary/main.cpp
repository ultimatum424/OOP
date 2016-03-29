// dictionary.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "dictionary.h"



int main()
{
	setlocale(LC_ALL, "Russian");
	string fileName;
	cout << "¬ведите название файла со словарем <им€.расширение> ";
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
				cout << "Ќеизвестное слово У" << tempString << "Ф .¬ведите перевод или пустую строку дл€ отказа." << endl;
				isWork++;
				tempWord = tempString;
			}
		}
		else if (isWork == 2)
		{
			AddTranslate(tempString, tempWord, dictionary, reverseDictionary);
			cout << "—лово У" << tempString << "Ф сохранено в словаре как У" << tempWord << "Ф." << endl;
			isWork--;
		}		
	}
	SaveDictionary(fileName, dictionary);
}