//Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
//{ Driver Code Starts for input 102 this code output is 012
// DUTCH NATIONAL FLAG PROBLEM
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr){
        int left = 0, mid = 0, right = arr.size() - 1;
        
        // Using three pointers to sort the array
        while (mid <= right) {
            if (arr[mid] == 0) {
                swap(arr[left], arr[mid]);
                left++;
                mid++;
            } 
            else if (arr[mid] == 1) {
                mid++;
            } 
            else { // arr[mid] == 2
                swap(arr[mid], arr[right]);
                right--;
            }
        }
    }
};

//{ Driver Code Starts.
/*int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends