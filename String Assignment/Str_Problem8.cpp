#include <iostream>
#include <string>
using namespace std;

int countPalindromicSubstrings(string s) {
    int count = 0;
    int n = s.length();

    count += n;
    
    for (int i = 0; i < n - 1; i++) {
        int left = i;
        int right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }

    
    for (int i = 0; i < n; i++) {
        int left = i - 1;
        int right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }

    return count;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int palindromicSubstrings = countPalindromicSubstrings(s);
    cout << "The number of palindromic substrings: " << palindromicSubstrings << endl;

    return 0;
}