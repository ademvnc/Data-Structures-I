#include<iostream>

using namespace std;

//! Question 1.C
//! Program to determine the sum of first n consecutive positive integers
//! using do-while loop and find complexity.
//! Complexity: O(n) 
 

int sumOfConsecutiveIntegersDoWhile(int n) {
    int sum = 0;
    int i = 1;

    do {
        sum += i;
        ++i;
    } while (i <= n);

    return sum;
}

int main() {
    
    int n_sum_do_while;
    cout << "Enter the number of consecutive positive integers (starting from 1) for sum calculation using do-while loop: ";
    cin >> n_sum_do_while;

    int result_sum_do_while = sumOfConsecutiveIntegersDoWhile(n_sum_do_while);

    cout << "The sum is: " << result_sum_do_while << endl;

    return 0;
}
