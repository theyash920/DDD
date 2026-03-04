class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return -1; // Handle empty input

        int ma = arr[0];
        int count = 1;

        // Phase 1: Finding the candidate
        for(int i = 1; i < n; i++) {
            if(arr[i] == ma) {
                count++;
            } else {
                count--;
            }

            if(count == 0) {
                ma = arr[i];
                count = 1;
            }
        }

        // Phase 2: Verification (Necessary if a majority isn't guaranteed)
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == ma) {
                c++;
            }
        }

        if(c > n / 2) {
            return ma;
        } else {
            return -1;
        }
    }
};




//TIME COMPLEXITY: O(N)
//SPACE COMPLEXITY: O(N)
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int val = arr.size() / 2;
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        for (auto x : m) {
            if (x.second > val)
                return x.first;
        }

        return -1;
    }
};