/**
 * @file 152120191040_Q2_A.cpp
 * @brief This code implements the multiplication table of a number using iteration.
 * @details The code takes a number as input and displays its multiplication table up to 10 using iteration.
 * @author ademvnc
 * @date 24.10.2023
 * @version 1.0
 * @note this code is the assignment Week4InClass 2A of Veri Yapıları Lab 1 lecture.
 */

#include <iostream>
using namespace std;

int main() {
    //! Input: The integer for which the multiplication table needs to be displayed
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    //! Check for non-positive input
    if (number <= 0) {
        cerr << "Error: Please enter a positive integer for the multiplication table." << endl;
        return 1; //!Return an error
    }

    //! Display multiplication table up to 10
    for (int i = 1; i <= 10; ++i) {
        cout << number << " * " << i << " = " << (number * i) << endl;
    }

    return 0;
}
