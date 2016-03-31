#include "stdafx.h"
#include "Ccar.h"



Ccar::Ccar()
	:gear(0)
	, speed(0)
	, statusMotor(false)
	, directionMovement(0)
	, mapSpeed({ { -1,{ 0, 20 } },{ 0,{ 0, INT_MAX } },
	{ 1,{ 0, 30 } },{ 2,{ 20, 50 } },{ 3,{ 30, 60 } },
	{ 4,{ 40, 90 } },{ 5,{ 50, 150 } } })
{
}
/*
Ccar::~Ccar()
{
}
*/
bool Ccar::TurnOnEngine()
{
	if (!Ccar::statusMotor)
	{
		Ccar::statusMotor = true;
		return true;
	}
	else
	{
		cout << "��������� ���������� ��� �������" << endl;
		return false;
	}
}

bool Ccar::TurnOffEngine()
{
	if ((Ccar::statusMotor) && (Ccar::gear == 0) && (Ccar::speed == 0))
	{
		Ccar::statusMotor = false;
		return true;
	}
	else
	{
		if (!statusMotor)
			cout << "��������� ��� ��������" << endl;
		else if (gear != 0)
			cout << "������� ������� �� � ��������. ����������� ������� � ����������� ���������" << endl;
		else if (speed)
			cout << "������ ��������. ��� ������ ���������� ������" << endl;
		return false;
	}
}

bool Ccar::PossibilityOfChangeGear(int inputGear)
{
	if ((Ccar::directionMovement != -1) && ((speed >= mapSpeed[inputGear][0]) && (speed <= mapSpeed[inputGear][1])))
		return true;
	else
		return false;

}

bool Ccar::SetGear(int inputGear)
{
	bool isChangeGear = false;
	if ((inputGear >= -1) && (inputGear <= 5))
	{
		switch (inputGear)
		{
		case -1:
		{
			if (speed == 0)
			{
				if ((Ccar::gear == 0) || (Ccar::gear == 1))
				{
					Ccar::gear = inputGear;
					isChangeGear = true;
				}	
				else
					cout << "� " << Ccar::gear << "�������� ���������� ������� �� ������." << endl;
			}
			else
			{
				if (inputGear == Ccar::gear)
				{
					isChangeGear = true;
					Ccar::gear = inputGear;
				}
				else
				{
					isChangeGear = false;
					cout << "���������� �����������, ���������� ������ ��� ������" << endl;
				}
			}
			break;
		}
		case 0:
		{
			isChangeGear = true;
			Ccar::gear = inputGear;
			break;
		}
		case 1:
		{
			if ((Ccar::gear == -1) && (speed == 0))
			{
				isChangeGear = true;
				Ccar::gear = inputGear;
			}
			else if ((Ccar::gear == 0) && (directionMovement != -1))
			{
				isChangeGear = true;
				Ccar::gear = inputGear;
			}
			else if (PossibilityOfChangeGear(inputGear) == 1)
			{
				isChangeGear = true;
				Ccar::gear = inputGear;
			}
			else
			{
				if (Ccar::gear == -1)
					cout << " ������������ ��� ������������ �������� " << endl;
				else if (!(PossibilityOfChangeGear(inputGear)))
					cout << " ���������� ������������ �� ������ �������� " << endl;
			}
			break;
		}
		default:
		{
			if (PossibilityOfChangeGear(inputGear))
			{
				Ccar::gear = inputGear;
				isChangeGear = true;
			}
			else
			{
				cout << " ���������� ������������ �� ������ �������� " << endl;
				isChangeGear = false;
			}
			break;
		}
		}
	}
	else
		cout << "��������� �������� �� ����������" << endl;
	Ccar::ChangeDirectionMovement();
	return isChangeGear;
}

bool Ccar::SetSpeed(int inputSpeed)
{
	bool isChangeSpeed = false;
	if ((gear != 0) && (statusMotor))
	{
		if ((inputSpeed >= mapSpeed[gear][0]) && (inputSpeed <= mapSpeed[gear][1]))
		{
			isChangeSpeed = true;
			Ccar::speed = inputSpeed;
		}
		else
			cout << "��������� �������� �� ������������� ������������ ��������. ������� ��������" << endl;
	}
	else
	{
		if ((gear == 0) && (statusMotor) && (inputSpeed <= Ccar::speed))
		{
			isChangeSpeed = true;
			Ccar::speed = inputSpeed;
		}
		else
			cout << "��������� �������� ��� ���������� �������� ����������" << endl;
	}
	Ccar::ChangeDirectionMovement();
	return isChangeSpeed;
}

void Ccar::ChangeDirectionMovement()
{
	if (speed == 0)
		directionMovement = 0;
	else
	{
		if (gear >= 0)
			directionMovement = 1;
		else if (gear == -1)
			directionMovement = -1;
	}
}

void Ccar::OutInfo()
{
	cout << "������ ����������: " << endl;
	if (statusMotor)
		cout << "��������� �������" << endl;
	else
		cout << "��������� ��������" << endl;
	cout << "������� " << gear << " ��������" << endl;
	if (directionMovement == 0)
		cout << "������ ����� �� �����" << endl;
	else
	{
		if (directionMovement == 1)
			cout << "������ �������� �����" << endl;
		else if (directionMovement == -1)
			cout << "������ �������� ������ �����" << endl;

		cout << "������ �������� �� ��������� " << speed << " ��/�" << endl;
	}
	

}
