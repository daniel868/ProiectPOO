//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_LETTER_H
#define FINALPROJECTPOO_LETTER_H


#include "Children.h"
#include "Wishlist.h"

//TODO: extended form Children class ->contains more information about children's wishlist
//TODO: and letter color

class Letter : public Children {
private:
    string color;
    Wishlist wishList;
public:
    Letter(const string &name, const string &surname, const string &city, int age, const string &color,
           const Wishlist &wishList);

    const string &getColor() const;

    void setColor(const string &color);

    const Wishlist &getWishList() const;

    void setWishList(const Wishlist &wishList);

    Letter();

    ~Letter();
};


#endif //FINALPROJECTPOO_LETTER_H
