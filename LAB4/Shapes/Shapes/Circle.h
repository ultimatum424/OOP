#pragma once
#include "SolidShape.h"
#include "Dot.h"
class CCircle :
	public CSolidShape
{
public:
	CCircle(const coordinatesType& coordinates, const double& radius, const std::string& color, const std::string& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::vector<std::string> ToStringSfml() const override;
private:
	CDot m_centre;
	double m_radius;
};

