#pragma once
class CVector3D
{
public:
	CVector3D();
	~CVector3D();
	CVector3D(double x0, double y0, double z0);

	double GetLength()const;

	void Normalize();

	CVector3D const operator+() const;

	CVector3D const  operator-() const;

	CVector3D& operator+=(const CVector3D& vector);

	CVector3D& operator-=(const CVector3D& vector);

	CVector3D& operator*=(const float scalar);

	CVector3D& operator/=(const float scalar);


	double x;
	double y;
	double z;
};

double DotProduct(CVector3D const& v1, CVector3D const& v2);

CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);

CVector3D Normalize(CVector3D const& v);

CVector3D const operator+(const CVector3D & v1, const CVector3D & v2);

CVector3D const operator-(const CVector3D & v1, const CVector3D & v2);

CVector3D const operator*(const CVector3D & vector, const float scalar);

CVector3D const operator*(const float scalar, const CVector3D & vector);

CVector3D const operator/(const CVector3D & vector, const float scalar);

CVector3D const operator/(const float scalar, const CVector3D & vector);

bool const operator==(const CVector3D & v1, const CVector3D & v2);

bool const operator!=(const CVector3D & v1, const CVector3D & v2);

std::ostream& operator<<(std::ostream& stream, CVector3D & vector);

std::istream & operator>>(std::istream & stream, CVector3D & counter);
