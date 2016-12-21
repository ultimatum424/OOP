#include "stdafx.h"


struct CircleFixture
{
	CCircle circle;
	CircleFixture()
		:circle({ 10, 10 }, 100, "#ff00ff", "#ff11ff")
	{}
	std::vector<std::shared_ptr<CShape>> figures;
};

BOOST_FIXTURE_TEST_SUITE(circle_tests, CircleFixture)

	BOOST_AUTO_TEST_CASE(correct_input)
	{
		std::vector<std::vector<std::string>> input = { { { "circle" },{ "0" },{ "0" },{ "10" },{ "#ff00ff" },{ "#ff11ff" } } };
		BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
		BOOST_CHECK(figures.size() == 1);
	}

	BOOST_AUTO_TEST_CASE(correct_output)
	{
		BOOST_CHECK(circle.Getcolor() == "#ff00ff");
		BOOST_CHECK(circle.GetFillColor() == "#ff11ff");
		BOOST_CHECK_EQUAL(circle.GetArea() / 100, M_PI * 100);
		BOOST_CHECK_EQUAL(circle.GetPerimeter() / 10, M_PI * 20);
	}
BOOST_AUTO_TEST_SUITE_END()


