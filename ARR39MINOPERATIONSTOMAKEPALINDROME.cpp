class Solution {
  public:
    int isPalinArray(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        int operations = 0;

        while (i <= j) {
            if (arr[i] == arr[j]) {
                i++;
                j--;
            } 
            else if (arr[i] < arr[j]) {
                i++;
                arr[i] += arr[i - 1];
                operations++;
            } 
            else {
                j--; 
                arr[j] += arr[j + 1];
                operations++;
            }
        }
        return operations;
    }
};