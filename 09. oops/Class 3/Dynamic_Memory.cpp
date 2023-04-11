#include<iostream>
using namespace std;

int main(){
    int* a= new int;

    int row = 3;
    int col = 5;

    int** arr= new int*[row];
    for (int i = 0; i < col; i++)
    {
        arr[i] = new int[row];
    }

    
    
    
}