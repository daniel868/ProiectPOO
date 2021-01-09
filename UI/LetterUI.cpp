//
// Created by danit on 12/28/2020.
//

#include "LetterUI.h"
#include "../Databases/GiftStoreData.h"
#include "../Databases/Cities/CitiesData.h"

class CityUI {
private:

public:
    int chooseCountryNumber();

    string cityName();
};

int CityUI::chooseCountryNumber() {
    int countryNumber;
    std::cout << "Children city:\n";
    std::cout << "Pick a country from the list. Type country's number:\n";
    CitiesData::printCountryList();
    cin >> countryNumber;
    return countryNumber;
}

string CityUI::cityName() {
    string city = "default_city";
    int cityId;
    int countryId = chooseCountryNumber();
    switch (countryId) {
        case 1: {
            CitiesData::printBotswanaCities();
            std::cout << "Select a city from the list.Type country's number:\n";
            cin >> cityId;
            city = CitiesData::FinlandToStartCities()[cityId - 1].getName();
            return city;
            break;
        }
        default:
            return city;
    }
}

Children LetterUI::setChildrenData() {
    CityUI cityUi;
    string childrenName, childrenSurname, status, city;
    int childrenAge;
    bool isGood;
    std::cout << "Children name:\n";
    std::cin >> childrenName;
    std::cout << "Children Surname:\n";
    std::cin >> childrenSurname;
    std::cout << "Children age:\n";
    std::cin >> childrenAge;

    city = cityUi.cityName();

    std::cout << "Good/bad children:Type bad/good :\n";
    std::cin >> status;
    if (status == "bad" || status == "Bad") {
        isGood = false;
    }
    if (status == "good" || status == "Good") {
        isGood = true;
    }
    Children children(childrenName, childrenSurname, city, childrenAge);
    children.setIsGood(isGood);
    return children;
}

Wishlist LetterUI::setWishListData(Children children) {
    int counter = -1;
    Wishlist wishlist;
    wishlist.setChildrenName(children.getName());
    wishlist.setChildrenSurname(children.getSurname());
    vector<Gift> giftList;
    std::cout << "Pick gift/gifts\n";


    vector<Gift>::iterator itr;
    while (counter != 0) {
        std::cout << "Pick a gift from the list:\n";

        for (int i = 0; i < GiftStoreData::getStoreList().size(); i++) {
            std::cout << i + 1 << "\t" << GiftStoreData::getStoreList()[i].getGiftName() << "\t"
                      << GiftStoreData::getStoreList()[i].getGiftPrice() << "\n";
        }
        std::cout << "Select a gift number to add in your wishList:\n";
        std::cin >> counter;
        giftList.push_back(GiftStoreData::getStoreList()[counter - 1]);
        std::cout << "Gift added to your wishList:\n";
        std::cout << "For add more gift, type -1 \t For exit, type 0:\n";
        std::cin >> counter;
    }
    wishlist.setGiftList(giftList);
    return wishlist;
}

Letter LetterUI::setLetterData(Children children, Wishlist wishlist) {
    string color;
    std::cout << "Letter color(Pink/Blue):\n";
    cin >> color;

    return Letter(children.getName(), children.getSurname(), children.getCity(), children.getAge(),
                  color, wishlist);
}



