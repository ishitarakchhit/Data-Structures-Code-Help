
/*
[   https://ww                  w.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549 ]
Find the first and last occurance of element k in a sorted array.
*/

#include <bits/stdc++.h> 
using namespace std;

int first(vector<int>& arr, int n, int k){
    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==k){
            ans= mid;
            e=mid-1;
        }
        else if(arr[mid]<k){
            s=mid+1;
        }
        else
            e=mid-1;
        
        mid=s+(e-s)/2;
    }
    return ans;
}

int last(vector<int>& arr, int n, int k){
    int s=0, e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==k){
            ans= mid;
            s=mid+1;
        }
        else if(arr[mid]<k){
            s=mid+1;
        }
        else
            e=mid-1;
        
        mid=s+(e-s)/2;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair <int, int> p;
    p.first= first(arr, n, k);
    p.second= last(arr,n,k);
    
    return p;
}