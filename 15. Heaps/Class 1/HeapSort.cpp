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
        index = largest;
        heapify(arr, index, size);
    }
}

void buildHeap(int arr[], int n){
    for (int i = n/2; i >0; i--)
    {
        heapify(arr, i, n);
    }
}


void heapSort(int arr[], int n){
    while(n>1){
        swap(arr[1], arr[n--]);
        int index = 1;
        heapify(arr, index, n);
    }
}
int main(){

    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;
    buildHeap(arr, n);
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr, n );
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}