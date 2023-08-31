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


/*
    int f(vector<int> &coins, int n, int amount, vector<vector<int>> &dp){
        if(n==0){
            if(amount != 0){
                if(amount%coins[n] != 0) return -1;
                else return amount/coins[n];
            }
            else
                return 0;
            
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        //not pick
        
        int notpick = 0 + f(coins, n-1, amount, dp);         //picking up 0 coins
        if(notpick == -1) notpick = 1e9;
        //pick 
        int pick = 1e9;
        if(coins[n] <= amount){
            int temp = f(coins, n, amount-coins[n], dp);
            if(temp != -1)
                pick = 1 + temp;                             //picking up 1 coins
        }

        return min(pick, notpick);
    }
    
    int f(vector<int> &coins, int n, int amount){
        //base case
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        for(int money = 1; money<=amount; money++){
            if(money % coins[0] != 0) dp[0][money] = 1e9;
            else dp[0][money] = money/coins[0];
        }
        for(int i=0; i<n; i++){
            dp[i][0] = 0;

        }

        for(int i=1; i<n; i++){
            for(int money = 1; money<=amount; money++){
                int notpick = dp[i-1][money];
                if(notpick == -1) notpick = 1e9;
                int pick = 1e9;
                if(coins[i] <= money){
                    int temp = dp[i][money-coins[i]];
                    if(temp!= -1)
                        pick = 1+temp;
                }
                dp[i][money] = min(pick, notpick);
            }
        }
        if(dp[n-1][amount] == 1e9) return -1;
        return dp[n-1][amount];

    }*/
    int f(vector<int> &coins, int n, int amount){
        //base case
        vector<int> prev(amount+1, -1);
        for(int money = 1; money<=amount; money++){
            if(money % coins[0] != 0) prev[money] = 1e9;
            else prev[money] = money/coins[0];
        }
        prev[0] = 0;

        vector<int> curr(amount+1, -1);
        curr[0] = 0;

        for(int i=1; i<n; i++){
            for(int money = 1; money<=amount; money++){
                int notpick = prev[money];
                if(notpick == -1) notpick = 1e9;
                int pick = 1e9;
                if(coins[i] <= money){
                    int temp = curr[money-coins[i]];
                    if(temp!= -1)
                        pick = 1+temp;
                }
                curr[money] = min(pick, notpick);
            }
            prev = curr;
        }
        if(prev[amount] == 1e9) return -1;
        return prev[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return f(coins, n, amount);
    }