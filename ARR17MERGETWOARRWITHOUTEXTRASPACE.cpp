class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        // Compare last element of a with first element of b
        int i = n - 1;
        int j = 0;
        
        while(i >= 0 && j < m && a[i] > b[j]) {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        
        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

// Time Complexity: O(n*m + n*log(n) + m*log(m))
// Space Complexity: O(1)
