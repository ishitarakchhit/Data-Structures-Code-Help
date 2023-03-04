#include<bits/stdc++.h>
using namespace std;

int bsearch(int arr[], int n, int key){
    int s=0;
    int e= n-1;
    int mid = s+ (e-s)/2;

    while(s<=e){
        if(arr[mid] == key){
            return mid;
        }
        if(mid-1 >=s && arr[mid-1] == key)
            return mid-1;
        if(mid+1 <=e && arr[mid+1] == key)
            return mid+1;
        
        else if(arr[mid] < key){
            s= mid+2;
        }
        else{
            e = mid-2;
        }

        mid = s+(s-e)/2;
    }

return -1;
}
int main(){
    int arr[7] = {3,10,20,40,70,50,80};

    cout<<bsearch(arr, 7, 50);
}