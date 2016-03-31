#pragma once
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Ccar
{
public:
	Ccar();

	bool TurnOnEngine();

	bool TurnOffEngine();

	bool PossibilityOfChangeGear(int gear);

	bool SetGear(int gear);

	bool SetSpeed(int speed);

	void ChangeDirectionMovement();

	void OutInfo();

	//~Ccar();

private:
	map <int, vector<int>> mapSpeed;
		//= { {-1, {0, 20}}, { 0,{ 0, INT_MAX } }, 
		//{ 1,{ 0, 30 } }, { -2,{ 20, 50 } }, { 3,{ 30, 60 } },
		//{ 4,{ 40, 90 } },{ 5,{ 50, 150 } } };
	bool statusMotor;
	int directionMovement;
	int speed;
	int gear;
};

