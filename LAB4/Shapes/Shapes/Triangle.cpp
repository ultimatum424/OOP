#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(const coordinatesType& dot1, const coordinatesType& dot2, const coordinatesType& dot3,
	const std::string& strColor, const std::string& fillColor)
	:CSolidShape(strColor, fillColor),
	m_dot1(dot1, strColor),
	m_dot2(dot2, strColor),
	m_dot3(dot3, strColor),
	m_line1(dot1, dot2, strColor),
	m_line2(dot1, dot3, strColor),
	m_line3(dot2, dot3, strColor)
{
}

float CTriangle::GetArea() const
{
	float semiperimeter = this->GetPerimeter() / 2;
	return sqrtf(semiperimeter * (semiperimeter - m_dot1.GetPerimeter()) * (semiperimeter - m_dot2.GetPerimeter()) *
		(semiperimeter - m_dot3.GetPerimeter()));
}

float CTriangle::GetPerimeter() const
{
	return m_line1.GetPerimeter() + m_line2.GetPerimeter() + m_line3.GetPerimeter();
}

std::string CTriangle::ToString() const
{

}