struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right) return head;
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;
    for (int i = 1; i < left; i++) pre = pre->next;
    struct ListNode* cur = pre->next;
    for (int i = left; i < right; i++) {
        struct ListNode* t = cur->next;
        cur->next = t->next;
        t->next = pre->next;
        pre->next = t;
    }
    return dummy->next;
}