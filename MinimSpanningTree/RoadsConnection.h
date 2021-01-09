//
// Created by danit on 1/2/2021.
//

#ifndef FINALPROJECTPOO_ROADSCONNECTION_H
#define FINALPROJECTPOO_ROADSCONNECTION_H

#include <vector>
#include "iostream"

using namespace std;

class RoadsConnection {
private:
    pair<string, int> from;
    pair<string, int> to;
public:
    RoadsConnection(const pair<string, int> &from, const pair<string, int> &to);

    static vector<RoadsConnection> getConnection();

    const pair<string, int> &getFrom() const;

    const pair<string, int> &getTo() const;
};


#endif //FINALPROJECTPOO_ROADSCONNECTION_H
