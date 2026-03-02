class Solution {
  private:
    int firstOcc(vector<int>& arr, int key) {
        int s = 0, e = arr.size() - 1, ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                ans = mid;
                e = mid - 1;      // go left to find first
            } else if (key > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& arr, int key) {
        int s = 0, e = arr.size() - 1, ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                ans = mid;
                s = mid + 1;      // go right to find last
            } else if (key > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

  public:
    vector<int> find(vector<int>& arr, int x) {
        return { firstOcc(arr, x), lastOcc(arr, x) };
    }
};