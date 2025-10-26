//kadane's algorithm
class solution{
    int maxSubArray(vector<int>& nums){
        int sum =0;
        int maxi = nums[0];

    for(int i=0; i<nums.size(); i++){
        sum = sum + nums[i];

        maxi = max(maxi, sum);

        if(sum<0){
            sum =0;
        }
    }
    return maxi; 
}
};


//final ans 
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int sum =0;
        int maxi = arr[0];

    for(int i=0; i<arr.size(); i++){
        sum = sum + arr[i];

        maxi = max(maxi, sum);

        if(sum<0){
            sum =0;
        }
    }
    return maxi; 
    }
};