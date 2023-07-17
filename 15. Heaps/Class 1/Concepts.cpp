#include<iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int size ;
    int totalsize;

    //constructor
    Heap(int totalsize){
        this->totalsize = totalsize;
        this->size = 0;
        arr = new int[totalsize+1];
        arr[0] = -1;
    }

    void insert(int value);
    void printHeap();
    int deleteHeap();
};


//function to insert value into heap
void Heap:: insert(int value){
    if(size == totalsize){
            cout<<"Heap is full"<<endl;
            return;
        }
        size++;
        arr[size] = value;
        int index = size;

        while(index >1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
}

//function to print heap
void Heap:: printHeap(){
    cout<<endl;
    for(int i = 0; i<=size; i++)
        cout<<arr[i]<<" ";
        cout<<endl;
}

//function to delete the root value from Heap
int Heap:: deleteHeap(){
    int data = arr[1];

    arr[1] = arr[size--];
    int index = 1;
    while(index <= size){

        int left = index*2;
        int right = index*2 +1;
        int largest = index;

        if(left<=size && arr[left] > arr[largest])   
            largest = left;
        
        if(right<= size && arr[right] > arr[largest])  
            largest = right;

        if(largest == index)   
            return data;

        else{
            swap(arr[largest], arr[index]);
            index = largest;
        }
    } 

    return data;
}

//main function
int main(){
    Heap* h = new Heap(10);
    h->insert(100);
    h->insert(50);
    h->insert(60);
    h->insert(40);
    h->insert(45);
    h->insert(53);
    h->insert(52);
    h->printHeap();
    cout<<"size"<<h->size;
    cout<<"Deleted value: "<<h->deleteHeap();
    h->printHeap();
}