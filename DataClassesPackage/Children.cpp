//
// Created by danit on 12/28/2020.
//

#include "Children.h"

const string &Children::getName() const {
    return name;
}

void Children::setName(const string &name) {
    Children::name = name;
}

const string &Children::getSurname() const {
    return surname;
}

void Children::setSurname(const string &surname) {
    Children::surname = surname;
}

const string &Children::getCity() const {
    return city;
}

void Children::setCity(const string &city) {
    Children::city = city;
}

int Children::getAge() const {
    return age;
}

void Children::setAge(int age) {
    Children::age = age;
}

bool Children::isGood1() const {
    return isGood;
}

void Children::setIsGood(bool isGood) {
    Children::isGood = isGood;
}

Children::Children(const string &name, const string &surname, const string &city, int age) : name(name),
                                                                                             surname(surname),
                                                                                             city(city), age(age) {}

Children::Children() {

}
