//
// Created by danit on 12/31/2020.
//

#ifndef FINALPROJECTPOO_PROCESSROAD_H
#define FINALPROJECTPOO_PROCESSROAD_H


#include "Graph.h"
#include "../Databases/Cities/City.h"

class ProcessRoad {
private:
    int edgeIndex = 0;
    Graph *graph;
    vector<pair<string, string>> finalCityList;
    vector<Edge>edges;
public:
    void setRoadData(int E, int V);

    void showRoad();

    static vector<pair<int, string>> getPair();

    City setStartPoint();

    void addEdgesToGraph(const City &startCity);

    const vector<pair<string, string>> &getFinalCityList() const;

    const vector<Edge> &getEdges() const;
};


#endif //FINALPROJECTPOO_PROCESSROAD_H
