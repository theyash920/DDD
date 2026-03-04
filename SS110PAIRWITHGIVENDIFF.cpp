class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        unordered_map<int,int> m;
        int size = arr.size();
        
        // Build frequency map
        for(int i = 0; i < size; i++){
            m[arr[i]]++;
        }
        
        // If x == 0, we need duplicates
        if(x == 0){
            for(auto& p : m){
                if(p.second > 1)
                    return true;
            }
            return false;
        }
        
        // For x != 0, check if arr[i] + x or arr[i] - x exists
        for(int i = 0; i < size; i++){
            if(m.find(arr[i] + x) != m.end() || 
               m.find(arr[i] - x) != m.end()){
                return true;
            }
        }
        
        return false;
    }
};

//short apporach using sets
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        unordered_set<int> s;
        
        for(int num : arr){
            if(s.count(num + x) || s.count(num - x))
                return true;
            s.insert(num);
        }
        return false;
    }
};