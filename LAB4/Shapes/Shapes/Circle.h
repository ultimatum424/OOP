#pragma once
#include "SolidShape.h"
#include "Dot.h"
class CCircle :
	public CSolidShape
{
public:
	CCircle(const coordinatesType& coordinates, const float& radius, const std::string& strColor, const std::string& fillColor);
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
private:
	CDot m_centre;
	float m_radius;
};

