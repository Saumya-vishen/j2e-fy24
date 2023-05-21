#include <iostream>
using namespace std;

class MyCircularDeque {
private:
    int* deque;
    int front;
    int rear;
    int capacity;
    int size;

public:
    MyCircularDeque(int k) {
        capacity = k;
        deque = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        size++;
        
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        
        front = (front + 1) % capacity;
        size--;
        
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        
        rear = (rear - 1 + capacity) % capacity;
        size--;
        
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        
        return deque[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        
        return deque[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularDeque circularDeque(3);

    cout << circularDeque.insertLast(1) << endl; 
    cout << circularDeque.insertLast(2) << endl; 
    cout << circularDeque.insertFront(3) << endl; 
    cout << circularDeque.insertFront(4) << endl; 
    cout << circularDeque.getRear() << endl;     
    cout << circularDeque.isFull() << endl;       
    cout << circularDeque.deleteLast() << endl;  
    cout << circularDeque.insertFront(4) << endl; 
    cout << circularDeque.getFront() << endl;     

    return 0;
}