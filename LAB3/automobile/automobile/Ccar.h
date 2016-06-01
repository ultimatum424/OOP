#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class CCar
{
public:
	CCar();
	~CCar();

	bool TurnOnEngine();

	bool TurnOffEngine();

	bool SetGear(int inputGear);

	bool SetSpeed(int inputSpeed);

	void OutInfo() const;

private:
	bool IsBetween(int x, int min, int max) const;
	bool CanChangeGear(int inputGear) const;
	void ChangeDirectionMovement();
	
	map <int, std::pair<int, int>> m_gearSpeedRangesMap;
	bool m_statusMotor;
	int m_directionMovement;
	int m_speed;
	int m_gear;
};

