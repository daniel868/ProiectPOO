//
// Created by danit on 12/28/2020.
//

#include "Wishlist.h"

Wishlist::Wishlist(const string &childrenName, const string &childrenSurname, const vector<Gift> &giftList)
        : children_name(childrenName), children_surname(childrenSurname), giftList(giftList) {

}

const string &Wishlist::getChildrenName() const {
    return children_name;
}

void Wishlist::setChildrenName(const string &childrenName) {
    children_name = childrenName;
}

const string &Wishlist::getChildrenSurname() const {
    return children_surname;
}

void Wishlist::setChildrenSurname(const string &childrenSurname) {
    children_surname = childrenSurname;
}

const vector<Gift> &Wishlist::getGiftList() const {
    return giftList;
}

void Wishlist::setGiftList(const vector<Gift> &giftList) {
    Wishlist::giftList = giftList;
}

Wishlist::Wishlist(const vector<Gift> &giftList) : giftList(giftList) {

}

void Wishlist::addGift(Gift gift) {
    this->giftList.push_back(gift);
}

void Wishlist::removeGift() {
    this->giftList.pop_back();
}

Wishlist::Wishlist() {}

Wishlist::~Wishlist() {

}
