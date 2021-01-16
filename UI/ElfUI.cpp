//
// Created by danit on 1/1/2021.
//

#include "ElfUI.h"
#include "../DataClassesPackage/Children.h"
#include "../Databases/ChildrenDB/ChildrenDatabase.h"
#include "../Databases/LetterDB/LetterDatabase.h"
#include "../ProcessData/ElfProcess.h"
#include "LetterUI.h"
#include "../Databases/Cities/City.h"
#include "../MinimSpanningTree/ProcessRoad.h"
#include "../Dijkstra/DijkstraShortestPath.h"
#include "map"
#include "../Databases/BuilderResults.h"

map<string, pair<float, int>> coasts;
//TODO: use for final UI display
//TODO: get all processed data and fetch to the UI
//TODO: check for good/bad child in order to display 'little surprise from trolls'
//TODO: get all data from ElfClass and display to the UI
//TODO: check if it's empty DB
void ElfUI::showFinalResult() {
    BuilderResults builderResults;

    LetterDatabase letterDB;
    ElfProcess elfProcess;

    vector<Letter> letters = letterDB.GetAllLetters();
    if (builderResults.checkSize(letters)) {
        for (Letter currentLetter:letters) {
            elfProcess.generateFinalElfData(currentLetter);
        }
        elfProcess.generateTotalCost();
        coasts = elfProcess.getElfData().finalCoast;

        vector<Wishlist> wishLists = elfProcess.getElfData().finalChildrenWishList;
        std::cout << "#########################################################\n";
        std::cout << "\t" << "2. Elf's Children final list:\n";
        for (Wishlist wishlist:wishLists) {
            float sum = 0;
            std::cout << " * " << wishlist.getChildrenName() << " " << wishlist.getChildrenSurname() << "\n";
            std::cout << "\t";
            for (int i = 0; i < wishlist.getGiftList().size(); i++) {
                if (i < wishlist.getGiftList().size() - 1) {
                    std::cout << "- " << wishlist.getGiftList()[i].getGiftName() << "\n" << "\t";
                } else {
                    std::cout << "- " << wishlist.getGiftList()[i].getGiftName() << "\n";
                }
                sum += wishlist.getGiftList()[i].getGiftPrice();
            }
        }
        vector<pair<string, int>> candyNumber = elfProcess.getElfData().getFinalChildrenCandyNumber();

        std::cout << "\n";
        std::cout << "#########################################################\n";
        std::cout << "\t" << "3. Troll's color packed:\n";
        std::cout << "- Girls: " << " " << elfProcess.getElfData().finalGirlPacks << "\n";
        std::cout << "- Boys: " << " " << elfProcess.getElfData().finalBoyPacks << "\n";
        std::cout << "\n";
        std::cout << "\t" << "Lady Christmas's Candy number list:\n";
        for (auto currentCandy:candyNumber) {
            std::cout << " - " << "Child name: " << currentCandy.first << "\t" << "Candy number: "
                      << currentCandy.second
                      << "\n";
        }

        std::cout << "\n";
        std::cout << "#########################################################\n";
        std::cout << "\t" << "4. Lady Christmas final's math:\n";
        float count = 0;
        for (Wishlist wishlist:wishLists) {

            bool isCoal = false;
            for (Gift gift: wishlist.getGiftList()) {
                if (gift.getGiftName() == "Coal" && !isCoal) {
                    isCoal = true;
                }
            }
            count++;
            float childTotalGift = coasts.find(
                    wishlist.getChildrenName() + " " + wishlist.getChildrenSurname())->second.first;
            int childCandyTotal = coasts.find(
                    wishlist.getChildrenName() + " " + wishlist.getChildrenSurname())->second.second;

            if (!isCoal) {
                std::cout << count << ". " + wishlist.getChildrenName() + " " << wishlist.getChildrenSurname() << ":\n";
                std::cout << "\t" << "Gift total price: " << childTotalGift << " $" << "\n";
                std::cout << "\t" << "Candy total price: " << childCandyTotal << " $" << "\n";
                std::cout << "-----------------------------------------------------------------\n";
                std::cout << "\t" << "Total:  " << childTotalGift + childCandyTotal << " $\n";
            } else {
                std::cout << count << " . " + wishlist.getChildrenName() + " " << wishlist.getChildrenSurname() << "\n";
                std::cout << "\t" << "Gift total price: " << childTotalGift << " $" << "\n";
                std::cout << "\t" << "Candy total price: " << childCandyTotal << " $" << "\n";
                std::cout << "\t" << "A surprise from trolls: 0.5$" << "\n";
                std::cout << "-----------------------------------------------------------------\n";
                std::cout << "\t" << "Total:  " << childTotalGift + childCandyTotal + 0.5 << " $ \n";
            }
        }
        std::cout << "\n";
        std::cout << "#########################################################\n";
        std::cout << "\t5. Santa's travel roads:\n";
        processCities1();
        std::cout << "\n";
        processCities2();
        std::cout << "\n";

        std::cout << "\n";
        std::cout << "#########################################################\n";
        std::cout << "\t6. Sharing with Lady Santa travel roads:\n";
        processCities1();
        std::cout << "\n";
        processCities2();
        std::cout << "\n";
    } else {
        std::cout << "Insert a children first:\n";
    }
}

