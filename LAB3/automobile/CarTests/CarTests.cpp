// CarTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../automobile/Ccar.h"

struct CarSetFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarSetFixture)

BOOST_AUTO_TEST_CASE(CarEngineTurnOffWhenEngineOff)
{
	BOOST_CHECK(!car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(SetSpeedWhenEngineOff)
{
	BOOST_CHECK(!car.SetSpeed(10));
}

BOOST_AUTO_TEST_CASE(SetGearWhenEngineOff)
{
	for (size_t i = -1; i <= 5; i++)
	{
		BOOST_CHECK(car.SetGear(i));
	}BOOST_CHECK(car.SetGear(0));
}


BOOST_AUTO_TEST_CASE(CarEngineOn)
{
	BOOST_CHECK(car.TurnOnEngine());
}

struct engineOn : CarSetFixture
{
	engineOn()
	{
		car.TurnOnEngine();
	}
};

BOOST_FIXTURE_TEST_SUITE(EngineTurnedOn, engineOn)

BOOST_AUTO_TEST_CASE(Set1Gear)
{
	BOOST_CHECK(car.SetGear(1));
}

BOOST_AUTO_TEST_CASE(SetIncorrectGear)
{
	BOOST_CHECK(!car.SetGear(-2));
	BOOST_CHECK(!car.SetGear(6));
}

BOOST_AUTO_TEST_CASE(SetIncorrectSpeed)
{
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(!car.SetSpeed(-1));
	BOOST_CHECK(!car.SetSpeed(21));
	BOOST_CHECK(car.SetSpeed(0));

	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(!car.SetSpeed(-10));
	BOOST_CHECK(!car.SetSpeed(31));
	BOOST_CHECK(car.SetSpeed(25));

	BOOST_CHECK(car.SetGear(2));
	BOOST_CHECK(!car.SetSpeed(19));
	BOOST_CHECK(!car.SetSpeed(51));
	BOOST_CHECK(car.SetSpeed(50));

	BOOST_CHECK(car.SetGear(3));
	BOOST_CHECK(!car.SetSpeed(29));
	BOOST_CHECK(!car.SetSpeed(61));
	BOOST_CHECK(car.SetSpeed(60));

	BOOST_CHECK(car.SetGear(4));
	BOOST_CHECK(!car.SetSpeed(39));
	BOOST_CHECK(!car.SetSpeed(91));
	BOOST_CHECK(car.SetSpeed(90));

	BOOST_CHECK(car.SetGear(5));
	BOOST_CHECK(!car.SetSpeed(49));
	BOOST_CHECK(!car.SetSpeed(151));
}

BOOST_AUTO_TEST_CASE(CanNotSetSpeed150On5Gear)
{
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetSpeed(30));

	BOOST_CHECK(car.SetGear(3));
	BOOST_CHECK(car.SetSpeed(30));
	BOOST_CHECK(car.SetSpeed(60));

	BOOST_CHECK(car.SetGear(5));
	BOOST_CHECK(car.SetSpeed(50));
	BOOST_CHECK(car.SetSpeed(150));
}

BOOST_AUTO_TEST_CASE(CanNotSetSpeedMore)
{
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(!car.SetSpeed(50));
}

BOOST_AUTO_TEST_CASE(ChangeSpeedOnNeutralGear)
{
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(30));

	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.SetSpeed(20));
	BOOST_CHECK(!car.SetSpeed(21));
}

BOOST_AUTO_TEST_CASE(SetReverseGear)
{
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(30));

	BOOST_CHECK(!car.SetGear(-1));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.SetSpeed(20));
}

BOOST_AUTO_TEST_CASE(Set1GearWhenMoveBack)
{
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.SetSpeed(20));

	BOOST_CHECK(!car.SetGear(1));
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(!car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.SetGear(1));
}

BOOST_AUTO_TEST_CASE(EngineOff)
{
	BOOST_CHECK(car.SetGear(1));

	BOOST_CHECK(!car.TurnOffEngine());
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.TurnOffEngine());
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()