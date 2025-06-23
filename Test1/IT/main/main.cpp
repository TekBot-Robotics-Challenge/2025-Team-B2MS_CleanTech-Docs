#include "travellingRobot.hpp"
#include "deliveryRobot.hpp"
#include "armRobot.hpp"
#include <iostream>

std::string rotateToString(rotate r)
{
    switch (r)
    {
    case anticlockwise:
        return "Anticlockwise";
    case Clockwise:
        return "Clockwise";
    default:
        return "Unknown";
    }
}

int main()
{
    // ------------------Travelling Robot----------------------
    travellingRobot a(Forward, 111, 0, 0);
    printNameOfRobot(&a);
    moveRobot(&a);
    vect2D v = a.getPosition();
    std::cout << "\n"
              << v.x << " " << v.y << std::endl;
    std::cout << a.getID() << std::endl;
    std::cout << a.getDirection() << std::endl;

    // ------------------Delivery Robot-----------------------
    deliveryRobot b(zone1, 10, 222, 0, 0);
    printNameOfRobot(&b);
    moveRobot(&b);
    v = b.getPosition();
    std::cout << "\n"
              << v.x << " " << v.y << std::endl;
    std::cout << b.getID() << std::endl;
    std::cout << b.getNbrOfEntities() << std::endl;
    std::cout << b.getZone() << std::endl;

    // ------------------ARM Robot---------------------------
    armRobot c(anticlockwise, 0, 333, 0, 0);
    printNameOfRobot(&c);
    moveRobot(&c);
    v = c.getPosition();
    std::cout << "\n"
              << v.x << " " << v.y << std::endl;
    std::cout << c.getID() << std::endl;
    std::cout << c.getAngle() << std::endl;
    std::cout << rotateToString(c.getRotationalDirection()) << std::endl;

    return 0;
}
