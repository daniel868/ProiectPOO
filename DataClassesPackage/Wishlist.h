//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_WISHLIST_H
#define FINALPROJECTPOO_WISHLIST_H

#include "vector"
#include "iostream"
#include "Gift.h"

using namespace std;

//TODO: store children's list of gift by using a simple vector
//TODO: for identify more easily, it contains 2 string field (name and surname)

class Wishlist {
private:
    string children_name;
    string children_surname;
    vector<Gift> giftList;
public:
    Wishlist();

    ~Wishlist();

    Wishlist(const string &childrenName, const string &childrenSurname, const vector<Gift> &giftList);

    Wishlist(const vector<Gift> &giftList);

    const string &getChildrenName() const;

    void setChildrenName(const string &childrenName);

    const string &getChildrenSurname() const;

    void setChildrenSurname(const string &childrenSurname);

    const vector<Gift> &getGiftList() const;

    void setGiftList(const vector<Gift> &giftList);

    void addGift(Gift gift);

    void removeGift();
};


#endif //FINALPROJECTPOO_WISHLIST_H
