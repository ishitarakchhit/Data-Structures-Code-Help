#include<iostream>
using namespace std;


void printmatrix(int arr[][4], int n){
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
        
    }
    
}

//function to transpose a matrix
void transpose(int arr[][4], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        
    }
    
}

int main(){
    int arr[4][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    
    //print the matrix
    printmatrix(arr,4);
    //transpose the matrix
    transpose(arr, 4);
    //print the matrix
    printmatrix(arr, 4);
}