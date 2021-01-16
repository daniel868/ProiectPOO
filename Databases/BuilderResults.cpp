//
// Created by danit on 1/13/2021.
//

#include "BuilderResults.h"
//TODO: check DB size
bool BuilderResults::checkSize(vector<Letter> letters) {
    if (letters.size() > 0) {
        return true;
    } else {
        return false;
    }
}
