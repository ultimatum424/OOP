#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(const coordinatesType& coordinates, const float& width, const float& height,
	const std::string& strColor, const std::string& fillColor)
	:CSolidShape(strColor, fillColor),
	m_LeftTop(coordinates, strColor),
	m_width(width),
	m_height(height)
{
}

float CRectangle::GetArea() const
{
	return m_width * m_height;
}

float CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

std::string CRectangle::ToString() const
{
	return "R<" + m_LeftTop.ToString() + "," + CSolidShape::Convert(m_width) + ","
		+ CSolidShape::Convert(m_height) + "," + "S=" + CSolidShape::Convert(GetArea()) + ","
		+ "P=" + CSolidShape::Convert(GetPerimeter()) + ">";
}

