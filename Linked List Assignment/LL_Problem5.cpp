#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* prev = dummy;
    ListNode* current = head;
    
    while (current != NULL) {
        while (current->next != NULL && current->val == current->next->val) {
            current = current->next;
        }
        
        if (prev->next == current) {
            prev = prev->next;
        } else {
            prev->next = current->next;
        }
        
        current = current->next;
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    
    cout << "Original list: ";
    printList(head);
    
    head = deleteDuplicates(head);
    
    cout << "List after deleting nodes with duplicates: ";
    printList(head);
    
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}