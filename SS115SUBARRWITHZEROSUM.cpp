 class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;  // Important: empty subarray
        
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            count += mp[sum];  // Count subarrays ending here
            mp[sum]++;
        }
        
        return count;
    }
};