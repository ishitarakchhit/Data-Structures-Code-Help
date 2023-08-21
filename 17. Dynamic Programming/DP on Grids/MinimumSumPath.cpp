/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/


/*
    int f(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){
        if( m < 0 || n < 0) return 0;

        if(m == 0 && n==0) return grid[0][0];

        if(dp[m][n] != -1) return dp[m][n];

        int up =INT_MAX, left= INT_MAX;
        if(m-1 >= 0)
            up = grid[m][n] + f(grid, m-1, n, dp);
        if( n-1 >= 0)
            left = grid[m][n] + f(grid, m, n-1, dp);

        dp[m][n] = min(up, left);
        return dp[m][n];
    }*/

    /*
    int f(vector<vector<int>> &grid, int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        dp[0][0] = grid[0][0];

        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i == 0 && j==0) continue;
                int up = INT_MAX, left = INT_MAX;
                if(i-1 >= 0) up = grid[i][j] + dp[i-1][j];
                if(j-1 >= 0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }

        return dp[m][n];

    }*/


    int f(vector<vector<int>> &grid, int m, int n){
        vector<int> dp(n+1, -1);            //vector to store answers for current row
        vector<int> temp(n+1, -1);        //vector to store answers for previous row
        dp[0] = grid[0][0];

        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i == 0 && j==0) continue;

                int up = INT_MAX, left = INT_MAX;

                if(i-1 >= 0) up = grid[i][j] + temp[j];  // to access the element just above
                if(j-1 >= 0) left = grid[i][j] + dp[j-1]; //to access the element just left
                dp[j] = min(up, left);
            }
            temp = dp;
        }

        return dp[n];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        return f(grid, m-1, n-1);
    }