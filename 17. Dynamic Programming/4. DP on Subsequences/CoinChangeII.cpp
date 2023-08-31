/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/


/*
    int f(vector<int> &coins, int n, int amount, vector<vector<int>> &dp){
        if(n==0){
            if(amount == 0) return 1;
            if(amount %coins[0] == 0) return 1;
            else return 0;
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        //not include
        int notpick = f(coins, n-1, amount, dp);

        //pick
        int pick = 0;
        if(amount >= coins[n])
            pick = f(coins, n, amount-coins[n], dp);
        
        dp[n][amount] = notpick + pick;
        return dp[n][amount];
    }


    int f(vector<int> &coins, int n, int amount){
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        

        for(int target=0; target<=amount; target++){
            if(target%coins[0] == 0) 
                dp[0][target] = 1;
        }

        for(int i=1; i<n; i++){
            for(int target =0; target<=amount; target++){
                int notpick = dp[i-1][target];
                int pick = 0;
                if(target>= coins[i])
                    pick = dp[i][target-coins[i]];
                
                dp[i][target] = notpick + pick;
            }
        }
        return dp[n-1][amount];

    }*/
    int f(vector<int> &coins, int n, int amount){
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);

        for(int target=0; target<=amount; target++){
            if(target%coins[0] == 0) 
                prev[target] = 1;
        }

        for(int i=1; i<n; i++){
            for(int target =0; target<=amount; target++){
                int notpick = prev[target];
                int pick = 0;
                if(target>= coins[i])
                    pick = curr[target-coins[i]];
                
                curr[target] = notpick + pick;
            }
            prev = curr;
        }
        return prev[amount];

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return f(coins, n, amount);
    }
};