class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;  // ✅ directly return prev, no need to update head
    }
};