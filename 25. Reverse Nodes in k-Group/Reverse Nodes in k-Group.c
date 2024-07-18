/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *curr = head, *prev = NULL, *next = NULL;
    int count = 0;

    // check if there are enough nodes to reverse
    while (count < k && curr != NULL) {
        curr = curr->next;
        count++;
    }

    // if there are enough nodes, reverse them
    if (count == k) {
        curr = head;
        count = 0;
        while (count < k && curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL) {
            // reverse the next group of nodes
            head->next = reverseKGroup(next, k);
        }

        return prev;
    } else {
        // not enough nodes to reverse, return the original list
        return head;
    }
}