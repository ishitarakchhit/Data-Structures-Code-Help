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


vector<int> findintersection(vector<int> a, vector<int>b){
    vector<int> arr;
    int k=0;
    
    //to push all the elements into arr if they are common in array a and b
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if(b[j]== a[i]){
                arr.push_back(a[i]);
                break;    
            }
        }
        
    }
    
    
    //to return the final array
    return arr;
    
}


int main(){
    vector<int> a{1,2,3,4,5};
    vector<int> b{3,4,5,1,7};
    
    //to print the final array
    printarray(findintersection(a, b));
    return 0;
}