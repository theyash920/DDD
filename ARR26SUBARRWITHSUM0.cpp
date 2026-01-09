class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        unordered_map<int, bool> mp;
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            
            // If cumulative sum is 0 or sum already seen
            if(sum == 0 || mp[sum])
                return true;
                
            mp[sum] = true;
        }
        
        return false;
    }
};

