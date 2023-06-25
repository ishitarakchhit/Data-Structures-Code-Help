/*
     *
    * *
   * * *
    * *
     *   
*/

#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"Enter the size of solid diamond: ";
    cin>>n;
    
    //loops for printing the upper part of diamond
    for (int row = 0; row < n; row++)
    {
        //loop for printing the blank spaces
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }

        //loop for printing the diamond
        for (int col = 0; col < row+1; col++)
        {
            cout<<"* ";
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

        //loop for printing the diamond
        for (int col = 0; col < n-row; col++)
        {
            cout<<"* ";
        }
        
        cout<<endl; 
    }
    


}
