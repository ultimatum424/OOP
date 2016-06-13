#pragma once
#include "IShape.h"
class CShape :
	public IShape
{
public:
	CShape(const std::string& color);
	std::string GetStrColor() const;
	std::string Convert(const float number) const;
protected:
	std::string m_strColor;
};

