#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <iterator>
#include <fstream>
#include <set>
using namespace std;


vector<bool> CreatingASieve(const int size);
void SievingSieve(vector<bool>& sieve);
set<int> CoutingPrimes(vector<bool>& sieve);