vector<pair<string, string>> ElfUI::childCities() {
    vector<pair<string, string>> childCities;
    LetterDatabase letterDatabase;
    ElfProcess elfProcess;
    for (Letter letter:letterDatabase.GetAllLetters()) {
        elfProcess.generateFinalElfData(letter);
    }
    childCities = elfProcess.getElfData().finalCityList;
    return childCities;
}

//TODO: function for  inserting a new child and a new letter into DB
//TODO check before inserting all info
void ElfUI::insertNewChild() {
    ChildrenDatabase childrenDB;
    LetterDatabase letterDB;
    LetterUI letterUi;

    Children new_children;
    Wishlist new_wishList;
    Letter new_letter;

    new_children = letterUi.setChildrenData();
    new_wishList = letterUi.setWishListData(new_children);
    new_letter = letterUi.setLetterData(new_children, new_wishList);

    try {
        if (!childrenDB.checkChildrenData(new_children) || !letterDB.CheckValidData(new_letter)) {
            throw "Problem inserting children or letter:\n";
        } else {
            childrenDB.InsertChildren(new_children);
            letterDB.AddLetterToDB(new_letter);
        }

    } catch (const char *err) {
        std::cout << err << "\n";
    }

}

//TODO: show optimal road using MST Algorithm
void ElfUI::processCities1() {
    ProcessRoad processRoad;
    processRoad.setRoadData(10, 5);
    processRoad.showRoad();
    std::cout << "\n";
}

//TODO: show optimal roads using Dijsktra Algorithm
void ElfUI::processCities2() {
    DijkstraShortestPath shortestPath;
    shortestPath.printRoad();

}

//TODO: display all letters to the UI
void ElfUI::showAllLetters() {
    LetterDatabase letterDatabase;
    vector<Letter> letters = letterDatabase.GetAllLetters();
    BuilderResults builderResults;
    if (builderResults.checkSize<int>(letters.size())) {
        std::cout << "\t 1." << " Children's letters:\n";
        int k = 0;
        for (Letter currentLetter:letters) {
            k++;
            std::cout << "-------------Letter #" << k << "------------------------" << "\n";
            std::cout << "* Child name and surname: " << currentLetter.getName() << " " << currentLetter.getSurname()
                      << "\n";
            std::cout << "* Child age: " << currentLetter.getAge() << "\n";
            std::cout << "* Child city: " << currentLetter.getCity() << "\n";
            std::cout << "* Child wishList:\n";
            for (Gift gift:currentLetter.getWishList().getGiftList()) {
                std::cout << "\t" << " - " << gift.getGiftName() << "\n";
            }
            std::cout << "* Letter color: " << currentLetter.getColor() << "\n";

            std::cout << "\n";
        }
    } else {
        std::cout << "Insert at least one child:\n";
    }

}

