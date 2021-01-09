//
// Created by danit on 12/31/2020.
//

#include "Edge.h"

int Edge::compareTo(Edge o) {
    if (this->weight > o.weight) {
        return this->weight;
    } else {
        return o.weight;
    }
}
