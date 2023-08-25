#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int func(vector<int> &arr, int n, int k){
    if( n==0) return 0;
    int minpath = 200;
    for (int i = 1; i <= k; i++)
    {
        if(n-i >= 0){
            int path = func(arr, n-i, k) + abs(arr[n] - arr[n-i]);
            minpath = min(minpath, path);
        }
        else    break;
    }
    return minpath;

}

int dp1(vector<int> &arr, int n, int k, vector<int> &dp){
    if( n==0) return 0;
    if(dp[n]!= -1)
        return dp[n];
    int minpath = 200;
    for (int i = 1; i <= k; i++)
    {
        if(n-i >= 0){
            int path = abs(arr[n] - arr[n-i]) + dp1(arr, n-i, k, dp);
            minpath = min(minpath, path);
        }
        else    break;
    }
    dp[n]  = minpath;
    return dp[n];
}

int dp2(vector<int> &arr, int n, int k){
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int index = 1; index<=n; index++){
        int minpath = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if(index-i >= 0){
                int path = abs(arr[index] - arr[index-i]) + dp[index-i];
                minpath = min(minpath, path);
            }
            else    break;
        }
        dp[index]  = minpath;
    }
    return dp[n];
    
}

int main(){
    vector<int> arr = {10, 20, 30, 10, 40};
    vector<int> dp(arr.size(), -1);
    cout<<dp1(arr, arr.size()-1, 3, dp);
    cout<<endl;

    cout<<dp2(arr, arr.size()-1, 3);

}