#include<iostream>

using namespace std;

// Question 2.A
// Program to print first n natural numbers using recursion and find complexity.
//! complexity: O(n)

void printNaturalNumbers(int n) {
    if (n > 0) {
        // Recursive call
        printNaturalNumbers(n - 1);
        cout << n << " ";
    }
}

int main() {
    
    int n_natural_numbers = 50;

    cout << "The natural numbers are: ";
    printNaturalNumbers(n_natural_numbers);
    cout << endl;

    
    return 0;
}
