class Solution {
  public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        
        // Separate positives and negatives while maintaining order
        vector<int> pos, neg;
        for(int i = 0; i < n; i++){
            if(arr[i] >= 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }
        
        // Merge back alternating positive and negative
        int i = 0, j = 0, k = 0;
        
        // Start with positive (even index) or negative based on what comes first
        while(i < pos.size() && j < neg.size()){
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        
        // Add remaining positives
        while(i < pos.size()){
            arr[k++] = pos[i++];
        }
        
        // Add remaining negatives
        while(j < neg.size()){
            arr[k++] = neg[j++];
        }
    }
};