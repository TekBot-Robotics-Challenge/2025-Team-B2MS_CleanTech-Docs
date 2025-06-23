#include "deliveryRobot.hpp"

deliveryRobot::deliveryRobot(zone ZONE, unsigned short nbrOfEntities, unsigned int Id, float x, float y)
    : robot(Id, x, y), entities(nbrOfEntities), Zone(ZONE) {}

deliveryRobot::deliveryRobot() : robot(), entities(0), Zone(keepYourPlace) {}

deliveryRobot::deliveryRobot(const deliveryRobot &rhs) : robot(rhs)
{
    if (this != &rhs)
    {
        entities = rhs.entities;
        Zone = rhs.Zone;
    }
}

deliveryRobot &deliveryRobot::operator=(const deliveryRobot &rhs)
{
    if (this != &rhs)
    {
        robot::operator=(rhs);
        entities = rhs.entities;
        Zone = rhs.Zone;
    }
    return *this;
}

deliveryRobot::~deliveryRobot() {}

void deliveryRobot::move()
{
    switch (Zone)
    {
    case keepYourPlace:
        break;
    case zone1:
        position.x = 10;
        position.y = 20;
        if (entities > 0)
            entities--;
        break;
    case zone2:
        position.x = 0;
        position.y = 30;
        if (entities > 0)
            entities--;
        break;
    default:
        Zone = keepYourPlace;
        break;
    }
}

std::string deliveryRobot::getNameOfRobot()
{
    return "Delivery Robot";
}

unsigned short deliveryRobot::getNbrOfEntities()
{
    return entities;
}

void deliveryRobot::setNbrOfEntities(unsigned short nbrOfEntities)
{
    entities = nbrOfEntities;
}

zone deliveryRobot::getZone()
{
    return Zone;
}

void deliveryRobot::setZone(zone ZONE)
{
    Zone = ZONE;
}
