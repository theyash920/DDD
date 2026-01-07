class Solution {
public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        
        int prev1, prev2, prev3;
        prev1 = prev2 = prev3 = INT_MIN;
        
        while(i < n1 && j < n2 && k < n3){
            // Skip duplicates
            while(i < n1 && arr1[i] == prev1)
                i++;
            while(j < n2 && arr2[j] == prev2)
                j++;
            while(k < n3 && arr3[k] == prev3)
                k++;
            
            // Check bounds after skipping
            if(i >= n1 || j >= n2 || k >= n3)
                break;
                
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
                ans.push_back(arr1[i]);
                prev1 = arr1[i];
                prev2 = arr2[j];
                prev3 = arr3[k];
                i++;
                j++;
                k++;
            }
            else if (arr1[i] < arr2[j]){
                prev1 = arr1[i];
                i++;
            }
            else if (arr2[j] < arr3[k]){
                prev2 = arr2[j];
                j++;
            }
            else {
                prev3 = arr3[k];
                k++;
            }
        }
        return ans;
    }
};