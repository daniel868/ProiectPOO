//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_GIFTSTOREDATA_H
#define FINALPROJECTPOO_GIFTSTOREDATA_H

#include "iostream"
#include "vector"
#include "../DataClassesPackage/Gift.h"

using namespace std;

//TODO: handle all gifts and real time gift stock
//TODO: use for choosing childrenGift

class GiftStoreData {
public:
    static vector<Gift> getStoreList();

    static vector<pair<Gift, bool>> getStock();

    static bool randomBool();

    static bool checkGiftStock(Gift gift);
};


#endif //FINALPROJECTPOO_GIFTSTOREDATA_H
