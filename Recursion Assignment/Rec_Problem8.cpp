#include <iostream>
#include <vector>

using namespace std;


bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}


void partitionPalindrome(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
    int n = s.length();


    if (start == n) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < n; i++) {
        if (isPalindrome(s, start, i)) {
            string substring = s.substr(start, i - start + 1);
            current.push_back(substring);

            partitionPalindrome(s, i + 1, current, result);

            current.pop_back();
        }
    }
}


vector<vector<string>> palindromePartition(const string& s) {
    vector<vector<string>> result;
    vector<string> current;

    partitionPalindrome(s, 0, current, result);

    return result;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    vector<vector<string>> partitions = palindromePartition(s);

    cout << "All possible palindrome partitions of " << s << ":" << endl;
    for (const vector<string>& partition : partitions) {
        for (const string& substring : partition) {
            cout << substring << " ";
        }
        cout << endl;
    }

    return 0;
}