#include<iostream>

using namespace std;

//! Question 4
//! Program to print Fibonacci Series using recursion and find complexity.
//! complexity: O(2^n)

void fibonacciSeries(int n, int a = 0, int b = 1) {
    if (n > 0) {
        cout << a << " ";
        fibonacciSeries(n - 1, b, a + b);
    }
}

int main() {
    
    int num_terms;
    cout << "Enter the number of terms of series: ";
    cin >> num_terms;

    cout << "Fibonacci Series: ";
    fibonacciSeries(num_terms);
    cout << endl;

    
    return 0;
}
