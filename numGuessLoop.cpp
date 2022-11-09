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
    // initializing variables
    int secretNumber, userGuess;

    int guess;

    // assigning a random integer from 0-9 to secretNumber
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    secretNumber = idist(rgen);

    // Asking for user's guess
    std::cout << "The secret number is between 0-9 \n";
    std::cout << "Enter your guess \n\n >> ";
    std::cin >> userGuess;
    std::cout << "\n"
              << std ::endl;

            // If userGuess us not within the 0-9 range
            if (userGuess < 0 && userGuess < 9) {
                    std::cout << "Your guess has to be between 0-9";
                } else {
                    // If userGuess matches secretNumber, tell
                    // the user the results and end using break
                    while (userGuess == secretNumber) {
                        std::cout << "Correct Guess!!!";
                        break;
                    }

                    // If that is not the case, loop and
                    // re-ask the question until correct
                    if (userGuess != secretNumber) {
                        std::cout << "Incorrect Guess\n";
                        return main();
                    }
                }
}
