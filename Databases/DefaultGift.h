//
// Created by danit on 1/1/2021.
//

#ifndef FINALPROJECTPOO_DEFAULTGIFT_H
#define FINALPROJECTPOO_DEFAULTGIFT_H

#include "../DataClassesPackage/Gift.h"

//TODO: template class that generate default Gifts for 100$ and 10$ gift
//TODO: generate by using int type

template<class T>
class DefaultGift {
private:
    T t;
    Gift gift;
public:
    DefaultGift(T t) : t(t) {}

    Gift getDefaultGift();

    T getT() const;
};

template<class T>
Gift DefaultGift<T>::getDefaultGift() {
    if (this->t == 100) {
        this->gift = Gift("100 Default Gift", 100);
    } else if (this->t == 10) {
        this->gift = Gift("10 Default Gift", 10);
    }
    return this->gift;
}

template<class T>
T DefaultGift<T>::getT() const {
    return t;
}


#endif //FINALPROJECTPOO_DEFAULTGIFT_H
