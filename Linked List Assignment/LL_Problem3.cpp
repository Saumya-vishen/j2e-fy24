#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* current = dummy;
    
    while (current->next != NULL && current->next->next != NULL) {
        ListNode* first = current->next;
        ListNode* second = current->next->next;
        
        
        first->next = second->next;
        second->next = first;
        current->next = second;
        
        current = current->next->next;
    }
    
    ListNode* newHead = dummy->next;
    delete dummy;
    
    return newHead;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original list: ";
    printList(head);
    
    head = swapPairs(head);
    
    cout << "List after swapping adjacent nodes: ";
    printList(head);
    

    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}