class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        Node* curr = head;
        Node* temp;

        // Step 1: Interleave cloned nodes
        while (curr) {
            temp = curr -> next;                   
            curr -> next = new Node(curr -> data);
            curr -> next -> next = temp;
            curr = temp;
        }

        // Step 2: Set arb pointers for cloned nodes
        curr = head;
        while (curr) {
            curr -> next -> random = curr -> random ? curr -> random -> next : curr -> random;
            curr = curr -> next -> next;
        }

        // Step 3: Separate the two lists
        Node* original = head;
        Node* copy = head -> next;
        temp = copy;                              

        while (original && copy) {
            original -> next = original -> next -> next;
            copy -> next = copy -> next ? copy -> next -> next : copy -> next;
            original = original -> next;
            copy = copy -> next;
        }

        return temp;                                
    }
};