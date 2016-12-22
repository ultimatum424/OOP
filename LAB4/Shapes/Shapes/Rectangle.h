#pragma once
#include "SolidShape.h"
#include "Dot.h"
class CRectangle :
	public CSolidShape
{
public:
	CRectangle(const coordinatesType& coordinates, const double& width, const double& height, 
		const std::string& color, const std::string& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::vector<std::string> ToStringSfml() const override;
private:
	CDot m_LeftTop;
	double m_width;
	double m_height;
};

