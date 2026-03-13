//TIME COMPLEXITY: O(N^3)
//SPACE COMPLEXITY: O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for(int i = 0; i < n-3; i++){
            // Skip duplicates for i
            if(i > 0 && arr[i] == arr[i-1]) continue;
            
            for(int start = i+1; start < n-2; start++){
                // Skip duplicates for start
                if(start > i+1 && arr[start] == arr[start-1]) continue;
                
                int left = start + 1;
                int right = n - 1;
                
                while(left < right){
                    long long sum = (long long)arr[i] + arr[start] + arr[left] + arr[right];
                    
                    if(sum == target){
                        ans.push_back({arr[i], arr[start], arr[left], arr[right]});
                        left++;
                        right--;
                        
                        // Skip duplicates for left and right
                        while(left < right && arr[left] == arr[left-1]) left++;
                        while(left < right && arr[right] == arr[right+1]) right--;
                    }
                    else if(sum < target){
                        left++;  // Need larger sum
                    }
                    else{
                        right--;  // Need smaller sum
                    }
                }
            }
        }
        
        return ans;
    }
};