//
// Created by danit on 12/28/2020.
//

#include "LetterUI.h"
#include "../Databases/GiftStoreData.h"
#include "../Databases/Cities/CitiesData.h"

//TODO: UI for pick child and letter data

class CityUI {
private:

public:
    int chooseCountryNumber();

    string cityName();
};

//TODO: UI Choose country Number
int CityUI::chooseCountryNumber() {
    int countryNumber;
    std::cout << "Children city:\n";
    std::cout << "Pick a country from the list. Type country's number:\n";
    CitiesData::printCountryList();
    int flag = 0;
    while (flag == 0) {
        try {
            cin >> countryNumber;
            if (countryNumber != 1) {
                throw "Only one city available. Type 1:\n";
            }
            flag = 1;
        } catch (const char *err) {
            std::cout << err;
        }
    }
    return countryNumber;
}

//TODO: UI select child's city
string CityUI::cityName() {
    string city = "default_city";
    int cityId;
    int countryId = chooseCountryNumber();
    switch (countryId) {
        case 1: {
            CitiesData::printBotswanaCities();
            std::cout << "Select a city from the list.Type country's number:\n";
            bool flag = false;
            while (!flag) {
                try {
                    cin >> cityId;
                    if (cityId != 1 && cityId != 2 && cityId != 3 && cityId != 4 && cityId != 5) {
                        throw "Invalid city number.Pick one between 1-5\n";
                    }
                    flag = true;
                } catch (const char *err) {
                    std::cout << err;
                }
            }
            city = CitiesData::FinlandToStartCities()[cityId - 1].getName();
            return city;
            break;
        }
        default:
            return city;
    }
}

//TODO: UI for child information
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

//TODO: UI for pick gifts for wishList
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
        if (counter < 0 || counter > GiftStoreData::getStoreList().size()) {
            std::cout << "Type a number between 0 and " << GiftStoreData::getStoreList().size()<< "\n";
        } else {
            giftList.push_back(GiftStoreData::getStoreList()[counter - 1]);
            std::cout << "Gift added to your wishList:\n";
            std::cout << "For add more gift, type -1 \t For exit, type 0:\n";
            std::cin >> counter;
        }
    }
    wishlist.setGiftList(giftList);
    return wishlist;
}

//TODO: generate final letter based on input data
Letter LetterUI::setLetterData(Children children, Wishlist wishlist) {
    string color;
    std::cout << "Letter color(Pink/Blue):\n";
    cin >> color;

    return Letter(children.getName(), children.getSurname(), children.getCity(), children.getAge(),
                  color, wishlist);
}



