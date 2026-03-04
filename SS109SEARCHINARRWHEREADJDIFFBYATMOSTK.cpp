class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // x is element to search, k is max difference between consecutive elements
        int i = 0;
        int n = arr.size();
        
        while(i < n) {
            if(arr[i] == x)
                return i;
            
            // Skip elements: if arr[i] < x, we can skip ahead
            // based on the minimum steps needed to reach x
            i = i + max(1, abs(arr[i] - x) / k);
        }
        
        return -1;
    }
};