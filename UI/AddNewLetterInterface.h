//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_ADDNEWLETTERINTERFACE_H
#define FINALPROJECTPOO_ADDNEWLETTERINTERFACE_H


#include "../DataClassesPackage/Children.h"
#include "../DataClassesPackage/Wishlist.h"
#include "../DataClassesPackage/Letter.h"

class AddNewLetterInterface {
public:
    virtual Children setChildrenData() = 0;

    virtual Wishlist setWishListData(Children children) = 0;

    virtual Letter setLetterData(Children children,Wishlist wishlist)=0;
};


#endif //FINALPROJECTPOO_ADDNEWLETTERINTERFACE_H
