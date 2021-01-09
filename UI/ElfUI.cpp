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

map<string, pair<float, int>> coasts;

void ElfUI::showFinalResult() {
    LetterDatabase letterDB;
    ElfProcess elfProcess;

    vector<Letter> letters = letterDB.GetAllLetters();
    for (Letter currentLetter:letters) {
        elfProcess.generateFinalElfData(currentLetter);
    }
    elfProcess.generateTotalCost();
    coasts = elfProcess.getElfData().finalCoast;

    vector<Wishlist> wishLists = elfProcess.getElfData().finalChildrenWishList;
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
    std::cout << "\t" << "3. Troll's color packed:\n";
    std::cout << "- Girls: " << " " << elfProcess.getElfData().finalGirlPacks << "\n";
    std::cout << "- Boys: " << " " << elfProcess.getElfData().finalBoyPacks << "\n";
    std::cout << "\n";
    std::cout << "\t" << "Lady Christmas's Candy number list:\n";
    for (auto currentCandy:candyNumber) {
        std::cout << " - " << "Child name: " << currentCandy.first << "\t" << "Candy number: " << currentCandy.second
                  << "\n";
    }

    std::cout << "\n";
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
    std::cout << "\t5. Santa's travel roads:";
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

void ElfUI::showFinalRoad() {
    ProcessRoad processRoad;
    City startCity = processRoad.setStartPoint();
    processRoad.addEdgesToGraph(startCity);
    for (auto currentPair :processRoad.getFinalCityList()) {
        processRoad.addEdgesToGraph(City(currentPair.second, 20));
    }

    vector<Edge> finalEdge = processRoad.getEdges();

    processRoad.setRoadData(processRoad.getEdges().size(), 4);
}

void ElfUI::processCities1() {
    ProcessRoad processRoad;
    processRoad.setRoadData(10, 5);
    processRoad.showRoad();
    std::cout << "\n";
}

void ElfUI::processCities2() {
    DijkstraShortestPath shortestPath;
    shortestPath.printRoad();

}

void ElfUI::showAllLeters() {
    LetterDatabase letterDatabase;
    vector<Letter> letters = letterDatabase.GetAllLetters();
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
}

