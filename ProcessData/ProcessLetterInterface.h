//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_PROCESSLETTERINTERFACE_H
#define FINALPROJECTPOO_PROCESSLETTERINTERFACE_H

#include "iostream"
#include "vector"
#include "../DataClassesPackage/Gift.h"
#include "../DataClassesPackage/Letter.h"

using namespace std;


class ProcessLetterInterface {
public:
    virtual void generateFinalElfData(Letter letter) = 0;

};


#endif //FINALPROJECTPOO_PROCESSLETTERINTERFACE_H
