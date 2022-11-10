// Copyright (c) 2022 Immaculata HS All rights reserved.
//
// Created by: Joseph Kwon
// Created on: November 8 2022
// This program generates a random number from 0-9 and repeats
// the process of asking the user to guess that random
// number until the user gets it correct

#include <iostream>
#include <random>

int main() {
    // Declaring variables
    int userGuessInt, wait;
    std::string userGuessStr;

    // Assigning a random integer from 0-9 to secretNumber:
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    const int SECRET_NUMBER{idist(rgen)};

    /*Executes the body code once and then continues to loop if
    the user did not guess correctly*/
    do {
        // Gets the user's guess
        std::cout << "Enter an integer guess from 0 to 9: ";
        std::cin >> userGuessStr;

        // Tries casting the user's number to an integer
        try {
            userGuessInt = std::stoi(userGuessStr);

            // Tells the user to restart if they did not enter a number.
        } catch (const std::exception) {
            std::cout << "You must enter a positive integer.\n";
            std::cout << "Please try again.";
            std::cin >> wait;
        }

        // Breaks the loop if the user guessed correctly
        if (userGuessInt == SECRET_NUMBER) {
            break;

            /*Tells the user they guessed incorrectly. User is then
            asked for another guess*/
        } else {
            std::cout << "Incorrect. Try again.\n\n";
        }
    } while (userGuessInt != SECRET_NUMBER);

    // Message telling the user that they guessed correctly
    std::cout << "Correct!\n";
}
