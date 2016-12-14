#include "stdafx.h"
#include "Shape.h"


CShape::CShape(const std::string& color)
{
	m_color = color;
}


std::string CShape::Getcolor() const
{
	return m_color;
}

std::string CShape::Convert(const double number) const
{
	std::ostringstream buff;
	buff << number;
	return buff.str();
}
