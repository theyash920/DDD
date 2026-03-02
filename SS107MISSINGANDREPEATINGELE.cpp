class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();  // ✅ declare n
        int a, b;            // a = repeating, b = missing

        for (int i = 0; i < n; i++) {
            if (arr[abs(arr[i]) - 1] < 0) {
                a = abs(arr[i]);  // already negative → visited twice → repeating
            } else {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];  // mark visited
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {   // never visited → missing
                b = i + 1;
                break;
            }
        }

        return {a, b};  // ✅ return vector directly
    }
};