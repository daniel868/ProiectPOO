//
// Created by danit on 1/9/2021.
//

#include "MainUI.h"
#include "ElfUI.h"
#include "../DataClassesPackage/Letter.h"
#include "../Databases/LetterDB/LetterDatabase.h"

void MainUI::startProgram() {
    int counterDigit;
    ElfUI elfUi;

    std::cout << "Welcome to Santa's workshop:\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Choose one option by typing the number:\n";
    showOption();
    while (counterDigit != 0) {
        try {
            cin >> counterDigit;
            if (counterDigit != 0 && counterDigit != 1 && counterDigit != 2 && counterDigit != 3 && counterDigit != 4 &&
                counterDigit != 5) {
                throw "Pick a digit between 0-4:\n";
            }
            if (counterDigit == 1) {
                elfUi.insertNewChild();
                showOption();
            } else if (counterDigit == 2) {
                elfUi.showAllLetters();
                showOption();
            } else if (counterDigit == 3) {
                elfUi.showFinalResult();
                showOption();
            } else if (counterDigit == 4) {
                readMe();
                showOption();
            } else if (counterDigit == 5) {
                elfUi.showAllLetters();
                deleteLetter();
                showOption();
            }

        } catch (const char *err) {
            std::cout << err << "\n";
        }

    }

}

void MainUI::showOption() {
    std::cout << "1. Insert new child and letter:\n";
    std::cout << "2. Check Letter Database:\n";
    std::cout << "3. Creates the final Santa's report based on children you inserted:\n";
    std::cout << "4. Read me:\n";
    std::cout << "5. Delete letter:\n";
    std::cout << "0. Exit program:\n";
    std::cout << "Pick an option:\n";
}

void MainUI::readMe() {
    std::cout << "\t-Option 1: Insert a new children with letter in Santa's database:\n";
    std::cout << "\t-Option 2: See all letters which are in the database:\n";
    std::cout << "\t-Option 3: Based on database letters, create Santa's request:\n";
    std::cout << "\t-Option 5: Delete a letter from Santa's database:\n";
    std::cout << "\t-Option 0: Close the program:\n";
}

void MainUI::deleteLetter() {
    int letterId;
    LetterDatabase letterDatabase;
    vector<Letter> allLetters = letterDatabase.GetAllLetters();
    std::cout << "Type letter ID in order to delete:\n";
    std::cin >> letterId;
    try {
        if (letterId < 1 || letterId > allLetters.size() ) {
            throw "Wrong letter Id:\n";
        }
        letterDatabase.DeleteLetterToDB(letterId-1);
        std::cout << "Letter deleted:\n";

    } catch (const char *err) {
        std::cout << err;
    }
}
