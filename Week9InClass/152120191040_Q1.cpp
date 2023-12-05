#include <iostream>
#include <queue>
#include <string>


using namespace std;

class StackUsingQueue {
private:
    queue<int> q1, q2;

public:
    bool empty() {
        return q1.empty();
    }

    int size() {
        return q1.size();
    }

    int top() {
    if (empty()) {
        cout << "Stack is empty." << endl;
        return -1;  // Assuming -1 is used as an error indicator

        return q1.back(); // Return the back element of q1 (top of the stack)
    }

    

    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }

    int topElement = q1.front();

    // Move the element back to q1
    q2.push(topElement);

    // Swap q1 and q2 to maintain the original order
    swap(q1, q2);

    return topElement;
}

   void push(int element) {
    // Move all elements from q1 to q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    // Push the new element to q1
    q1.push(element);

    // Move back the elements from q2 to q1
    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
}


    void pop() {
        if (empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Remove the top element
        q1.pop();

        // Swap q1 and q2 to maintain the original order
        swap(q1, q2);
    }

    void display() {

         if (empty()) {
            cout << "Stack is empty. Cannot display." << endl;
            return;
        }
        queue<int> tempQ = q1;

        cout << "Stack elements from last to first: ";
        while (!tempQ.empty()) {
            cout << tempQ.front() << " ";
            tempQ.pop();

        }
        cout << endl;
    }
};

int main() {
    StackUsingQueue stack;
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        

  


        switch (choice) {
            case 1:

                cout << "Enter element to push: ";
                cin >> element;
                stack.push(element);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                cout << "Top element: " << stack.top() << endl;
                break;

            case 4:
                cout << "Size of stack: " << stack.size() << endl;
                break;

            case 5:
                stack.display();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
