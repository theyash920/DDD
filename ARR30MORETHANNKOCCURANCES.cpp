class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int>m;
        int x = n/k, count = 0;
        for(int i = 0; i< n; i++){
            m[arr[i]] += 1;
            if(m[arr[i]] > x){
                count += 1;
                m[arr[i]] = -1000;
            }
        }
        return count;
    }
};