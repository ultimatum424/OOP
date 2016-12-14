#include "stdafx.h"
#include "SolidShape.h"


CSolidShape::CSolidShape(const std::string& color, const std::string& fillColor)
	:CShape(color),
	m_fillColor(fillColor)
{
}

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}
