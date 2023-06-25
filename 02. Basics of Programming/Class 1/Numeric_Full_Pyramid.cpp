/*
To print the pattern 
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5
*/

#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//main function
int main(){

    int n;
    cout<<"Enter the size of numeric full pyramid: ";
    cin>>n;

    int count=0;
    for (int row = 0; row < n; row++)                           //loop for rows
    {   
        for (int col = 0; col < n-row-1; col++)                //loop to print blank spaces in every row before printing stars
        {
        cout<<" ";
        }
        for (int col =0; col <= row; col++)                   //loop to print * after the blank space, row+1 in
        {
            count++;
            cout<<count;
        }
        
        for (int col = 0; col < row; col++)
        {
            count--;
            cout<<count;
        }
        
        cout<<endl;
        
    }
    
} 
