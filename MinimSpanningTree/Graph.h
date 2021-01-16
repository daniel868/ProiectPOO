//
// Created by danit on 12/31/2020.
//

#ifndef FINALPROJECTPOO_GRAPH_H
#define FINALPROJECTPOO_GRAPH_H


#include "Edge.h"
#include "Subset.h"
#include "../Utils/Util.h"

//TODO: Main Class for MST Algorithm
//TODO: Method's that calculate the best solution for graph

class Graph {
public:
    int V, E;

    Edge *edge;

    Graph(int v, int e);

    int find(Subset subset[], int i);

    void Union(Subset subset[], int x, int y);

    void KruskalMST(Graph *graph);
};


#endif //FINALPROJECTPOO_GRAPH_H
