/**
 * @file 152120191040_Q1_A.cpp
 * @brief Program to find the union of two sorted linked lists.
 * @details Given two sorted linked lists, the program finds the union of the two lists.
 *          The union of two sets is a set containing all the elements of both the sets.
 *          The union of two linked lists is a linked list containing all the elements of both the lists.
 *          The union of two sorted linked lists is also a sorted linked list.
 *          The program uses a simple algorithm to find the union of the two lists.
 *          It compares the elements of the two lists and adds the smaller element to the merged list.
 *          If the elements are equal, it adds the element to the merged list and moves both the lists forward.
 *          If one of the lists is empty, it adds the remaining elements of the other list to the merged list.
 *          The time complexity of the algorithm is O(n + m), where n and m are the lengths of the two lists.
 *          The space complexity of the algorithm is O(n + m), where n and m are the lengths of the two lists.
 *          The program contains a helper function to print a linked list.
 *          The program contains a main function to demonstrate the working of the algorithm.
 * @author ademvnc
 * @date 14/11/2023
 * @version 1.0
 * @note This program is written as an assignment Q1A WeekInClass7 for the Data Structures Lab 1. 
 */


#include <iostream>
using namespace std;

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
 * @brief Merges two sorted linked lists into one.
 * 
 * @param L1 First linked list.
 * @param L2 Second linked list.
 * @return Merged linked list.
 */
Node* findOrderedUnion(Node* L1, Node* L2) {
    Node* result = nullptr; ///< Head of the merged list.
    Node* tail = nullptr;   ///< Tail of the merged list.

    // Compare elements of L1 and L2 to create the merged list.
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
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/**
 * @brief Main function, contains example usage.
 * 
 * @return Program exit code.
 */
int main() {
    // Example usage
    Node* L1 = new Node(1);
    L1->next = new Node(3);
    L1->next->next = new Node(5);

    Node* L2 = new Node(2);
    L2->next = new Node(4);
    L2->next->next = new Node(5);

    Node* result = findOrderedUnion(L1, L2);

    cout << "Ordered Union: ";
    printList(result);

    return 0;
}
