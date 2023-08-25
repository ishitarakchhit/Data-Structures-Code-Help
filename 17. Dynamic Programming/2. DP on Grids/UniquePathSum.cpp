/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
*/


/*
int f(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return 1;        //we have reached the destination
        if(m<0 || n<0) return 0;             //we have crossed the boundary so did not reach the destination
        
        //check for dp array
        if( dp[m][n] != -1) return dp[m][n];
        //for travelling up
        int up = f(m-1, n, dp);
        //for left
        int left = f(m, n-1, dp);

        //return total
        dp[m][n] = up+left;
        return dp[m][n]; 

    }
*/

    int f (int m, int n){
        vector<int> dp(n);
        //set the base cases
            vector<int> temp(n);
        dp[0]  = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( i==0 && j==0) continue;
                else{

                    int up = 0, left = 0;
                    if(i>0)
                    up = temp[j];
                    if(j>0)
                    left = dp[j-1];
                    dp[j] = up + left;
                }
            }
            temp = dp;
        }
        return dp[n-1];

    }
    int uniquePaths(int m, int n) {
        //vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m, n);
    }