#include <iostream>
#include <stack>

using namespace std;

bool isValidParentheses(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s1 = "((()))";
    string s2 = "{[()]}";
    string s3 = "([)]";
    string s4 = "{[()]";

    cout << s1 << " is " << (isValidParentheses(s1) ? "valid" : "not valid") << endl;
    cout << s2 << " is " << (isValidParentheses(s2) ? "valid" : "not valid") << endl;
    cout << s3 << " is " << (isValidParentheses(s3) ? "valid" : "not valid") << endl;
    cout << s4 << " is " << (isValidParentheses(s4) ? "valid" : "not valid") << endl;

    return 0;
}