#include <iostream>
#include <queue>

using namespace std;

class QueueOperations {
private:
    queue<int> myQueue;

public:
    void Enqueue() {
        int item;
        cout << "Enqueue Operation\n";
        cout << "Enter an item to Enqueue in the Queue: ";
        cin >> item;
        myQueue.push(item);
        
    }

    void Dequeue() {
        if (!myQueue.empty()) {
            cout << "Dequeue Operation. Removed item: " << myQueue.front() << "\n";
            myQueue.pop();
        } else {
            cout << "Queue is Empty. Cannot dequeue.\n";
        }
    }

    void IsEmpty() {
        if (myQueue.empty()) {
            cout << "Queue is Empty\n";
        } else {
            cout << "Queue is not Empty\n";
        }
    }

    void IsFull() {
        cout << "Queue is not Full (using dynamic memory, it won't be full unless memory is exhausted)\n";
    }

    void Count() {
        cout << "Number of elements in the Queue: " << myQueue.size() << "\n";
    }

    void Display() {
        if (!myQueue.empty()) {
            cout << "Elements in the Queue: ";
            queue<int> tempQueue = myQueue;
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            cout << "\n";
        } else {
            cout << "Queue is Empty. Nothing to display.\n";
        }
    }
};

int main() {
    QueueOperations queueObj;

    int choice;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit.\n";
        cout << "1. Enqueue()\n";
        cout << "2. Dequeue()\n";
        cout << "3. IsEmpty()\n";
        cout << "4. IsFull()\n";
        cout << "5. Count()\n";
        cout << "6. Display()\n";
        cout << "7. Clear Screen\n";

        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting program.\n";
                break;
            case 1:
                queueObj.Enqueue();
                break;
            case 2:
                queueObj.Dequeue();
                break;
            case 3:
                queueObj.IsEmpty();
                break;
            case 4:
                queueObj.IsFull();
                break;
            case 5:
                queueObj.Count();
                break;
            case 6:
                queueObj.Display();
                break;
            case 7:
                system("clear"); // For Windows, use "cls"
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
