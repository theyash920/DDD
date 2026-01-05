class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int sum = 0;
        int maxi = arr[0];  // more robust: use arr[0] -> INT_MIN as initial value handles all min cases
        
        for(int i = 0; i < arr.size(); i++) {
            // Step 1: Add current element to sum
            sum = sum + arr[i];  
            
            // Step 2: Update maximum
            maxi = max(maxi, sum);
            
            // Step 3: Reset sum if negative
            if(sum < 0)
                sum = 0;
        }
        
        return maxi;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)