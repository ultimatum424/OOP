#include "stdafx.h"



struct TringleFixture
{
	CTriangle tringle;
	TringleFixture()
		:tringle({ 0, 0 }, { 10, 10 }, { 5, 5 }, "#ff00ff", "#ff11ff")
	{};
	std::vector<std::shared_ptr<CShape>> figures;
};

BOOST_FIXTURE_TEST_SUITE(tringle_tests, TringleFixture)

	BOOST_AUTO_TEST_CASE(correct_input)
	{
		std::vector<std::vector<std::string>> input = { { "triangle", "0", "5", "10", "0", "0", "0", "#ff00ff", "#ff11ff" } };
		BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
		BOOST_CHECK(figures.size() == 1);
	}

	BOOST_AUTO_TEST_CASE(correct_output)
	{
		BOOST_CHECK(tringle.Getcolor() == "#ff00ff");
		BOOST_CHECK(tringle.GetFillColor() == "#ff11ff");
		BOOST_CHECK_CLOSE(tringle.GetArea(), 200, 0.01);
		BOOST_CHECK_CLOSE(tringle.GetPerimeter(), 28.284, 0.01);
	}
BOOST_AUTO_TEST_SUITE_END()