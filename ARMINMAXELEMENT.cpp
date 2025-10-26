// Find the min and max element in the array
#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
public:
    vector<int> getMinMax(vector<int> &arr) {
        int min = arr[0];
        int max = arr[0];

        // No need for special case; loop handles single-element arrays fine
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < min) {
                min = arr[i];
            }
            if(arr[i] > max) {
                max = arr[i];
            }
        }

        return {min, max};
    }
};

//{ Driver Code Starts.

/*int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends  