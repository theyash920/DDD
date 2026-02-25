//dutch algorithm
//time complexity O(n)
//space complexity O(1)

class Solution {
  public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        int n = arr.size();
        int start = 0;
        int end = n - 1; // Fix 1: Corrected index
        int i = 0;
        
        while(i <= end) {
            if(arr[i] < a) {
                swap(arr[i], arr[start]);
                i++;
                start++;
            }
            else if(arr[i] > b) {
                swap(arr[i], arr[end]);
                // Fix 2: Do NOT increment i here. 
                // We need to check the swapped element in the next loop.
                end--;
            }
            else {
                i++;
            }
        }
    }
};