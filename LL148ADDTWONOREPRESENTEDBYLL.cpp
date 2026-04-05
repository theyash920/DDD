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
        return prev;  
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        
        int c = 0;
        int s = 0;
        Node* temp;
        Node* res = NULL;
        Node* curr = NULL;
        
        while(head1 != NULL || head2 != NULL){
            s = c + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
            c = (s >= 10) ? 1 : 0;
            s = s % 10;
            temp = new Node(s);
            if(res == NULL)
                res = temp;
            else
                curr->next = temp;
            curr = temp;
            if(head1) head1 = head1->next;
            if(head2) head2 = head2->next;
        }
        
        if(c > 0){
            temp = new Node(c);
            curr->next = temp;
        }
        
        res = reverseList(res);
        while(res != NULL && res->data == 0 && res->next != NULL){
        res = res->next;
        }
        return res;
    }
};