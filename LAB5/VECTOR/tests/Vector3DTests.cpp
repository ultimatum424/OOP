// tests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../vector/Vector3D.h"

struct Vector3DFixture
{
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

BOOST_AUTO_TEST_CASE(Vector3D_get_value_from_constructor)
{
	CVector3D vector = { 5.26, 0, -15 };
	BOOST_CHECK(vector.x == 5.26);
	BOOST_CHECK(vector.y == 0);
	BOOST_CHECK(vector.z == -15);
}

BOOST_AUTO_TEST_CASE(Vector3D_reutrn_length_vector)
{
	CVector3D vector = { 5.26, 0, -15 };
	BOOST_CHECK_EQUAL(Rounding(vector.GetLength()), 15.895);
}

BOOST_AUTO_TEST_CASE(Vector3D_have_unary_operators_plus_and_minus)
{
	CVector3D vector = { 5.26, 0, -15 };
	CVector3D rightVector = vector;
	BOOST_CHECK(+vector == rightVector);
	rightVector = -vector;
	BOOST_CHECK(-vector == rightVector);
}

BOOST_AUTO_TEST_CASE(Vector3D_have_binary_operators_plus)
{
	CVector3D vector = { 5.26, 0, -15 };
	CVector3D vector2 = { 10, 2, 3 };
	CVector3D zeroVector = { 0, 0, 0 };
	CVector3D rightVector = { 15.26, 2, -12 };
	CVector3D vector3 = vector2;
	BOOST_CHECK(vector + vector2 == rightVector);
	BOOST_CHECK(vector + zeroVector == vector);
	vector3 += vector;
	BOOST_CHECK(vector3 == rightVector);
}

BOOST_AUTO_TEST_CASE(Vector3D_have_binary_operators_minus)
{
	CVector3D vector = { 5.26, 0, -15 };
	CVector3D vector2 = { 10, 2, 3 };
	CVector3D zeroVector(0, 0, 0);
	CVector3D rightVector = { -4.74, -2, -18 };
	CVector3D vector3 = vector;
	BOOST_CHECK(vector - vector2 == rightVector);
	BOOST_CHECK(vector - zeroVector == vector);
	vector3 -= vector2;
	BOOST_CHECK(vector3 == rightVector);
}

BOOST_AUTO_TEST_CASE(Vector3D_can_multiply_vector_and_scalar)
{
	CVector3D vector = { 5.26, 0, -15 };
	CVector3D vector2 = { 10, 2, 3 };
	CVector3D rightVector = { 20, 4, 6 };
	CVector3D zeroVector = { 0, 0, 0 };
	CVector3D vector3 = vector2;
	BOOST_CHECK(vector2 * 2 == rightVector);
	BOOST_CHECK(2 * vector2 == rightVector);
	BOOST_CHECK(vector2 * 0 == zeroVector);
	vector3 *= 2;
	BOOST_CHECK(vector3 == rightVector);
	vector3 *= 0;
	BOOST_CHECK(vector3 == zeroVector);

}

BOOST_AUTO_TEST_CASE(Vector3D_can_division_vector_and_scalar)
{
	CVector3D vector2 = { 10, 2, 3 };
	CVector3D rightVector = { 5, 1, 1.5 };
	CVector3D vector3 = vector2;
	BOOST_CHECK(vector2 / 2 == rightVector);
	vector3 /= 2;
	BOOST_CHECK(vector3 == rightVector);
}

BOOST_AUTO_TEST_CASE(Vector3D_have_operation_equality_and_inequality)
{
	BOOST_CHECK(CVector3D(4, 4, 4) == CVector3D(4, 4, 4));
	BOOST_CHECK_EQUAL(CVector3D(4, 4, 4) == CVector3D(4, 0, 4), false);
	BOOST_CHECK_EQUAL(CVector3D(4, 4, 4) != CVector3D(4, 0, 4), true);
	BOOST_CHECK_EQUAL(CVector3D(4, 4, 4) != CVector3D(4, 4, 4), false);
	BOOST_CHECK(CVector3D(1, 0, 0) != CVector3D(1, 1, 0));
}

BOOST_AUTO_TEST_CASE(Vector3D_can_multiply_vectors)
{
	BOOST_CHECK(CrossProduct(CVector3D(1, 2, 3), CVector3D(10, 2, 3)) == CVector3D(0, 27, -18));
}

BOOST_AUTO_TEST_CASE(Vector3D_have_scalar_multiplication_vectors)
{
	CVector3D vectorZero = { 0, 0, 0 };
	CVector3D vector2 = { 10, 2, 3 };
	CVector3D vector3 = { 1, 2, 3 };
	CVector3D zeroVector(0, 0, 0);
	BOOST_CHECK(DotProduct(vector2, vector3) == 23);
	BOOST_CHECK(DotProduct(vector2, zeroVector) == 0);
}

BOOST_AUTO_TEST_CASE(Vector3D_have_operation_normalizion)
{
	CVector3D vector2 = { 10, 2, 3 };
	CVector3D vector3 = vector2;
	vector3.Normalize();
	CVector3D normalizeVector = Normalize(vector2);
	CVector3D rightVector = { 0.940, 0.188, 0.282 };
	BOOST_CHECK(Rounding(normalizeVector) == rightVector);
	BOOST_CHECK(Rounding(vector3) == rightVector);
}

BOOST_AUTO_TEST_CASE(Vector3D_can_read_data_from_stream)
{
	CVector3D vector2 = { 10, 2, 3 };
	std::stringbuf stringBuff("5 2 1");
	std::istream is(&stringBuff);
	is >> vector2;
	CVector3D rightVector = { 5, 2, 1 };
	BOOST_CHECK(vector2 == rightVector);
}

BOOST_AUTO_TEST_CASE(Vector3D_can_output_data_to_stream)
{
	CVector3D vector = { 5.26, 0, -15 };
	output_test_stream output;
	output << vector;
	BOOST_TEST(!output.is_empty(false));
	BOOST_TEST(output.is_equal("5.26, 0, -15"));
}
BOOST_AUTO_TEST_SUITE_END()