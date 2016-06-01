#pragma once
#include "IShape.h"
#include "Shape.h"
class CDot : public CShape
{
public:
	CDot(const coordinatesType& coordinates, const std::string& strColor);
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string ToString() const override;
	coordinatesType GetCoordinates() const;

private:
	coordinatesType m_coordinates;
};

