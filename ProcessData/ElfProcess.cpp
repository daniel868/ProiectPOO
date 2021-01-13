//
// Created by danit on 12/29/2020.
//

#include <algorithm>
#include "ElfProcess.h"
#include "ElfData.h"
#include "../Utils/Util.h"
#include "map"


void ElfProcess::generateFinalElfData(Letter letter) {
    bool isdefaultGift = false, addCoal = false;
    vector<Gift> finalGiftList;
    pair<string, int> childCandy;
    pair<string, string> childCity;
    float max_children_amount;
    float current_children_amount = 0;

    if (this->elfData.checkBad_GoodChild(letter)) {
        max_children_amount = 100;
    } else {
        max_children_amount = 10;
        addCoal = true;
    }

    vector<Gift> letterGift = letter.getWishList().getGiftList();
    sort(letterGift.begin(), letterGift.end(), Util::sortGiftPrice);

    if (letterGift[0].getGiftPrice() > max_children_amount) {
        DefaultGift<int> childDefaultGift((int) max_children_amount);
        isdefaultGift = true;
        finalGiftList.emplace_back(childDefaultGift.getDefaultGift());
        current_children_amount = max_children_amount;
    }

    if (!isdefaultGift) {
        for (Gift currentGift :letter.getWishList().getGiftList()) {
            if ((current_children_amount + currentGift.getGiftPrice()) <= max_children_amount
                && GiftStoreData::checkGiftStock(currentGift)) {
                current_children_amount += currentGift.getGiftPrice();
                finalGiftList.emplace_back(currentGift);
            }
        }
    }
    if (finalGiftList.empty()) {
        finalGiftList.emplace_back(DefaultGift<int>(max_children_amount).getDefaultGift());
        current_children_amount = max_children_amount;
    }
    this->candyNumber = (int) (max_children_amount - current_children_amount);

    childCandy.first = letter.getName() + " " + letter.getSurname();
    childCandy.second = candyNumber;
    childCity.first = letter.getName() + " " + letter.getSurname();
    childCity.second = letter.getCity();

    if (addCoal) {
        finalGiftList.emplace_back(Gift("Coal", 0.5));
    }
    if (letter.getColor() == "pink" || letter.getColor() == "Pink") {
        this->elfData.finalGirlPacks++;
    }
    if (letter.getColor() == "blue" || letter.getColor() == "Blue") {
        this->elfData.finalBoyPacks++;
    }
    this->elfData.finalChildrenWishList.emplace_back(Wishlist(letter.getName(), letter.getSurname(), finalGiftList));
    this->elfData.finalChildrenCandyNumber.emplace_back(childCandy);
    this->elfData.finalCityList.emplace_back(childCity);
}

const ElfData &ElfProcess::getElfData() const {
    return elfData;
}

void ElfProcess::generateTotalCost() {
    map<string, pair<float, int>> finalCoasts;
    for (auto currentWishlist:this->elfData.getFinalChildrenWishList()) {
        float giftTotalCost = 0;
        for (auto currentGift :currentWishlist.getGiftList()) {
            giftTotalCost += currentGift.getGiftPrice();
        }
        float totalCandyNumber = 0;
        int flag = 0;
        for (int i = 0; i < elfData.getFinalChildrenCandyNumber().size() && flag == 0; i++) {
            if (elfData.getFinalChildrenCandyNumber()[i].first ==
                currentWishlist.getChildrenName() + " " + currentWishlist.getChildrenSurname()) {
                totalCandyNumber = elfData.getFinalChildrenCandyNumber()[i].second;
                flag = 1;
            }
        }
        finalCoasts.insert(pair<string, pair<float, int>>(
                currentWishlist.getChildrenName() + " " + currentWishlist.getChildrenSurname(),
                pair<float, int>(giftTotalCost, totalCandyNumber)));
    }
    elfData.finalCoast = finalCoasts;

}
