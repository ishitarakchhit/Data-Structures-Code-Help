#include<iostream>
#include<vector>
using namespace std;

//recursive solution
int rec(int n){
    if(n == 0)
        return 1;
    if( n== 1)
        return 1;
    
    return rec(n-1) + rec(n-2);
}

//DP top down
int topDown(int n, vector<int> &dp){
    if( n == 0)
        return 1;
    if( n== 1)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];
    dp[n] = topDown(n-1, dp) + topDown(n-2, dp);
    return dp[n];
}


//DP: bottom up appraoch
int bottomUP(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    if( n == 0)
        return dp[n];
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
    
}

//Space optimisation
int spaceopt(int n){
    int prev1 = 1;
    int prev2 = 1;
    int curr;

    //base cases
    if( n== 1)
        return prev1;
    
    if(n == 0)
        return prev2;
    
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
    
}


int main(){
    int n = 10;

    cout<<rec(n)<<endl;

    vector<int> dp(n+1, -1);
    cout<<topDown(n, dp)<<endl;

    cout<<bottomUP(n)<<endl;

    cout<<spaceopt(n);
}