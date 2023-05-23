#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeAdjacentDuplicates(string s) {
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && c == st.top()) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    string s = "abbaca";

    string result = removeAdjacentDuplicates(s);

    cout << "Result: " << result << endl;

    return 0;
}