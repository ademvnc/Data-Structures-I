/**
 * @file 152120191040_Q2.cpp
 * @brief Program to check if a linked list is a palindrome.
 * @details Given a linked list, the program checks if the linked list is a palindrome.
 *          A palindrome is a sequence that reads the same backward as forward.
 *          The program uses a stack to check if the linked list is a palindrome.
 *          It compares the elements of the first half with the reversed elements of the second half.
 *          The time complexity of the algorithm is O(n), where n is the length of the linked list.
 *          The space complexity of the algorithm is O(n), where n is the length of the linked list.
 *          The program contains a helper function to print a linked list.
 *          The program contains a main function to demonstrate the working of the algorithm.
 * @author ademvnc
 * @date 14/11/2023
 * @version 1.0
 * @note This program is written as an assignment Q2 WeekInClass7 for the Data Structures Lab 1.
 * 
 */


#include <iostream>
#include <stack>

// Linked List Node
struct Node {
    char data;
    Node* next;

    Node(char value) : data(value), next(nullptr) {}
};

/**
 * @brief Checks if a given linked list is a palindrome.
 * 
 * This function uses a stack to check if the linked list is a palindrome.
 * It compares the elements of the first half with the reversed elements of the second half.
 * 
 * @param head Head of the linked list.
 * @return True if the linked list is a palindrome, false otherwise.
 */
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a single node is a palindrome.
    }

    // Use a stack to store the elements of the first half of the linked list.
    std::stack<char> stack;
    Node* slow = head;
    Node* fast = head;

    // Push the elements of the first half onto the stack.
    while (fast != nullptr && fast->next != nullptr) {
        stack.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the length of the linked list is odd, skip the middle element.
    if (fast != nullptr) {
        slow = slow->next;
    }

    // Compare the elements of the second half with the elements popped from the stack.
    while (slow != nullptr) {
        if (slow->data != stack.top()) {
            return false; // Not a palindrome.
        }
        stack.pop();
        slow = slow->next;
    }

    return true; // Palindrome.
}

/**
 * @brief Helper function to print a linked list.
 * 
 * @param head Head of the linked list.
 */
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example 1: Palindrome Linked List
    Node* list1 = new Node('M');
    list1->next = new Node('A');
    list1->next->next = new Node('D');
    list1->next->next->next = new Node('A');
    list1->next->next->next->next = new Node('M');

    std::cout << "Linked List 1: ";
    printList(list1);

    if (isPalindrome(list1)) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Example 2: Non-Palindrome Linked List
    Node* list2 = new Node('H');
    list2->next = new Node('E');
    list2->next->next = new Node('L');
    list2->next->next->next = new Node('L');
    list2->next->next->next->next = new Node('O');

    std::cout << "\nLinked List 2: ";
    printList(list2);

    if (isPalindrome(list2)) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Example 3: Empty Linked List
    Node* list3 = nullptr;

    std::cout << "\nLinked List 3 (Empty): ";
    printList(list3);

    if (isPalindrome(list3)) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Example 4: Single-Node Linked List
    Node* list4 = new Node('X');

    std::cout << "\nLinked List 4 (Single Node): ";
    printList(list4);

    if (isPalindrome(list4)) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}
