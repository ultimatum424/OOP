#pragma once
#include "stdafx.h"

typedef std::pair<double, double> coordinatesType;
class IShape
{
public:
	IShape() {};
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
};

