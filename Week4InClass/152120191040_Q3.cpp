
#include <iostream>
#include <vector>
#include <list>
using namespace std;
template <typename T>
void showRepresentation(const T& container, const string& name) {
    cout << "Representation for " << name << endl;

    //!Display data and addresses
    int index = 0;
    for (const auto& element : container) {
        cout << "&" << name << "[" << index << "] = " << static_cast<const void*>(&element) << endl;
        index++;
    }

    cout << endl;
}

int main() {
    int n;

    //!Get user input for n
    cout << "Enter the value of n: ";
    cin >> n;

    //!ArrayList for contiguous allocation (int)
    vector<int> intArrayList;
    for (int i = 0; i <= n; i++) {
        intArrayList.push_back(i);
    }
    //!Show ArrayList representation (int)
    showRepresentation(intArrayList, "IntArray");

    //!LinkedList for non-contiguous allocation (int)
    list<int> intLinkedList;
    for (int i = 0; i <= n; i++) {
        intLinkedList.push_back(i);
    }
    //!Show LinkedList representation (int)
    showRepresentation(intLinkedList, "IntList");

    //!ArrayList for contiguous allocation (double)
    vector<double> doubleArrayList;
    for (double i = 0.0; i <= n; i += 0.5) {
        doubleArrayList.push_back(i);
    }
    //!Show ArrayList representation (double)
    showRepresentation(doubleArrayList, "DoubleArray");

    //!LinkedList for non-contiguous allocation (double)
    list<double> doubleLinkedList;
    for (double i = 0.0; i <= n; i += 0.5) {
        doubleLinkedList.push_back(i);
    }
    //!Show LinkedList representation (double)
    showRepresentation(doubleLinkedList, "DoubleList");

    //!ArrayList for contiguous allocation (char)
    vector<char> charArrayList;
    for (char i = 'A'; i <= 'A' + n; i++) {
        charArrayList.push_back(i);
    }
    //!Show ArrayList representation (char)
    showRepresentation(charArrayList, "CharArray");

    //!LinkedList for non-contiguous allocation (char)
    list<char> charLinkedList;
    for (char i = 'A'; i <= 'A' + n; i++) {
        charLinkedList.push_back(i);
    }
    //!Show LinkedList representation (char)
    showRepresentation(charLinkedList, "CharList");

    return 0;
}
