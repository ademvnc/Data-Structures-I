/**
 * @file 152120191040_Q2.cpp
 * @brief Sorts a stack in ascending order using another stack.
 * @details This function sorts a stack in ascending order using another stack.
 * @param inputStack The stack to be sorted.
 * @author  ademvnc
 * @date 07.11.2023
 * @version 1.0
 * @return void
 * @note This code is the Week6InClass Q2 assignment for Data Structures Lab1 Fall 2023.
 */


#include <iostream>
#include <stack>

using namespace std;


void sortStack(stack<int>& inputStack) {
    stack<int> tempStack;

    //!Iterate through each element in the original stack
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

/**
 * @brief Main function to demonstrate sorting a stack.
 * @return Program exit status.
 */
int main() {
    //!Create a stack
    stack<int> myStack;

    //!Add elements to the stack
    myStack.push(34);
    myStack.push(3);
    myStack.push(31);
    myStack.push(98);
    myStack.push(92);
    myStack.push(23);

    //!Display the original stack
    cout << "Original Stack: ";
    stack<int> tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    //!Sort the stack
    sortStack(myStack);

    //!Display the sorted stack
    cout << "Sorted Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
