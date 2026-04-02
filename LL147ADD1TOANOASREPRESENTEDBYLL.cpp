/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

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
    Node* addOne(Node* head) {
    head = reverseList(head);  // ✅
    bool f = true;
    Node* curr = head;
    while(curr != NULL && f == true){
        if(curr->next == NULL && curr->data == 9){
            curr->data = 1;            
            Node* temp = new Node(0);  
            temp->next = head;
            head = temp;
            curr = curr->next;
        } else if(curr->data == 9){
            curr->data = 0;            
            curr = curr->next;
        } else {
            curr->data = curr->data + 1;
            curr = curr->next;
            f = false;
        }
    }
    head = reverseList(head);  
    return head;
}
};