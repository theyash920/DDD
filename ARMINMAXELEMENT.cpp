// Find the min and max element in the array
// Time Complexity: O(n)
// Space Complexity: O(1)
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
// }*/  

//using min occurences 


class Solution {
  public:
    int minOccurences() {
        // code here
    if(n%2 == 0){
    if(a[0] > a[1]){
        max = a[0];
        min = a[1];
    }
    else{
        max = a[1];
        min = a[0];
    }
    i = 2; // no of elements to be compared
}
else{
    max = a[0];
    min = a[0];
    i = 1; // no of elements to be compared
}

while( i < n-1){
    if(a[i] > a[i+1]){
        if(a[i] > max){
            max = a[i];
        }
        if(a[i+1] < min){
            min = a[i+1];
        }
    }
    else{
        if(a[i+1] > max){
            max = a[i+1];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    i = i + 2;
}
    }
};