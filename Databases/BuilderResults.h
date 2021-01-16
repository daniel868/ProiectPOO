//
// Created by danit on 1/13/2021.
//

#ifndef FINALPROJECTPOO_BUILDERRESULTS_H
#define FINALPROJECTPOO_BUILDERRESULTS_H

#include "iostream"
#include "vector"
#include "LetterDB/LetterDatabase.h"

using namespace std;

//TODO: useful for case you have 0 children and 0 letters in your DB
//TODO: it provide a bool value
//TODO: use templates

class BuilderResults {
private:

public:
    template<class T>

    bool checkSize(T t);

    bool checkSize(vector<Letter> letters);

};

//TODO: check DB Size
template<class T>
bool BuilderResults::checkSize(T t) {
    if (t == 0) {
        return false;
    } else {
        return true;
    }
}


#endif //FINALPROJECTPOO_BUILDERRESULTS_H
