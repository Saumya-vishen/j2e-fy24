#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeLists(ListNode* list1, ListNode* list2, int a, int b) {
    
    if (list1 == NULL || list2 == NULL || a >= b)
        return list1;
    
    ListNode* curr = list1;
    ListNode* prev = NULL;
    int count = 0;
    while (curr != NULL && count < a - 1) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    
    if (prev != NULL)
        prev->next = list2;
    
    ListNode* lastNode = list2;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    
    count = 0;
    while (curr != NULL && count < b) {
        curr = curr->next;
        count++;
    }
    
    
    if (lastNode != NULL)
        lastNode->next = curr;
    
    
    if (a == 1)
        return list2;
    else
        return list1;
}


void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
   
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    
    ListNode* list2 = new ListNode(6);
    list2->next = new ListNode(7);
    list2->next->next = new ListNode(8);
    
    int a = 2;
    int b = 4;
    
    cout << "Original list1: ";
    printList(list1);
    
    cout << "Original list2: ";
    printList(list2);
    
    ListNode* mergedList = mergeLists(list1, list2, a, b);
    cout << "Modified list1: ";
    printList(mergedList);
    
    return 0;
}