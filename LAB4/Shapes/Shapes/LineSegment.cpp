#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment(const coordinatesType& coordinates1, const coordinatesType& coordinates2, const std::string& color)
	:CShape(color),
	m_start(coordinates1, color),
	m_end(coordinates2, color)
{
}


double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow(m_start.GetCoordinates().first - m_end.GetCoordinates().first, 2) +
		pow(m_start.GetCoordinates().second - m_end.GetCoordinates().second, 2));
}

std::string CLineSegment::ToString() const
{
	return "Line <" + m_start.ToString() + ", " + m_end.ToString() + ", " + " S=" + CShape::Convert(GetArea())
		+ " P=" + CShape::Convert(GetPerimeter()) + "> ";
}

std::vector<std::string> CLineSegment::ToStringSfml() const
{
	return std::vector<std::string>{"Line", Convert(m_start.GetCoordinates().first),
		Convert(m_start.GetCoordinates().second), Convert(m_end.GetCoordinates().first), Convert(m_end.GetCoordinates().second),
		m_color};
}
