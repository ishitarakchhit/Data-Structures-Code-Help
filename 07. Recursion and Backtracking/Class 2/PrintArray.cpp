#include<iostream>
using namespace std;

//recursive function to print array
void printArray(int arr[], int n){
    if(n<0)
        return;
    
    printArray(arr, n-1);
    cout<<arr[n]<<"\t";
}


int main(){
    int arr[] = {10,15,2,3,5,6,3,49};

    printArray(arr, 7);
}