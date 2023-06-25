/*
To print the pattern 
*
**
***
****
*****
******
*/

#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//main function
int main(){

    int n;
    cout<<"Enter the size of pyramid: ";
    cin>>n;

    for (int row = 0; row < n; row++)                           //loop for rows
    {
        for (int col = 0; col < row+1; col++)                   //loop for columns to print * in number row+1
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
    
} 
