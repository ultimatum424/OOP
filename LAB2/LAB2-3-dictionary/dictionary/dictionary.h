#pragma once
#include "stdafx.h"
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>


typedef std::map<std::string, std::string> dictionaryType;

void InitDictonary(std::string file);
dictionaryType ReadWorlds(std::string file);
dictionaryType CreatReverseDictionary(dictionaryType& dictionary);
std::string FindTranclate(std::string word, dictionaryType dictionary, dictionaryType reverseDictionary);
void AddTranslate(std::string word1, std::string word2, dictionaryType& dictionary, dictionaryType& reverseDictionary);
void SaveDictionary(std::string fileName, dictionaryType dictionary);
void OutDict(dictionaryType dictionary);


