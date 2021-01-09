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
    std::cout << "2. Germany:\n";
    std::cout << "3. Italy:\n";
    std::cout << "4. Romania:\n";
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

vector<string> CitiesData::Cities() {
    vector<string> cities;
    cities.emplace_back("Botswana");
    cities.emplace_back("Germany");
    cities.emplace_back("Italy");
    cities.emplace_back("Romania");
    return cities;
}

float CitiesData::getDistanceBetweenCities(string x, string y) {
    float distance = 0.0;
    if ((x == "Molepolole,Botswana" && y == "Gaborone,Botswana") ||
        (y == "Molepolole,Botswana" && x == "Gaborone,Botswana")) {
        distance = 49.41;
    }
    if ((x == "Molepolole,Botswana" && y == "Francistown,Botswana") ||
        (y == "Molepolole,Botswana" && x == "Francistown,Botswana")) {
        distance = 414.76;
    }
    if ((x == "Molepolole,Botswana" && y == "Mahalapye,Botswana") ||
        (y == "Molepolole,Botswana" && x == "Mahalapye,Botswana")) {
        distance = 197.23;
    }

    if ((x == "Gaborone,Botswana" && y == "Mahalapye,Botswana") ||
        (y == "Gaborone,Botswana" && x == "Mahalapye,Botswana")) {
        distance = 196.18;
    }

    if ((x == "Gaborone,Botswana" && y == "Francistown,Botswana") ||
        (y == "Gaborone,Botswana" && x == "Francistown,Botswana")) {
        distance = 421.68;
    }
    if ((x == "Mahalapye,Botswana" && y == "Francistown,Botswana") ||
        (y == "Mahalapye,Botswana" && x == "Francistown,Botswana")) {
        distance = 227.10;
    }

    return distance;
}



