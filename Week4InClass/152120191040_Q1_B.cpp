/**
 * @file 152120191040_Q1_B.cpp
 * @brief This code implements the factorial of a number using iteration.
 * @details The code takes a number as input and calculates its factorial using iteration.
 * @author ademvnc
 * @date 24.10.2023
 * @version 1.0
 * @note this code is the assingment Week4InClass 1A of Veri Yapıları Lab 1 lecture.
 */

#include <iostream>
using namespace std;

//!Function to calculate factorial using iteration
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    //!Input: The number for which factorial needs to be calculated
    int number;
    cout << "Enter a number: ";
    cin >> number;

    //!Check for non-negative input
    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        //!Calculate factorial using the iterative function
        int result = factorial(number);

        //!Output the result
        cout << "Factorial of " << number << " using Iteration is: " << result << endl;
    }

    return 0;
}
