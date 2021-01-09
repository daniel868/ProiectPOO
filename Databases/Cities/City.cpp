//
// Created by danit on 12/29/2020.
//

#include "City.h"

City::City(const string &name, float distance) : name(name), distance(distance) {

}

const string &City::getName() const {
    return name;
}

void City::setName(const string &name) {
    City::name = name;
}

float City::getDistance() const {
    return distance;
}

void City::setDistance(float distance) {
    City::distance = distance;
}
