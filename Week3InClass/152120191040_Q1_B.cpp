#include<iostream>

//! Question 1.B
//! Program to determine the sum of first n consecutive positive integers
//! using while loop and find complexity.
//! Complexity: O(n)


int sumOfConsecutiveIntegers(int n) {
    int sum = 0;
    int i = 1;

    while (i <= n) {
        sum += i;
        ++i;
    }

    return sum;
}

int main() {
    int n;
    std::cout << "Enter the number of consecutive positive integers (starting from 1): ";
    std::cin >> n;

    int result = sumOfConsecutiveIntegers(n);

    std::cout << "The sum is: " << result << std::endl;


    return 0;
}
