//Move all the negative elements to one side of the array 
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[],int n)
{
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i != j){ //i: Represents the current position in the array during iteration.
//j: Tracks the position where the next negative number should be placed.
            swap(arr[i],arr[j]);
            j++;
        }
     }
    }
}
//A UTILITY FUNCTION TO PRINT AN ARRAY
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
// DRIVER CODE
int main()
{
    int arr[] = {-1,2,-3,4,5,6,-7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
//sizeof(arr[0]):
//Returns the size (in bytes) of a single element of the array arr.
//For an integer array, sizeof(arr[0]) will return 4 bytes (the size of one integer).
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
//TIME COMPLEXITY =O(N)
//SPACE COMPLEXITY = O(1) 