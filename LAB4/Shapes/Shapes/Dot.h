#pragma once
#include "IShape.h"
class CDot : public CShape
{
public:
	CDot(const coordinatesType& coordinates, const std::string& color);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	coordinatesType GetCoordinates() const;
	std::vector<std::string> ToStringSfml() const override;

private:
	coordinatesType m_coordinates;
};

