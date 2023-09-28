/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/


void mark(vector<vector<char>>& board, vector<vector<bool>>& vis, int row, int col){
        vis[row][col] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nx = row+dx[i];
            int ny = col+dy[i];
            if(nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size())
                if(board[nx][ny] =='O' && vis[nx][ny] == 0)
                    mark(board, vis, nx, ny);
        } 
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));

        //to mark visted all those cells which cannot be turned to 'X'
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O' && vis[0][j] == 0)
                mark(board, vis, 0, j);
            
            if(board[n-1][j] == 'O' && vis[n-1][j] == 0)
                mark(board, vis, n-1, j);
        }

        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0)
                mark(board, vis, i, 0);
            
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0)
                mark(board, vis, i, m-1);
        }

        

        //now flip all 0's which are not visited
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }

        
    }