#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int minSumOfAbsoluteDifferences(string msg, vector<int>& security_values) {
    vector<pair<int, char>> chars;

    for (int i = 0; i < msg.length(); i++) {
        chars.push_back({ security_values[msg[i] - 'a'], msg[i] });
    }

    sort(chars.begin(), chars.end());

    int sum = 0;
    for (int i = 1; i < chars.size(); i++) {
        sum += abs(chars[i].first - chars[i - 1].first);
    }

    return sum;
}

int main() {
    string msg;
    cout << "Enter the encrypted message: ";
    cin >> msg;

    vector<int> security_values(26);
    cout << "Enter the security values for each character from 'a' to 'z': ";
    for (int i = 0; i < 26; i++) {
        cin >> security_values[i];
    }

    int minSum = minSumOfAbsoluteDifferences(msg, security_values);
    cout << "The minimum possible sum of absolute differences: " << minSum << endl;

    return 0;
}