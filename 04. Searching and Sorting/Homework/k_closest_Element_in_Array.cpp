/*
[   https://leetcode.com/problems/find-k-closest-elements/description/  ]
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int bs(vector<int>& arr, int x){
        int s=0; 
        int e= arr.size()-1;
        int ans = e;
        while(s<=e){
            int mid= s+ (e-s)/2;
            if(arr[mid]>= x){
                ans= mid;
                e=mid-1;
            }
            else if(x> arr[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            
        }
        return ans;
    }


    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n= arr.size();
        vector<int> ans;
        int e= bs(arr, x);
        int s= e-1;
        int count=0;

        while(k--){
            if(s<0){
                e++;
            }
            else if(e>=n){
                s--;
            }
            else if(abs(arr[s]-x) <= abs(arr[e]-x)){
                s--;
            }
            else {
                e++;
            }
        }
        
        
        return vector<int> (arr.begin()+s+1, arr.begin()+e);
    }
};