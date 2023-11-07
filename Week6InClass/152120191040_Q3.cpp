/**
 * @file 152120191040_Q3.cpp
 * @brief This code checks whether a given string is a palindrome.
 * @details This code checks whether a given string is a palindrome. It ignores non-alphanumeric characters and is case-insensitive.
 * @author ademvnc
 * @date 07.11.2023
 * @version 1.0
 * @return Program exit status.
 * @note This code is the Week6InClass Q3 assignment for Data Structures Lab1 Fall 2023.
 */

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

/**
 * @brief Checks whether a given string is a palindrome.
 * @param str The string to be checked.
 * @return True if the string is a palindrome, false otherwise.
 */
bool isPalindrome(const string& str) {
    stack<char> charStack;
    int length = str.length();

    for (int i = 0; i < length; ++i) {
        if (isalnum(str[i])) { // Ignore non-alphanumeric characters
            charStack.push(tolower(str[i])); // Convert characters to lowercase for case-insensitive comparison
        }
    }

    // Compare the remaining characters with the stack
    for (int i = 0; i < length; ++i) {
        if (isalnum(str[i])) { // Ignore non-alphanumeric characters
            if (charStack.empty() || tolower(str[i]) != charStack.top()) {
                return false;
            }
            charStack.pop();
        }
    }

    return true;
}

int main() {
    // Test cases
    string test1 = "radar";
    string test2 = "Hello";
    string test3 = "A man a plan a canal Panama";
    string test4 = "dadsas" ;

    cout << "Is \"" << test1 << "\" a palindrome? " << (isPalindrome(test1) ? "Yes" : "No") << endl;
    cout << "Is \"" << test2 << "\" a palindrome? " << (isPalindrome(test2) ? "Yes" : "No") << endl;
    cout << "Is \"" << test3 << "\" a palindrome? " << (isPalindrome(test3) ? "Yes" : "No") << endl;
    cout << "Is \"" << test4 << "\" a palindrome? " << (isPalindrome(test4) ? "Yes" : "No") << endl;
    return 0;
}
