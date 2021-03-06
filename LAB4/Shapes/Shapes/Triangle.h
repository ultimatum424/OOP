#pragma once
#include "SolidShape.h"
#include "Dot.h"
#include "LineSegment.h"
class CTriangle :
	public CSolidShape
{
public:
	CTriangle(const coordinatesType& dot1, const coordinatesType& dot2, const coordinatesType& dot3,
		const std::string& strString, const std::string& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::vector<std::string> ToStringSfml() const override;

private:
	CDot m_dot1;
	CDot m_dot2;
	CDot m_dot3;
	CLineSegment m_line1;
	CLineSegment m_line2;
	CLineSegment m_line3;
};

