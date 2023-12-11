#include <iostream>
#include "Deque.h"

using namespace std;

int Test1();
int Test2();
int Test3();
int Test4();
int Test5();
int Test6();

int main() {
    int grade = 0;

    grade += Test1();
    grade += Test2();
    grade += Test3();
    grade += Test4();
    grade += Test5();
    grade += Test6();

    cout << "Your grade is: " << grade << endl;

    return 0;
}

// Diğer test fonksiyonları...

int Test3() {
    try {
        Deque dq;

        // Test adding to the front and rear
        dq.AddFront(10);
        dq.AddRear(20);

        if (dq.Front() != 10 || dq.Rear() != 20 || dq.Size() != 2)
            return 0;

        // Test removing from the front and rear
        if (dq.RemoveFront() != 10 || dq.RemoveRear() != 20 || !dq.IsEmpty() || dq.Size() != 0)
            return 0;

        // Test adding and removing in alternating order
        dq.AddFront(30);
        dq.AddRear(40);
        dq.RemoveFront();
        dq.AddFront(50);
        dq.RemoveRear();

        if (dq.Front() != 50 || dq.Rear() != 30 || dq.Size() != 2)
            return 0;
    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 20;
}

int Test4() {
    try {
        Deque dq;

        // Test adding and removing a large number of elements
        int N = 1000;
        for (int i = 1; i <= N; i++)
            dq.AddFront(i);

        for (int i = 1; i <= N; i++) {
            if (dq.Front() != i || dq.RemoveFront() != i || dq.Size() != (N - i))
                return 0;
        }

        for (int i = 1; i <= N; i++)
            dq.AddRear(i);

        for (int i = 1; i <= N; i++) {
            if (dq.Rear() != i || dq.RemoveRear() != i || dq.Size() != (N - i))
                return 0;
        }

        if (!dq.IsEmpty() || dq.Size() != 0)
            return 0;
    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 20;
}

int Test5() {
    try {
        Deque dq;

        // Test removing from an empty deque
        dq.RemoveFront();
        dq.RemoveRear();

        // Test adding and removing to an empty deque
        dq.AddFront(10);
        if (dq.RemoveRear() != 10 || !dq.IsEmpty() || dq.Size() != 0)
            return 0;

        // Test adding and removing a single element
        dq.AddRear(20);
        if (dq.RemoveFront() != 20 || !dq.IsEmpty() || dq.Size() != 0)
            return 0;
    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 20;
}

int Test6() {
    try {
        Deque dq;

        // Test adding and removing elements, alternating between front and rear
        dq.AddFront(10);
        dq.AddRear(20);
        dq.RemoveFront();
        dq.AddFront(30);
        dq.RemoveRear();
        dq.AddRear(40);

        if (dq.Front() != 30 || dq.Rear() != 40 || dq.Size() != 2)
            return 0;
    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 20;
}
