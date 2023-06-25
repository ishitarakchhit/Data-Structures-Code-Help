/*
     *
    * *
   *   *
   *   *
    * *
     *   
*/

#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"Enter the size of hollow diamond: ";
    cin>>n;
    
    //loops for printing the upper part of diamond
    for (int row = 0; row < n; row++)
    {
        //loop for printing the blank spaces
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }

        //loop for printing the left part of diamond
        for (int col = 0; col < 1; col++)
        {
            cout<<"* ";
        }
        

        //loop for printing the hollow part of diamond
        for (int col = 0; col < row-1; col++)
        {
            cout<<"  ";
        }

        //loop for printing the right part of diamond
        for (int col = 0; col < 1 && row !=0; col++)
        {
            cout<<"*";
        }
        
        
        cout<<endl;   

    
    }
    
    //loops for printing the lower part of diamond
    for (int row = 0; row < n; row++)
    {
        //loop for printing the blank spaces
        for (int col = 0; col < row; col++)
        {
            cout<<" ";
        }

        //loop for printing the left part of diamond
        for (int col = 0; col < 1; col++)
        {
            cout<<"* ";
        }
        

        for (int col = 0; col < n-row-2; col++)
        {
            cout<<"  ";
        }
        
        for (int col = 0; col < 1 && row!= n-1; col++)
        {
            cout<<"*";
        }
        
        cout<<endl; 
    }
    


}
