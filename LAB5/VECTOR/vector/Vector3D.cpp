#include "stdafx.h"
#include "Vector3D.h"


CVector3D::CVector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

CVector3D::~CVector3D()
{
}

CVector3D::CVector3D(const double x0, const double y0, const double z0)
{
	x = x0;
	y = y0;
	z = z0;
}

double CVector3D::GetLength() const
{

	return 	sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void CVector3D::Normalize()
{
	double length = GetLength();
	if (length == 0)
	{
		throw std::invalid_argument("Err: Division by zero");
	}
	x /= length;
	y /= length;
	z /= length;
}

CVector3D Normalize(CVector3D const & v)
{
	double length = v.GetLength();
	if (length == 0)
	{
		throw std::invalid_argument("Err: Division by zero");
	}
	return CVector3D(v.x / length, v.y / length, v.z / length);
}

double DotProduct(CVector3D const & v1, CVector3D const & v2)
{
	return v1.x * v2.x + v1.y *v2.y + v1.z * v2.z;
}

CVector3D CrossProduct(CVector3D const & v1, CVector3D const & v2)
{

	return CVector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x *v2.y - v1.y * v2.x);
}

CVector3D const CVector3D::operator+() const
{
	return *this;
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D & CVector3D::operator+=(const CVector3D & vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

CVector3D & CVector3D::operator-=(const CVector3D & vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

CVector3D & CVector3D::operator*=(const double scalar)
{
	x = x * scalar;
	y = y * scalar;
	z = z * scalar;
	return *this;
}

CVector3D & CVector3D::operator/=(const double scalar)
{
	if (scalar == 0)
	{
		throw std::invalid_argument("Err: Division by zero");
	}
	x = x / scalar;
	y = y / scalar;
	z = z / scalar;
	return *this;
}

CVector3D const operator+(const CVector3D & v1, const CVector3D & v2)
{
	double x = v1.x + v2.x;
	double y = v1.y + v2.y;
	double z = v1.z + v2.z;
	return  CVector3D(x, y, z);
}

CVector3D const operator-(const CVector3D & v1, const CVector3D & v2)
{
	double x = v1.x - v2.x;
	double y = v1.y - v2.y;
	double z = v1.z - v2.z;
	return  CVector3D(x, y, z);
}

CVector3D const operator*(const CVector3D & vector, const double scalar)
{
	return CVector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

CVector3D const operator*(const double scalar, const CVector3D & vector)
{
	return CVector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

CVector3D const operator/(const CVector3D & vector, const double scalar)
{
	if (scalar == 0)
	{
		throw std::invalid_argument("Err: Division by zero");
	}
	return CVector3D(vector.x / scalar, vector.y / scalar, vector.z / scalar);
}

bool const operator==(const CVector3D & v1, const CVector3D & v2)
{
	if (abs(v1.x - v2.x) > DBL_EPSILON)
	{
		return false;
	}
	if (abs(v1.y - v2.y) > DBL_EPSILON)
	{
		return false;
	}
	if (abs(v1.z - v2.z) > DBL_EPSILON)
	{
		return false;
	}
	return true;
}

bool const operator!=(const CVector3D & v1, const CVector3D & v2)
{
	if (v1 == v2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::ostream& operator<<(std::ostream& stream, CVector3D & vector)
{
	stream << vector.x << ", " << vector.y << ", " << vector.z;
	return stream;
}

std::istream & operator>>(std::istream & stream, CVector3D & counter)
{
	double x;
	double y;
	double z;
	try
	{
		if ((stream >> x) && (stream.get() == ',') && (stream >> y) && (stream.get() == ',') && (stream >> z))
		{
			counter.x = x;
			counter.y = y;
			counter.z = z;
		}
	}
	catch (const std::exception&)
	{
		stream.setstate(std::ios::failbit);
	}
	return stream;
}