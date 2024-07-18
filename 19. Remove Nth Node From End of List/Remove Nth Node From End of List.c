/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *start = malloc(sizeof(struct ListNode));
    start->next = head;
    struct ListNode *fast = start, *slow = start;
     for(int i=1; i<=n+1; i++) {
        fast = fast->next;
    }
     while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
     slow->next = slow->next->next;
    return start->next;
}