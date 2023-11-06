/**
 * @file 152120191040_Q1.cpp
 * @brief Main function to demonstrate vector operations.
 * @details This function demonstrates the use of vector operations.
 * It creates a vector, updates it, displays its elements, reverses the order,
 * removes the last element, and displays the updated vector.
 * @return Returns 0 on successful execution.
 * @author ademvnc
 * @date 31.10.2023
 * @version 1.0
 * @note this code is the assignment Week5InClass Q1 of Veri Yapıları Lab 1 lecture.
 */

#include <iostream>
#include <vector>
using namespace std;


int main() {
    //! Create a vector with initial elements
    vector<int> myVector = {0, 1, 2, 3, 4};
    cout << endl;

    //! Display the size and elements of the vector
    cout << "Size of vector is: " << myVector.size() << endl;
    cout << "Vector elements are given below: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;

    //! Update the vector by adding an element at the beginning
    myVector.insert(myVector.begin(), 20);

    //! Display the updated vector
    cout << "Size of vector is: " << myVector.size() << endl;
    cout << "Updated Vector elements are given below: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    //! Display the vector in reverse order using iterator
    cout << "Output of reverse array: ";
    for (auto it = myVector.rbegin(); it != myVector.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //! Remove the last element from the vector
    myVector.pop_back();

    //! Display the vector after removing the last element
    cout << "Output after removing last array element: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;


    return 0;
}
