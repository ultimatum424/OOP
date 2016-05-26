// dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Cdictonary.h"
#include "dict.h"
using namespace std;

int main()
{
	CDictonary dict;
	setlocale(LC_ALL, "Russian");
	string fileName;
	string inputWord;
	string tempTranslate;
	cout << "Введите название файла со словарем <имя.расширение> ";
	cin >> fileName;
	dict.SetFileName(fileName);
	dict.InitDictonary();
	dict.ReadWords();
	dict.CreateReverseDictionary();
	while (!(dict.IfState(CDictonary::States::EXIT)))
	{
		cin >> inputWord;
		if (dict.IfState(CDictonary::States::CHANGES))
		{
			SaveChanges(inputWord, dict);
		}
		else if (dict.IfState(CDictonary::States::WAIT_WORD))
		{
			WaitingWord(inputWord, tempTranslate, dict);
		}
		else if (dict.IfState(CDictonary::States::WAIT_TRANSLATE))
		{
			WaitingTranslation(inputWord, tempTranslate, dict);
		}

	}
}