#pragma once
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
using namespace std;

typedef map<string, string> dictionaryType;

void InitDictonary(string file);
dictionaryType ReadWorlds(string file);
dictionaryType CreatReverseDictionary(dictionaryType& dictionary);
string FindTranclate(string word, dictionaryType dictionary, dictionaryType reverseDictionary);
void AddTranslate(string word1, string word2, dictionaryType& dictionary, dictionaryType& reverseDictionary);
void SaveDictionary(string fileName, dictionaryType dictionary);


