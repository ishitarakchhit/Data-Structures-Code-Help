/*
To print the pattern 
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/

#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//main function
int main(){

    int n;
    cout<<"Enter the size of inverted half pyramid: ";
    cin>>n;

    for (int row = 0; row < n; row++)                           //loop for rows
    {
        for (int col = 0; col < n-row; col++)                   //loop for columns to print numbers from 1 to n-row
        {
            cout<<col+1;
        }
        cout<<endl;
        
    }
    
} 
