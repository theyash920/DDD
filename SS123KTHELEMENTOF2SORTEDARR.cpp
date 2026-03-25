class Solution {
  public:
    int search(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();
        int l = max(0, k - 1 - m), r = min(k - 1, n - 1); // ✅ k-1-m not k-m
        while (l <= r) {
            int mid = (l + r) / 2;
            int x = a[mid], req = k - 1 - mid;
            int lb = INT_MIN, ub = INT_MAX;
            if (req - 1 >= 0)
                lb = b[req - 1];
            if (req < m)
                ub = b[req];
            if (lb <= x && x <= ub)
                return x;
            if (x < lb)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        if (a.size() <= b.size()) {
            int ans = search(a, b, k);
            if (ans != -1) return ans;
            return search(b, a, k);
        }
        int ans = search(b, a, k);
        if (ans != -1) return ans;
        return search(a, b, k);
    }
};