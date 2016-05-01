#include "stdafx.h"
#include "PrimeNumbers.h"

int main()
{
	// TODO: don't declare variable on separate line +
	
	std::cout << "SIZE = ";
	int size = ReadNumber();
	if (size) {
		std::vector<bool> sieve = CreatingASieve(size);
		SievingSieve(sieve);

		// TODO: print set elements
		std::set<int> setOfPrimeNumbers = GetPrimesSet(sieve);
		size_t count = setOfPrimeNumbers.size();
		std::cout << count << std::endl;
		std::cout << std::endl;
		OutSetPrime(setOfPrimeNumbers);
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}
	return 0;
}