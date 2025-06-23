#include "armRobot.hpp"

armRobot::armRobot()
	: robot(), angle(0), rotationalDirection(Clockwise) {}

armRobot::armRobot(rotate rotationalDirection, unsigned short initAngle, unsigned int id, float x, float y)
	: robot(id, x, y), angle(initAngle), rotationalDirection(rotationalDirection) {}

armRobot::armRobot(const armRobot &rhs)
	: robot(rhs), angle(rhs.angle), rotationalDirection(rhs.rotationalDirection) {}

armRobot &armRobot::operator=(const armRobot &rhs)
{
	if (this != &rhs)
	{
		robot::operator=(rhs);
		angle = rhs.angle;
		rotationalDirection = rhs.rotationalDirection;
	}
	return *this;
}

armRobot::~armRobot() {}

void armRobot::move()
{
	// Simuler un mouvement de rotation de 10 degrés
	if (rotationalDirection == Clockwise)
		angle = (angle + 10) % 360;
	else
		angle = (angle + 350) % 360; // recule de 10 degrés
}

std::string armRobot::getNameOfRobot()
{
	return "Arm Robot";
}

unsigned short armRobot::getAngle() const
{
	return angle;
}

void armRobot::setAngle(unsigned short angle_)
{
	angle = angle_;
}

rotate armRobot::getRotationalDirection() const
{
	return rotationalDirection;
}

void armRobot::setRotationalDirection(rotate rotationalDirection_)
{
	rotationalDirection = rotationalDirection_;
}
