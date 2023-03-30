#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int end){

    int mid = start + (end- start)/2;


    int len1 = mid - start +1;
    int len2 = end - mid;

    int *left = new int[len1];
    int *right = new int[len2];
    int k = start;

    //copying elements of arr from start to mid into the left array
    for (int i = 0; i < len1; i++)
    {
        left[i]= arr[k++];
    }
    
    //copying elements of arr from start to mid into the right array
    k= mid+1;
    for(int i = 0; i<len2; i++){
        right[i]= arr[k++];
    }

    int leftIndex = 0;
    int rightIndex= 0;
    int arrayIndex= start;

    //merging the two arrays to arr
    while(leftIndex<len1 && rightIndex<len2){

        if(left[leftIndex]< right[rightIndex]){
            arr[arrayIndex++]= left[leftIndex++];
        }
        else{
            arr[arrayIndex++]= right[rightIndex++];
        }
    }

    //copy the remaining elements into arr 
    while(leftIndex<len1){
        arr[arrayIndex++]= left[leftIndex++];
    }

    //copy the remaining elements into arr 
    while(rightIndex<len2){
        arr[arrayIndex++]= right[rightIndex++];
    }
    
} 
void mergesort(int arr[], int start, int end){
    if(start>=end){
        return;
    }

    int mid = start+ (end-start)/2;

    //to sort the left part
    mergesort(arr, start, mid);
    
    //to sort the right part
    mergesort(arr, mid+1, end);

    //to merge the sorted arrays 
    merge(arr, start, end);

}

int main(){
    int arr[] = {40, 30, 20, 29, 50, 1000, 9000};
    int n=sizeof(arr)/sizeof(int);

    mergesort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}