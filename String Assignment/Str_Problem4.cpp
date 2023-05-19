#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string isPangram(const string& s) {
    unordered_set<char> letters;

    for (char c : s) {
        if (isalpha(c)) {
            letters.insert(tolower(c));
        }
    }

    return letters.size() == 26 ? "1" : "0";
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore();  

    for (int i = 0; i < n; i++) {
        string pangram;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, pangram);

        cout << isPangram(pangram) << endl;
    }

    return 0;
}