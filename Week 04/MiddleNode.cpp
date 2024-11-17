ListNode* middleNode(ListNode* head) {
    ListNode* curr = head;
    ListNode* returnNode = head;
    int count = 1;
    while (curr) {
        curr = curr->next;
        count++;
    }

    if (count % 2 == 0) {
        count /= 2;
    }
    else {
        count /= 2;
        count++;
    }
    for (size_t i = 1; i < count; i++)
    {
        returnNode= returnNode->next;
    }
    return returnNode;
}
