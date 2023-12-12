#include <stdio.h>
#include <iostream>
#include "Deque.h"

using namespace std;

int Test1();
int Test2();
int Test3(); // Add the new test
int Test4(); // Add the new test
int Test5(); // Add the new test


///--------------------------------------------------------------------
/// main function
///
int main() {
	int grade = 0;

	grade += Test1();
	grade += Test2();
	grade += Test3(); // Add the new test
	grade += Test4(); // Add the new test
	grade += Test5(); // Add the new test
	cout<< endl;

	printf("Your grade is: %d\n", grade);

	cout << endl;

	return 0;
} //end-main

///-------------------------------------------------------------------
/// Test1
///
int Test1() {
	try {
		Deque dq;

		dq.AddFront(10);
		dq.AddFront(20);

		if (dq.head->item != 20) return 0;
		if (dq.tail->item != 10) return 0;

		dq.AddFront(30);
		dq.AddFront(40);
		dq.AddRear(50);
		dq.AddRear(60);
		dq.AddRear(70);

		if (dq.Front() != 40) return 0;
		if (dq.Rear() != 70) return 0;
		if (dq.RemoveFront() != 40) return 0;
		if (dq.RemoveRear() != 70) return 0;

		if (dq.Front() != 30) return 0;
		if (dq.Rear() != 60) return 0;
		if (dq.RemoveFront() != 30) return 0;
		if (dq.RemoveRear() != 60) return 0;

		if (dq.Front() != 20) return 0;
		if (dq.Rear() != 50) return 0;
		if (dq.RemoveFront() != 20) return 0;
		if (dq.RemoveRear() != 50) return 0;

		if (dq.Front() != 10) return 0;
		if (dq.Rear() != 10) return 0;
		if (dq.RemoveFront() != 10) return 0;
		if (!dq.IsEmpty()) return 0;
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
	} //end-catch

	return 20;
} //end-Test1

///-------------------------------------------------------------------
/// Test2
///
int Test2() {
	try {
		Deque dq;

		int N = 100;
		for (int i = 1; i <= N; i++) dq.AddFront(i);

		// Walk forward
		DequeNode* p = dq.head;
		for (int i = N; i >= 1; i--) {
			if (p->item != i) return 0;
			p = p->next;
		} //end-for

		// Walk backwards
		p = dq.tail;
		for (int i = 1; i <= N; i++) {
			if (p->item != i) return 0;
			p = p->prev;
		} //end-for

		for (int i = 1; i <= N; i++) dq.AddRear(i);

		for (int i = N; i >= 1; i--) {
			if (dq.Front() != i) return 0;
			if (dq.RemoveFront() != i) return 0;
		} //end-for

		for (int i = N; i >= 1; i--) {
			if (dq.Rear() != i) return 0;
			if (dq.RemoveRear() != i) return 0;
		} //end-for

		if (!dq.IsEmpty()) return 0;
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
	} //end-catch

	return 20;
} //end-Test2

///-------------------------------------------------------------------
/// Test3
///
int Test3() {
	try {
		Deque dq;

		// Test Logic: Add elements to both front and rear, then check Front and Rear
		dq.AddFront(30);
		dq.AddRear(40);
		dq.AddFront(20);
		dq.AddRear(50);

		if (dq.Front() != 20) return 0;
		if (dq.Rear() != 50) return 0;

		// Modify the return statement based on the success criteria
		return 20;
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		return 0;
	} //end-catch
} //end-Test3

///-------------------------------------------------------------------
/// Test4
///
int Test4() {
    try {
        Deque dq;

        dq.AddFront(10);
        dq.AddFront(20);
        dq.AddRear(30);
        dq.AddRear(40);

        
        dq.RemoveFront();
        dq.RemoveRear();
        dq.AddFront(50);
        dq.AddRear(60);
        dq.AddFront(70);
       
        

        return 20; // Test başarılı olduysa 20 puan
    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() << endl;
        return 0;
    }
}

 //end-Test4

///-------------------------------------------------------------------
/// Test5
///
int Test5() {
	try {
		Deque dq;

		// Test Logic: Add a large number of elements and check if they are added and removed correctly
		int N = 1000;
		for (int i = 1; i <= N; i++) {
			dq.AddRear(i);
		}

		for (int i = 1; i <= N / 2; i++) {
			if (dq.RemoveFront() != i) return 0;
		}

		for (int i = N; i > N / 2; i--) {
			if (dq.RemoveRear() != i) return 0;
		}

		// Modify the return statement based on the success criteria
		return 20;
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		return 0;
	} //end-catch
} //end-Test5
