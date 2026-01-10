class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int maxp = INT_MIN, prod = 1;
        
        // Left to right scan
        for(int i = 0; i < n; i++){
            prod *= arr[i];
            maxp = max(maxp, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        
        prod = 1;
        // Right to left scan
        for(int i = n-1; i >= 0; i--){
            prod *= arr[i];
            maxp = max(maxp, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        
        return maxp;
    }
};