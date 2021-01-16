//
// Created by danit on 1/8/2021.
//


#include "DijkstraShortestPath.h"
#include "iostream"
#include "vector"
#include "set"
#include "algorithm"
#include "../Databases/ChildrenDB/ChildrenDatabase.h"
#include "map"
#include "../MinimSpanningTree/ProcessRoad.h"

using namespace std;

//TODO: function class that build optimal path, but using the existing roads
//TODO: as example, in DB are children only from X, or from X and Y cities
//TODO: we don't need to use MST for all default graph, we build a new graph and use Dijkstra Algorithm

//TODO: use for algorithm
typedef pair<int, unsigned long long> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

map<int, pair<int, string>> citiesNames;

//TODO: get pair int-string (cities_Id-cities_Name)
vector<pair<int, string>> citiesPair = ProcessRoad::getPair();

//TODO: main DikstraAlgorithm that find the minimal distance between source_node -> destination_node)
//TODO: return the results as type of pair<int,int>, where: first = distance,second = next_node
pair<int, int> DijkstraShortestPath(int source_node, int destination_node, int node_count, VVPII &graph) {

    // Assume that the distance from source_node to other nodes is infinite
    // in the beginnging, i.e initialize the distance vector to a max value
    const long long INF = 999999999999;
    vector<unsigned long long> dist(node_count, INF);
    set<PII> set_length_node;

    // Distance from starting vertex to itself is 0
    dist[source_node] = 0;
    set_length_node.insert(PII(0, source_node));

    while (!set_length_node.empty()) {

        PII top = *set_length_node.begin();
        set_length_node.erase(set_length_node.begin());

        int source_node = top.second;

        for (auto &it : graph[source_node]) {

            int adj_node = it.first;
            int length_to_adjnode = it.second;

            // Edge relaxation
            if (dist[adj_node] > length_to_adjnode + dist[source_node]) {

                // If the distance to the adjacent node is not INF, means the pair <dist, node> is in the set
                // Remove the pair before updating it in the set.
                if (dist[adj_node] != INF) {
                    set_length_node.erase(set_length_node.find(PII(dist[adj_node], adj_node)));
                }
                dist[adj_node] = length_to_adjnode + dist[source_node];
                set_length_node.insert(PII(dist[adj_node], adj_node));
            }
        }
    }

//    for (int i=0; i<node_count; i++)
//        cout << "Source Node(" << source_node << ") -> Destination Node(" << i << ") : " << dist[i] << endl;
//    std::cout << "Source Node " << source_node << " " << destination_node << " " << dist[destination_node] << "\n";
    return pair<int, int>(dist[destination_node], destination_node);
}

//TODO: algorithm that use Greedy method to build optimal path using Dijkstra Algorithm
//TODO: use DijkstraAlgorithm apply for every existing node in graph
//TODO: use a bool vector to keep evidence for every node
void findTheRoad(VVPII &graph, int start_node, int node_count) {
    bool isVisited[node_count];
    int next_node = start_node;
    int total_distance_km = 10136.37;

    for (int j = 0; j < node_count - 1; j++) {
        int minDistance = 99999;
        for (int i = 0; i < node_count; i++) {
            if (i != start_node && !isVisited[i]) {
                if (DijkstraShortestPath(start_node, i, node_count, graph).first < minDistance) {
                    minDistance = DijkstraShortestPath(start_node, i, node_count, graph).first;
                    next_node = DijkstraShortestPath(start_node, i, node_count, graph).second;
                }
            }
        }


        std::cout << "---> " << citiesNames.find(next_node)->second.second;
        //  std::cout << "---> " << next_node;
        total_distance_km += minDistance;
        isVisited[start_node] = true;
        start_node = next_node;
    }
    std::cout << "\n";
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "Total distance distance is " << total_distance_km;
}


vector<int> DijkstraShortestPath::getCityNumber() {
    bool city1 = false, city2 = false, city3 = false, city4 = false, city5 = false;
    ChildrenDatabase childrenDatabase;
    vector<Children> children = childrenDatabase.GetAllChildren();
    vector<int> cities;
    for (Children currentChildren:children) {
        if (currentChildren.getCity() == "Molepolole,Botswana" && !city1) {
            cities.push_back(0);
            city1 = true;
        }
        if (currentChildren.getCity() == "Francistown,Botswana" && !city2) {
            cities.push_back(1);
            city2 = true;
        }
        if (currentChildren.getCity() == "Gaborone,Botswana" && !city3) {
            cities.push_back(2);
            city3 = true;
        }
        if (currentChildren.getCity() == "Mahalapye,Botswana" && !city4) {
            cities.push_back(3);
            city4 = true;
        }
        if (currentChildren.getCity() == "Maun,Botswana" && !city5) {
            cities.push_back(4);
            city5 = true;
        }

    }
    return cities;


}

