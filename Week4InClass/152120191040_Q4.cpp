/**
 * @file 152120191040_Q4.cpp
 * @brief This code implements a 2-dimensional integer array using dynamic memory allocation.
 * @details The code takes the number of rows and columns as input and creates a 2-dimensional integer array using dynamic memory allocation. The code then initializes the array with some values and prints the address information of the elements in the array. Finally, the code prints the total amount of memory used by the array and deallocates the memory.
 * @author ademvnc
 * @date 24.10.2023
 * @version 1.0
 * @note this code is the assignment Week4InClass 4 of Veri Yapıları Lab 1 lecture.
 * 
 */


#include <iostream>
using namespace std;
int main() {
    //!Get row and column information from the user
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    //!Define a 2-dimensional integer array
    int** array2D = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array2D[i] = new int[cols];
    }

    //!Initialize the array with some values
    int value = 100;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array2D[i][j] = value;
            value += sizeof(int);
        }
    }

    //!Print the address information of the elements in the array
    cout << "Address information of elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "&X[" << i << "][" << j << "] = " << reinterpret_cast<void*>(&array2D[i][j]) << endl;
        }
    }

    //!Print the total amount of memory used
    size_t totalMemory = rows * cols * sizeof(int);
    cout << "Total memory used: " << totalMemory << " bytes" << endl;

    //!Deallocate the memory
    for (int i = 0; i < rows; ++i) {
        delete[] array2D[i];
    }
    delete[] array2D;

    return 0;
}
