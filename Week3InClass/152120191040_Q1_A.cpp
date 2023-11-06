#include<iostream>

//! Question 1.A
//! Program to display a countdown using for loop and find complexity.
//! Complexity: O(n)

void countdown(int n) {
    for (int i = n; i >= 0; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the n: ";
    std::cin >> n;

    countdown(n);

    return 0;
}
