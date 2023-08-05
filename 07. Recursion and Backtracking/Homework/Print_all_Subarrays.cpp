#include<bits/stdc++.h>
using namespace std;
print(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    
} 

void rec(vector<int>& arr, int i, int j){
    if(i>= arr.size()){
        return;
    }
    
    if(j<i){
        i++;
        j=arr.size()-1;
    }
    else{

        for (int k = i; k <= j; k++){
            cout<<arr[k];
        }
        cout<<endl;
        j--;
    }
    rec(arr, i, j);
    
    
}

int main(){
    vector<int> arr={1,2,3,4};

    rec(arr, 0, arr.size()-1);
}


//--------OR------------

/*
#include<iostream>
#include<vector>
using namespace std;

void rec(vector<int> arr, int i, vector<int> &ans , vector<vector<int>> &output){
    if(i == arr.size()){
        return;
    }
    
    for(int j=i; j<arr.size(); j++){
        ans.push_back(arr[j]);
        output.push_back(ans);
    }
    ans = {};
    rec(arr, i+1, ans, output);
    return;
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    vector<int> ans;
    vector<vector<int>> output;
    rec(arr,0,  ans, output);

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
} 

*/