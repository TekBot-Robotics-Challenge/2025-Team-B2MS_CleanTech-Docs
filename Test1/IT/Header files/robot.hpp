#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <cmath>
#include <string>

enum state
{
    OFF,
    ON
};

struct vect2D
{
    float x;
    float y;
    vect2D(float x = 0, float y = 0) : x(x), y(y) {}
};

class robot
{
protected:
    unsigned int ID;
    vect2D position;
    state status;

public:
    robot();
    robot(unsigned int Id, float x, float y);
    robot(const robot &rhs);
    robot &operator=(const robot &rhs);
    virtual ~robot();

    float distanceFromOrigin();

    vect2D getPosition() const;
    void setPosition(const vect2D &currentPosition);

    unsigned int getID() const;
    void setID(int Id);

    state getStatus() const;
    void setStatus(const state &OnOrOff);

    virtual void move() = 0;
    virtual std::string getNameOfRobot() = 0;
};

void printNameOfRobot(robot *p);
void moveRobot(robot *p);

#endif // ROBOT_HPP
