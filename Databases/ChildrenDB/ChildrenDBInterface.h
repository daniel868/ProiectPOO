//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_CHILDRENDBINTERFACE_H
#define FINALPROJECTPOO_CHILDRENDBINTERFACE_H


#include "../../DataClassesPackage/Children.h"

#include "iostream"

using namespace std;

#include "vector"

class ChildrenDBInterface {
public:
    virtual void InsertChildren(Children children) = 0;

    virtual void DeleteChildren(Children children) = 0;

    virtual vector<Children> GetAllChildren() = 0;

    virtual bool checkChildrenData(Children children) = 0;
};


#endif //FINALPROJECTPOO_CHILDRENDBINTERFACE_H
