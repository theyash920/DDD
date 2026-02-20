//time complexity O(m+n)
//space complexity O(n)
class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> freq;
        
        // Count frequency of each element in 'a'
        for(int i = 0; i < a.size(); i++){
            freq[a[i]]++;  // ← Changed from = 1
        }
        
        // Check if 'b' elements exist with sufficient frequency
        for(int j = 0; j < b.size(); j++){
            if(freq[b[j]] == 0){  // Not present or count exhausted
                return false;
            }
            freq[b[j]]--;  // ← Decrement the count
        }
        
        return true;
    }
};

// claude optimised     
bool isSubset(vector<int> &a, vector<int> &b) {
    unordered_map<int, int> freq;
    
    // Count frequency of elements in 'a'
    for(int num : a){
        freq[num]++;
    }
    
    // Check if 'b' elements exist with sufficient frequency
    for(int num : b){
        if(freq[num] == 0){
            return false;
        }
        freq[num]--;
    }
    
    return true;
}