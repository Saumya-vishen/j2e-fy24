#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (string token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();

            if (token == "+") {
                st.push(num1 + num2);
            } else if (token == "-") {
                st.push(num1 - num2);
            } else if (token == "*") {
                st.push(num1 * num2);
            } else if (token == "/") {
                st.push(num1 / num2);
            }
        } else {
            int num;
            istringstream iss(token);
            iss >> num;
            st.push(num);
        }
    }

    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    int result = evalRPN(tokens);

    cout << "Result: " << result << endl;

    return 0;
}