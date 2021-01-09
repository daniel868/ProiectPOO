#include <iostream>
#include "DataClassesPackage/Gift.h"
#include "Databases/LetterDB/LetterDatabase.h"
#include "Databases/GiftStoreData.h"
#include "UI/LetterUI.h"
#include "Databases/ChildrenDB/ChildrenDatabase.h"
#include "ProcessData/ElfProcess.h"
#include "ProcessData/ElfData.h"
#include "MinimSpanningTree/Graph.h"
#include "MinimSpanningTree/ProcessRoad.h"
#include "bits/stdc++.h"
#include "Databases/DefaultGift.h"
#include "UI/ElfUI.h"
#include "Dijkstra/DijkstraShortestPath.h"


int main() {
    ElfUI elfUi;
    elfUi.showAllLeters();
    elfUi.showFinalResult();
    std::cout << "\n";
    elfUi.processCities1();
    std::cout << "\n";
    elfUi.processCities2();

}


