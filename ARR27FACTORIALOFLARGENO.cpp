class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> result;
        result.push_back(1); // Start with 1
        
        // Multiply result by each number from 2 to n
        for(int i = 2; i <= n; i++){
            int carry = 0;
            
            // Multiply each digit by i
            for(int j = 0; j < result.size(); j++){
                int prod = result[j] * i + carry;
                result[j] = prod % 10;
                carry = prod / 10;
            }
            
            // Add remaining carry digits
            while(carry > 0){
                result.push_back(carry % 10);
                carry /= 10;
            }
        }
        
        // Reverse to get correct order (most significant digit first)
        reverse(result.begin(), result.end());
        
        return result;
    }
};