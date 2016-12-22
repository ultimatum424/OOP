#pragma once

typedef std::pair<float, float> coordinatesType;
class IShape
{
public:
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::vector<std::string> ToStringSfml() const = 0;
};

