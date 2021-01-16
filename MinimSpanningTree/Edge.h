//
// Created by danit on 12/31/2020.
//

#ifndef FINALPROJECTPOO_EDGE_H
#define FINALPROJECTPOO_EDGE_H

#include "iostream"

using namespace std;

//TODO: use in MST Algorithm in order to represent graph edge (start/dest) and weight

class Edge {
public:
    int weight,src,dest;

    int compareTo(Edge o);
};


#endif //FINALPROJECTPOO_EDGE_H
