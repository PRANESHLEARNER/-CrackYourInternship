class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0), *prev = dummy;
        dummy->next = head;
        
        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        
        return dummy->next;
    }
};