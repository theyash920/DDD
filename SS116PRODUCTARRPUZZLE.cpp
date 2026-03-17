class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n), r(n);

        l[0] = 1;
        r[n-1] = 1;

        for (int i = 1; i < n; i++) {
            l[i] = l[i-1] * arr[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            r[i] = r[i+1] * arr[i+1];
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = l[i] * r[i];
        } 

        return result;
    }
}; 
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 1);

        // Left pass: ans[i] = product of all elements to the LEFT
        int left = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = left;
            left *= arr[i];
        }

      
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {  
            ans[i] *= right;                  
            right *= arr[i];
        }

        return ans;
    }
};