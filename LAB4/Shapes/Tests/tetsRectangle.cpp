#include "stdafx.h"

struct RectangleFixture
{
	CRectangle rectangle;
	RectangleFixture()
		:rectangle({ 0, 0 }, 10, 20, "#ff00ff", "#ff11ff")
	{};
	std::vector<std::shared_ptr<CShape>> figures;
};

BOOST_FIXTURE_TEST_SUITE(rectangle_tests, RectangleFixture)

	BOOST_AUTO_TEST_CASE(correct_input)
	{
		std::vector<std::vector<std::string>> input = { { { "rectangle" },{ "0" },{ "0" },{ "10" },{ "20" },{ "#ff00ff" },{ "#ff11ff" } } };
		BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
		BOOST_CHECK(figures.size() == 1);
	}

	BOOST_AUTO_TEST_CASE(correct_output)
	{
		std::vector<std::shared_ptr<ISolidShape>> solidShapes;
		BOOST_CHECK(rectangle.Getcolor() == "#ff00ff");
		BOOST_CHECK(rectangle.GetFillColor() == "#ff11ff");
		BOOST_CHECK(rectangle.GetArea() == 200);
		BOOST_CHECK(rectangle.GetPerimeter() == 60);
	}
BOOST_AUTO_TEST_SUITE_END()
