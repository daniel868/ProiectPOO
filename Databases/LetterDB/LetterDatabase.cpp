//
// Created by danit on 12/28/2020.
//

#include <fstream>
#include "LetterDatabase.h"
#include "map"
#include "../ChildrenDB/ChildrenDatabase.h"

map<int, Letter> letterCountMap;

void LetterDatabase::AddLetterToDB(Letter letter) {
    int count = 0;
    ifstream MyLetterDB_in;
    MyLetterDB_in.open(LetterDatabaseName, ios::in);
    string currentLine;
    while (getline(MyLetterDB_in, currentLine)) {
        count++;
    }
    MyLetterDB_in.close();

    ofstream MyLetterDB;
    MyLetterDB.open(LetterDatabaseName, ios_base::app);
    MyLetterDB << count << " " << letter.getName() << " " << letter.getSurname() << " " << letter.getAge() << " "
               << letter.getCity() << " " << letter.getColor() << " ";
    for (const Gift &currentChildrenGift:letter.getWishList().getGiftList()) {
        MyLetterDB << currentChildrenGift.getGiftName() << " ";
    }
    MyLetterDB << "\n";
    MyLetterDB.close();

}

void LetterDatabase::DeleteLetterToDB(int letterId) {
    GetAllLetters();
    ofstream MyLetterDB;
    MyLetterDB.open(LetterDatabaseName, ios::out);
    MyLetterDB << "";
    MyLetterDB.close();

    map<int, Letter>::iterator itr;
    for (itr = letterCountMap.begin(); itr != letterCountMap.end(); itr++) {
        if (itr->first != letterId) {
            AddLetterToDB(itr->second);
        }
    }
    ChildrenDatabase childrenDatabase;
    childrenDatabase.DeleteChildren(letterId);
}

bool LetterDatabase::CheckValidData(Letter letter) {
    bool isSafe = true;
    try {
        if (letter.getName().size() == 0) {
            isSafe = false;
            throw "Letter with wrong name";
        }
    } catch (const char *err) {
        std::cout << err;
    }
    try {
        if (letter.getSurname().size() == 0) {
            isSafe = false;
            throw "Letter with wrong surname";
        }
    } catch (const char *err) {
        std::cout << err;
    }
    try {
        if (letter.getWishList().getGiftList().size() == 0) {
            isSafe = false;
            throw "Letter with empty wish list";
        }
    } catch (const char *err) {
        std::cout << err;
    }
    try {
        if (letter.getAge() <= 0) {
            isSafe = false;
            throw "Letter with wrong age";
        }
    } catch (const char *err) {
        std::cout << err;
    }
    try {
        if (letter.getColor() != "Pink" && letter.getColor() != "pink" && letter.getColor() != "Blue" &&
            letter.getColor() != "blue") {
            isSafe = false;
            throw "Letter with wrong color";
        }
    } catch (const char *err) {
        std::cout << err;
    }
    return isSafe;
}

vector<Letter> LetterDatabase::GetAllLetters() {
    vector<Letter> existingLetters;
    ifstream LetterDatabase;
    LetterDatabase.open(LetterDatabaseName, ios::in);
    string line;

    while (getline(LetterDatabase, line)) {
        vector<string> stringOut;
        Util::tokenize(line, ' ', stringOut);
        Letter letter;
        letter.setName(stringOut[1]);
        letter.setSurname(stringOut[2]);
        letter.setAge(stoi(stringOut[3], nullptr, 10));
        letter.setCity(stringOut[4]);
        letter.setColor(stringOut[5]);

        vector<Gift> letterGifts;
        letterGifts.clear();
        Wishlist wishlist;

        for (int i = 6; i < stringOut.size(); i++) {
            wishlist.setChildrenName(stringOut[1]);
            wishlist.setChildrenSurname(stringOut[2]);
            string giftName = stringOut[i];
            float giftPrice;
            for (Gift gift:GiftStoreData::getStoreList()) {
                if (gift.getGiftName() == giftName) {
                    giftPrice = gift.getGiftPrice();
                }
            }
            Gift letterGift(giftName, giftPrice);
            letterGifts.emplace_back(letterGift);
        }
        wishlist.setGiftList(letterGifts);
        letter.setWishList(wishlist);

        letterCountMap.insert(pair<int, Letter>(stoi(stringOut[0], nullptr, 10), letter));
        existingLetters.emplace_back(letter);
    }
    LetterDatabase.close();

    return existingLetters;
}

void LetterDatabase::DeleteLetterToDB(Letter letter) {

}
