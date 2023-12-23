#include <iostream>
#include <vector>
#include "ThreadedBST.h"

using namespace std;

int Test1();
int Test2();
int Test3();
int Test4();
int Test5();
int Test6();
int Test7();

int main() {
	int grade = Test1();
	grade += Test3();
	grade += Test5();
	grade += Test6();
	grade += Test4();

	cout << "Your Grade is " << grade << endl;

	return 0;
} //end-main

///----------------------------------------------
/// Test 1
///
int Test1() {
	
	ThreadedBST bst;

	cout << "Test 1 entered" << endl;
	
	bst.add(10);
	bst.add(5);
	bst.add(15);
	bst.add(2);
	bst.add(7);
	bst.add(12);
	bst.add(6);

	// Check if the bst is set up correctly
	BSTNode* root = bst.getRoot();
	if (root->key != 10) return 0;

	BSTNode* p = root->left;
	if (p->key != 5) return 0;

	p = root->left->left;
	if (p->key != 2) return 0;
	if (p->left != NULL) return 0;
	if (p->right != root->left) return 0;

	p = root->left->right;
	if (p->key != 7) return 0;
	if (p->right != root) return 0;

	p = root->left->right->left;
	if (p->key != 6) return 0;
	if (p->left != root->left) return 0;
	if (p->right != root->left->right) return 0;

	p = root->right;
	if (p->key != 15) return 0;
	if (p->right != NULL) return 0;

	p = root->right->left;
	if (p->key != 12) return 0;
	if (p->left != root) return 0;
	if (p->right != root->right) return 0;

	// Forward walk
	vector<int> keys = { 2, 5, 6, 7, 10, 12, 15 };
	p = bst.min();
	for (auto key : keys) {
		if (p->key != key) return 0;
		p = bst.next(p);  // Go to the next node
	} //end-for
	if (p != NULL) return 0;

	// Backward walk
	p = bst.max();
	for (int i = keys.size() - 1; i >= 0; i--) {
		if (p->key != keys[i]) return 0;
		p = bst.previous(p);  // Go to the previous node
	} // end-for
	if (p != NULL) return 0;


	cout << "Test 1 passed" << endl;
	// OK. Passed all tests
	return 20;
} //end-Test1

///----------------------------------------------
/// Test 2
///
int Test2() {
	ThreadedBST bst;

	cout << "Test 2 entered" << endl;
	bst.add(10);
	bst.add(5);
	bst.add(15);
	bst.add(2);
	bst.add(7);
	bst.add(12);
	bst.add(6);

	// Delete two nodes
	bst.remove(7);
	bst.remove(15); 

	// Check if the bst is correct
	BSTNode* root = bst.getRoot();
	if (root->key != 10) return 0;

	BSTNode* p = root->left;
	if (p->key != 5) return 0;

	p = root->left->left;
	if (p->key != 2) return 0;
	if (p->left != NULL) return 0;
	if (p->right != root->left) return 0;

	p = root->left->right;
	if (p->key != 6) return 0;
	if (p->left != root->left) return 0;
	if (p->right != root) return 0;

	p = root->right;
	if (p->key != 12) return 0;
	if (p->left != root) return 0;
	if (p->right != NULL) return 0;

	// Forward walk
	vector<int> keys = { 2, 5, 6, 10, 12 };
	p = bst.min();
	for (auto key : keys) {
		if (p->key != key) return 0;
		p = bst.next(p);  // Go to the next node
	} //end-for
	if (p != NULL) return 0;

	// Backward walk
	p = bst.max();
	for (int i = keys.size() - 1; i >= 0; i--) {
		if (p->key != keys[i]) return 0;
		p = bst.previous(p);  // Go to the previous node
	} // end-for
	if (p != NULL) return 0;

	// OK. Passed all tests
	cout << "Test 2 passed" << endl;
	return 20;
} //end-Test2

int Test3() {
    ThreadedBST bst;

    cout << "Test 3 entered" << endl;

    // Eğitim amacıyla ThreadedBST sınıfınızı kullanarak yeni senaryolar ekleyin.
    bst.add(8);
    bst.add(3);
    bst.add(12);
    bst.add(1);
    bst.add(6);
    bst.add(10);
    bst.add(14);

    // Forward walk
    vector<int> keys = {1, 3, 6, 8, 10, 12, 14};
    BSTNode* p = bst.min();
    for (auto key : keys) {
        if (p->key != key) return 0;
        p = bst.next(p);  // Go to the next node
    }
    if (p != nullptr) return 0;

    // Backward walk
    p = bst.max();
    for (int i = keys.size() - 1; i >= 0; i--) {
        if (p->key != keys[i]) return 0;
        p = bst.previous(p);  // Go to the previous node
    }
    if (p != nullptr) return 0;

    cout << "Test 3 passed" << endl;
    // OK. Passed all tests
    return 20;
}




int Test4() {
    ThreadedBST bst;

    cout << "Test 4 entered" << endl;

    
    bst.add(10);
    bst.add(5);
    bst.add(14);
    bst.add(3);
    bst.add(8);
    bst.add(12);
    bst.add(16);


    BSTNode* minNode = bst.min();
    BSTNode* maxNode = bst.max();

    if (minNode->key != 3 || maxNode->key != 16) return 0;

    cout << "Test 4 passed" << endl;
    // OK. Passed all tests
    return 20;
}



int Test5() {
    ThreadedBST bst;

    cout << "Test 5 entered" << endl;

    
    bst.add(8);
    bst.add(3);
    bst.add(12);
    bst.add(1);
    bst.add(6);
    bst.add(10);
    bst.add(14);


    BSTNode* minNode = bst.min();
    BSTNode* maxNode = bst.max();

    if (minNode->key != 1 || maxNode->key != 14) return 0;

    cout << "Test 5 passed" << endl;
    // OK. Passed all tests
    return 20;
}


int Test6() {
    ThreadedBST bst;

    cout << "Test 6 entered" << endl;


    bst.add(8);
    bst.add(3);
    bst.add(12);
    bst.add(1);
    bst.add(6);
    bst.add(10);
    bst.add(14);

    
    BSTNode* node = bst.find(6);
    BSTNode* prevNode = bst.previous(node);
    BSTNode* nextNode = bst.next(node);

    if (prevNode->key != 3 || nextNode->key != 8) return 0;

    cout << "Test 6 passed" << endl;
    // OK. Passed all tests
    return 20;
}


// test-7 için yardımcı fonksiyon

int Test7() {
	ThreadedBST bst;

	cout << "Test 7 entered" << endl;

	bst.add(10);
	bst.add(5);
	bst.add(15);
	bst.add(2);
	bst.add(7);
	bst.add(12);
	