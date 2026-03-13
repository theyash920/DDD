class Solution {
  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        long long count = 0;  // Changed to long long
        sort(arr, arr+n);      // Changed a to arr
        
        for(int k=0; k<n-2; k++){
            int i = k+1;
            int j = n-1;
            while(i<j){
                long long s = arr[k]+arr[i]+arr[j];  // Changed a to arr
                if(s < sum){
                    count += (j-i);
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return count;  // Moved outside for loop
    }
};