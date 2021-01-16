//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_GIFT_H
#define FINALPROJECTPOO_GIFT_H

#include "iostream"

using namespace std;

//TODO: use for storing possible child's gift
//TODO: help creating 'WihsList' for children

class Gift {
private:
    string gift_name;
    float gift_price;
    bool isAdded = false;
public:
    Gift();

    ~Gift();

    Gift(const string &giftName, float giftPrice);

    const string &getGiftName() const;

    void setGiftName(const string &giftName);

    float getGiftPrice() const;

    void setGiftPrice(float giftPrice);

    bool isAdded1() const;

    void setIsAdded(bool isAdded);
};


#endif //FINALPROJECTPOO_GIFT_H
