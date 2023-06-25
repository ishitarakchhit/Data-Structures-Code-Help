/*
********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****
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
        //loop to print the left part of pattern
        for (int col = 0; col < n-row-1+4; col++)
        {
            cout<<"*";
        }
        
        int count = row+1;
        //loop to print the pattern
        for (int col = 0; col < row+1; col++)
        {
            cout<<count;
            if(col!=row)
                cout<<"*";
        }
        

        //loop to print the right part of pattern
        for (int col = 0; col < n-row-1+4; col++)
        {
            cout<<"*";
        }
        
        cout<<endl;
        
    }
    
    
    


}
