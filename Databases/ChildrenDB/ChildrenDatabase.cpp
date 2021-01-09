//
// Created by danit on 12/28/2020.
//

#include "ChildrenDatabase.h"
#include "../../Utils/Util.h"

void ChildrenDatabase::InsertChildren(Children children) {
    int count = 0;
    ifstream MyChildDatabase_in;
    MyChildDatabase_in.open(ChildrenDatabaseName, ios::in);
    string line;
    while (getline(MyChildDatabase_in, line)) {
        count++;
    }
    MyChildDatabase_in.close();

    ofstream MyChildDatabase;
    MyChildDatabase.open(ChildrenDatabaseName, ios_base::app);
    MyChildDatabase << count << " " << children.getName() << " " << children.getSurname() << " " << children.getAge()
                    << " "
                    << children.getCity() << " " << children.isGood1() << "\n";
    MyChildDatabase.close();
}

void ChildrenDatabase::DeleteChildren(Children children) {

}

vector<Children> ChildrenDatabase::GetAllChildren() {
    vector<Children> children;

    ifstream MyChildDatabase_in;
    MyChildDatabase_in.open(ChildrenDatabaseName, ios::in);
    string line;
    while (getline(MyChildDatabase_in, line)) {
        vector<string> stringOut;
        Util::tokenize(line, ' ', stringOut);

        Children child;
        child.setName(stringOut[1]);
        child.setSurname(stringOut[2]);
        child.setAge(stoi(stringOut[3], nullptr, 10));
        child.setCity(stringOut[4]);
        child.setIsGood(stoi(stringOut[5], nullptr, 10));

        children.emplace_back(child);
    }
    MyChildDatabase_in.close();
    return children;
}

bool ChildrenDatabase::checkChildrenData(Children children) {
    bool isSafe = true;
    try {
        if (children.getName().size() == 0) {
            isSafe = false;
            throw "Child name problems:\n";
        }
    } catch (const char *err) {
        std::cout << err << "\n";
    }
    try {
        if (children.getSurname().size() == 0) {
            isSafe = false;
            throw "Child surname problems:\n";
        }
    } catch (const char *err) {
        std::cout << err << "\n";
    }
    try {
        if (children.getCity().size() == 0) {
            isSafe = false;
            throw "Child city problems:\n";
        }
    } catch (const char *err) {
        std::cout << err << "\n";
    }
    try {
        if (children.getAge() <= 0) {
            isSafe = false;
            throw "Child age problems:\n";
        }
    } catch (const char *err) {
        std::cout << err << "\n";
    }
    return isSafe;
}
