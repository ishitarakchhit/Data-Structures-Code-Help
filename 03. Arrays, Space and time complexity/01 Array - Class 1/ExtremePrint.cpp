#include<iostream>
using namespace std;

void extremeprint(int arr[], int size){
    int start=0;
    int end=size-1;

    while(start<end){
        cout<<arr[start++]<<"\t"<<arr[end--]<<"\t";
    }
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    extremeprint(arr, 10);
}
