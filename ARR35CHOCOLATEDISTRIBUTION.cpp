class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        sort(a.begin(), a.end());
        int d = INT_MAX;
        for (int i = 0; i + m - 1 < n; i++) {
            d = min(d, a[i + m - 1] - a[i]);
        }
        return d;
    }
};