#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
    void push(int data) {
        s1.push(data);
    }

    int pop() {
        
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            return -1; 
        }

        int poppedElement = s2.top();
        s2.pop();

        return poppedElement;
    }
};

int main() {
    Queue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Popped element: " << queue.pop() << endl;
    cout << "Popped element: " << queue.pop() << endl;

    queue.push(4);

    cout << "Popped element: " << queue.pop() << endl;
    cout << "Popped element: " << queue.pop() << endl;

    return 0;
}