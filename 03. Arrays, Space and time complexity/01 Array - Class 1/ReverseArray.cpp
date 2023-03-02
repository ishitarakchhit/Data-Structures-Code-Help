#include<iostream>
using namespace std;

void reverse(int arr[], int size){
    int i=0; 
    int j=size-1;
    while(i<j){
        swap(arr[i++], arr[j--]);
    }
}

void printarray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"\t";
    }
    
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    reverse(arr, 10);
    printarray(arr, 10);
}