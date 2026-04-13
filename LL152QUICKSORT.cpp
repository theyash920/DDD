class Solution {
  public:

    // Step 1: Get tail node
    Node* getTail(Node* head) {
        while (head->next != NULL)
            head = head->next;
        return head;
    }

    // Step 2: Partition around pivot (last node)
    // Rearranges nodes and returns pivot
    Node* partition(Node* head, Node* end,
                    Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = NULL;
        Node* cur  = head;
        Node* tail = pivot;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                // cur goes to left side
                if (*newHead == NULL)
                    *newHead = cur;
                prev = cur;
                cur  = cur->next;
            } else {
                // cur goes to right side (after pivot)
                if (prev)
                    prev->next = cur->next;
                Node* next  = cur->next;
                cur->next   = NULL;
                tail->next  = cur;
                tail        = cur;
                cur         = next;
            }
        }

        if (*newHead == NULL)   // all nodes were >= pivot
            *newHead = pivot;

        *newEnd = tail;
        return pivot;           // pivot is now at correct position
    }

    // Step 3: Recursive helper
    Node* quickSortHelper(Node* head, Node* end) {
        // Base case
        if (head == NULL || head == end)
            return head;

        Node* newHead = NULL;
        Node* newEnd  = NULL;

        Node* pivot = partition(head, end, &newHead, &newEnd);

        // Sort left side (nodes before pivot)
        if (newHead != pivot) {
            // Find node just before pivot
            Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;                        // detach left from pivot

            newHead   = quickSortHelper(newHead, tmp); // sort left
            tmp       = getTail(newHead);              // reconnect
            tmp->next = pivot;
        }

        // Sort right side (nodes after pivot)
        pivot->next = quickSortHelper(pivot->next, newEnd);

        return newHead;
    }

    // Step 4: Main function
    Node* quickSort(Node* head) {
        if (head == NULL) return head;
        Node* tail = getTail(head);
        return quickSortHelper(head, tail);
    }
};