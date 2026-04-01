class Solution {
  public:
    void removeLoop(Node* head) {
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
        if(low == head){
            while(high -> next!= low){
                high = high -> next;
            }
            high -> next = NULL;
        }
        else if(low == high){
            low = head;
            while(low -> next != high->next){
                low = low -> next;
                high = high -> next;
            }
            high -> next = NULL;
        }
    }
};