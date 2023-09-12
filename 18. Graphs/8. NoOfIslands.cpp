/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/




//--------------Solution--------------------

void bfs(vector<vector<char>>& grid, vector<vector<bool>> &vis, int &n, int &m, int i, int j){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        vis[i][j] = 1;

        while(!q.empty()){
            auto front = q.front();
            i = front.first;
            j = front.second;
            q.pop();

            //pushing elements in upper, left, bottom and right part of current cell
            for(int dx=-1; dx<=1; dx++){
                for(int dy=-1; dy<=1; dy++){
                    if(abs(dx) != abs(dy)){
                        if(i+dx >=0 && i+dx <n && j+dy >=0 && j+dy <m){
                            if(!vis[i+dx][j+dy] && grid[i+dx][j+dy] == '1'){
                                q.push(make_pair(i+dx, j+dy));
                                vis[i+dx][j+dy] = 1;
                            }
                        }
                    }
                }
            } 
        }
        return;
    }


    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &vis, int &n, int &m, int i, int j){
            vis[i][j] = 1;

            for(int dx=-1; dx<=1; dx++){
                for(int dy=-1; dy<=1; dy++){
                    if(abs(dx) != abs(dy)){
                        if(i+dx >=0 && i+dx <n && j+dy >=0 && j+dy <m){
                            if(!vis[i+dx][j+dy] && grid[i+dx][j+dy] == '1'){
                                dfs(grid, vis, n, m, i+dx, j+dy);
                            }
                        }
                    }
                }
            } 
            return;

    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //visited matrix
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int islands = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    //cout<<i<<j<<" ";
                    dfs(grid, vis, n, m, i, j);
                    islands ++;
                }
            }
        }
        return islands;
    }