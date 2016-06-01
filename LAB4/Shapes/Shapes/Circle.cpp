#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(const coordinatesType& coordinates, const float& radius, const std::string& strColor, const std::string& fillColor)
	:CSolidShape(strColor, fillColor),
	m_centre(coordinates, strColor),
	m_radius(radius)
{
}

float CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

float CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{

}

