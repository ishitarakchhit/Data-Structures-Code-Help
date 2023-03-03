/*
[   https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1   ]
Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing. 

Example 1:

Input:
n = 7
arr[] = {1, 5, 3, 4, 3, 5, 6}
Output: 2
Explanation: 
5 is appearing twice and 
its first appearence is at index 2 
which is less than 3 whose first 
occuring index is 3.

Example 2:

Input:
n = 4
arr[] = {1, 2, 3, 4}
Output: -1
Explanation: 
All elements appear only once so 
answer is -1.
*/

#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

//Approach 1: double loop w time complexity O(n^2)
int firstRepeated(int arr[], int n) {
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] == arr[j]){
                    return i+1;
                }
            }    
        }
        return -1;
    }

//Approach2: hashing w time complexity O(n)
int firstRepeated(int arr[], int n) {
        unordered_map<int,int> hash;
        
        for(int i=0; i<n; i++){
            hash[arr[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(hash[arr[i]]> 1){
                return i+1;
            }
        }
        return -1;
    }

int main() {
    int arr[]={ 1,2,3,4,5,5,4,3,2,1,0};

    cout<<firstRepeated(arr,11);
}