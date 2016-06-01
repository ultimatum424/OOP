#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment(const coordinatesType& coordinates1, const coordinatesType& coordinates2, const std::string& strColor)
	:CShape(strColor),
	m_start(coordinates1, strColor),
	m_end(coordinates2, strColor)
{
}


float CLineSegment::GetArea() const
{
	return 0;
}

float CLineSegment::GetPerimeter() const
{
	return sqrtf(pow(m_start.GetCoordinates.first - m_end.GetCoordinates.first, 2) + 
		(m_start.GetCoordinates.second - m_end.GetCoordinates.second, 2));
}

std::string CLineSegment::ToString() const
{
}
