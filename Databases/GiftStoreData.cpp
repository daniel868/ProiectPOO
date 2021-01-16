//
// Created by danit on 12/28/2020.
//

#include <functional>
#include "ctime"
#include "GiftStoreData.h"
#include "random"
#include "iostream"

using namespace std;

//TODO: all possible gift are stored here
vector<Gift> GiftStoreData::getStoreList() {
    vector<Gift> giftList;
    giftList.emplace_back(Gift("Remote_Car_Control", 20.5f));
    giftList.emplace_back(Gift("Simple_Car", 10.5f));
    giftList.emplace_back(Gift("Truck_Car", 20.5f));
    giftList.emplace_back(Gift("Doll", 10));
    giftList.emplace_back(Gift("Lego_Constructor", 30));
    giftList.emplace_back(Gift("Kitchen_set", 30.5f));
    giftList.emplace_back(Gift("Lego_Spider", 30.5f));
    giftList.emplace_back(Gift("Lamborghini_Remote_Car_Control", 50));
    giftList.emplace_back(Gift("Simple_Toy", 5));
    giftList.emplace_back(Gift("Firefight_car", 6));
    giftList.emplace_back(Gift("Simple_Doll", 7));
    giftList.emplace_back(Gift("Race_Car", 15));
    giftList.emplace_back(Gift("Doll_House", 20));
    giftList.emplace_back(Gift("Phone", 150));
    giftList.emplace_back(Gift("Iphone", 300));
    return giftList;
}

vector<pair<Gift, bool>> GiftStoreData::getStock() {
    srand((unsigned) time(0));
    vector<pair<Gift, bool>> giftStock;

    for (Gift gift:getStoreList()) {
        giftStock.emplace_back(pair<Gift, bool>(gift, randomBool()));
    }
    return giftStock;
}

//TODO: function that return random bool values
bool GiftStoreData::randomBool() {
    return rand() > (RAND_MAX / 2);
}

//TODO: function that check a gift's stock and return a bool value
//TODO: use for creating child's final wishlist
bool GiftStoreData::checkGiftStock(Gift gift) {
    bool isStock = false;
    for (pair<Gift, bool> currentPair:getStock()) {
        if (currentPair.first.getGiftName() == gift.getGiftName()) {
            if (currentPair.second) {
                isStock = true;
                break;
            }
        }
    }
    return isStock;
}
