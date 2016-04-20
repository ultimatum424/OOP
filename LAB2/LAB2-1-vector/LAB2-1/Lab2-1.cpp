#include "stdafx.h"
#include "Lab2-1.h"

vector<double> ReadVector()
{
	cout << "Input numbers or other symbol to stop the input" << endl;
	vector<double> readVec((istream_iterator<double>(cin)), istream_iterator<double>());
	return readVec;
}

vector<double> DivisinonArrayOnMàxElement(vector<double>& mainVector)
{
	if (!mainVector.size())
		return mainVector;
	double maxNumber = *max_element(mainVector.begin(), mainVector.end());
	if (maxNumber == 0)
		return mainVector;
	else
	{
		maxNumber = maxNumber / 2;

		for (auto& i : mainVector)
		{
			i = i / maxNumber;
		}
		return mainVector;
	}
}
void SortVector(vector <double>& sortVector)
{
	sort(sortVector.begin(), sortVector.end());
}
void OutVector(const vector<double> outVector)
{
	copy(outVector.begin(), outVector.end(), ostream_iterator<double>(cout << fixed << setprecision(3), " "));
	cout << endl;
}


