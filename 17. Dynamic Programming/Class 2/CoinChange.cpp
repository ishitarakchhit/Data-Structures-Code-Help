/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

//to find the answer using recursive approach
    int solutionUsingRec(vector<int> &coins, int amount){
        if( amount == 0){
            return 0;
        }
        if( amount <0){
            return INT_MAX;
        }
        int count = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solutionUsingRec(coins, amount-coins[i]) ;
            if(ans!= INT_MAX)
                count = min(count, ans+1);
        }
        return count;
    }

    //solutin using top down approach: DP
    int solutionUsingTopDown(vector<int> &coins, int amount, vector<int> &dp){
        if( amount == 0){
            return 0;
        }
        if( amount <0){
            return INT_MAX;
        }
        //check condition just after BASe case
        if(dp[amount] != -1)
            return dp[amount];

        int count = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solutionUsingTopDown(coins, amount-coins[i], dp) ;
            if(ans!= INT_MAX)
                count = min(count, ans+1);
        }
        dp[amount] = count;
        return count;
    }

    

    //Solution Using tabulation Method
    int SolveUsingTab(vector<int>& coins, int amount){
        //create dp array
        vector<int> dp(amount+1, -1);

        //update base cases
        dp[0] = 0;

        //run a loop
        for(int target=1; target<= amount; target++){
                int count = INT_MAX;
            for(int i=0; i<coins.size(); i++){
                if(target-coins[i] >=0){

                    int ans = dp[target-coins[i]];
                    if(ans!= INT_MAX)
                        count = min(count, ans+1);
                }
            }
            dp[target] = count;
        }
        return dp[amount];
    }


    //no space optimiztion is possible 
    // for tabulation method 
    //first create dp array
    // then update it with base case
    // then find the range of loop
    // then copy the code from top down and modify it accordingly.
    // first update recursive relation with dp array



    int coinChange(vector<int>& coins, int amount) {
        // int ans  = solutionUsingRec(coins, amount);
        // if(ans == INT_MAX)
        //     return -1;
        // return ans;

        // vector<int> dp(amount+1, -1);
        // int ans = solutionUsingTopDown(coins, amount, dp);
        // if(ans == INT_MAX)
        //     return -1;
        // return ans;

        int ans = SolveUsingTab(coins, amount);
        if(ans == INT_MAX)
            return -1;
        return ans;
    }