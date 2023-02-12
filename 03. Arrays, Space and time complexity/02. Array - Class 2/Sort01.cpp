
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

void printarray(vector<int> arr){
    cout<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    
}
//Approach: two pointer
vector<int> sort01(vector<int> arr){
    
    int start=0, end=arr.size()-1;
    int i=0;

    while (start<=end)
    {   
        
        if(arr[i]==0){
            swap(arr[i], arr[start]);
            start++;
            i++;
        }
        else{
            swap(arr[i], arr[end]);
            end--;
        }
    }
    return arr;
    
}


int main(){
	vector<int> arr{1,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0};

    cout<<endl<<"initial array";
    printarray(arr);
    cout<<endl<<"final array";
	printarray(sort01(arr));
}
