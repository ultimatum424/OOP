#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(const coordinatesType& dot1, const coordinatesType& dot2, const coordinatesType& dot3,
	const std::string& color, const std::string& fillColor)
	:CSolidShape(color, fillColor),
	m_dot1(dot1, color),
	m_dot2(dot2, color),
	m_dot3(dot3, color),
	m_line1(dot1, dot2, color),
	m_line2(dot1, dot3, color),
	m_line3(dot2, dot3, color)
{
}

double CTriangle::GetArea() const
{
	double semiperimeter = this->GetPerimeter() / 2;
	return sqrt(semiperimeter * (semiperimeter - m_dot1.GetPerimeter()) * (semiperimeter - m_dot2.GetPerimeter()) *
		(semiperimeter - m_dot3.GetPerimeter()));
}

double CTriangle::GetPerimeter() const
{
	return m_line1.GetPerimeter() + m_line2.GetPerimeter() + m_line3.GetPerimeter();
}

std::string CTriangle::ToString() const
{
	return "Triangle <" + m_dot1.ToString() + " , " + m_dot2.ToString() + " , " + m_dot3.ToString()
		+ " , " + m_line1.ToString() + "," + m_line2.ToString() + " , " + m_line3.ToString()
		+ " S=" + CSolidShape::Convert(GetArea()) + " P=" + CSolidShape::Convert(GetPerimeter()) + "> ";
}

std::vector<std::string> CTriangle::ToStringSfml() const
{
	return std::vector<std::string>{"Triangle", 
		Convert(m_dot1.GetCoordinates().first), Convert(m_dot1.GetCoordinates().second), 
		Convert(m_dot2.GetCoordinates().first), Convert(m_dot2.GetCoordinates().second),
		Convert(m_dot3.GetCoordinates().first), Convert(m_dot3.GetCoordinates().second),
		m_fillColor};
}
