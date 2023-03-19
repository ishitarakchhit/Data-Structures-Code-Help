#include<bits/stdc++.h>
using namespace std;


int findpivot(vector <int> & arr, int n){
    int s= 0; 
    int e= n-1;
    int mid= e+(s-e)/2;
    
    while(s<e){
        if(arr[mid]>= arr[0])
            s=mid+1;
        else
            e=mid;
        mid=s+(e-s)/2;
    }
    return s;
}