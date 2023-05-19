#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minSwapsToBalance(const string& parenthesesString) {
    stack<char> st;
    int swaps = 0;

    for (char c : parenthesesString) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty()) {
                st.pop();
            } else {
                swaps++;  
            }
        }
    }

    return swaps;
}

int main() {
    string parenthesesString;
    cout << "Enter the parentheses string: ";
    cin >> parenthesesString;

    int minSwaps = minSwapsToBalance(parenthesesString);
    cout << "The minimum number of swaps required: " << minSwaps << endl;

    return 0;
}