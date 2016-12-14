#pragma once
#include "IShape.h"
class CShape :
	public IShape
{
public:
	CShape(const std::string& color);
	std::string Getcolor() const;
	std::string Convert(const double number) const;
protected:
	std::string m_color;
};

