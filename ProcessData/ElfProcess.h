//
// Created by danit on 12/29/2020.
//

#ifndef FINALPROJECTPOO_ELFPROCESS_H
#define FINALPROJECTPOO_ELFPROCESS_H


#include "ProcessLetterInterface.h"
#include "ElfData.h"
#include "../Databases/DefaultGift.h"
#include "../Databases/GiftStoreData.h"

//TODO: Class that process all information from DB (not included cities)
//TODO: Use ElfData class to store all processed information
//TODO: use ProcessLetterInterface

class ElfProcess : public ProcessLetterInterface {
private:
    int candyNumber;
    ElfData elfData;
public:
    void generateFinalElfData(Letter letter) override;

    void generateTotalCost() override;

    const ElfData &getElfData() const;
};


#endif //FINALPROJECTPOO_ELFPROCESS_H
