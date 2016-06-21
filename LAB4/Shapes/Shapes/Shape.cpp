#include "stdafx.h"
#include "Shape.h"


CShape::CShape(const std::string& color)
{
	m_strColor = color;
}


std::string CShape::GetStrColor() const
{
	return m_strColor;
}

std::string CShape::Convert(const double number) const
{
	std::ostringstream buff;
	buff << number;
	return buff.str();
}
