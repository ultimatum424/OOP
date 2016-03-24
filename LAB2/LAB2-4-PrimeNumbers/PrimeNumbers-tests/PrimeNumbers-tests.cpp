// PrimeNumbers-tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../PrimeNumbers/PrimeNumbers.h"
#include <vector>


BOOST_AUTO_TEST_SUITE(PrimeNumersTests)

BOOST_AUTO_TEST_CASE(DivСheck)
{
	vector<bool> inputVector(10, true);
	set<int> outSet = {2, 3, 5, 7};
	SievingSieve(inputVector);
	//BOOST_CHECK_EQUAL(SearchPrimeNumbers(100'000'000), 5791455);
	BOOST_CHECK_EQUAL(inputVector, outSet);

}
BOOST_AUTO_TEST_SUITE_END()

