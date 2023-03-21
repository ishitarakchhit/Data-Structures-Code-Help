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