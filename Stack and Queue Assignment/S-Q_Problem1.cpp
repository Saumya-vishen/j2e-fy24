#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2;
    int topElement;

public:
    void push(int data) {
        q1.push(data);

        topElement = data;
    }

    void pop() {
        
        while (q1.size() > 1) {
            topElement = q1.front();
            q2.push(topElement);
            q1.pop();
        }

        q1.pop();

        swap(q1, q2);
    }

    int top() {
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();

    cout << "Top element after pop: " << stack.top() << endl;

    return 0;
}