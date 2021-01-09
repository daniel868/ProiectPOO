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


        //  graph->edge = setEdges();
//        for (int i = 0; i < edges.size(); i++) {
//            graph->edge[i].src = edges[i].src;
//            graph->edge[i].dest = edges[i].dest;
//            graph->edge[i].weight = edges[i].weight;
//        }
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

City ProcessRoad::setStartPoint() {
    ElfUI elfUi;
    vector<pair<string, string>> childCities = elfUi.childCities();
    int numberDifferentCity = childCities.size();
    vector<pair<string, string>>::iterator itr = childCities.begin();

    for (int i = 0; i < childCities.size()-1; i++) {
        string firstCity = childCities[i].second;
        for (int j = i + 1; j < childCities.size(); j++) {
            string secondCity = childCities[j].second;
            if (firstCity == secondCity) {
                numberDifferentCity--;
                advance(itr, j);
                childCities.erase(itr);
            }
        }
    }
    this->finalCityList = childCities;

    float minimDistance;
    vector<City> allCities = CitiesData::FinlandToStartCities();
    minimDistance = allCities[0].getDistance();
    string startCity;
    for (pair<string, string> currentPair:childCities) {
        if (currentPair.second == "Gaborone,Botswana" && allCities[0].getDistance() < minimDistance) {
            minimDistance = allCities[0].getDistance();
            startCity = allCities[0].getName();
        }
        if (currentPair.second == "Francistown,Botswana" && allCities[1].getDistance() < minimDistance) {
            minimDistance = allCities[1].getDistance();
            startCity = allCities[1].getName();
        }
        if (currentPair.second == "Molepolole,Botswana" && allCities[2].getDistance() < minimDistance) {
            minimDistance = allCities[2].getDistance();
            startCity = allCities[2].getName();
        }
        if (currentPair.second == "Mahalapye,Botswana" && allCities[3].getDistance() < minimDistance) {
            minimDistance = allCities[3].getDistance();
            startCity = allCities[3].getName();
        }
    }

    return City(startCity, minimDistance);

}

void ProcessRoad::addEdgesToGraph(const City &startPoint) {
    Edge *edge = new Edge[3];
    vector<RoadsConnection> connection = RoadsConnection::getConnection();
    int possibleStartPointConnection = 0;
    for (auto currentPairConnection:connection) {
        if (currentPairConnection.getFrom().first == startPoint.getName()) {
            // edge[edgeIndex].src = currentPairConnection.getFrom().second;
            possibleStartPointConnection++;
        }
    }
    for (auto currentPairCity:this->getFinalCityList()) {
        if (currentPairCity.second != startPoint.getName()) {
            for (auto currentPairConnection:connection) {
                if (currentPairConnection.getFrom().first == startPoint.getName() &&
                    currentPairConnection.getTo().first == currentPairCity.second) {
                    Edge new_edge;
                    new_edge.src = currentPairConnection.getFrom().second;
                    new_edge.dest = currentPairConnection.getTo().second;
                    new_edge.weight = CitiesData::getDistanceBetweenCities(currentPairConnection.getFrom().first,
                                                                           currentPairConnection.getTo().first);
                    this->edges.push_back(new_edge);
                    edgeIndex++;
                }
            }
        }
    }


}

const vector<pair<string, string>> &ProcessRoad::getFinalCityList() const {
    return finalCityList;
}

const vector<Edge> &ProcessRoad::getEdges() const {
    return edges;
}
