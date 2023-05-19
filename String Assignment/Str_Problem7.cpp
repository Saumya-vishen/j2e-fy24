#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int countDistinctSubstrings(string s) {
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;
        for (int j = i; j < n; j++) {
            if (seen.count(s[j]) > 0) {
                break;
            }
            seen.insert(s[j]);
            count++;
        }
    }

    return count;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int distinctSubstrings = countDistinctSubstrings(s);
    cout << "The number of different substrings with no repeating characters: " << distinctSubstrings << endl;

    return 0;
}