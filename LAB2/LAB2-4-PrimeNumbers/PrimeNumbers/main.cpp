#include "stdafx.h"
#include "PrimeNumbers.h"

int main()
{
	int size;
	cout << "SIZE = ";
	cin >> size;
	
	vector<bool> sieve = CreatingASieve(size);
	SievingSieve(sieve);
	set<int> setOfPrimeNumbers = CoutingPrimes(sieve);
	int count =  setOfPrimeNumbers.size();
	cout << count << endl;
	return 0;
}