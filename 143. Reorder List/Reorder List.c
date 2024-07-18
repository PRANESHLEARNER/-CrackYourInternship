void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return;
    
    // Find the middle of the list
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half in-place
    struct ListNode *head2 = slow->next, *prev = NULL;
    while (head2 != NULL) {
        struct ListNode *next = head2->next;
        head2->next = prev;
        prev = head2;
        head2 = next;
    }
    slow->next = NULL;
    
    // Link the two halves together
    while (prev != NULL) {
        struct ListNode *next = head->next;
        head->next = prev;
        prev = prev->next;
        head->next->next = next;
        head = next;
    }
}