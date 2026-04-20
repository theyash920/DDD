class Solution {
  public:

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result;

        if (left->data < right->data) {
            result = left;
            result->bottom = merge(left->bottom, right);  
        } else {
            result = right;
            result->bottom = merge(left, right->bottom); 
        }

        result->next = nullptr;
        return result;
    }

    Node* flattenLinkedList(Node* head) {
        if (!head || !head->next) return head;

        head->next = flattenLinkedList(head->next);
        return merge(head, head->next);
    }

    Node* flatten(Node* root) {
        return flattenLinkedList(root);
    }
};