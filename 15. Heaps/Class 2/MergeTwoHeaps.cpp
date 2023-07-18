#include<queue>
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


void mergeHeaps(int arr1[], int arr2[], int size1, int size2){
    int k = 1;
    for(int i = size1; i<=size1+size2; i++){
        arr1[i] = arr2[k++];
    }
    buildHeap(arr1, size1+size2);
    for(int i =0; i<=size1+size2; i++)
        cout<<arr1[i]<<" ";
    return;
}

int main(){
    int arr1[] = {-1,1,2,3,4,5,6};
    int arr2[] = {-1,7,8,9,10};
    int size1 = 6;
    int size2 =4;
    mergeHeaps(arr1, arr2, size1, size2);
    

}