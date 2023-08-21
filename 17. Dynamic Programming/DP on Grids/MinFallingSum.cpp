/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/



/*
    int f(vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp){
        if(m == 0) return matrix[m][n];

        if(m<0 || n<0 || m>=matrix.size() || n>= matrix.size()) return INT_MAX;
        if(dp[m][n] != -1) return dp[m][n];
        int u = INT_MAX, dl = INT_MAX, dr = INT_MAX;

        if(m-1>=0)
            u  = matrix[m][n] + f(matrix, m-1, n, dp);
        if(m-1>=0 && n-1>=0)
            dl = matrix[m][n] + f(matrix, m-1, n-1, dp);
        if(m-1>=0 && n+1< matrix.size())
            dr = matrix[m][n] + f(matrix, m-1, n+1, dp);

        dp[m][n] = min(u, min(dl, dr));
        return dp[m][n];
    }*/
    

    int f(vector<vector<int>> &matrix, int a, int b){
        int n = matrix.size();

        vector<int> dp(n, INT_MAX);
        vector<int> temp(n, INT_MAX);

        temp[b] = matrix[0][b];

        for(int i=1; i<n; i++){
            for(int j= 0; j<n; j++){

                if (i == a && j== b) continue;

                int u = INT_MAX, dl = INT_MAX, dr = INT_MAX;

                if(i-1>=0 && temp[j] != INT_MAX)
                    u  = matrix[i][j] + temp[j];

                if(i-1>=0 && j-1>=0 && temp[j-1] != INT_MAX)
                    dl = matrix[i][j] + temp[j-1];

                if(i-1>=0 && j+1< n && temp[j+1] != INT_MAX)
                    dr = matrix[i][j] + temp[j+1];

                dp[j] = min(u, min(dl, dr));
            
            }

            temp = dp;
        }

        int ans = INT_MAX;

        for(int it = 0; it<n; it++){
            if(dp[it] != INT_MAX){
                ans = min(ans, dp[it]);
            }
        }

        return ans;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        if(n == 1) return matrix[0][0];

        for(int i = 0; i<n; i++){
            ans = min(ans, f(matrix, 0, i));
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }