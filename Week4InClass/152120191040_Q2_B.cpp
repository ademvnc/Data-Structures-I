/**
 * @file 152120191040_Q2_B.cpp
 * @brief This code implements the multiplication table of a number for a given range using iteration.
 * @details The code takes a number as input and displays its multiplication table up to a specified range using iteration.
 * @author ademvnc  
 * @date 24.10.2023
 * @version 1.0
 * @note this code is the assignment Week4InClass 2B of Veri Yapıları Lab 1 lecture.
 * 
 */

#include <iostream>
using namespace std;

int main() {
    //! Input: The integer for which the multiplication table needs to be displayed
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    //! Check for non-positive input
    if (number < 0) {
        cout << "Error: Please enter a non-negative integer for the multiplication table." << endl;
        return 1; //!Return a non-zero value to indicate an error
    }

    //! Input: The range up to which the multiplication table should be displayed
    int range;
    cout << "Enter range: ";
    cin >> range;

    //! Check for non-positive input
    if (range < 0) {
        cout << "Error: Please enter a non-negative range for the multiplication table." << endl;
        return 1; //!Return a non-zero value to indicate an error
    }

    //! Display multiplication table up to the specified range
    for (int i = 1; i <= range; ++i) {
        cout << number << " * " << i << " = " << (number * i) << endl;
    }

    return 0;
}
