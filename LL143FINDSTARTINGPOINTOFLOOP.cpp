class Solution {
  public:
    int cycleStart(Node* head) {
        // code here
        Node* low = head;
        Node* high = head;
        while(high!=NULL && high->next!= NULL){
            low = low -> next;
            high = high -> next -> next;
            if(low == high){
               break; 
            }
        }
        if(low!=high){
            return -1;
        }
        low = head;// reset low to head
        while(low!=high){
            low = low -> next;
            high = high -> next;
        }
        return low->data;
    }
};