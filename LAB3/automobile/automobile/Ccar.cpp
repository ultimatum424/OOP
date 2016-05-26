#include "stdafx.h"
#include "Ccar.h"



CCar::CCar()
	:m_gear(0)
	, m_speed(0)
	, m_statusMotor(false)
	, m_directionMovement(0)
	, m_gearSpeedRangesMap({ { -1,{ 0, 20 } },{ 0,{ 0, INT_MAX } },
	{ 1,{ 0, 30 } },{ 2,{ 20, 50 } },{ 3,{ 30, 60 } },
	{ 4,{ 40, 90 } },{ 5,{ 50, 150 } } })
{
}

CCar::~CCar()
{
}

bool CCar::TurnOnEngine()
{
	if ((!CCar::m_statusMotor) && (m_gear == 0))
	{
		CCar::m_statusMotor = true;
		return true;
	}
	else
	{
		cout << "Двигатель автомобиля уже включен" << endl;
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if ((CCar::m_statusMotor) && (CCar::m_gear == 0) && (CCar::m_speed == 0))
	{
		CCar::m_statusMotor = false;
		return true;
	}
	else
	{
		if (!m_statusMotor)
			cout << "Двигатель уже выключен" << endl;
		else if (m_gear != 0)
			cout << "Коробка передач не в нейтрали. Переключите коробку в нейтральное положение" << endl;
		else if (m_speed)
			cout << "Машина движется. Для начала остановите машину" << endl;
		return false;
	}
}

bool CCar::IsBetween(int x, int min, int max) const
{
	return ((x >= min) && (x <= max));
}
bool CCar::CanChangeGear(int inputGear) const
{
	
	return (m_directionMovement != -1) &&
		IsBetween(m_speed, m_gearSpeedRangesMap.at(inputGear)[0], m_gearSpeedRangesMap.at(inputGear)[1]);
}

bool CCar::SetGear(int inputGear)
{
	bool isChangeGear = false;
	// TODO: decrease nesting level.
	if ((inputGear >= -1 && inputGear <= 5))
	{
		if ((m_statusMotor) || (inputGear == 0))
		{
			switch (inputGear)
			{
			case -1:
			{
				if (m_speed == 0)
				{
					if ((CCar::m_gear == 0) || (CCar::m_gear == 1))
					{
						CCar::m_gear = inputGear;
						isChangeGear = true;
					}
					else
						cout << "С " << CCar::m_gear << "передачи невозможно перейти на заднюю." << endl;
				}
				else
				{
					if (inputGear == CCar::m_gear)
					{
						isChangeGear = true;
						CCar::m_gear = inputGear;
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
				CCar::m_gear = inputGear;
				break;
			}
			case 1:
			{
				if ((CCar::m_gear == -1) && (m_speed == 0))
				{
					isChangeGear = true;
					CCar::m_gear = inputGear;
				}
				else if ((CCar::m_gear == 0) && (m_directionMovement != -1))
				{
					isChangeGear = true;
					CCar::m_gear = inputGear;
				}
				else if (CanChangeGear(inputGear) == 1)
				{
					isChangeGear = true;
					CCar::m_gear = inputGear;
				}
				else
				{
					if (CCar::m_gear == -1)
						cout << " Остановитесь для переключения передачи " << endl;
					else if (!(CanChangeGear(inputGear)))
						cout << " Невозможно переключение на данной скорости " << endl;
				}
				break;
			}
			default:
			{
				if (CanChangeGear(inputGear))
				{
					CCar::m_gear = inputGear;
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
		{
			cout << "Включите двигатель" << endl;
		}
	}
	else
	{
		cout << "Выбранной передачи не существует" << endl;
	}
	CCar::ChangeDirectionMovement();

	return isChangeGear;
}

bool CCar::SetSpeed(int inputSpeed)
{
	bool didChangeSpeed = false;
	if ((m_gear != 0) && (m_statusMotor))
	{
		// TODO: make function IsBetween(x, min, max) +
		if (IsBetween(inputSpeed, m_gearSpeedRangesMap[m_gear][0], m_gearSpeedRangesMap[m_gear][1]))
		{
			didChangeSpeed = true;
			CCar::m_speed = inputSpeed;
		}
		else // TODO: add {} +
		{
			cout << "выбранная скорость не соответствует выставленной передачи. Смените передачу" << endl;
		}
	}
	else
	{
		// TODO: check that inputSpeed isn't negative  +
		if ((m_gear == 0) && (m_statusMotor) && (inputSpeed <= m_speed) && (inputSpeed >= 0))
		{
			didChangeSpeed = true;
			m_speed = inputSpeed;
		}
		else // TODO: add {} +
		{
			cout << "Увеличить скорость при включенной нейтрали невозможно" << endl;
		}
	}
	ChangeDirectionMovement();
	return didChangeSpeed;
}

void CCar::ChangeDirectionMovement()
{
	if (m_speed == 0)
	{
		m_directionMovement = 0;
	}
	else if ((m_directionMovement == 1) && (m_gear > 0))
	{
		m_directionMovement = 1;
	}
	else if ((m_directionMovement == -1) && (m_gear == -1))
	{
		m_directionMovement = -1;
	}
	else if (m_directionMovement == 0)
	{
		// TODO: use "x?a:b"
		if (m_gear == -1)
		{
			m_directionMovement = -1;
		}
		else
		{
			m_directionMovement = 1;
		}
	}
}

void CCar::OutInfo() const
{
	cout << "Статус автомобиля: " << endl;
	if (m_statusMotor)
	{
		cout << "Двигатель включен" << endl;
	}
	else
	{
		cout << "Двигатель выключен" << endl;
	}
	cout << "Выбрана " << m_gear << " передача" << endl;
	if (m_directionMovement == 0)
	{
		cout << "Машина стоит на месте" << endl;
	}
	else
	{
		// TODO: add {}1 +
		if (m_directionMovement == 1)
		{
			cout << "Машина движется вперёд" << endl;
		}
		else if (m_directionMovement == -1)
		{
			cout << "Машина движется задним ходом" << endl;
		}
		cout << "Машина движется со скоростью " << m_speed << " км/ч" << endl;
	}
	

}
