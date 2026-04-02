// User function Template for C++

class Solution {
  public:
    Node *moveToFront(Node *head) {
        // code here
        if(head -> next == NULL)
        return head;
        
        Node *prev = NULL;
        Node *curr = head;
        
        while(curr -> next!=NULL){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = NULL;
        curr -> next = head;
        
        return curr;
        
    }
};