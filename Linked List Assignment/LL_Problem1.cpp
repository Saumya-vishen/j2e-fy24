#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }
    
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    
    delete temp;
    
    return dummy->next;
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
    
    int n = 2; 
    
    cout << "Original list: ";
    printList(head);
    
    head = removeNthFromEnd(head, n);
    
    cout << "List after removing the " << n << "th node from the end: ";
    printList(head);
    
   
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}