/**
 * @file 152120191040_Q1_C.cpp
 * @brief Program to find the union of two sorted linked lists.
 * @details Given two sorted linked lists, the program finds the union of the two linked lists.
 *          The union of two sets is a set containing all the elements of both the sets.
 *          The union of two linked lists is a linked list containing all the elements of both the lists.
 *          The union of two sorted linked lists is also a sorted linked list.
 *          The program uses a simple algorithm to find the union of the two linked lists.
 *          It compares the elements of the two linked lists and adds the smaller element to the merged list.
 *          If the elements are equal, it adds the element to the merged list and moves both the linked lists forward.
 *          If one of the linked lists is empty, it adds the remaining elements of the other linked list to the merged list.
 *          The time complexity of the algorithm is O(n + m), where n and m are the lengths of the two linked lists.
 *          The space complexity of the algorithm is O(n + m), where n and m are the lengths of the two linked lists.
 *          The program contains a helper function to print a linked list.
 *          The program contains a main function to demonstrate the working of the algorithm.
 * @author ademvnc
 * @date 14/11/2023
 * @version 1.0
 * @note This program is written as an assignment Q1C WeekInClass7 for the Data Structures Lab 1.
 */

#include <iostream>
#include <vector>

/**
 * @brief Node struct, represents a node in a linked list.
 */
struct Node {
    int data; ///< Data value of the node.
    Node* next; ///< Pointer to the next node.

    /**
     * @brief Node constructor.
     * @param value Data value of the node.
     */
    Node(int value) : data(value), next(nullptr) {}
};

/**
 * @brief Finds the ordered union of two linked lists.
 * 
 * This function takes two linked lists and finds their ordered union.
 * The result is stored in a new linked list.
 * 
 * @param L1 First linked list.
 * @param L2 Second linked list.
 * @return Ordered union of the two linked lists.
 */
Node* findOrderedUnionLinkedList(Node* L1, Node* L2) {
    Node* result = nullptr; ///< Head of the merged list.
    Node* tail = nullptr;   ///< Tail of the merged list.

    // Merge linked lists L1 and L2 into the result linked list.
    while (L1 != nullptr && L2 != nullptr) {
        if (L1->data < L2->data) {
            if (result == nullptr) {
                result = tail = new Node(L1->data);
            } else {
                tail->next = new Node(L1->data);
                tail = tail->next;
            }
            L1 = L1->next;
        } else if (L2->data < L1->data) {
            if (result == nullptr) {
                result = tail = new Node(L2->data);
            } else {
                tail->next = new Node(L2->data);
                tail = tail->next;
            }
            L2 = L2->next;
        } else {
            // Common element found.
            if (result == nullptr) {
                result = tail = new Node(L1->data);
            } else {
                tail->next = new Node(L1->data);
                tail = tail->next;
            }
            L1 = L1->next;
            L2 = L2->next;
        }
    }

    // Add remaining elements from L1.
    while (L1 != nullptr) {
        tail->next = new Node(L1->data);
        tail = tail->next;
        L1 = L1->next;
    }

    // Add remaining elements from L2.
    while (L2 != nullptr) {
        tail->next = new Node(L2->data);
        tail = tail->next;
        L2 = L2->next;
    }

    return result;
}

/**
 * @brief Helper function to print a linked list.
 * 
 * @param head Head of the linked list.
 */
void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

/**
 * @brief Finds the ordered union of two arrays.
 * 
 * This function takes two arrays along with their sizes and finds their ordered union.
 * The result is stored in a new array.
 * 
 * @param A1 First array.
 * @param size1 Size of the first array.
 * @param A2 Second array.
 * @param size2 Size of the second array.
 * @param result Ordered union of the two arrays.
 * @return Size of the result array.
 */
int findOrderedUnionArray(const int A1[], int size1, const int A2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge arrays A1 and A2 into the result array.
    while (i < size1 && j < size2) {
        if (A1[i] < A2[j]) {
            result[k++] = A1[i++];
        } else if (A2[j] < A1[i]) {
            result[k++] = A2[j++];
        } else {
            result[k++] = A1[i++];
            j++;
        }
    }

    // Add remaining elements from A1.
    while (i < size1) {
        result[k++] = A1[i++];
    }

    // Add remaining elements from A2.
    while (j < size2) {
        result[k++] = A2[j++];
    }

    return k; // Size of the result array.
}

/**
 * @brief Helper function to print an array.
 * 
 * @param arr Array to be printed.
 * @param size Size of the array.
 */
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Main function, contains example usage.
 * 
 * @return Program exit code.
 */
int main() {
    // Linked List Example
    Node* LL1 = new Node(1);
    LL1->next = new Node(3);
    LL1->next->next = new Node(5);

    Node* LL2 = new Node(2);
    LL2->next = new Node(4);
    LL2->next->next = new Node(5);

    Node* resultLinkedList = findOrderedUnionLinkedList(LL1, LL2);
    std::cout << "Ordered Union (Linked List): ";
    printLinkedList(resultLinkedList);

    // Array Example
    int A1[] = {1, 3, 5};
    int size1 = sizeof(A1) / sizeof(A1[0]);

    int A2[] = {2, 4, 5};
    int size2 = sizeof(A2) / sizeof(A2[0]);

    int resultArray[size1 + size2];

    int resultSizeArray = findOrderedUnionArray(A1, size1, A2, size2, resultArray);
    std::cout << "Ordered Union (Array): ";
    printArray(resultArray, resultSizeArray);

    return 0;
}
