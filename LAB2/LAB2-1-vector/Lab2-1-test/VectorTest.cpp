#include "stdafx.h"
#include "../LAB2-1/Lab2-1.h"
#include <vector>

BOOST_AUTO_TEST_SUITE(VectorDivisionTest)

	BOOST_AUTO_TEST_CASE(Div—heck)
	{
		vector<double> startVector1 = {2, 2, 1};
		vector<double> resultVector1 = { 2, 2, 1};

		vector<double> startVector2 = { 0, -12, 3 };
		vector<double> resultVector2 = { 0, -8, 2};

		BOOST_CHECK(DivisinonArrayOnM‡xElement(startVector1) == resultVector1);
		BOOST_CHECK(DivisinonArrayOnM‡xElement(startVector2) == resultVector2);
		
	}
	BOOST_AUTO_TEST_CASE(CheckFor0)
{
	vector<double> startVector1 = { 0, 0, 0 };
	vector<double> resultVector1 = { 0 , 0, 0 };

	vector<double> startVector2 = { -2, -2, 0 };
	vector<double> resultVector2 = { -2, -2, 0 };

	BOOST_CHECK(DivisinonArrayOnM‡xElement(startVector1) == resultVector1);
	BOOST_CHECK(DivisinonArrayOnM‡xElement(startVector2) == resultVector2);
}
	BOOST_AUTO_TEST_CASE(CheckForNull)
	{
		vector<double> startVector = {};
		vector<double> resultVector = {};
		BOOST_CHECK(DivisinonArrayOnM‡xElement(startVector) == resultVector);
	}
BOOST_AUTO_TEST_SUITE_END()
