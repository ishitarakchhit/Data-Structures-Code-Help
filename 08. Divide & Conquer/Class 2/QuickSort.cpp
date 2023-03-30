#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){
    int count=0;
    int pivotElement = arr[s];
    int pivotIndex = s;
    
    //loop to find the correct index of pivot element
    for (int i = s+1; i <=e; i++)
    {
        if(pivotElement >= arr[i])
            count++;
    }

    int rightIndex = count+s;

    //to swap the elements at pivotIndex and its correct index
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex= rightIndex;

    int i=s;
    int j=e;
    
    //loop to place all elements smaller than pivotIndex to the left and bigger elements to the right 
    while(i< pivotIndex && j> pivotIndex){
        while(arr[i] < pivotElement){
            i++;
        }
        while(arr[j] > pivotElement){
            j--;
        }
        if(i<pivotIndex && j< pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
    
}


void quicksort(int arr[], int s, int e){
    //base case
    if(s>=e){
        return;
    }
    
    //function partition returns the pivot index and we make a recursive call for the left and the right part
    int index = partition(arr, s, e);

    //left part
    quicksort(arr, s, index-1);

    //right part
    quicksort(arr, index+1, e);
}


int main(){
    int arr[]= {100,8,6,4,2,10};
    int n = 6;
    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
}