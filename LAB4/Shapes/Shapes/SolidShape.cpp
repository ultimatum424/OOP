#include "stdafx.h"
#include "SolidShape.h"


CSolidShape::CSolidShape(const std::string& strColor, const std::string& fillColor)
	:CShape(strColor),
	m_fillColor(fillColor)
{
}

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}
