// Shapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "IShape.h"
#include "Shape.h"
#include "ShapesUtility.h"

int main()
{
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::vector<std::string>> inputData = GetInputData();

	ParseCommands(figures, inputData);
	OutputInfo(figures);
    return 0;
}

