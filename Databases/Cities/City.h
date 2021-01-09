//
// Created by danit on 12/29/2020.
//

#ifndef FINALPROJECTPOO_CITY_H
#define FINALPROJECTPOO_CITY_H

#include "iostream"

using namespace std;

class City {
private:
    string name;
    float distance;
public:
    City(const string &name, float distance);

    const string &getName() const;

    void setName(const string &name);

    float getDistance() const;

    void setDistance(float distance);
};


#endif //FINALPROJECTPOO_CITY_H
