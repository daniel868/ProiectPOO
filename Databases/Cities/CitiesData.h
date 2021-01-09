//
// Created by danit on 12/29/2020.
//

#ifndef FINALPROJECTPOO_CITIESDATA_H
#define FINALPROJECTPOO_CITIESDATA_H

#include "iostream"
#include "vector"
#include "City.h"

using namespace std;


class CitiesData {
public:
    static vector<City> FinlandToStartCities();

    static vector<string>Cities();

    static void printCountryList();

    static void printBotswanaCities();

    static float getDistanceBetweenCities(string x, string y);

};


#endif //FINALPROJECTPOO_CITIESDATA_H
