// Copyright (c) 2023 Noah Smith All rights reserved.
//
// Created by: Noah Smith
// Date: Dec. 4th, 2023
// This program asks the user for two numbers
// and a sign (+, -, x, /, %)
// then displays the answer to the expression
#include <iostream>
#include <cmath>

float CalcResult(float num1, float num2, char sign) {
    // Return result to main
    if (sign == '+') {
        return num1 + num2;
    } else if (sign == '-') {
        return num1 - num2;
    } else if (sign == 'x') {
        return num1 * num2;
    } else if (sign == '/') {
        return num1 / num2;
    } else if (sign == '%') {
        // in C++, the modulus symbol might not work with floats
        // Programiz.com/cpp-programming/library-function/cmath/remainder
        return remainder(num1, num2);
    }
}

int main() {
    // Declare variables
    std::string userNum1Str, userNum2Str;
    float userNum1Float, userNum2Float;
    char userSign;

    // get numbers and sign from user
    std::cout << "Enter a number: ";
    std::cin >> userNum1Str;
    std::cout << "Enter a second number: ";
    std::cin >> userNum2Str;
    std::cout << "Enter one of the following signs (+, -, x, /, %): ";
    std::cin >> userSign;

    // Catch invalid input
    try {
        userNum1Float = std::stof(userNum1Str);
        try {
            userNum2Float = std::stof(userNum2Str);

            // If user tries to divide 0
            if (userNum1Float == 0 && userSign == '/') {
                std::cout << "0 / " << userNum2Float;
                std::cout << " is undefined." << std::endl;
            } else if (userSign != '+'
                       && userSign != '-'
                       && userSign != 'x'
                       && userSign != '/'
                       && userSign != '%') {
                // user entered an invalid sign
                std::cout << userSign << " is not a valid sign." << std::endl;
            } else {
                // Call function to find the answer
                float calculatedResult =
                CalcResult(userNum1Float, userNum2Float, userSign);

                // Display result
                std::cout << userNum1Float << " " << userSign;
                std::cout << " " << userNum2Float << " = ";
                std::cout << calculatedResult << std::endl;
            }
        } catch (std::exception) {
            std::cout << userNum2Str << " is not a float." << std::endl;
        }
    } catch (std::exception) {
        std::cout << userNum1Str << " is not a float." << std::endl;
    }
}
