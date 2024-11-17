#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (list1 == nullptr && list2 == nullptr) { 
        return list1;
    }
    if(list1 == nullptr && list2 != nullptr){
        return list2;
    }
    if (list1 != nullptr && list2 == nullptr) {
        return list1;
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (list1 != nullptr && list2!= nullptr)
    {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    ListNode* mergedHead = dummy->next;
    return mergedHead;

}

ListNode* createLinkedList(int n) {
    if (n == 0) return nullptr;

    int data;
    cin >> data;

    ListNode* head = new ListNode(data);
    ListNode* current = head;

    for (int i = 2; i <= n; i++) {
        cin >> data;
        current->next = new ListNode(data);
        current = current->next;
    }

    return head;
}

int main() {
    int t;
    cin>>t;
    
    for(int i = 0; i < t ; i++){
        int n,m;

    cin >> n;
    ListNode* head1 = createLinkedList(n);

   
    cin >> m;
    ListNode* head2 = createLinkedList(m);
    
    ListNode* mergedHead = mergeTwoLists(head1, head2);
    
    printLinkedList(mergedHead);
        
    }
    
    
    return 0;
}
