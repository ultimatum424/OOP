#pragma once
#include "ISolidShape.h"
#include "Shape.h"
class CSolidShape :
	public ISolidShape, public CShape
{
public:
	CSolidShape(const std::string& color, const std::string& fillColor);
	std::string GetFillColor() const;
protected:
	std::string m_fillColor;
};

