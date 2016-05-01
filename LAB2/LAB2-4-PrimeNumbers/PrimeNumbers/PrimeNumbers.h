#pragma once

// TODO: move headers to stdafx + 

int ReadNumber();
std::vector<bool> CreatingASieve(const int size);
void SievingSieve(std::vector<bool>& sieve);
std::set<int> GetPrimesSet(std::vector<bool>& sieve);
void OutSetPrime(std::set<int> setOfPrimeNumbers);
