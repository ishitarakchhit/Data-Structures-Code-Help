#include<bits/stdc++.h>
using namespace std;

bool func(int arr[], int size){
    if(size==0 || size==1)                      //base case
        return true;
    if(arr[0]>arr[1])                           //processing
        return false;

    bool remain = func(arr+1, size-1);         //recursive relation
    return remain;                               
}

int main(){
    int size;
 
    cout<<"Enter the size of the array";      //taking the input of size of array from user
    cin>>size;
    
    int arr[size];
  
    cout<<"Enter the array";
    for (int i = 0; i < size; i++)             //taking the input of array from user
    {
        cin>>arr[i];
    }
    

    if(func(arr, size))
        cout<<"True";
    else
        cout<<"False";
    
    
} 