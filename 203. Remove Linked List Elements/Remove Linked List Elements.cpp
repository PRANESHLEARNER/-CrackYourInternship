class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to handle cases where the head node itself has the value val
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* current = dummy;
        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};