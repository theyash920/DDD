class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {
        if (p == 0) {         
            return head;
        }
        Node* curr = head;
        int count = 1;
        while (count < p && curr != NULL) {   
            curr = curr->next;
            count++;
        }
        Node* NthNode = curr;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = head;
        head->prev = curr;
        head = NthNode->next;
        head->prev = NULL;
        NthNode->next = NULL;

        return head;           
    }
};