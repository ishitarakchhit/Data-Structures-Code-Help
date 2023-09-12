/*
ou are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/




//---------------Solution---------------------

//pushing all inital rotton oranges into queue with secon0. pop elements from queue until empty. 
//in the front element push for direction elements into the quue if they are fresh along with q.front's seconds+1. 
//In the end if the grid contains any 1's rturn -1
//else return the answer


int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue <pair<pair<int,int>,int>> q;
        int ans = 0;                          //to push seconds in which oranges rot 

        //pushing all starting rot oranges in sec 0
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        //pushing / rotting other oragnes
        while(!q.empty()){
            auto front = q.front();
            int row = front.first.first;
            int col = front.first.second;
            int sec = front.second;
            ans = max(ans, sec);
            q.pop();

            for(int dx=-1; dx<=1; dx++){
                for(int dy=-1; dy<=1; dy++){
                    if(abs(dx) != abs(dy)){
                        if(row+dx >=0 && row+dx <n && col+dy >=0 && col+dy <m){
                            if(grid[row+dx][col+dy] == 1){
                                q.push({{row+dx, col+dy}, sec+1});
                                grid[row+dx][col+dy] = 2;
                            }
                        }
                    }
                }
            } 
        }

        //checking for any availabel fresh oranges
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return ans;

    }
};