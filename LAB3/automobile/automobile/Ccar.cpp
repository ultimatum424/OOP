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
		cout << "Двигатель автомобиля уже включен" << endl;
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
			cout << "Двигатель уже выключен" << endl;
		else if (gear != 0)
			cout << "Коробка передач не в нейтрали. Переключите коробку в нейтральное положение" << endl;
		else if (speed)
			cout << "Машина движется. Для начала остановите машину" << endl;
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
					cout << "С " << Ccar::gear << "передачи невозможно перейти на заднюю." << endl;
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
					cout << "Невозможно переключить, остановите машину для начала" << endl;
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
					cout << " Остановитесь для переключения передачи " << endl;
				else if (!(PossibilityOfChangeGear(inputGear)))
					cout << " Невозможно переключение на данной скорости " << endl;
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
				cout << " Невозможно переключение на данной скорости " << endl;
				isChangeGear = false;
			}
			break;
		}
		}
	}
	else
		cout << "Выбранной передачи не существует" << endl;
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
			cout << "выбранная скорость не соответствует выставленной передачи. Смените передачу" << endl;
	}
	else
	{
		if ((gear == 0) && (statusMotor) && (inputSpeed <= Ccar::speed))
		{
			isChangeSpeed = true;
			Ccar::speed = inputSpeed;
		}
		else
			cout << "Увеличить скорость при включенной нейтрали невозможно" << endl;
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
	cout << "Статус автомобиля: " << endl;
	if (statusMotor)
		cout << "Двигатель включен" << endl;
	else
		cout << "Двигатель выключен" << endl;
	cout << "Выбрана " << gear << " передача" << endl;
	if (directionMovement == 0)
		cout << "Машина стоит на месте" << endl;
	else
	{
		if (directionMovement == 1)
			cout << "Машина движется вперёд" << endl;
		else if (directionMovement == -1)
			cout << "Машина движется задним ходом" << endl;

		cout << "Машина движется со скоростью " << speed << " км/ч" << endl;
	}
	

}
