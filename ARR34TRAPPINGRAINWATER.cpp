//time complexity O(n)
//space complexity O(n)
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();                        
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);
        
        lmax[0] = arr[0];                         
        rmax[n-1] = arr[n-1];                      
        
        for(int i = 1; i < n; i++){
            lmax[i] = max(lmax[i-1], arr[i]);      
        }
        for(int i = n-2; i >= 0; i--){             
            rmax[i] = max(rmax[i+1], arr[i]);      
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(lmax[i], rmax[i]) - arr[i];
        }
        
        return ans;
    }
};
//optimised solution
class Solution {
  public:
    int maxWater(vector<int> &arr) {
       int ans = 0;
       int n = arr.size();
       int l = 0, r = n-1;
       int rmax = 0, lmax = 0;
       
       while(l < r){
           lmax = max(lmax, arr[l]);
           rmax = max(rmax, arr[r]);
           
           if(lmax < rmax){
              ans += lmax - arr[l];
              l++;
           }else{
               ans += rmax - arr[r];
               r--;
           }
       }
       return ans;
    }
};