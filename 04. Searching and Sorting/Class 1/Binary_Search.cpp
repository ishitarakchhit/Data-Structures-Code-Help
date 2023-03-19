#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//Approach: we compare the arr[mid] element with the key and if arr[mid] < key then we search in the right part else in the left part

int bsearch(int arr[], int size, int key){

    int s=0;
    int e= size-1;
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

//main function
int main(){

    int size;
 
    cout<<endl<<"Enter the size of the array: ";      //taking the input of size of array from user
    cin>>size;
    
    int arr[size], key;
  
    cout<<"Enter the array: ";
    for (int i = 0; i < size; i++)             //taking the input of array from user
    {
        cin>>arr[i];
    }

    cout<<endl<<"Enter the key element: ";
    cin>>key;

    cout<<bsearch(arr, size, key);
    
    
} 