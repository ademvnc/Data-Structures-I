/**
 * @file 152120191040_Q2.cpp
 * @brief Main function to demonstrate vector operations.
 * @details This function demonstrates the use of vector operations.
 * It creates a vector, updates it, displays its elements, reverses the order,
 * removes the last element, and displays the updated vector.
 * @param vec The vector to be sorted.
 * @return Returns 0 on successful execution.
 * @author ademvnc
 * @date 31.10.2023
 * @version 1.0
 * @note this code is the assignment Week5InClass Q2 of Veri Yapıları Lab 1 lecture.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Perform Bubble Sort on a vector.
 * @param vec The vector to be sorted.
 */
void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                //!Swap elements if they are in the wrong order
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

/**
 * @brief Perform Insertion Sort on a vector.
 * @param vec The vector to be sorted.
 */
void insertionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;

        //!Move elements of vec[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

int main() {
    //!Create a vector with initial elements
    vector<int> myVector = {20, 15, 5, 10, 1};

    //!Display the size and elements of the vector
    cout << "Size of vector is: " << myVector.size() << endl;
    cout << "Vector elements are given below: ";
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;
    
    //! Perform insertion at the beginning
    int value;
    cout << "Enter the value for insertion: ";
    cin >> value;
    myVector.insert(myVector.begin(), value);
    cout << "Added to begin of the array" << endl;
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    //! Perform insertion at the end
    cout << "Enter the value for insertion: ";
    cin >> value;
    myVector.push_back(value);
    cout << "Added to end of the array" << endl;
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    //! Bubble Sort
    cout << "Bubble sort ..." << endl;
    bubbleSort(myVector);
    cout << "Sorted Element List ..." << endl;
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    //! Insertion Sort
    cout << "Insertion sort ..." << endl;
    insertionSort(myVector);
    cout << "Sorted Element List ..." << endl;
    for (int element : myVector) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
