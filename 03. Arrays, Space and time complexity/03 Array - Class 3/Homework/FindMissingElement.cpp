#include<bits/stdc++.h>
using namespace std;

//Approach1: Sorting + traversal 
int findMissing(vector<int> arr){
    int ans;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size()-1; i++)
    {
        if( arr[i] != arr[i+1]-1 ){
            ans= arr[i]+1;
            break;
        }
    }

    return ans;
}

//Approach: sorting + swapping method
int findMissing2(vector<int> arr){
    int i=0;
    while(i< arr.size()){
        if(arr[i] == i+1){
            i++;
        }
        else{
            if(arr[i] == arr[arr[i]-1])
                return i+1;

            swap( arr[i], arr[arr[i]-1]);
        }
    }
}


int main(){
    vector<int> arr= {1,2,3,5,5};

    cout<<findMissing(arr);
    cout<<findMissing2(arr);
}