#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
#include <string>

using namespace std;

bool isPalindrome(const string &input) {
    stack<char> charStack;
    queue<char> charQueue;

    // Küçük harfe çevirme ve gereksiz karakterleri atlama
    for (char ch : input) {
        if (isalnum(ch)) {  // Sadece alfanumerik karakterlere izin ver
            charStack.push(tolower(ch));
            charQueue.push(tolower(ch));
        }
    }

    // Stack ve Queue'dan çıkartarak kontrol etme
    while (!charStack.empty() && !charQueue.empty()) {
        if (charStack.top() != charQueue.front()) {
            return false;
        }
        charStack.pop();
        charQueue.pop();
    }

    return true;
}

int main() {
    string input;

    cout << "Bir ifade giriniz: " << endl;
    getline(cin, input);
    cout << endl;
    if (isPalindrome(input)) {
        cout << "Girdiginiz ifade bir palindromdur!" << endl;
    } else {
        cout << "Girdiginiz ifade palindrom degildir!" << endl;
    }
    cout << endl;
    return 0;
}
