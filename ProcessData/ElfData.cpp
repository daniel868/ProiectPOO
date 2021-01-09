//
// Created by danit on 12/29/2020.
//

#include "ElfData.h"
#include "../Utils/Util.h"

const vector<Wishlist> &ElfData::getFinalChildrenWishList() const {
    return finalChildrenWishList;
}

void ElfData::setFinalChildrenWishList(const vector<Wishlist> &finalChildrenWishList) {
    ElfData::finalChildrenWishList = finalChildrenWishList;
}

const vector<pair<string, int>> &ElfData::getFinalChildrenCandyNumber() const {
    return finalChildrenCandyNumber;
}

void ElfData::setFinalChildrenCandyNumber(const vector<pair<string, int>> &finalChildrenCandyNumber) {
    ElfData::finalChildrenCandyNumber = finalChildrenCandyNumber;
}

bool ElfData::checkBad_GoodChild(Letter letter) {
    bool isGood;
    bool search = false;

    ifstream MyChildDB_in;
    MyChildDB_in.open(ChildrenDatabaseName, ios::in);
    string line;
    while (getline(MyChildDB_in, line) && !search) {
        vector<string> outString;
        Util::tokenize(line, ' ', outString);
        if (outString[1] == letter.getName() && outString[2] == letter.getSurname()) {
            if (stoi(outString[5], nullptr, 10) == 1) {
                isGood = true;
                search = true;
            } else if (stoi(outString[5], nullptr, 10) == 0) {
                isGood = false;
                search = true;
            }
        }
    }
    MyChildDB_in.close();
    return isGood;
}

const int &ElfData::getFinalGirlPacks() const {
    return finalGirlPacks;
}

const int &ElfData::getFinalBoyPacks() const {
    return finalBoyPacks;
}
