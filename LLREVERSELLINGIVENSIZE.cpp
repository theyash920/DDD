class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (head == NULL) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int c = 0;

        // Reverse up to k nodes (or whatever remains)
        while (curr != NULL && c < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }

        // curr is now the start of the next group
        if (curr != NULL)
            head->next = reverseKGroup(curr, k);

        return prev;
    }
};
//completed