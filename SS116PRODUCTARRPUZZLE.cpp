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