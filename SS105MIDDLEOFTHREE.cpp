class Solution {
  public:
    int middle(int a, int b, int c) {
        int mi = min({a, b, c});   
        int ma = max({a, b, c});   
        return (a + b + c) - (mi + ma);  
    }
};