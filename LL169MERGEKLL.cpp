class Solution {
  public:

    Node* Merge(Node* a, Node* b) {            
        Node* result = NULL;
        if (a == NULL) return b;
        else if (b == NULL) return a;

        if (a -> data <= b -> data) {
            result = a;
            result -> next = Merge(a -> next, b);  
        } else {
            result = b;
            result -> next = Merge(a, b -> next);
        }
        return result;                          
    }                                          

    Node* mergeKLists(vector<Node*>& arr) {
        int i = 0;
        int last = arr.size() - 1;              
        int j;

        while (last != 0) {
            i = 0;
            j = last;
            while (i < j) {
                arr[i] = Merge(arr[i], arr[j]);
                i++;
                j--;
                if (i >= j) {
                    last = j;
                }
            }
        }
        return arr[0];                          
    }                                           
};