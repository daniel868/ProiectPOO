//
// Created by danit on 1/1/2021.
//

#ifndef FINALPROJECTPOO_ELFUI_H
#define FINALPROJECTPOO_ELFUI_H

#include "iostream"
#include "vector"

using namespace std;


class ElfUI {
public:
    void insertNewChild();

    void showAllLetters();

    void showFinalResult();


    vector<pair<string, string>> childCities();

    void processCities1();

    void processCities2();
};


#endif //FINALPROJECTPOO_ELFUI_H
