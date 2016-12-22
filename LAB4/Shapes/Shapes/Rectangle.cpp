#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(const coordinatesType& coordinates, const double& width, const double& height,
	const std::string& color, const std::string& fillColor)
	:CSolidShape(color, fillColor),
	m_LeftTop(coordinates, color),
	m_width(width),
	m_height(height)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

std::string CRectangle::ToString() const
{
	return "Rectangle <" + m_LeftTop.ToString() + ", " + CSolidShape::Convert(m_width) + ", "
		+ CSolidShape::Convert(m_height) + ", " + " S=" + CSolidShape::Convert(GetArea()) + ", "
		+ " P=" + CSolidShape::Convert(GetPerimeter()) + "> ";
}

std::vector<std::string> CRectangle::ToStringSfml() const
{
	return std::vector<std::string>{"Rectangle", Convert(m_LeftTop.GetCoordinates().first), Convert(m_LeftTop.GetCoordinates().second),
		Convert(m_width), Convert(m_height), m_fillColor};
}

