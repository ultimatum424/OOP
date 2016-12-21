#include "stdafx.h"

struct PointFixture
{
	CDot dot;
	PointFixture()
		:dot({ 10 , 10 }, "#ff00ff")
	{ }
	std::vector<std::shared_ptr<CShape>> figures;
};

BOOST_FIXTURE_TEST_SUITE(point_tests, PointFixture)
	BOOST_AUTO_TEST_CASE(correct_out_result)
	{
		BOOST_CHECK(dot.GetCoordinates().first == 10);
		BOOST_CHECK(dot.GetCoordinates().second == 10);
		BOOST_CHECK(dot.Getcolor() == "#ff00ff");
		BOOST_CHECK(dot.GetArea() == 0);
		BOOST_CHECK(dot.GetPerimeter() == 0);
	}

	BOOST_AUTO_TEST_CASE(correct_input)
	{
		std::vector<std::vector<std::string>> input = { { { "point" },{ "10" },{ "20" },{ "#ff00ff" } } };
		BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
		BOOST_CHECK(figures.size() == 1);
	}
BOOST_AUTO_TEST_SUITE_END()

