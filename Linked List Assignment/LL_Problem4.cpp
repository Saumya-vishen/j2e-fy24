#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
    
    return head;
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    
    cout << "Original list: ";
    printList(head);
    
    head = deleteDuplicates(head);
    
    cout << "List after deleting duplicates: ";
    printList(head);
    
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}