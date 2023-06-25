/*
To print the pattern 
     *
    * *
   * * * 
  * * * *
 * * * * *
* * * * * * 
*/

#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//main function
int main(){

    int n;
    cout<<"Enter the size of full pyramid: ";
    cin>>n;

    for (int row = 0; row < n; row++)                           //loop for rows
    {   for (int col = 0; col < n-row-1; col++)                //loop to print blank spaces in every row before printing stars
    {
        cout<<" ";
    }
    
        for (int col = 0; col <= row; col++)                   //loop to print * after the blank space, row+1 in number
        {
            cout<<" *";
        }
        cout<<endl;
        
    }
    
} 
