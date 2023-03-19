#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int s, int e, int key){
    int mid = e+ (s-e)/2;

    while(s<=e){
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            s = mid+1;
        else 
            e = mid-1;
        
        mid = e+ (s-e)/2;
    }
    return -1;
}


int exponential_search(int arr[], int n, int key){
    if(arr[0] == key)
        return 0;

    int i=1;
    while(i<n && arr[i]<=key){                                 
        i*=2;                                                   //incrementing i in power of 2 to jump exponentially
    }                                                           //as soon as arr[i] > key we are able to get our search space which is from the previous i to the current i

    return binarysearch(arr, i/2, min(i, n-1), key);
}

int main(){
    int a[]={3, 4, 5, 6, 11, 13 ,14, 15, 56, 70};
    int n= sizeof(a)/sizeof(int);
    int x= 56;

    cout<<exponential_search(a, n, x);
    return 0;
}
