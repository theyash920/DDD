class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        unordered_map<int, int> freq;
        set<pair<int, int>> uniquePairs;
        
        for (int i = 0; i < arr.size(); i++) {
            if (freq[0 - arr[i]] > 0) {
                uniquePairs.insert({min(arr[i], -arr[i]), max(arr[i], -arr[i])});
            }
            freq[arr[i]]++;
        }
        
        // Convert set<pair<int,int>> to vector<vector<int>>
        vector<vector<int>> result;
        for (auto& p : uniquePairs) {
            result.push_back({p.first, p.second});
        }
        
        return result;
    }
};