/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    while (current != NULL) {
        next = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}