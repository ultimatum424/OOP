
#include "stdafx.h"
#include "PrimeNumbers.h"


vector<bool> CreatingASieve(const int size)
{
	if (size <= 0)
	{
		vector<bool> sieve(1, true);
		return sieve;
	}
	else
	{
		vector<bool> sieve(size, true);
		return sieve;
	}
}

void SievingSieve(vector<bool>& sieve)
{
	int p = 2;
	while ((p * p) < (sieve.size() - 1))
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



