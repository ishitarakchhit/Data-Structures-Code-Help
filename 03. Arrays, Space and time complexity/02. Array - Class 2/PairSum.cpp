
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
vector<int> PairSum(vector<int> arr, int sum){
    
    int i=0;
    int j=0;
    vector<int> a;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[i]+ arr[j]== sum){
                a.push_back(arr[i]);
                a.push_back(arr[j]);
                return a;
            }
        }
        
    }
    return a;
    
    
}


int main(){
	vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    int sum=10;

    cout<<endl<<"initial array";
    printarray(arr);
    cout<<endl<<"final ans";
	printarray(PairSum(arr,10));
}
