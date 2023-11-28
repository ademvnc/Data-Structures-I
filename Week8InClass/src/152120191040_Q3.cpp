#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
#include <string>

using namespace std;

// Function to sort the elements in the queue
void sortQueue(queue<int> &q) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap kullanarak sıralama

    // Queue'daki elemanları min heap'e ekleme
    while (!q.empty()) {
        minHeap.push(q.front());
        q.pop();
    }

    // Min heap'den elemanları çekip queue'ye ekme
    while (!minHeap.empty()) {
        q.push(minHeap.top());
        minHeap.pop();
    }
}

// Function to display the elements in the queue
void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int size;

    cout << "Please enter the number of elements: ";
    cin >> size;

    queue<int> myQueue;

    cout << "Please enter elements in the queue:\n";
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        myQueue.push(element);
    }

    cout << "Original Queue\n";
    displayQueue(myQueue);

    // Sort the elements in the queue
    sortQueue(myQueue);

    cout << "Sorted Queue\n";
    displayQueue(myQueue);

    return 0;
}
