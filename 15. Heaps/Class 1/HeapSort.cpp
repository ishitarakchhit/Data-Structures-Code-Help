#include<iostream>
using namespace std;

void heapify(int arr[], int &index, int size){

    int largest = index;
    int left = index*2;
    int right = index*2 +1;

    if( left<=size && arr[left] > arr[largest])
        largest = left;
    
    if(right <=size && arr[right] > arr[largest])
        largest = right;

    if(largest != index){
        swap(arr[largest], arr[index]);
        largest = index;
        heapify(arr, index, size);
    }
}

void buildHeap(int arr[], int n){
    for (int i = n/2; i >0; i--)
    {
        heapify(arr, i, n);
    }
}

int main(){

    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;
    buildHeap(arr, n);

    for (int i = 0; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}