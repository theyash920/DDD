class Solution {
  public:
    pair<Node*, Node*> splitList(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        // find middle
        while(fast != head && fast->next != head){
            slow = slow->next;
            fast = fast->next->next;  // ✅
        }
        
        Node* head1 = head;          // ✅ first half
        Node* head2 = slow->next;    // ✅ second half
        
        // fix first half's last node
        slow->next = head1;
        
        // fix second half's last node
        Node* curr = head2;
        while(curr->next != head){  
            curr = curr->next;
        }
        curr->next = head2;
        
        return {head1, head2};       // ✅ return the pair
    }
};