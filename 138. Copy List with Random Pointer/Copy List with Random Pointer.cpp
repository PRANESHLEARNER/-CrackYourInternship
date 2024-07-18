class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // First pass: Make copy of each node,
        // and link them together side-by-side in a single list.
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        }

        // Second pass: Assign random pointers for the copy nodes.
        for (Node* node = head; node != nullptr; node = node->next->next) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }
        }

        // Third pass: Restore the original list, and extract the copy list.
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* next = node->next->next;
            // extract the copy
            copy->next = node->next;
            copy = copy -> next;
            // restore the original list
            node->next = next;
        }

        return pseudoHead->next;
    }
};