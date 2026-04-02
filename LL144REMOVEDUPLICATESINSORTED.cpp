class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        Node* temp = head;  
        if(!head)
            return NULL;
        while(temp->next != NULL){
            if(temp->data == temp->next->data){
                temp->next = temp->next->next;  
            }
            else temp = temp->next;
        }
        return head;  
    }
};