#pragma once
#include "stdafx.h"

typedef std::pair<float, float> coordinatesType;
class IShape
{
public:
	IShape() {};
	virtual ~IShape() = default;
	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
};

