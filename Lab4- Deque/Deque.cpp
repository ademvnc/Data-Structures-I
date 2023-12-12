#include "Deque.h"
#include <stdexcept>
///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	 // Initialize an empty deque
    head = tail = NULL;
    noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	 // Delete all nodes in the deque
    while (head != NULL) {
        DequeNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    noOfItems = 0;
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	  DequeNode* newNode = new DequeNode(item);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    noOfItems++;
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	 DequeNode* newNode = new DequeNode(item);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    noOfItems++;
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }

    int frontItem = head->item;
    DequeNode* temp = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    delete temp;
    noOfItems--;
    return frontItem;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
    if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }

    int rearItem = tail->item;
    DequeNode* temp = tail;

    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
    }

    delete temp;
    noOfItems--;
    return rearItem;
}


 //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }

    return head->item;
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	 if (IsEmpty()) {
        throw std::out_of_range("Deque is empty");
    }

    return tail->item;
} //end-Rear
