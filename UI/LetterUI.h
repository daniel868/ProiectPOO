//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_LETTERUI_H
#define FINALPROJECTPOO_LETTERUI_H


#include "AddNewLetterInterface.h"
#include "iostream"
using namespace std;
//TODO: handle UI for inserting a new child and letter
//TODO: create Children/Letter object
//TODO: sent all data to the ElfUI in order to process data
//TODO: extended from LetterInterface
class LetterUI : public AddNewLetterInterface {
public:
    Letter setLetterData(Children children, Wishlist wishlist) override;
    Children setChildrenData() override;
    Wishlist setWishListData(Children children) override;
};


#endif //FINALPROJECTPOO_LETTERUI_H
