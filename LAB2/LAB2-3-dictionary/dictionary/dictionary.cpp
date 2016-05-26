/*
#include "stdafx.h"
#include "dictionary.h"
using namespace std;

void InitDictonary(const string &file)
{
	ifstream dictonaryFile;
	dictonaryFile.open(file);
	if (!dictonaryFile.is_open())
	{
		ofstream dictonaryFile;
		dictonaryFile.open(file);
	}
}

dictionaryType ReadWords(const string &file)
{
	dictionaryType dictionary;
	ifstream fileDictonary;
	fileDictonary.open(file);
	string readString;
	vector<string> vectorString;
	while (!fileDictonary.eof())
	{
		getline(fileDictonary, readString);
		if (readString!= "")
			vectorString.push_back(readString);
	}
	for (size_t i = 0; i < vectorString.size(); i += 2)
		dictionary[vectorString[i]] = vectorString[i + 1];
	return dictionary;
}

dictionaryType CreateReverseDictionary(const dictionaryType& dictionary)
{
	dictionaryType reverseDictionary;
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		reverseDictionary[it->second] = it->first;
	}

	return reverseDictionary;
}

string FindTranclate(const string &word,  dictionaryType &dictionary,  dictionaryType &reverseDictionary)
{
	if (dictionary.find(word) != dictionary.end())
		return dictionary[word];
	else if (reverseDictionary.find(word) != reverseDictionary.end())
		return reverseDictionary[word];
	else
		return "";
}

void AddTranslate(const std::string &word1, const std::string &word2, dictionaryType& dictionary, dictionaryType& reverseDictionary)
{
	dictionary[word1] = word2;
	reverseDictionary[word2] = word1;
}

void SaveDictionary(const string &fileName, dictionaryType &dictionary)
{
	ofstream outFile;
	outFile.open(fileName);
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		outFile << it->first << endl;
		outFile << it->second << endl;
	}
}
void OutDict(dictionaryType dictionary)
{
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << " --> ";
		cout << it->second << endl;
	}
}
*/