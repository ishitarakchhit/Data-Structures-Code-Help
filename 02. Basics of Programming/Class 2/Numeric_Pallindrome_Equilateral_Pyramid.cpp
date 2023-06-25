/*
    1
   121
  12321
 1234321
123454321
*/


#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"Enter the size of Alphabet Pallindrome Pyramid: ";
    cin>>n;
    
    //loops to print the pattern
    for (int row = 0; row < n; row++)
    {   
        //loop to print the blank spaces
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }
        
        int count = 1;
        //loop to print the increasing part of pattern
        for (int col = 0; col < row+1; col++)
        {
            cout<<count++;
        }
        
        count-=2;
        
        //loop to orint the decreasing part of pattern
        for (int col = 0; col < row; col++)
        {
            cout<<count--;
        }
        cout<<endl;
        
    }
    
    
    


}
