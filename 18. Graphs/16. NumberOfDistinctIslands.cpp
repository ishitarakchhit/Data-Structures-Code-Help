/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1


*/



    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &shape, int row0, int col0 ,int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        shape.push_back({row - row0, col - col0});
        vis[row][col] = 1;
        
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        
        for(int k=0; k<4; k++){
            int nx = row+dx[k];
            int ny = col+dy[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(grid[nx][ny] == 1 && vis[nx][ny]==0)
                    dfs(grid, vis, shape, row0, col0, nx, ny);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    
                    vector<pair<int,int>> shape;           //to store coordinates of current dfs call / or shape
                    dfs(grid, vis, shape, i, j, i, j);
                    
                    //to insert in set 
                    s.insert(shape);
                    
                }
            }
        }
        
        return s.size();
        
    }


