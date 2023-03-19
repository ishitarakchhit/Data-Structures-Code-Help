#include<bits/stdc++.h>
using namespace std;

bool bs(int arr[], int key, int s, int e){                              //use call by referecne to reduce time and space complexity
    if(s>e)
        return 0;
    //solving for one case
    int mid = s + (s-e)/2;

    if(arr[mid]== key)
        return true;
    else if(arr[mid] > key)
        return bs(arr, key, s, mid-1 );
    else 
        return bs( arr, key, mid+1, e);
}
int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n= sizeof(arr)/sizeof(int);
    cout<<bs(arr, 8, 0, n-1);
}