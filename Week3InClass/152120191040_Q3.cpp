#include<iostream>

using namespace std;

//! Question 3
//! Program to find the factorial of a number using recursion and find complexity.
//! complexity: O(n)

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        
        return n * factorial(n - 1);
    }
}

int main() {
    
    int input_number;
    cout << "Input a number: ";
    cin >> input_number;

    int result_factorial = factorial(input_number);

    cout << "The Factorial of " << input_number << " is: " << result_factorial << endl;

   
    return 0;
}
