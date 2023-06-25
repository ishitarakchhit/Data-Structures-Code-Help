/*
To print the pattern 
**********
*        *
*        *
**********
*/

#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//main function
int main(){

    int r,c ;
    cout<<"Enter the row size:";
    cin>>r;
    cout<<endl<<"Enter the col size";
    cin>>c;

    for (int row = 0; row < r; row++)                                //loop for rows
    {
        for (int col = 0; col < c; col++)                            //loop for columns
        {
            if(row==0 || row==r-1)                                   //print * for every first and last row
                cout<<"*";
            else if((row!=0 ||row!=r-1) &&(col==0 || col==c-1))      //print * for every first and last column in all rows except first and last
                cout<<"*";
            else{
                cout<<" ";                                           //print " " for the rest cells
            }
        }
        cout<<endl;                                                  //change line after every row 
        
    }
    
    
    
} 
