class Solution {
  public:
    int longestConsecutiveSubsequence(vector<int>& arr) {
        int n = arr.size();
        vector<int> isPresent(100006, 0);
        
        for(int i = 0; i < n; i++){
            isPresent[arr[i]] = 1;  // Square brackets, not parentheses
        }
        
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < 100006; i++){
            if(isPresent[i]){
                cnt++;
            }
            else{
                cnt = 0;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};