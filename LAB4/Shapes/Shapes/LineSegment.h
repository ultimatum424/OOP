#pragma once
#include "Shape.h"
#include "Dot.h"
class CLineSegment :
	public CShape
{
public:
	CLineSegment(const coordinatesType& coordinates1, const coordinatesType& coordinates2, const std::string& color);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
private:
	CDot m_start;
	CDot m_end;
};

