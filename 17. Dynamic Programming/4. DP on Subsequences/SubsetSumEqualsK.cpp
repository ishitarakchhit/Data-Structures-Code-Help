/*
You are given an array of non-negative integers and an integer value ‘target’. You need to search if there is a subset whose sum is equal to ‘target’.

Let us see a few examples: 

Example 1

Input: 

arr: {1, 2, 3, 4, 5}

target: 10

Output: True

Explanation: 

{1, 4, 5} is one of the subsets of the input array whose subset-sum is equal to the target value i.e., 10.

 

Example 2

Input: 

arr: {3, 7, 12, 2, 5}

target: 11

Output: False

Explanation: 

There is no subset whose subset-sum is equal to the given target value.
*/


/*
bool f(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    //base cases
    //when target is reached
    if(k == 0) return true;

    //if last element is equal to target
    if(n == 0) return arr[n] == k;
    

    if(dp[n][k] != -1) return dp[n][k];

    //when we do not include the current element
    bool notpick = f(n-1, k, arr, dp);

    //when we do not include the current element
    bool pick = false;
    if(arr[n] <= k)
        pick = f(n-1, k-arr[n], arr, dp);

    dp[n][k] = pick|notpick;
    return dp[n][k];
} 


bool f(int n, int k, vector<int> &arr){
    //dp array
    vector<bool>> dp(n, vector<bool> (k+1, false));

    //setting the base cases
    //when target == 0 every index of array will return true
    for(int i=0; i<n; i++) dp[i][0] = true;

    //when we are at 0th index and target == arr[0] return true;
    //if(arr[0] < k)
        dp[0][arr[0]] = true;

    //run loops
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            bool notpick = dp[i-1][j];
            bool pick = false;
            if(arr[i] <= j)
                pick = dp[i-1][j-arr[i]];

            dp[i][j] = pick | notpick;

        }
    }

    return dp[n-1][k];
} */


bool f(int n, int k, vector<int> &arr){
    //dp array
    vector<bool> prev(k+1, false);
    vector<bool> dp(k+1, false);

    //setting the base cases
    //when target == 0 every index of array will return true
    prev[0] = true;
    //when we are at 0th index and target == arr[0] return true;
    prev[arr[0]] = true;

    dp[0] = true;         //everytime for target==0 all indiced = 0
    

    //run loops
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            bool notpick = prev[j];
            bool pick = false;
            if(arr[i] <= j)
                pick = prev[j-arr[i]];

            dp[j] = pick | notpick;

        }
        prev = dp;
    }

    return dp[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {

    //vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n, k, arr);
}