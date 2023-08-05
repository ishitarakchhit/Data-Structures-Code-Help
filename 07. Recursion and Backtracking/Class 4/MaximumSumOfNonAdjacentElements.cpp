#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int> &arr, int i){
    if(i>= arr.size())
        return 0;
    
    //if we start from current element
    int ans = arr[i] + maxSum(arr, i+2);

    //if we start from next element;
    int ans2 = maxSum(arr, i+1);

    return max(ans, ans2);
}


int main(){
    vector<int> arr = {2,1,4,9, 90};
    cout<<maxSum(arr, 0);

    return 0;
}