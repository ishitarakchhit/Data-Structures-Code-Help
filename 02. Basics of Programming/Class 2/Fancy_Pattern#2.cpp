/*
1
2*2
3*3*3
4*4*4*4
4*4*4*4
3*3*3
2*2
1
*/

#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"Enter the size of fancy pattern: ";
    cin>>n;
    
    //loops for printing the upper part of pattern
    for (int row = 0; row < n; row++)
    {   int count=row+1;

        //loop for prinitng the pattern
        for (int col = 0; col < row+1; col++)
        {
            cout<<count;
            if(col!=row)
                cout<<"*";
        }
        cout<<endl;
    }
    
    //loops for printing the lower part of pattern
    for (int row = 0; row < n; row++)
    {   int count= n-row;

        //loop for printing the pattern
        for (int col = 0; col < n-row; col++)
        {
            cout<<count;
            if(col!=n-row-1)
                cout<<"*";
        }
        cout<<endl;
        
    }
    
    


}
