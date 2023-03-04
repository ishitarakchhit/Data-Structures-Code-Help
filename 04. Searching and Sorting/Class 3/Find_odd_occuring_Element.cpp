#include<bits/stdc++.h>
using namespace std;

int oddOccurence(int arr[], int n){
    int s=0; 
    int e=n-1;
    int mid= s+ (e-s)/2;

    while(s<=e){
        if(s==e){
            return arr[s];
        }
        if(mid % 2==0){
            if(arr[mid] == arr[mid+1] ){
                s= mid+2;
            }
            else{
                e=mid;
            }
        }

        else{
            if(arr[mid] == arr[mid-1]){
                s= mid+1;
            }
            else{
                e=mid-1;
            }
        }

        mid = e+ (s-e)/2;

    }

    return -1;
}

int main(){
    int arr[]= { 1,1,2,2,3,3,4,4,3,600,600,4,4};

    cout<<oddOccurence(arr, 13);
}