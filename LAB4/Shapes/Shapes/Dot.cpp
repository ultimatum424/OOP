#include "stdafx.h"
#include "Dot.h"


CDot::CDot(const coordinatesType& coordinates, const std::string& color)
	:CShape(color),
	m_coordinates(coordinates)
{
}

double CDot::GetArea() const
{
	return 0;
}

double CDot::GetPerimeter() const
{
	return 0;
}

std::string CDot::ToString() const
{
	return "Point < " + CShape::Convert(m_coordinates.first) +  ", " + CShape::Convert(m_coordinates.second) + +" S=" +
		CShape::Convert(GetArea()) +  " P=" + CShape::Convert(GetPerimeter()) + "> ";
}

coordinatesType CDot::GetCoordinates() const
{
	return m_coordinates;
}

