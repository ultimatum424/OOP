#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(const coordinatesType& coordinates, const double& width, const double& height,
	const std::string& strColor, const std::string& fillColor)
	:CSolidShape(strColor, fillColor),
	m_LeftTop(coordinates, strColor),
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
	return "Rectangle <" + m_LeftTop.ToString() + " , " + CSolidShape::Convert(m_width) + " , "
		+ CSolidShape::Convert(m_height) + " , " + " S=" + CSolidShape::Convert(GetArea()) + " , "
		+ " P=" + CSolidShape::Convert(GetPerimeter()) + "> ";
}

