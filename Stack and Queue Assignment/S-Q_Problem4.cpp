#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int capacity;
    int count;
    Node* head;
    Node* tail;

public:
    LRUCache(int cap) {
        capacity = cap;
        count = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            deleteNode(node);
            addToHead(node);
            return node->value;
        }
        return -1;
    }

    void set(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            count++;

            if (count > capacity) {
                Node* tailPrev = tail->prev;
                deleteNode(tailPrev);
                cache.erase(tailPrev->key);
                count--;
            }
        }
    }
};

int main() {
    LRUCache cache(2);

    cache.set(1, 10);
    cache.set(2, 20);

    cout << cache.get(1) << endl; 

    cache.set(3, 30);

    cout << cache.get(2) << endl; 

    cache.set(4, 40);

    cout << cache.get(1) << endl; 
    cout << cache.get(3) << endl; 
    cout << cache.get(4) << endl; 

    return 0;
}