//
// Created by danit on 12/28/2020.
//

#include "Letter.h"

const string &Letter::getColor() const {
    return color;
}

void Letter::setColor(const string &color) {
    Letter::color = color;
}

const Wishlist &Letter::getWishList() const {
    return wishList;
}

void Letter::setWishList(const Wishlist &wishList) {
    Letter::wishList = wishList;
}

Letter::Letter(const string &name, const string &surname, const string &city, int age, const string &color,
               const Wishlist &wishList) : Children(name, surname, city, age), color(color), wishList(wishList) {

}

Letter::Letter() {

}

Letter::~Letter() {

}

