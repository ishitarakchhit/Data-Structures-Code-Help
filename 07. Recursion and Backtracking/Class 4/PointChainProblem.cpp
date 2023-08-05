#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int func(vector<int> arr, int target){
    if(target <0)
        return INT_MAX;
    if(target == 0)
        return 0;

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
            int ans = func(arr, target-arr[i]);
            if(ans!=INT_MAX)
            mini = min(mini, ans+1);              //The +1 is added because we are using one coin in this iteration, and we are calculating the total number of coins needed.
    }
    return mini;
    

}



int main(){
    vector<int> arr = {1,2};
    int target = 5;
    int ans = 100;
    cout<<func(arr, target);
}