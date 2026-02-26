//
class Solution {
  public:
    double findMedian(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        if(n % 2 == 1){
            return arr[n / 2];
        }
        
        return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;  // 2.0 to avoid integer division
    }
};