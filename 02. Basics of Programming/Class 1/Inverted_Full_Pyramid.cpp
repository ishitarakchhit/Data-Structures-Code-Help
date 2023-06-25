/*
To print the pattern 
* * * * * * 
 * * * * *
  * * * * 
   * * *
    * *
     *
*/

#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//main function
int main(){

    int n;
    cout<<"Enter the size of inverted full pyramid: ";
    cin>>n;

    for (int row = 0; row < n; row++)                           //loop for rows
    {   for (int col = 0; col < row; col++)                //loop to print blank spaces in every row before printing stars, equal to row number
    {
        cout<<" ";
    }
    
        for (int col = 0; col < n-row; col++)                   //loop to print * after the blank space, equal to n-row in number
        {
            cout<<" *";
        }
        cout<<endl;
        
    }
    
} 
