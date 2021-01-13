//
// Created by danit on 12/28/2020.
//

#include "Gift.h"

Gift::Gift(const string &giftName, float giftPrice) : gift_name(giftName), gift_price(giftPrice) {

}

const string &Gift::getGiftName() const {
    return gift_name;
}

void Gift::setGiftName(const string &giftName) {
    gift_name = giftName;
}

float Gift::getGiftPrice() const {
    return gift_price;
}

void Gift::setGiftPrice(float giftPrice) {
    gift_price = giftPrice;
}

bool Gift::isAdded1() const {
    return isAdded;
}

void Gift::setIsAdded(bool isAdded) {
    Gift::isAdded = isAdded;
}

Gift::Gift() {}

Gift::~Gift() {

}
