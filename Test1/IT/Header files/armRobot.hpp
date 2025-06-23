#ifndef ARM_ROBOT_HPP
#define ARM_ROBOT_HPP

#include "robot.hpp"

enum rotate
{
	anticlockwise,
	Clockwise
};

// A robot with one degree of freedom rotating its arm
class armRobot : public robot
{
public:
	armRobot();
	armRobot(rotate rotationalDirection, unsigned short initAngle, unsigned int id, float x, float y);
	armRobot(const armRobot &rhs);
	armRobot &operator=(const armRobot &rhs);
	~armRobot() override;

	void move() override;
	std::string getNameOfRobot() override;

	unsigned short getAngle() const;
	void setAngle(unsigned short angle);

	rotate getRotationalDirection() const;
	void setRotationalDirection(rotate rotationalDirection);

private:
	unsigned short angle;
	rotate rotationalDirection;
};

#endif // ARM_ROBOT_HPP
