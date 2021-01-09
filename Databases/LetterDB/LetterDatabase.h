//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_LETTERDATABASE_H
#define FINALPROJECTPOO_LETTERDATABASE_H

#include "fstream"
#include "LetterDatabaseInterface.h"
#include "../../Utils/Util.h"
#include "../GiftStoreData.h"


class LetterDatabase : public LetterDatabaseInterface {
public:
    void AddLetterToDB(Letter letter)override;

    void DeleteLetterToDB(Letter letter)override;

    bool CheckValidData(Letter letter) override;

    vector<Letter> GetAllLetters() override;
   // Letter getLetterFromDB(int letterId) override;

};


#endif //FINALPROJECTPOO_LETTERDATABASE_H
