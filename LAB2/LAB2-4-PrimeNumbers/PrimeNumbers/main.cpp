#include "stdafx.h"
#include "PrimeNumbers.h"

int main()
{
	int size;
	cout << "SIZE = ";
	cin >> size;
	int count = SearchCountPrimeNumbers(size);
	cout << count << endl;
	system("pause");
	return 0;
}