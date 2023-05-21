#include <iostream>
#include <unordered_map>

using namespace std;


struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {

            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);
            
            if (cache.size() > capacity) {
                Node* removedNode = removeTail();
                cache.erase(removedNode->key);
                delete removedNode;
            }
        }
    }
    
private:
    
    void moveToHead(Node* node) {
        removeNode(node);
        addToFront(node);
    }
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    Node* removeTail() {
        Node* removedNode = tail->prev;
        removeNode(removedNode);
        return removedNode;
    }
};

int main() {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    
    cout << cache.get(1) << endl; 
    
    cache.put(3, 3);
    
    cout << cache.get(2) << endl;
    
    cache.put(4, 4);
    
    cout << cache.get(1) << endl;
}