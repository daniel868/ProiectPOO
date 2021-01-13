//
// Created by danit on 12/29/2020.
//

#include "CitiesData.h"

vector<City> CitiesData::FinlandToStartCities() {
    vector<City> cities;
    cities.emplace_back(City("Gaborone,Botswana", 10136.37));
    cities.emplace_back(City("Francistown,Botswana", 9748.89));
    cities.emplace_back(City("Molepolole,Botswana", 10108.29));
    cities.emplace_back(City("Mahalapye,Botswana", 9964.13));
    cities.emplace_back(City("Maun,Botswana", 0));
    return cities;

}

void CitiesData::printCountryList() {
    std::cout << "1. Botswana:\n";
}

void CitiesData::printBotswanaCities() {
    vector<City> cities;
    cities.emplace_back(City("Gaborone", 10136.37));
    cities.emplace_back(City("Francistown ", 9748.89));
    cities.emplace_back(City("Molepolole", 10108.29));
    cities.emplace_back(City("Mahalapye", 9964.13));
    cities.emplace_back(City("Maun,Botswana", 0));

    for (int i = 0; i < cities.size(); i++) {
        std::cout << i + 1 << "\t" << cities[i].getName() << "\n";
    }
}



