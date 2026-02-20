class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int curr_sum = 0;
        int min_len = n + 1;

        int start = 0, end = 0;
        while (end < n) {
            while (curr_sum <= x && end < n)
                curr_sum += arr[end++];

            while (curr_sum > x && start < n) {
                if (end - start < min_len)
                    min_len = end - start;
                curr_sum -= arr[start++];
            }
        }

        return (min_len == n + 1) ? 0 : min_len;
    }
};