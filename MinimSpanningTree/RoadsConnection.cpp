//
// Created by danit on 1/2/2021.
//

#include "RoadsConnection.h"

RoadsConnection::RoadsConnection(const pair<string, int> &from, const pair<string, int> &to) : from(from), to(to) {

}

vector<RoadsConnection> RoadsConnection::getConnection() {
    vector<RoadsConnection> roadConnection;
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Molepolole,Botswana", 0), pair<string, int>("Francistown,Botswana", 1)));
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Molepolole,Botswana", 0), pair<string, int>("Gaborone,Botswana", 2)));
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Molepolole,Botswana", 0), pair<string, int>("Mahalapye,Botswana", 3)));
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Francistown,Botswana", 1), pair<string, int>("Gaborone,Botswana", 2)));
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Francistown,Botswana", 1), pair<string, int>("Mahalapye,Botswana", 3)));
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Gaborone,Botswana", 2), pair<string, int>("Mahalapye,Botswana", 3)));


    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Francistown,Botswana", 1), pair<string, int>("Molepolole,Botswana", 0)));
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Gaborone,Botswana", 2), pair<string, int>("Molepolole,Botswana", 0)));
    roadConnection.emplace_back(
            RoadsConnection(pair<string, int>("Mahalapye,Botswana", 3), pair<string, int>("Molepolole,Botswana", 0)));

    return roadConnection;
}

const pair<string, int> &RoadsConnection::getFrom() const {
    return from;
}

const pair<string, int> &RoadsConnection::getTo() const {
    return to;
}