//TODO: based on the main road graph, this algorithm create the graph that contains only roads from letter DB
//TODO: it's like an adaptive graph , based on DB information
//TODO: maybe the difficult task that I faced for this project
//TODO: function that print cities order
void DijkstraShortestPath::printRoad() {
    vector<VPII> graph1;
    VPII a0 = {
            {1, 414},
            {2, 49},
            {3, 198},
            {4, 882}
    };
    graph1.push_back(a0);
    VPII a1 = {
            {0, 414},
            {2, 421},
            {3, 227},
            {4, 489}
    };
    graph1.push_back(a1);
    VPII a2 = {
            {0, 49},
            {1, 421},
            {3, 196},
            {4, 851}
    };
    graph1.push_back(a2);
    VPII a3 = {
            {1, 227},
            {2, 196},
            {0, 198},
            {4, 654}
    };
    graph1.push_back(a3);
    VPII a4 = {
            {0, 882},
            {1, 489},
            {2, 851},
            {3, 654}
    };
    graph1.push_back(a4);

    vector<int> points = DijkstraShortestPath::getCityNumber();

    sort(points.begin(), points.end());

    for (int i = 0; i < points.size(); i++) {
        for (auto pair:citiesPair) {
            if (pair.first == points[i]) {
                citiesNames.insert(std::pair<int, std::pair<int, string>>(i, pair));
            }
        }
    }
    vector<VPII> finalVector;
    vector<pair<int, int>> convertElement;
    for (int i = 0; i < points.size(); i++) {
        convertElement.emplace_back(i, points[i]);
    }
    for (int i = 0; i < points.size(); i++) {
        //  std::cout << points[i] << " ";
    }

    for (int currentPoint :points) {
        if (currentPoint == 0) {
            VPII a0_prim;
            for (int secondPoint:points) {
                if (secondPoint != currentPoint) {
                    for (auto connection:a0) {
                        if (connection.first == secondPoint) {
                            a0_prim.push_back(pair<int, unsigned long long>(connection.first, connection.second));
                        }
                    }
                }
            }
            if (!a0_prim.empty()) {
                finalVector.push_back(a0_prim);
            }
        }
        if (currentPoint == 1) {
            VPII a1_prim;
            for (int secondPoint:points) {
                if (secondPoint != currentPoint) {
                    for (auto connection:a1) {
                        if (connection.first == secondPoint) {
                            a1_prim.push_back(pair<int, unsigned long long>(connection.first, connection.second));

                        }
                    }
                }
            }
            if (!a1_prim.empty()) {
                finalVector.push_back(a1_prim);
            }
        }

        if (currentPoint == 2) {
            VPII a2_prim;
            for (int secondPoint:points) {
                if (secondPoint != currentPoint) {
                    for (auto connection:a2) {
                        if (connection.first == secondPoint) {
                            a2_prim.push_back(pair<int, unsigned long long>(connection.first, connection.second));

                        }
                    }
                }

            }
            if (!a2_prim.empty()) {
                finalVector.push_back(a2_prim);
            }
        }

        if (currentPoint == 3) {
            VPII a3_prim;
            for (int secondPoint:points) {
                if (secondPoint != currentPoint) {
                    for (auto connection:a3) {
                        if (connection.first == secondPoint) {
                            a3_prim.push_back(pair<int, unsigned long long>(connection.first, connection.second));
                        }
                    }
                }
            }
            if (!a3_prim.empty()) {
                finalVector.push_back(a3_prim);
            }
        }
        if (currentPoint == 4) {
            VPII a4_prim;
            for (int secondPoint:points) {
                if (secondPoint != currentPoint) {
                    for (auto connection:a4) {
                        if (connection.first == secondPoint) {
                            a4_prim.push_back(pair<int, unsigned long long>(connection.first, connection.second));
                        }
                    }
                }
            }
            if (!a4_prim.empty()) {
                finalVector.push_back(a4_prim);
            }
        }


    }

    vector<VPII> secondFinalVector;

    for (auto currentVPII:finalVector) {
        VPII finalEdge;
        for (int j = 0; j < currentVPII.size(); j++) {
            for (int i = 0; i < convertElement.size(); i++) {
                if (currentVPII[j].first == convertElement[i].second) {
                    pair<int, unsigned long long> convertedPair(convertElement[i].first, currentVPII[j].second);
                    finalEdge.push_back(convertedPair);
                }
            }
        }
        secondFinalVector.push_back(finalEdge);
    }
//    for (auto currentVPII:secondFinalVector) {
//        std::cout << "New Connection:\n";
//        for (auto currentPair:currentVPII) {
//            std::cout << currentPair.first << " " << currentPair.second << "\n";
//        }
//    }
    std::cout << "2. Second road which includes only current children's cities:\n";
    std::cout << "\n";
    std::cout << "Start from: Rovaniemi--->" << " " << citiesNames.find(0)->second.second;
    findTheRoad(secondFinalVector, 0, secondFinalVector.size());

}