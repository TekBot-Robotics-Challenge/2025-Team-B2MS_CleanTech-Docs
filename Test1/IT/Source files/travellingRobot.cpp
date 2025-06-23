#include "travellingRobot.hpp"

travellingRobot::travellingRobot(direction DIRECTION, unsigned int Id, float x, float y)
    : robot(Id, x, y), Direction(DIRECTION) {}

travellingRobot::travellingRobot() : robot(), Direction(Stop) {}

travellingRobot::travellingRobot(const travellingRobot &rhs) : robot(rhs)
{
    if (this != &rhs)
    {
        Direction = rhs.Direction;
    }
}

travellingRobot &travellingRobot::operator=(const travellingRobot &rhs)
{
    if (this != &rhs)
    {
        robot::operator=(rhs);
        Direction = rhs.Direction;
    }
    return *this;
}

travellingRobot::~travellingRobot() {}

void travellingRobot::move()
{
    switch (Direction)
    {
    case Stop:
        break;
    case Forward:
        position.y += 1;
        break;
    case Backward:
        position.y -= 1;
        break;
    case Right:
        position.x += 1;
        break;
    case Left:
        position.x -= 1;
        break;
    default:
        Direction = Stop;
        break;
    }
}

std::string travellingRobot::getNameOfRobot()
{
    return "Travelling Robot";
}

direction travellingRobot::getDirection()
{
    return Direction;
}

void travellingRobot::setDirection(direction DIRECTION)
{
    Direction = DIRECTION;
}
