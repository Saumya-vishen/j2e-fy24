#include <iostream>
#include <string>
using namespace std;

bool isEqualAfterBackspace(string s1, string s2) {
    string finalS1 = "", finalS2 = "";

    for (char c : s1) {
        if (c == '#') {
            if (!finalS1.empty()) {
                finalS1.pop_back();
            }
        } else {
            finalS1.push_back(c);
        }
    }

    for (char c : s2) {
        if (c == '#') {
            if (!finalS2.empty()) {
                finalS2.pop_back();
            }
        } else {
            finalS2.push_back(c);
        }
    }

    return finalS1 == finalS2;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    getline(cin, s1);
    cout << "Enter the second string: ";
    getline(cin, s2);

    if (isEqualAfterBackspace(s1, s2)) {
        cout << "The two strings are equal after backspacing. The answer is 1\n";
    } else {
        cout << "The two strings are not equal after backspacing. The answer is 0\n";
    }

    return 0;
}