#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>


using namespace std;

vector<double> ReadVector();
void OutVector(const vector<double> outVector);
void SortVector(vector <double>& sortVector);
vector<double> DivisinonArrayOnMàxElement(const vector<double>& mainVector);
