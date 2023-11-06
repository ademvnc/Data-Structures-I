#include <stdio.h>
#include <iostream>
#include <string>
#include "Poly.h"

using namespace std;
void separate(string str, int& expo, double& coef);
//-------------------------------------------------
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
//
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5
//
PolyNode *CreatePoly(char *expr){	//creates a new node and the given char values ​​are separated term by term

	PolyNode* head = NULL;

	int expo = 0, i = 0;
	double  coef = 0;
	string str;

	for (expr; *expr != '\0'; expr++, i++) {
		if (*expr == '-' || *expr == '+' || *(expr + 1) == '\0') { // stop conditions
			if (i == 0) {
				str += *expr;
				continue;
			}
			else//polynomial splits one by one
			{
				if (*(expr + 1) == '\0') str += *expr;
				separate(str, expo, coef);
				//cout << "float Coef = " << coef << endl;
				//cout << "int Expo = " << expo << endl;
				head = AddNode(head, coef, expo);
				str.clear();
			}
		}
		if (*expr != ' ')
			str += *expr; //append character until stop condition runs
	}

	return head;
} //end-CreatePoly

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* poly) {//filled nodes are deleted one by one to the end
	// Fill this in
	PolyNode* current = poly;
	PolyNode* next = NULL;

	while (current != NULL) {
		next = current->next;
		delete current;
		current = next;
	}
	poly = NULL;
	


} // end-DeletePoly
	
//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//
PolyNode* AddNode(PolyNode *head, double coef, int exp){
	// Fill this in
	
	PolyNode* check = head;

	while (check != NULL) { // checks same exponent and simplfy it
		if (check->exp == exp)
		{
			check->coef += coef;

			return head;
		}
		check = check->next;
	}

	PolyNode* node = new PolyNode(); // create a new node.
	node->coef = coef;
	node->exp = exp;
	node->next = NULL;

	
	PolyNode* q = NULL;
	PolyNode* p = head;

	while (p != NULL && exp<p->exp) { // walking to the end of the list
		q = p;
		p = p->next;
	}

	if (q == NULL) {
		node->next = head;
		head = node;
	}
	else {
		node->next = q->next;
		q->next = node;
	}



	return head;
	

} // end-AddNode

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode *Add(PolyNode *poly1, PolyNode *poly2){
	// Fill this in
	PolyNode* headNew = NULL;

	PolyNode* run1 = poly1;
	PolyNode* run2 = poly2;

	while (run1 != NULL) {
		headNew = AddNode(headNew, poly1->coef, poly1->exp);
		run1 = run1->next;
		poly1 = poly1->next;
	}
	while (run2 != NULL) {
		headNew = AddNode(headNew, poly2->coef, poly2->exp);
		run2 = run2->next;
		poly2 = poly2->next;
	}

	return headNew;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode *Subtract(PolyNode *poly1, PolyNode *poly2){
	// Fill this in

	PolyNode* head = NULL;

	PolyNode* run = poly2;

	while (run != NULL) {
		run->coef *= -1;
		run = run->next;
	}
	head = Add(poly1, poly2);
	run = poly2;
	while (run != NULL) {
		run->coef *= -1;
		run = run->next;
	}

	return head;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode *Multiply(PolyNode *poly1, PolyNode *poly2){
	// Fill this in
	PolyNode* head =NULL;
	PolyNode* run1 = poly1;
	PolyNode* run2 = poly2;

	while (run1 != NULL) {
		
		while (run2 != NULL) {
			head = AddNode(head, run1->coef * run2->coef, run1->exp + run2->exp);
			run2 = run2->next;
		}
		run2 = poly2;
		run1 = run1->next;
	}


	return head;
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode *poly, double x){
	// Fill this in
	float result = 0;
	PolyNode* p = poly;

	while (p != NULL) {
		result += pow(x, p->exp) * p->coef;
		p = p->next;
	}

	return result;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode *Derivative(PolyNode *poly){
	// Fill this in

	PolyNode* current = poly; 

	while (current != NULL) {
		if (current->exp == 0) {
			current->coef = 0;
			current->exp = 0;
		}
		else {
			current->coef *= current->exp;
			current->exp--;
		}
		
		
		current = current->next;
	}

	return poly;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode *poly, int x1, int x2){

	
	cout << "\n";
	for (int i = 12; i >= -12; i--)
	{
		
		for (int j = x1; j < x2; j++)
		{
			double result = Evaluate(poly, j);
			if (round(result) == i && result < 12 && result > -12)
			{
				cout << "*";
			}
			else
			{
				if (i == 0 && j == 0)
					cout << "+";
				else if (i == 0)
					cout << "-";
				else if (j == 0)
					cout << "|";
				else 
					cout << " ";
				
			}
		}
		cout << "\n";

    }
	// Fill this in	
} //end-Plot
void separate(string str, int& expo, double& coef) {

	string exPortion, coefPortion;
	int stop = 0;
	for (int i = 0; i < str.size(); i++) {

		if (stop == 0) {
			if (str[i] == 'x') {
				stop = 1;
			}
			else coefPortion += str[i];
		}
		else if (stop == 1) {
			if (str[i] != '^') {
				exPortion += str[i];
			}
		}
	}

	if (coefPortion.size() == 1 && (coefPortion == "-" || coefPortion == "+")) {
		coefPortion += '1';
		coef = stof(coefPortion);
	}
	else if (coefPortion.size() == 0) {
		coefPortion += '1';
		coef = stof(coefPortion);
	}
	else {
		coef = stof(coefPortion);
	}
	if (exPortion.size() == 0) {
		if (stop == 0) {
			exPortion += '0';
			expo = stoi(exPortion);
		}
		else {
			exPortion += '1';
			expo = stoi(exPortion);
		}

	}
	else
		expo = stoi(exPortion);


}