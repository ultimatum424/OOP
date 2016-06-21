#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(const coordinatesType& coordinates, const double& radius, const std::string& strColor, const std::string& fillColor)
	:CSolidShape(strColor, fillColor),
	m_centre(coordinates, strColor),
	m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	return "Circle <" + m_centre.ToString() + " , " +  "R=" + CSolidShape::Convert(m_radius)
		+ " S=" + CSolidShape::Convert(GetArea()) + " , " + " P=" + CSolidShape::Convert(GetPerimeter()) + "> ";
}


