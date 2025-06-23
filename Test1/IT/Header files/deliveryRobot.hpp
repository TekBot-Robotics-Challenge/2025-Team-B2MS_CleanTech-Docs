#ifndef DELIVERYROBOT_HPP
#define DELIVERYROBOT_HPP

#include "robot.hpp"

enum zone
{
    keepYourPlace,
    zone1,
    zone2
};

class deliveryRobot : public robot
{
private:
    unsigned short entities;
    zone Zone;

public:
    deliveryRobot(zone ZONE, unsigned short nbrOfEntities, unsigned int Id, float x, float y);
    deliveryRobot();
    deliveryRobot(const deliveryRobot &rhs);
    deliveryRobot &operator=(const deliveryRobot &rhs);
    ~deliveryRobot();

    void move() override;
    std::string getNameOfRobot() override;

    unsigned short getNbrOfEntities();
    void setNbrOfEntities(unsigned short nbrOfEntities);
    zone getZone();
    void setZone(zone ZONE);
};

#endif
