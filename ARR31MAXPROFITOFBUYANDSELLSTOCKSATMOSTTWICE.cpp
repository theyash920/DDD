//TIME COMPLEXITY O(N)
//SPACE COMPLEXITY O(N)

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        int* profit = new int[n];
        for(int i = 0; i < n; i++){
            profit[i] = 0;
        }
        
        int max_price = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            if(prices[i] > max_price)
               max_price = prices[i];
            
            profit[i] = max(profit[i+1], max_price - prices[i]);
        }  
            
        int min_price = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] < min_price)
                min_price = prices[i];
            
            profit[i] = max(profit[i-1], profit[i] + (prices[i] - min_price)); 
        }
        
        int result = profit[n-1];
        delete[] profit;  // Don't forget to free memory! 
        
        return result;
    }
};


//claude optimised for o(1) space
//You can reduce space to O(1) by using variables instead of an array:
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if(n == 0) return 0;
    
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;
    
    for(int price : prices) {
        buy1 = max(buy1, -price);
        sell1 = max(sell1, buy1 + price);
        buy2 = max(buy2, sell1 - price);
        sell2 = max(sell2, buy2 + price);
    }
    
    return sell2;
}