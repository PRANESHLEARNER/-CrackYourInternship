/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// A utility function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// A utility function to swap two nodes
void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to heapify a subtree rooted at i
void heapify(struct ListNode** heap, int i, int size) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is smaller than root
    if (left < size && heap[left]->val < heap[smallest]->val)
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < size && heap[right]->val < heap[smallest]->val)
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        // Swap the nodes
        swap(&heap[i], &heap[smallest]);
        // Recursively heapify the affected sub-tree
        heapify(heap, smallest, size);
    }
}

// A utility function to build a min-heap from an array
void buildHeap(struct ListNode** heap, int size) {
    // Index of last non-leaf node
    int i = (size - 2) / 2;
    // Perform reverse level order traversal
    // from last non-leaf node and heapify each node
    while (i >= 0) {
        heapify(heap, i, size);
        i--;
    }
}

// A utility function to extract the minimum node from the heap
struct ListNode* extractMin(struct ListNode** heap, int* size) {
    // Store the root node
    struct ListNode* min = heap[0];
    // Replace root node with last node
    heap[0] = heap[*size - 1];
    // Reduce heap size and heapify root
    (*size)--;
    heapify(heap, 0, *size);
    // Return the minimum node
    return min;
}

// A utility function to insert a new node to the heap
void insertHeap(struct ListNode** heap, int* size, struct ListNode* node) {
    // Increase the heap size
    (*size)++;
    // Insert the node at the end
    heap[*size - 1] = node;
    // Fix the min heap property if violated
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2]->val > heap[i]->val) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// The main function to merge k sorted linked lists
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // Create an array to store the first node of each list
    struct ListNode** heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    int heapSize = 0; // Heap size
    // Initialize the heap with the first node of each list
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            heap[heapSize] = lists[i];
            heapSize++;
        }
    }
    // Build a min-heap from the array
    buildHeap(heap, heapSize);

    // Create a dummy node to store the head of the merged list
    struct ListNode* dummy = newNode(0);
    struct ListNode* tail = dummy; // Pointer to the last node of the merged list

    // Repeat until the heap is empty
    while (heapSize > 0) {
        // Extract the minimum node from the heap
        struct ListNode* min = extractMin(heap, &heapSize);
        // Add the minimum node to the merged list
        tail->next = min;
        tail = tail->next;
        // If the minimum node has a next node, insert it to the heap
        if (min->next != NULL) {
            insertHeap(heap, &heapSize, min->next);
        }
    }

    // Return the head of the merged list
    return dummy->next;
}