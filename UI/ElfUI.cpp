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

void ElfUI::showChildGift() {
    LetterDatabase letterDB;
    ElfProcess elfProcess;

    vector<Letter> letters = letterDB.GetAllLetters();
    for (Letter currentLetter:letters) {
        elfProcess.generateFinalElfData(currentLetter);
    }

    vector<Wishlist> wishLists = elfProcess.getElfData().finalChildrenWishList;
    std::cout << "Children final list:\n";
    for (Wishlist wishlist:wishLists) {
        float sum = 0;
        std::cout << wishlist.getChildrenName() << " " << wishlist.getChildrenSurname() << "\n";
        std::cout << "\t";
        for (int i = 0; i < wishlist.getGiftList().size(); i++) {
            if (i < wishlist.getGiftList().size() - 1) {
                std::cout << "- " << wishlist.getGiftList()[i].getGiftName() << "\n" << "\t";
            } else {
                std::cout << "- " << wishlist.getGiftList()[i].getGiftName() << "\n";
            }
        }
    }
    vector<pair<string, int>> candyNumber = elfProcess.getElfData().getFinalChildrenCandyNumber();

    std::cout << "\n";
    std::cout << "Ambalaj pentru fete: \n" << " " << elfProcess.getElfData().finalGirlPacks << "\n";
    std::cout << "Ambalaj pentru baieti: \n" << " " << elfProcess.getElfData().finalBoyPacks << "\n";
    std::cout << "\n";
    std::cout << "Candy number list:\n";
    for (auto currentCandy:candyNumber) {
        std::cout << " - " << currentCandy.first << "\t" << currentCandy.second << "\n";
    }

    std::cout<<"\n";
    std::cout<<"Final prices are:\n";
    for (Wishlist wishlist:wishLists) {
        float sum = 0;
        bool isCoal = false;
        for (Gift gift: wishlist.getGiftList()) {
            if (gift.getGiftName() == "Coal" && !isCoal) {
                isCoal = true;
            }
            sum += gift.getGiftPrice();
        }
        if (!isCoal) {
            std::cout << wishlist.getChildrenName() + " " + wishlist.getChildrenName() + " " << sum << "$\n";
        } else {
            std::cout << wishlist.getChildrenName() + " " + wishlist.getChildrenName() + " "
                      << sum << "+" << "0.5$ = " << sum<<"$\n";
        }
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
//    processRoad.showRoad(finalEdge);
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

