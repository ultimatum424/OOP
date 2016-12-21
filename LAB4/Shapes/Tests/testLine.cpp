#include "stdafx.h"



struct LineFixture
{
	CLineSegment line;
	LineFixture()
		:line({ 0, 0 }, { 0, 10 }, "#ff00ff")
	{}
	std::vector<std::shared_ptr<CShape>> figures;
};

BOOST_FIXTURE_TEST_SUITE(line_tests, LineFixture)

	BOOST_AUTO_TEST_CASE(correct_input)
	{
		std::vector<std::vector<std::string>> input = { { { "line" },{ "10" },{ "20" },{ "10" },{ "20" },{ "#ff00ff" } } };
		BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
		BOOST_CHECK(figures.size() == 1);
	}

	BOOST_AUTO_TEST_CASE(correct_output)
	{
		BOOST_CHECK(line.Getcolor() == "#ff00ff");
		BOOST_CHECK(line.GetArea() == 0);
		BOOST_CHECK(line.GetPerimeter() == 10);
	}
BOOST_AUTO_TEST_SUITE_END()