//
// Created by danit on 12/28/2020.
//

#include "Util.h"
#include "../MinimSpanningTree/Edge.h"

void Util::tokenize(string &str, char delim, vector<string> &out) {
    std::size_t start;
    std::size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

int Util::myComp(const void *a, const void *b) {
    Edge *a1 = (Edge *) a;
    Edge *b1 = (Edge *) b;
    return a1->weight > b1->weight;
}

bool Util::sortGiftPrice(Gift g1, Gift g2) {
    return g1.getGiftPrice() > g2.getGiftPrice();
}
