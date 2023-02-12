#include<iostream>
#include<vector>
using namespace std;

void printarray(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    
}


vector<int> findunion(vector<int> a, vector<int>b){
    vector<int> arr;
    int k=0;
    
    //to mark all the duplicate elements with a random number
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if(b[j]== a[i])
                b[j]=-1;     
        }
        
    }
    
    //to push all the elements from array a to arr
    for (int i = 0; i < a.size(); i++)
    {
        arr.push_back(a[i]);
    }

    //to push all elements from array b to arr except those marked with random value
    for (int j = 0; j < b.size(); j++)
    {
        if(b[j]== -1) 
            continue;
        arr.push_back(b[j]);
    }
    
    //to return the final array
    return arr;
    
}


int main(){
    vector<int> a{1,2,3,4,5};
    vector<int> b{3,4,5,6,7};
    
    //to print the final array
    printarray(findunion(a, b));
    return 0;
}