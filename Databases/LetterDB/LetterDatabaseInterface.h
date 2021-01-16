//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_LETTERDATABASEINTERFACE_H
#define FINALPROJECTPOO_LETTERDATABASEINTERFACE_H


#include "../../DataClassesPackage/Letter.h"

//TODO: virtual abstract class for Letter database (interface)

class LetterDatabaseInterface {
public:
    virtual void AddLetterToDB(Letter letter) = 0;

    virtual void DeleteLetterToDB(int letterId) = 0;

    virtual void DeleteLetterToDB(Letter letter)=0;

    virtual bool CheckValidData(Letter letter) = 0;

    virtual vector<Letter> GetAllLetters() = 0;
    //  virtual Letter getLetterFromDB(int letterId)=0;
};


#endif //FINALPROJECTPOO_LETTERDATABASEINTERFACE_H
