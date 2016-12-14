#pragma once
#include "Shape.h"
#include "IShape.h"



void CreatDot(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand);

void CreatLineSegment(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand);

void CreateCircle(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand);

void CreateRectangle(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand);

void CreateTriangle(std::vector<std::shared_ptr<CShape>>& figures, const std::vector<std::string>& stringsComand);

std::vector<std::vector<std::string>> GetInputData();

void ParseCommands(std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::vector<std::string>> stringsComand);

void OutputInfo(std::vector<std::shared_ptr<CShape>>& figures);

float CalculationLineLength(const coordinatesType & dot1, const coordinatesType & dot2);

bool IsTriangle(const coordinatesType & dot1, const coordinatesType & dot2, const coordinatesType & dot3);