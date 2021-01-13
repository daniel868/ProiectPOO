//
// Created by danit on 12/31/2020.
//

#include <list>
#include "ProcessRoad.h"
#include "../UI/ElfUI.h"
#include "../Databases/Cities/City.h"
#include "../Databases/Cities/CitiesData.h"
#include "RoadsConnection.h"

void ProcessRoad::setRoadData(int E, int V) {
    this->graph = new Graph(V, E);
}

void ProcessRoad::showRoad(){
    Graph *graph = this->graph;
    if (graph != nullptr) {
        graph->edge[0].src = 0;
        graph->edge[0].dest = 1;
        graph->edge[0].weight = 414;


        graph->edge[1].src = 0;
        graph->edge[1].dest = 2;
        graph->edge[1].weight = 49;

        graph->edge[2].src = 0;
        graph->edge[2].dest = 3;
        graph->edge[2].weight = 197;

        graph->edge[3].src = 1;
        graph->edge[3].dest = 2;
        graph->edge[3].weight = 421;


        graph->edge[4].src = 1;
        graph->edge[4].dest = 3;
        graph->edge[4].weight = 227;


        graph->edge[5].src = 2;
        graph->edge[5].dest = 3;
        graph->edge[5].weight = 196;

        graph->edge[6].src = 0;
        graph->edge[6].dest = 4;
        graph->edge[6].weight = 882;

        graph->edge[7].src = 1;
        graph->edge[7].dest = 4;
        graph->edge[7].weight = 489;

        graph->edge[8].src = 2;
        graph->edge[8].dest = 4;
        graph->edge[8].weight = 851;

        graph->edge[9].src = 3;
        graph->edge[9].dest = 4;
        graph->edge[9].weight = 654;

        graph->KruskalMST(graph);
    }
}

vector<pair<int, string>> ProcessRoad::getPair() {
    vector<pair<int, string>> roadsName;
    roadsName.emplace_back(pair<int, string>(0, "Molepolole,Botswana"));
    roadsName.emplace_back(pair<int, string>(1, "Francistown,Botswana"));
    roadsName.emplace_back(pair<int, string>(2, "Gaborone,Botswana"));
    roadsName.emplace_back(pair<int, string>(3, "Mahalapye,Botswana"));
    roadsName.emplace_back(pair<int, string>(4, "Maun,Botswana"));
    return roadsName;
}


const vector<pair<string, string>> &ProcessRoad::getFinalCityList() const {
    return finalCityList;
}

const vector<Edge> &ProcessRoad::getEdges() const {
    return edges;
}
