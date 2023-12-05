#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStack {
private:
    stack<int> inputStack;
    stack<int> outputStack;

public:
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }

    int size() {
        return inputStack.size() + outputStack.size();
    }

    int front() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        if (!outputStack.empty()) {
            return outputStack.top();
        } else {
            cout << "Queue is empty.\n";
            return -1; // Assuming -1 as an error code for an empty queue
        }
    }

    void enqueue(int i) {
        inputStack.push(i);
    }

    void dequeue() {
    if (outputStack.empty()) {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

    if (!outputStack.empty()) {
        outputStack.pop(); // Only remove the front element from the output stack
    } else {
        cout << "Queue is empty. Cannot dequeue.\n";
    }
}


    void display() {
        stack<int> tempStack = outputStack;

        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }

        while (!inputStack.empty()) {
            cout << inputStack.top() << " ";
            inputStack.pop();
        }

        cout << "\n";
    }
};

int main() {
    QueueUsingStack myQueue;
    int choice, element;

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Empty\n";
        cout << "5. Size\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                myQueue.enqueue(element);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                cout << "Front element: " << myQueue.front() << "\n";
                break;
            case 4:
                if (myQueue.empty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Queue is not empty.\n";
                }
                break;
            case 5:
                cout << "Queue size: " << myQueue.size() << "\n";
                break;
            case 6:
                cout << "Queue elements: ";
                myQueue.display();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 7);

    return 0;
}
