class Solution {
  private:
    bool checkPalindrome(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e) {
            if (arr[s] != arr[e]) {  
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

  public:
    bool isPalindrome(Node* head) {
        // Copy linked list into array
        vector<int> arr;
        Node* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);  
    }
};