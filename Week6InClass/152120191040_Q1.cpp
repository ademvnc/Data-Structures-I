/**
 * @file 152120191040_Q1.cpp
 * @brief This code implements a stack using STL stack container.
 * @details This code creates a stack, adds elements to it, prints the elements from first in to last in and from last in to first in, deletes the last two elements, and prints the remaining elements from last in to first in.
 * @author ademvnc
 * @date 07.11.2023
 * @version 1.0
 * @return Program exit status.
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Sorts a stack in ascending order using another stack.
 * @param inputStack The stack to be sorted.
 */
void sortStack(stack<int>& inputStack) {
    stack<int> tempStack;

    while (!inputStack.empty()) {
        //!Pop the top element from the original stack
        int temp = inputStack.top();
        inputStack.pop();

        //!Move elements from the temporary stack to the original stack
        while (!tempStack.empty() && tempStack.top() > temp) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        //!Push the current element onto the temporary stack
        tempStack.push(temp);
    }

    //!Move elements back from the temporary stack to the original stack
    while (!tempStack.empty()) {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    //!Create a stack
    stack<int> myStack;

    //!Check the initial state of the stack
    cout << "Check stack initial state: " << (myStack.empty() ? "empty" : "not empty") << endl;

    //!Add elements to the stack
    cout << "Add elements to stack: ";
    myStack.push(21);
    cout << "21 ";
    myStack.push(22);
    cout << "- 22 ";
    myStack.push(24);
    cout << "- 24 ";
    myStack.push(25);
    cout << "- 25" << endl;

    //!Print the stack elements from first in to last in
    cout << "Show stack element (print first in to last in): ";
    stack<int> tempStack; // Create a temporary stack to print elements without modifying the original stack
    while (!myStack.empty()) {
        tempStack.push(myStack.top()); // Store elements in a temporary stack to reverse the order
        myStack.pop();
    }

    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        myStack.push(tempStack.top()); // Restore the elements to the original stack
        tempStack.pop();
    }
    cout << endl;

    //!Print the stack elements from last in to first in
    cout << "Show stack element (print last in to first in): ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    //!Delete the last two elements from the stack, then print the stack elements from last in to first in
    myStack.push(21);
    myStack.push(22);
    myStack.push(24);
    myStack.push(25);
    myStack.pop(); //!Remove the last element
    myStack.pop(); //!Remove one more element

    cout << "Delete last two elements from stack then show stack elements (print last in to first in): ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
