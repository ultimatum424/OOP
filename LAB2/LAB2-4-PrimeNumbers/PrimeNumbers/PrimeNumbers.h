#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <iterator>
#include <fstream>
#include <set>
using namespace std;


vector<bool> CreatingASieve(const int size);
bool CheckPrime(int number);
void SievingSieve(vector<bool>& sieve);
set<int> CoutingPrimes(vector<bool>& sieve);
int SearchCountPrimeNumbers(int size);