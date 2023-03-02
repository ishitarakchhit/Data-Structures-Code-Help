#include<iostream>
using namespace std;


int findmax(int arr[], int size){
    int large=arr[0];

    for (int i = 0; i < size; i++)
    {
        if(large<arr[i])
            large = arr[i];
    }

    return large;
    
}
int main(){
    int arr[5]={1,2,3,4,1000};

    cout<<findmax(arr, 5);
}