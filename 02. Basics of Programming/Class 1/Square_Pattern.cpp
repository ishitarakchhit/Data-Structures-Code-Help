/*
To print the pattern 
*****
*****
*****
*****
*****
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
        for (int col = 0; col < n; col++)                   //loop for columns to print n stars in every row
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
    
} 
