#pragma once
#include "SolidShape.h"
#include "Dot.h"
class CRectangle :
	public CSolidShape
{
public:
	CRectangle(const coordinatesType& coordinates, const float& width, const float& height, 
		const std::string& strColor, const std::string& fillColor);
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
private:
	CDot m_LeftTop;
	float m_width;
	float m_height;
};

