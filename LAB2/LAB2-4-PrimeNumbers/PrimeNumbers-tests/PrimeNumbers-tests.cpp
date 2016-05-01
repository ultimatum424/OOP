// PrimeNumbers-tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../PrimeNumbers/PrimeNumbers.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(PrimeNumbersTest)

	BOOST_AUTO_TEST_CASE(CheckCreatingVector)
	{
		vector<bool> startVecotr1 = {1};
		vector<bool> resultVector1 = CreatingASieve(0);
		BOOST_CHECK(startVecotr1 == resultVector1);
		vector<bool> startVecotr2 = {1, 1, 1, 1, 1, 1};
		vector<bool> resultVector2 = CreatingASieve(5);
		BOOST_CHECK(startVecotr2 == resultVector2);
	}
	
	BOOST_AUTO_TEST_CASE(CheckSievingSieve)
	{
		vector<bool> startVecotr1(5, true);
		vector<bool> resultVector1 = { 1, 1, 1, 1, 1 };
		BOOST_CHECK(startVecotr1 == resultVector1);
		vector<bool> startVecotr2(1, true);
		vector<bool> resultVector2 = { 1 };
		BOOST_CHECK(startVecotr2 == resultVector2);
	}
	BOOST_AUTO_TEST_CASE(CheckCoutingPrimes)
	{
		vector<bool> startVecotr1 = {1};
		set<int> startSet1 = GetPrimesSet(startVecotr1);
		set<int> resultSet1 = {};
		BOOST_CHECK(startSet1 == resultSet1);
		vector<bool> startVecotr2 = { 1, 1, 1, 1, 0, 1, 0, 1, 0 };
		set<int> startSet2 = GetPrimesSet(startVecotr2);
		set<int> resultSet2 = { 2, 3, 5, 7 };
		BOOST_CHECK(startSet2 == resultSet2);
	} 
	
	BOOST_AUTO_TEST_CASE(CheckMaxPrime)
	{
		std::vector<bool> sieve = CreatingASieve(100000000);
		SievingSieve(sieve);
		std::set<int> setOfPrimeNumbers = GetPrimesSet(sieve);
		size_t size = setOfPrimeNumbers.size();
		BOOST_CHECK(size == (5761455));
	}
	
BOOST_AUTO_TEST_SUITE_END()