/*
To print the pattern 
        1
      1   2
    1       3
  1           4
1   2   3   4   5 
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

    
    for (int row = 0; row < n; row++)                           
    {   int count=0;

        //loop 1 for printing spaces
        for (int col = 0; col < n-row-1; col++)                
        {
        cout<<"  ";
        }
        

        if(row==0 || row==n-1){
            //loop2 for printing left part of hollow pyramid
            for (int col = 0; col <= row; col++)
            {
                cout<<col+1<<"   ";
            }           
        }
     
        else{
          
            //loop2 for printing left part of pyramid
            for (int col =0; col < 1; col++)                   
            {
                count++;
                cout<<count;
            }

            //loop3 for printing spaces inside pyramid
            for (int col = 0; col < row; col++)
            {
                cout<<"    ";
                count++;
            }
        
            //loop4 for printing right part of hollow pyramid
            for (int col = 0; col < 1; col++)
            {
                cout<<count;
            }
        }
        
        
        cout<<endl;
        
    }
    
} 
