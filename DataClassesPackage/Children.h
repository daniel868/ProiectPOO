//
// Created by danit on 12/28/2020.
//

#ifndef FINALPROJECTPOO_CHILDREN_H
#define FINALPROJECTPOO_CHILDREN_H

#include "iostream"

using namespace std;

//TODO: main class for fetching the data from files
//TODO: contains all useful data for a children


class Children {
private:
    string name, surname, city;
    int age;
    bool isGood;
public:
    Children(const string &name, const string &surname, const string &city, int age);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const string &getCity() const;

    void setCity(const string &city);

    int getAge() const;

    void setAge(int age);

    bool isGood1() const;

    void setIsGood(bool isGood);

    Children();

    ~Children();
};


#endif //FINALPROJECTPOO_CHILDREN_H
