/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/




//solution-------- using BFS or DFS

int numEnclaves(vector<vector<int>>& grid) {
        //Approach: using BFS or DFS
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        
        //pushing all boundary elements into queue for performing multisource BFS
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(grid[n-1][j] == 1){
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1){
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        //now traverse through all queue elements and apply bfs
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //to push all directions 
            for(int i=0; i<4; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m)
                    if(grid[nx][ny] == 1 && vis[nx][ny] == 0){
                        q.push({nx, ny});
                        vis[nx][ny] = 1; 
                    }
            } 
        }

        int ans = 0;

        //now all non visited 1's will be our answer
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) ans++;
            }
        }

        return ans;
    }