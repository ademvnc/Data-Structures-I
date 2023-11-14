/**
 * @file 152120191040_Q1_B.cpp
 * @brief Program to find the union of two sorted arrays.
 * @details Given two sorted arrays, the program finds the union of the two arrays.
 *          The union of two sets is a set containing all the elements of both the sets.
 *          The union of two arrays is an array containing all the elements of both the arrays.
 *          The union of two sorted arrays is also a sorted array.
 *          The program uses a simple algorithm to find the union of the two arrays.
 *          It compares the elements of the two arrays and adds the smaller element to the merged array.
 *          If the elements are equal, it adds the element to the merged array and moves both the arrays forward.
 *          If one of the arrays is empty, it adds the remaining elements of the other array to the merged array.
 *          The time complexity of the algorithm is O(n + m), where n and m are the lengths of the two arrays.
 * @author ademvnc 
 * @date 14/11/2023
 * @version 1.0
 * @note This program is written as an assignment Q1B WeekInClass7 for the Data Structures Lab 1.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Finds the ordered union of two arrays.
 * 
 * This function takes two arrays along with their sizes and finds the ordered union of these arrays.
 * The result is stored in the result array, and the size of the result array is returned.
 * 
 * @param A1 First array.
 * @param size1 Size of the first array.
 * @param A2 Second array.
 * @param size2 Size of the second array.
 * @param result Ordered union of the two arrays.
 * @return Size of the result array.
 */
int findOrderedUnion(const int A1[], int size1, const int A2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge arrays A1 and A2 into the result array
    while (i < size1 && j < size2) {
        if (A1[i] < A2[j]) {
            result[k++] = A1[i++];
        } else if (A2[j] < A1[i]) {
            result[k++] = A2[j++];
        } else {
            // Common element found
            result[k++] = A1[i++];
            j++;
        }
    }

    // Add remaining elements from A1
    while (i < size1) {
        result[k++] = A1[i++];
    }

    // Add remaining elements from A2
    while (j < size2) {
        result[k++] = A2[j++];
    }

    return k; // Size of the result array
}

/**
 * @brief Main function, contains example usage.
 * 
 * @return Program exit code.
 */
int main() {
    // Example usage
    int A1[] = {1, 3, 5};
    int size1 = sizeof(A1) / sizeof(A1[0]);

    int A2[] = {2, 4, 5};
    int size2 = sizeof(A2) / sizeof(A2[0]);

    int result[size1 + size2];

    int resultSize = findOrderedUnion(A1, size1, A2, size2, result);

    // Print the ordered union
    cout << "Ordered Union: ";
    for (int i = 0; i < resultSize; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
