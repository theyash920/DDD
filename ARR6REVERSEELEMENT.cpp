//1
//{ Driver Code Starts


// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void reverseArray(vector<int> &arr){
        int n= arr.size();
        int i = 0;
        int e =n-1;
        while(i<e){
            swap(arr[i],arr[e]);
            i++;
            e--;
        }
    }
    void printArray(const vector<int> &arr){
        int n= arr.size();
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    
    }
};
// FOR VECTOR ANS ONLY 
/*
#include<vector>
using namespace std;
vector <int> reverse(vector<int> v){
    int s =0;
   int  e = v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return  v;
}
void print(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] <<" ";
    }
    cout<<endl;
}*/