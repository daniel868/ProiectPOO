//
// Created by danit on 12/29/2020.
//

#ifndef FINALPROJECTPOO_ELFDATA_H
#define FINALPROJECTPOO_ELFDATA_H

#include "iostream"
#include "vector"
#include "fstream"
#include "../DataClassesPackage/Wishlist.h"
#include "../DataClassesPackage/Letter.h"
#include "map"

using namespace std;

//TODO: class that contains all final's data
//TODO: number of candies for every child, final gift list and so on

class ElfData {
public:
    vector<Wishlist> finalChildrenWishList;
    vector<pair<string, int>> finalChildrenCandyNumber;
    vector<pair<string, string>> finalCityList;
    map<string, pair<float, int>> finalCoast;


    int finalGirlPacks = 0;
    int finalBoyPacks = 0;


    const vector<Wishlist> &getFinalChildrenWishList() const;

    void setFinalChildrenWishList(const vector<Wishlist> &finalChildrenWishList);

    const vector<pair<string, int>> &getFinalChildrenCandyNumber() const;

    void setFinalChildrenCandyNumber(const vector<pair<string, int>> &finalChildrenCandyNumber);

    bool checkBad_GoodChild(Letter letter);

    const int &getFinalGirlPacks() const;

    const int &getFinalBoyPacks() const;

    const map<string, pair<float, int>> &getFinalCoast() const;
};


#endif //FINALPROJECTPOO_ELFDATA_H
