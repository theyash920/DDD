class Solution {
  public:
    bool isPossible(vector<int>& arr, int n, int m, long long maxAllowedTime) {
        int painters = 1;
        long long time = 0;
        for (int i = 0; i < n; i++) {
            if (time + arr[i] <= maxAllowedTime) {
                time += arr[i];
            } else {
                painters++;
                time = arr[i];
            }
        }
        return painters <= m;
    }

    long long minTime(vector<int>& arr, int k) {
        int n = arr.size();   // ✅ fix: was undefined
        long long sum = 0;
        long long maxVal = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxVal = max(maxVal, (long long)arr[i]);  // ✅ consistent naming
        }

        long long st = maxVal, end = sum, ans = -1;

        while (st <= end) {
            long long mid = st + (end - st) / 2;
            if (isPossible(arr, n, k, mid)) {  // ✅ fix: pass k not m
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;  // ✅ fix: was missing
    }
};