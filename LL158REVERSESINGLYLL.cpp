class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        if(curr == NULL || curr -> next == NULL){
            return head;
        }
        while(curr -> next != NULL)
        curr = curr -> next;
        head = curr;
        while(curr!= NULL){
            Node* temp = curr -> next;
            curr -> next = curr -> prev;
            curr -> prev = temp;
            curr = curr -> next;
        }
        return head;
    }
};