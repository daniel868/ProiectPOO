//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_GIFTSTOREDATA_H
#define FINALPROJECTPOO_GIFTSTOREDATA_H

#include "iostream"
#include "vector"
#include "../DataClassesPackage/Gift.h"

using namespace std;


class GiftStoreData {
public:
    static vector<Gift> getStoreList();

    static vector<pair<Gift, bool>> getStock();

    static bool randomBool();

    static bool checkGiftStock(Gift gift);
};


#endif //FINALPROJECTPOO_GIFTSTOREDATA_H
