ListNode* oddEvenList(ListNode* head) {

    if (!head || !head->next) {
        return head; // Handle edge cases of empty or single-node lists
    }

    ListNode* odd = head;             // Start with the first (odd) node
    ListNode* even = head->next;      // Start with the second (even) node
    ListNode* evenHead = even;        // Keep track of the even list head

    while (even && even->next) {
        odd->next = even->next;       // Link the next odd node
        odd = odd->next;              // Move odd pointer forward
        even->next = odd->next;       // Link the next even node
        even = even->next;            // Move even pointer forward
    }

    odd->next = evenHead;             // Connect the odd list to the even list
    return head;
}
