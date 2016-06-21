// Tests.cpp: определяет точку входа для консольного приложения.
//

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
		BOOST_CHECK(dot.GetStrColor() == "#ff00ff");
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
		BOOST_CHECK(line.GetStrColor() == "#ff00ff");
		BOOST_CHECK(line.GetArea() == 0);
		BOOST_CHECK(line.GetPerimeter() == 10);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CircleFixture
{
	CCircle circle;
	CircleFixture()
		:circle({10, 10}, 100, "#ff00ff", "#ff11ff")
	{}
	std::vector<std::shared_ptr<CShape>> figures;
};

BOOST_FIXTURE_TEST_SUITE(circle_tests, CircleFixture)

BOOST_AUTO_TEST_CASE(correct_input)
{
	std::vector<std::vector<std::string>> input = { { { "circle" },{ "0" },{ "0" },{ "10" }, { "#ff00ff" },{ "#ff11ff" } } };
	BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(correct_output)
{
	BOOST_CHECK(circle.GetStrColor() == "#ff00ff");
	BOOST_CHECK(circle.GetFillColor() == "#ff11ff");
	BOOST_CHECK_EQUAL(circle.GetArea() / 100, M_PI * 100);
	BOOST_CHECK_EQUAL(circle.GetPerimeter() / 10, M_PI * 20 );
}
BOOST_AUTO_TEST_SUITE_END()


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
	std::vector<std::vector<std::string>> input = { { { "rectangle" },{ "0" },{ "0" },{ "10" },{ "20" },{ "#ff00ff" }, { "#ff11ff" } } };
	BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(correct_output)
{
	BOOST_CHECK(rectangle.GetStrColor() == "#ff00ff");
	BOOST_CHECK(rectangle.GetFillColor() == "#ff11ff");
	BOOST_CHECK(rectangle.GetArea() == 200);
	BOOST_CHECK(rectangle.GetPerimeter() == 60);
}
BOOST_AUTO_TEST_SUITE_END()


struct TringleFixture
{
	CTriangle tringle;
	TringleFixture()
		:tringle({ 0, 0 }, { 10, 10}, { 5, 5 }, "#ff00ff", "#ff11ff")
	{};
	std::vector<std::shared_ptr<CShape>> figures;
};

BOOST_FIXTURE_TEST_SUITE(tringle_tests, TringleFixture)

BOOST_AUTO_TEST_CASE(correct_input)
{
	std::vector<std::vector<std::string>> input = { {"triangle", "0", "5", "10", "0", "0", "0", "#ff00ff", "#ff11ff"} };
	BOOST_CHECK_NO_THROW(ParseCommands(figures, input));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(correct_output)
{
	BOOST_CHECK(tringle.GetStrColor() == "#ff00ff");
	BOOST_CHECK(tringle.GetFillColor() == "#ff11ff");
	BOOST_CHECK_EQUAL(std::trunc( 1000 *tringle.GetArea()), 200 * 1000);
	BOOST_CHECK_EQUAL(std::trunc(1000 * tringle.GetPerimeter()), (28.284) * 1000);
}
BOOST_AUTO_TEST_SUITE_END()