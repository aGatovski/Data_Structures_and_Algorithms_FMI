ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to simplify edge cases where the head needs to be removed
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Advance `first` pointer by `n+1` steps to keep a gap of `n` nodes between `first` and `second`
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move `first` to the end, maintaining the gap
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // `second` is now just before the node to be deleted
    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;  // Remove the nth node from end

    delete nodeToDelete;  // Free the memory of the removed node

    ListNode* newHead = dummy->next;  // Get the updated head
    delete dummy;  // Free the dummy node
    return newHead;
}
