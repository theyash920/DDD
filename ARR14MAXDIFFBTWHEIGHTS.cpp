int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);

    int ans = arr[n-1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;
    int mi, ma;

    for (int i = 0; i < n - 1; i++) {
        mi = min(smallest, arr[i+1] - k);//mi (minimum possible): smaller of smallest or arr[i+1] - k
        ma = max(largest, arr[i] + k);//ma (maximum possible): larger of largest or arr[i] + k
        if (mi < 0) continue;
        ans = min(ans, ma - mi); //Calculate the current difference (`ma - mi`)
                                // If it's **smaller** than our previous answer, update it
                               // Keep doing this to find the **smallest possible difference**
    }
    return ans;
}


//final ans
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
    sort(arr.begin(), arr.end());
    
    int n= arr.size();

    int ans = arr[n-1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;
    int mi, ma;

    for (int i = 0; i < n - 1; i++) {
        mi = min(smallest, arr[i+1] - k);
        ma = max(largest, arr[i] + k);
        if (mi < 0) continue;
        ans = min(ans, ma - mi);
    }
    return ans;
}
};