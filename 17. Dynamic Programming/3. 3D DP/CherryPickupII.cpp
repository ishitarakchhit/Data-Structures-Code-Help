/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 

Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:


Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100
*/



/*
    int f(vector<vector<int>> &grid, int i1, int j1, int i2, int j2, vector<vector<vector<int>>> &dp){
        //cout<<i1<<" "<<j1<<"    "<<i2<<" "<<j2<<endl;

        //if out of bound
        if(j1<0 || j1>grid[0].size()-1 || j2<0 || j2>grid[0].size()-1) return -1e8;

        //base case
        if(i1 == grid.size()-1 || i2== grid.size()-1){
            if(i1 == i2 && j1== j2) return grid[i1][j1];
            else return grid[i1][j1]+grid[i2][j2];
        } 

        if(dp[i1][j1][j2] != -1) return dp[i1][j1][j2];

        int cherry  = 0;
        if(i1==i2 && j1==j2) cherry = grid[i1][j1];
        else cherry = grid[i1][j1] + grid[i2][j2];
        int ans = 0;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                ans = max(ans, cherry + f(grid, i1+1, j1+x, i2+1, j2+y, dp));
            }
        }
        dp[i1][j1][j2] = ans;
        return ans;
        
    }*/

    int f(vector<vector<int>> &grid, int i1, int j1, int i2, int j2){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> front(n, vector<int>(n, 0));
        vector<vector<int>> curr(n, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                int cherry = 0;
                if(j==k) cherry = grid[m-1][j]; 
                else cherry = grid[m-1][j] + grid[m-1][k];
                front[j][k] = cherry;
            }
        }
        
        for(int i=m-2; i>=0; i--){    //!-=== mistake: started from m-1
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    //cout<<i<<" "<<j<<" "<<k;
                    
                    //else
                    int ans = -1e8;
                    

                    for(int x = -1; x<=1; x++){
                        for(int y=-1; y<=1; y++){
                            //if(i==1 && j==0 && k==2)cout<<"here"<<endl;

                            int cherry = 0;

                            if(j==k) cherry = grid[i][j];
                            else cherry = grid[i][j] + grid[i][k];
                            if( j+x<n && k+y<n && j+x>=0 && k+y>=0)       //!----mistake : added another condition for i+1<m but we had to calculate all paths irrespective of condition
                                cherry += front[j+x][k+y];
                            else cherry += -1e7;
                            ans = max(ans, cherry);
                        }
                    }
                    curr[j][k] = ans;
                    //cout<<" "<<ans<<endl;
                }
            }
            front = curr;
        }
        int ans = 0;
        ans = front[0][n-1];

        return ans;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(grid, 0, 0, 0, n-1);
    }