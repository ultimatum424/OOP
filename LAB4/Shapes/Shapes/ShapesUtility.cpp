#include "stdafx.h"
#include "ShapesUtility.h"


void CreatDot(const std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand) {
	if (stringsComand.size() != 3)
	{
		throw std::exception("Err: Invalid parameters count ");
	}
	try
	{
		coordinatesType coordinates = { stof(stringsComand[1]), stof(stringsComand[2]) };
		figures.push_back(std::make_shared<CDot>(coordinates, stringsComand[3]));
	}
	catch (const std::exception&)
	{
		throw std::exception("Err: Invalid parameters to create point");
	}
}

void CreatLineSegment(const std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 6)
	{
		throw std::exception("Err: Invalid parameters count ");
	}
	try
	{
		coordinatesType firstDot = { stof(stringsComand[1]), stof(stringsComand[2]) };
		coordinatesType secondDot = { stof(stringsComand[3]), stof(stringsComand[4]) };
		figures.push_back(std::make_shared<CDot>(firstDot, secondDot, stringsComand[5]));
	}
	catch (const std::exception&)
	{
		throw std::exception("Err: Invalid parameters to create line");
	}
}

void CreateCircle(const std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 6)
	{
		throw std::exception("Err: Invalid parameters count ");
	}
	try
	{
		float radius = stof(stringsComand[3]);
			if (radius == 0)
			{
				throw std::exception("");
			}
		coordinatesType coordinates = { stof(stringsComand[1]), stof(stringsComand[2]) };
		figures.push_back(std::make_shared<CCircle>(coordinates, radius, stringsComand[4], stringsComand[5]));
	}
	catch (const std::exception&)
	{
		throw std::exception("Err: Invalid parameters to create circle");
	}
}

void CreateRectangle(const std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 7)
	{
		throw std::exception("Err: Invalid parameters count ");

	}
	try
	{
		float width = stof(stringsComand[3]);
		float height = stof(stringsComand[4]);
		if (width <= 0 || height <= 0)
		{
			throw std::exception("");
		}
		coordinatesType coordinates = { stof(stringsComand[1]), stof(stringsComand[2]) };
		figures.push_back(std::make_shared<CRectangle>(coordinates, width, height, stringsComand[4], stringsComand[5]));
	}
	catch (const std::exception&)
	{
		throw std::exception("Err: Invalid parameters to create rectangle");
	}
}

void CreateTriangle(const std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 9)
	{
	}
	try
	{
		coordinatesType dot1 = { stof(stringsComand[1]), stof(stringsComand[2]) };
		coordinatesType dot2 = { stof(stringsComand[3]), stof(stringsComand[4]) };
		coordinatesType dot3 = { stof(stringsComand[5]), stof(stringsComand[6]) };
		figures.push_back(std::make_shared<CTriangle>(dot1, dot2, dot3, stringsComand[4], stringsComand[5]));
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create triangle");
	}
}