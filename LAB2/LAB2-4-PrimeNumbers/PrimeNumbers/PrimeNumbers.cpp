
#include "stdafx.h"
#include "PrimeNumbers.h"
#include <fstream>

// TODO: move to main or cleanup and fix input size here +
int ReadNumber()
{
	int number = 0;
	if (std::cin >> number)
	{
		if (number < 0)
		{
			number = 0;
		}
	}
	return number;
}

// TODO: don't use if branching here, modify input size instead +
std::vector<bool> CreatingASieve(const int size)
{
	std::vector<bool> sieve(size + 1, true);
		return sieve;
}

void SievingSieve(std::vector<bool>& sieve)
{
	// TODO: rename p to primeIdx +
	int primeIdx = 2;
	while ((primeIdx * primeIdx) < (sieve.size()))
	{
		for (size_t i = primeIdx * primeIdx; i < sieve.size(); i += primeIdx)
			sieve[i] = false;
		primeIdx++;
	}
}

// TODO: rename to GetPrimesSet +
std::set<int> GetPrimesSet(std::vector<bool>& sieve)
{
	std::set<int> setOfPrimeNumbers;
	for (int i = 2; i < sieve.size(); i++) // TODO: add {} +
	{
		if (sieve[i])
		{
			setOfPrimeNumbers.insert(i);
		}
	}
	return setOfPrimeNumbers;
}

void OutSetPrime(std::set<int> setOfPrimeNumbers)
{
	std::ofstream outFile;
	outFile.open("prime_set.txt");
	std::ostream_iterator<int> out_it(outFile, "\n");
	copy(setOfPrimeNumbers.begin(), setOfPrimeNumbers.end(), out_it);
}



