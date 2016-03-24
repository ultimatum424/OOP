#include "stdafx.h"
#include "Lab2-1.h"

vector<double> ReadVector()
{
	cout << "Input nubers or other symbol to stop the input" << endl;
	vector<double> readVec((istream_iterator<double>(cin)), istream_iterator<double>());
	return readVec;
}

vector<double> DivisinMassOnMàxElement(const vector<double>& mainVector)
{
	vector <double> dividedVector = mainVector;
	double maxNumber = *max_element(mainVector.begin(), mainVector.end());
	if (maxNumber == 0)
		return dividedVector;
	else
	{
		maxNumber = maxNumber / 2;

		for (auto& vectorI : dividedVector)
		{
			vectorI = vectorI / maxNumber;
		}
		return dividedVector;
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


