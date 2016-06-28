// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../vector/Vector3D.h"

struct Vector3DFixture
{
	CVector3D vector = { 5.26, 0, -15 };
	CVector3D vector2 = { 10, 2, 3 };
	CVector3D zeroVector = { 0, 0, 0 };
	double Rounding(const double value)
	{
		return double(int(value * 1000)) / 1000;
	}
	CVector3D Rounding(const CVector3D& v)
	{
		double x = Rounding(v.x);
		double y = Rounding(v.y);
		double z = Rounding(v.z);
		return CVector3D(x, y, z);
	}
};

BOOST_FIXTURE_TEST_SUITE(vector3d_tests, Vector3DFixture)

BOOST_AUTO_TEST_CASE(correct_out_result)
{
	BOOST_CHECK(vector.x == 5.26);
	BOOST_CHECK(vector.y == 0);
	BOOST_CHECK(vector.z == -15);
}

BOOST_AUTO_TEST_CASE(correct_length_vector)
{
	BOOST_CHECK_EQUAL(Rounding(vector.GetLength()), 15.895);
}

BOOST_AUTO_TEST_CASE(unary_plus_and_mines)
{
	CVector3D rightVector = vector;
	BOOST_CHECK(+vector == rightVector);
	rightVector = -vector;
	BOOST_CHECK(-vector == rightVector);
}

BOOST_AUTO_TEST_CASE(binary_plus)
{
	CVector3D rightVector = { 15.26, 2, -12 };
	CVector3D vector3 = vector2;
	BOOST_CHECK(vector + vector2 == rightVector);
	BOOST_CHECK(vector + zeroVector == vector);
	vector3 += vector;
	BOOST_CHECK(vector3 == rightVector);
}

BOOST_AUTO_TEST_CASE(binary_mines)
{
	CVector3D rightVector = { -4.74, -2, -18 };
	CVector3D vector3 = vector;
	BOOST_CHECK(vector - vector2 == rightVector);
	BOOST_CHECK(vector - zeroVector == vector);
	vector3 -= vector2;
	BOOST_CHECK(vector3 == rightVector);
}

BOOST_AUTO_TEST_CASE(multiplication)
{
	CVector3D rightVector = { 20, 4, 6 };
	CVector3D vector3 = vector2;
	BOOST_CHECK(vector2 * 2 == rightVector);
	BOOST_CHECK(2 * vector2 == rightVector);
	BOOST_CHECK(vector2 * 0 == zeroVector);
	vector3 *= 2;
	BOOST_CHECK(vector3 == rightVector);
	vector3 *= 0;
	BOOST_CHECK(vector3 == zeroVector);

}

BOOST_AUTO_TEST_CASE(division)
{
	CVector3D rightVector = { 5, 1, 1.5 };
	CVector3D vector3 = vector2;
	BOOST_CHECK(vector2 / 2 == rightVector);
	//BOOST_CHECK(vector2 / 0 != zeroVector);
	vector3 /= 2;
	BOOST_CHECK(vector3 == rightVector);
	//vector3 /= 0;
	//BOOST_CHECK((vector3 /= 0) != zeroVector);
}

BOOST_AUTO_TEST_CASE(equality_and_inequality)
{
	CVector3D vector3;
	BOOST_CHECK(vector3 == zeroVector);
	vector3 = vector;
	BOOST_CHECK(vector3 == vector);
	BOOST_CHECK(vector2 != zeroVector);
	BOOST_CHECK(vector2 != vector);
}

BOOST_AUTO_TEST_CASE(multiplication_vectors)
{
	CVector3D vector3 = { 1, 2, 3 };
	CVector3D rightVector = { 0, 27, -18 };
	BOOST_CHECK(CrossProduct(vector3, vector2) ==  rightVector);
}

BOOST_AUTO_TEST_CASE(scalar_multiplication_vectors)
{
	CVector3D vector3 = { 1, 2, 3 };
	BOOST_CHECK(DotProduct(vector2, vector3) == 23);
	BOOST_CHECK(DotProduct(vector2, zeroVector) == 0);
}

BOOST_AUTO_TEST_CASE(normalize)
{
	CVector3D normalizeVector = Normalize(vector2);
	CVector3D rightVector = { 0.940, 0.188, 0.282 };
	BOOST_CHECK(Rounding(normalizeVector) == rightVector);
}

BOOST_AUTO_TEST_CASE(cin_vector)
{
	std::stringbuf stringBuff("5 2 1");
	std::istream is (&stringBuff);
	is >> vector2;
	CVector3D rightVector = { 5, 2, 1 };
	BOOST_CHECK(vector2 == rightVector);
}

BOOST_AUTO_TEST_CASE(cout_vector)
{
	output_test_stream output;
	output << vector;
	BOOST_TEST(!output.is_empty(false));
	BOOST_TEST(output.is_equal("5.26, 0, -15"));
}
BOOST_AUTO_TEST_SUITE_END()