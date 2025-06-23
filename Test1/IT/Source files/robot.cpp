#include "robot.hpp"

robot::robot() : ID(0), position(0, 0), status(OFF) {}

robot::robot(unsigned int Id, float x, float y) : ID(Id), position(x, y), status(ON) {}

robot::robot(const robot &rhs)
    : ID(rhs.ID), position(rhs.position), status(rhs.status) {}

robot &robot::operator=(const robot &rhs)
{
    if (this != &rhs)
    {
        ID = rhs.ID;
        position = rhs.position;
        status = rhs.status;
    }
    return *this;
}

robot::~robot() {}

float robot::distanceFromOrigin()
{
    return std::sqrt(position.x * position.x + position.y * position.y);
}

vect2D robot::getPosition() const
{
    return position;
}

void robot::setPosition(const vect2D &currentPosition)
{
    position = currentPosition;
}

unsigned int robot::getID() const
{
    return ID;
}

void robot::setID(int Id)
{
    ID = Id;
}

state robot::getStatus() const
{
    return status;
}

void robot::setStatus(const state &OnOrOff)
{
    status = OnOrOff;
}

void printNameOfRobot(robot *p)
{
    std::cout << p->getNameOfRobot() << std::endl;
}

void moveRobot(robot *p)
{
    p->move();
}
