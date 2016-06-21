#include "stdafx.h"
#include "ShapesUtility.h"
#include <boost\algorithm\string.hpp>


void CreatDot(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand) {
	if (stringsComand.size() != 4)
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

void CreatLineSegment(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 6)
	{
		throw std::exception("Err: Invalid parameters count ");
	}
	try
	{
		coordinatesType firstDot = { stof(stringsComand[1]), stof(stringsComand[2]) };
		coordinatesType secondDot = { stof(stringsComand[3]), stof(stringsComand[4]) };
		figures.push_back(std::make_shared<CLineSegment>(firstDot, secondDot, stringsComand[5]));
	}
	catch (const std::exception&)
	{
		throw std::exception("Err: Invalid parameters to create line");
	}
}

void CreateCircle(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 6)
	{
		throw std::exception("Err: Invalid parameters count ");
	}
	try
	{
		double radius = stof(stringsComand[3]);
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

void CreateRectangle(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 7)
	{
		throw std::exception("Err: Invalid parameters count ");

	}
	try
	{
		double width = stof(stringsComand[3]);
		double height = stof(stringsComand[4]);
		if (width <= 0 || height <= 0)
		{
			throw std::exception("");
		}
		coordinatesType coordinates = { stof(stringsComand[1]), stof(stringsComand[2]) };
		figures.push_back(std::make_shared<CRectangle>(coordinates, width, height, stringsComand[5], stringsComand[6]));
	}
	catch (const std::exception&)
	{
		throw std::exception("Err: Invalid parameters to create rectangle");
	}
}

void CreateTriangle(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand)
{
	if (stringsComand.size() != 9)
	{
	}
	try
	{
		coordinatesType dot1 = { stof(stringsComand[1]), stof(stringsComand[2]) };
		coordinatesType dot2 = { stof(stringsComand[3]), stof(stringsComand[4]) };
		coordinatesType dot3 = { stof(stringsComand[5]), stof(stringsComand[6]) };
		figures.push_back(std::make_shared<CTriangle>(dot1, dot2, dot3, stringsComand[7], stringsComand[8]));
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create triangle");
	}
}

std::vector<std::vector<std::string>> GetInputData()
{
	std::vector<std::vector<std::string>> lines;
	std::string line;
	while (std::getline(std::cin, line))
	{
		if (line.empty())
		{
			return lines;
		}
		std::vector<std::string> currentString;
		boost::split(currentString, line, std::bind2nd(std::equal_to<char>(), ' '));
		lines.push_back(currentString);
	}
	return lines;
}

void ParseCommands(std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::vector<std::string>> stringsComand)
{
	for (const auto& command : stringsComand)
	{
		try
		{
			std::cout << "> Parsing:" << std::endl;
			std::copy(command.begin(), command.end(), std::ostream_iterator<std::string>(std::cout, " "));
			std::cout << std::endl;
			if (command[0] == "rectangle")
			{
				CreateRectangle(figures, command);
			}
			else if (command[0] == "circle")
			{
				CreateCircle(figures, command);
			}
			else if (command[0] == "line")
			{
				CreatLineSegment(figures, command);
			}
			else if (command[0] == "triangle")
			{
				CreateTriangle(figures, command);
			}
			else if (command[0] == "point")
			{
				CreatDot(figures, command);
			}
			else
			{
				throw std::exception("\tError: Invalid command");
			}
		}
		catch (const std::exception& error)
		{
			std::cout << error.what() << std::endl;
		}
	}
}

void OutputInfo(std::vector<std::shared_ptr<CShape>>& figures)
{
	if (figures.size() == 0)
	{
		std::cout << "Nothing to output" << std::endl;
		return;
	}
	std::vector<std::shared_ptr<CShape>> figuresCopy = figures;

	std::sort(figuresCopy.begin(), figuresCopy.end(), [](std::shared_ptr<CShape>& shape1, std::shared_ptr<CShape>& shape2) {return shape1->GetPerimeter() < shape2->GetPerimeter(); });
	std::cout << ">Sorted by perimeter" << std::endl;
	for (const auto& figure : figuresCopy)
	{
		std::cout << figure->ToString() << std::endl;
	}

	std::cout << std::endl;

	std::sort(figuresCopy.begin(), figuresCopy.end(), [](std::shared_ptr<CShape>& shape1, std::shared_ptr<CShape>& shape2) {return shape1->GetArea() < shape2->GetArea(); });
	std::cout << ">Sorted by area" << std::endl;
	for (const auto& figure : figuresCopy)
	{
		std::cout << figure->ToString() << std::endl;
	}
}