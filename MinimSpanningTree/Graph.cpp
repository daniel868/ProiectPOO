//
// Created by danit on 12/31/2020.
//

#include <cstdlib>
#include "Graph.h"
#include "ProcessRoad.h"

Graph::Graph(int v, int e) {
    this->V = v;
    this->E = e;
    edge = new Edge[E];
}


int Graph::find(Subset *subset, int i) {
    if (subset[i].parent != i) {
        subset[i].parent = find(subset, subset[i].parent);
    }
    return subset[i].parent;
}

void Graph::Union(Subset *subset, int x, int y) {
    int xRoot = find(subset, x);
    int yRoot = find(subset, y);

    if (subset[xRoot].rank < subset[yRoot].rank) {
        subset[xRoot].parent = yRoot;
    } else if (subset[xRoot].rank > subset[yRoot].rank) {
        subset[yRoot].parent = xRoot;
    } else {
        subset[yRoot].parent = xRoot;
        subset[xRoot].rank++;
    }
}


void Graph::KruskalMST(Graph *graph) {
    int V = graph->V;
    Edge results[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), Util::myComp);

    Subset *subset = new Subset[(V * sizeof(subset))];

    for (int v = 0; v < V; v++) {
        subset[v].parent = v;
        subset[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++];

        int x = find(subset, next_edge.src);
        int y = find(subset, next_edge.dest);

        if (x != y) {
            results[e++] = next_edge;
            Union(subset, x, y);
        }
    }
    std::cout << "1. First road which includes all default cities:\n";
    std::cout << "\n";
    std::cout << "Start from: Rovaniemi:\n";
    int minimCost = 10136.37;

    ProcessRoad cityName;


    for (int j = 0; j < e; j++) {
        std::cout << "\t" << cityName.getPair()[results[j].src].second << " ---> "
                  << cityName.getPair()[results[j].dest].second
                  << "\n";
        minimCost += results[j].weight;
    }
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "Total distance: " << minimCost << " km";

}


