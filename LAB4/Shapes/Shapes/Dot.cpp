#include "stdafx.h"
#include "Dot.h"


CDot::CDot(const coordinatesType& coordinates, const std::string& strColor)
	:CShape(strColor),
	m_coordinates()
{
}

float CDot::GetArea() const
{
	return 0;
}

float CDot::GetPerimeter() const
{
	return 0;
}

std::string CDot::ToString() const
{
	return "D<" + CShape::Convert(m_coordinates.first) + "," + CShape::Convert(m_coordinates.second) + ">";
}

coordinatesType CDot::GetCoordinates() const
{
	return m_coordinates;
}

