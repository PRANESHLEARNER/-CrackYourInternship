bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    
    // Find the middle of the list
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the list
    struct ListNode *secondHalfHead = slow->next;
    struct ListNode *p1 = secondHalfHead, *p2 = p1->next;
    while (p1 != NULL && p2 != NULL) {
        struct ListNode *temp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = temp;
    }
    secondHalfHead->next = NULL;
    
    // Compare the first and the second half of the list
    if (fast != NULL) { // if the length of the list is odd
        secondHalfHead = p1;
    } else { // if the length of the list is even
        secondHalfHead = p1->next;
    }
    while (head != NULL && secondHalfHead != NULL) {
        if (head->val != secondHalfHead->val) return false;
        head = head->next;
        secondHalfHead = secondHalfHead->next;
    }
    
    return true;
}