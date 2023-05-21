#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printStringsUtil(const vector<char>& charSet, string& currString, int k) {
    if (currString.length() == k) {
        cout << currString << endl;
        return;
    }

    for (char c : charSet) {

        currString.push_back(c);
        printStringsUtil(charSet, currString, k);
        currString.pop_back();
    }
}

void printStrings(const vector<char>& charSet, int k) {
    string currString;
    printStringsUtil(charSet, currString, k);
}

int main() {
    int k, n;
    cout << "Enter the length of strings (k): ";
    cin >> k;
    cout << "Enter the number of characters (n): ";
    cin >> n;

    vector<char> charSet(n);
    cout << "Enter the characters: ";
    for (int i = 0; i < n; ++i) {
        cin >> charSet[i];
    }

    cout << "All possible strings of length " << k << " from the character set are:" << endl;
    printStrings(charSet, k);

    return 0;
}