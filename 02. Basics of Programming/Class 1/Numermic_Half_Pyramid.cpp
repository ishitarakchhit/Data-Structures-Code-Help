/*
To print the pattern 
1
12
123
1234
12345
*/

#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//main function
int main(){

    int n;
    cout<<"Enter the size of numeric half pyramid: ";
    cin>>n;

    for (int row = 0; row < n; row++)                           //loop for rows
    {
        for (int col = 0; col < row; col++)                   //loop for columns to print numbers starting from 1 going till row in every row
        {
            cout<<col+1;
        }
        cout<<endl;
        
    }
    
} 
