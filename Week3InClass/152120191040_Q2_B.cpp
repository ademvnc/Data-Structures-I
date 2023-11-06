#include<iostream>

using namespace std;

//! Question 2.B
//! Program to calculate the sum of numbers from 1 to n using recursion and find complexity.
//! complexity: O(n)

int sumOfNumbers(int n) {
    if (n == 0) {
        return 0;
    } else {
        
        return n + sumOfNumbers(n - 1);
    }
}

int main() {
    
    int n_sum_numbers;
    cout << "Enter the value of n to calculate the sum of numbers from 1 to n: ";
    cin >> n_sum_numbers;

    int result_sum_numbers = sumOfNumbers(n_sum_numbers);

    cout << "The sum of numbers from 1 to " << n_sum_numbers << ": " << result_sum_numbers << endl;

    
    return 0;
}
