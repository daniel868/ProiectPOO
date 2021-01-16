//
// Created by danit on 12/29/2020.
//

#ifndef FINALPROJECTPOO_CITIESDATA_H
#define FINALPROJECTPOO_CITIESDATA_H

#include "iostream"
#include "vector"
#include "City.h"

using namespace std;

//TODO: static class for printing cities
//TODO: returns Botswana's cities

class CitiesData {
public:
    static vector<City> FinlandToStartCities();

    static void printCountryList();

    static void printBotswanaCities();

};


#endif //FINALPROJECTPOO_CITIESDATA_H
