#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    ListNode* head = dummy->next;
    delete dummy;
    
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

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    
    cout << "List 1: ";
    printList(list1);
    
    cout << "List 2: ";
    printList(list2);
    
    ListNode* mergedList = mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    printList(mergedList);
    
    ListNode* current = mergedList;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}