
#include "stdafx.h"
#include "PrimeNumbers.h"


vector<bool> CreatingASieve(const int size)
{
	vector<bool> sieve(size, true);
	return sieve;
}
bool CheckPrime(int number)
{
	int root = int(sqrt(number));
	for (size_t i = 2; i <= root; i++)
		if (!(number % i))	
			return false;
	return true;
}

void SievingSieve(vector<bool>& sieve)
{
	int p = 2;
	while (p * p < sieve.size() - 1)
	{
		for (size_t i = p * p; i < sieve.size(); i += p)
			sieve[i] = false;
		p++;
	}
}

set<int> CoutingPrimes(vector<bool>& sieve)
{
	set<int> setOfPrimeNumbers;
	int count = 0;
	for (int i = 2; i <= sieve.size(); i++)
		if (sieve[i])
		{
			setOfPrimeNumbers.insert(i);
		}
	return setOfPrimeNumbers;
}

int SearchCountPrimeNumbers(int size)
{
	
	vector<bool> sieve = CreatingASieve(size);
	SievingSieve(sieve);
	set<int> setOfPrimeNumbers = CoutingPrimes(sieve);
	
	return setOfPrimeNumbers.size();
}



