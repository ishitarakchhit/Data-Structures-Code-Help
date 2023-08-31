/*
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.



You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.



Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.


Input Format:
The first line of input contains two integers ‘n’ and ‘w’ - number of items and weight capacity of the knapsack.

The second line of each test case contains 'n' integers - elements of 'profit' array.

The third line of each test case contains 'n' integers - elements of 'weight' array.


Output Format:
Return an integer denoting the maximum profit that can be obtained by filling the knapsack.


Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
*/


//--------------------Solution------------------------


/*
int f(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(n == 0){
        if(weight[0] <= w){
            int temp = w/weight[0];
            return profit[0]*temp;
        }
        else
            return 0;
    }

    if(dp[n][w] != -1) return dp[n][w];

    //not picking the current weight
    int notpick = f(n-1, w, profit, weight, dp);

    //picking
    int pick = 0;
    if(weight[n] <= w)
        pick = profit[n] + f(n, w-weight[n], profit, weight, dp);
    
    dp[n][w] = max(notpick, pick);
    return dp[n][w];
}

int f(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int> (w+1, 0));

    for(int i=0; i<=w; i++){
        if(weight[0] <= i){
            int temp = i/weight[0];
               dp[0][i] = profit[0]*temp;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=w; j++){
            //not picking the current weight
            int notpick = dp[i-1][j];

            //picking
            int pick = 0;
            if(weight[i] <= j)
                pick = profit[i] + dp[i][j-weight[i]];
            
            dp[i][j] = max(notpick, pick);
        }
    }

    return dp[n-1][w];
    
}*/


int f(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1, 0);
    vector<int> curr(w+1, 0);

    for(int i=0; i<=w; i++){
        if(weight[0] <= i){
            int temp = i/weight[0];
               prev[i] = profit[0]*temp;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=w; j++){
            //not picking the current weight
            int notpick = prev[j];

            //picking
            int pick = 0;
            if(weight[i] <= j)
                pick = profit[i] + curr[j-weight[i]];
            
            curr[j] = max(notpick, pick);
        }
        prev = curr;
    }

    return prev[w];
    
}


int f(int n, int w, vector<int> &profit, vector<int> &weight){
    //vector<int> prev(w+1, 0);
    vector<int> curr(w+1, 0);

    for(int i=0; i<=w; i++){
        if(weight[0] <= i){
            int temp = i/weight[0];
               curr[i] = profit[0]*temp;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=w; j++){
            //not picking the current weight
            int notpick = curr[j];

            //picking
            int pick = 0;
            if(weight[i] <= j)
                pick = profit[i] + curr[j-weight[i]];
            
            curr[j] = max(notpick, pick);
        }

    }

    return curr[w];
    
}