class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // If array has only one element or is empty
        if(n <= 1)
            return 0;
        
        // If first element is 0, we can't move forward
        if(arr[0] == 0)
            return -1;
        
        int maxReach = arr[0];  // Maximum index we can reach
        int step = arr[0];       // Steps we can still take in current jump
        int jump = 1;            // Number of jumps made so far
        
        for(int i = 1; i < n; i++) {
            // If we've reached the last index
            if(i == n - 1)
                return jump;
            
            // Update maxReach
            maxReach = max(maxReach, i + arr[i]);
            
            // Use a step to move forward
            step--;
            
            // If no more steps left
            if(step == 0) {
                jump++;  // We must have made a jump
                
                // If current index is beyond maxReach, impossible to proceed
                if(i >= maxReach)
                    return -1;
                
                // Re-initialize steps for next jump
                step = maxReach - i;
            }
        }
        
        return -1;  // If we exit loop without reaching end
    }
};
