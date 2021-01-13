//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_CHILDRENDATABASE_H
#define FINALPROJECTPOO_CHILDRENDATABASE_H


#include "ChildrenDBInterface.h"
#include "fstream"

class ChildrenDatabase : public ChildrenDBInterface {
public:
    void InsertChildren(Children children) override;

    void DeleteChildren(int childrenIn) override;

    void DeleteChildren(Children children) override;

    vector<Children> GetAllChildren() override;

    bool checkChildrenData(Children children) override;
};


#endif //FINALPROJECTPOO_CHILDRENDATABASE_H
