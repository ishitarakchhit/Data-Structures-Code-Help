#include<iostream>
using namespace std;


void rowsum(int arr[][5], int row, int col){
    for (int i = 0; i < row; i++)
    {   int sum=0;
        for (int j = 0; j < col; j++)
        {
            sum+=arr[i][j];
        }
        cout<<endl<<"row "<<i<<", sum= "<<sum;     
    }
}
void colsum(int arr[][5], int row, int col){
    for (int i = 0; i < col; i++)
    {   int sum=0;
        for (int j = 0; j < row; j++)
        {
            sum+=arr[j][i];
        }
        cout<<endl<<"col "<<i<<", sum= "<<sum;     
    }
}




int main(){
    //to declare and initialize a 2d array
    int arr[2][5]= {{1,2,3,4,5}, {6,7,8,9,10}};

    //rowwise sum
    rowsum(arr, 2, 5);
    //colwise sum
    colsum(arr, 2, 5);
}