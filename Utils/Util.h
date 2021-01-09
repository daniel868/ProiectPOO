//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_UTIL_H
#define FINALPROJECTPOO_UTIL_H

#include "iostream"
#include "vector"
#include "../DataClassesPackage/Gift.h"

using namespace std;

class Util {
public:
    static void tokenize(string &str, char delim, vector<string> &out);

    static int myComp(const void *a, const void *b);

   static bool sortGiftPrice(Gift g1, Gift g2);
};

static string LetterDatabaseName = "LetterDB.txt";
static string ChildrenDatabaseName = "ChildrenDB.txt";

#endif //FINALPROJECTPOO_UTIL_H
