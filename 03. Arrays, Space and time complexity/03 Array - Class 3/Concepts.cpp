#include<iostream>
#include<vector>
using namespace std;


void printmatrix(int arr[][5], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
        
    }
}


int main(){
    //to declare and initialize a 2d array
    int arr[2][5]= {{1,2,3,4,5}, {6,7,8,9,10}};

    //to print the 2d array
    cout<<"Printing matrix arr"<<endl;
    printmatrix(arr,2,5);

    //to declare 2d vector 
    vector<vector<int> > v;

    //to add elements into a 2d vector
    vector<int> a{1,2,3,4};
    vector<int> b{5,6};
    vector<int> c{9,10,11,12};

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    //to print the 2d vector

    cout<<endl<<"Printing 2d Vector v"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<"\t";
        }
        cout<<endl;
        
    }

    //alter method to declare and initialize a 2d vector
    //vector<vector<int> > vector_name (numberofrows , vector<int> (numberofcolumns, elementvalue));
    vector<vector<int>> mat(3, vector<int>(5,-8));
    cout<<endl<<"Printing 2d vector with rows 3 and columns 5 initialized with -8"<<endl;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
        
    }

    //to print a particular value
    cout<<endl<<"Printing a particular element of matrix arr"<<endl<<v[2][3];                             //element present at row index 1 and col index 2
    
    

}