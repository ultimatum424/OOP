#pragma once
#include "ISolidShape.h"
#include "Shape.h"
class CSolidShape :
	public CShape, ISolidShape
{
public:
	CSolidShape(const std::string& strColor, const std::string& fillColor);
	std::string GetFillColor() const;
protected:
	std::string m_fillColor;
};

