/*

* * * * * *
*       *
*     *
*   *
* *
*

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    
    //taking input of size of pyramid
    cout<<"Enter the size of inverted hollow half pyramid: ";
    cin>>n;


    for (int row = 0; row < n; row++)
    {

        //for printing the first and last row
        if(row==0 || row==n-1){
            for (int col = 0; col < n-row; col++)
            {
                cout<<"* ";
            }
        }
        
        //for printing the rows except first and last
        else{
            cout<<"*";

            //for printing the hollow part of pattern
            for (int col = 0; col < n-row-2; col++)
            {
                cout<<"  ";
            }

            cout<<" *";
            
        }
        cout<<"\n";
    
    }
    
    
}
