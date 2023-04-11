/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
*/

class Solution{
    public:
    int dx[4]={-1, 0, 0, 1};
    int dy[4]={0, -1, 1, 0};
    char direction[4]={'U', 'L', 'R', 'D'}; 
    
    
bool ispossible(vector<vector<int>> &maze, int x, int y, int row, int col, vector<vector<bool>>& visited){
    if( ((x>=0 && x<row) && (y>=0 && y<col)) && 
        (visited[x][y]==0) && 
        (maze[x][y]==1))

      return 1;

    else 
        return 0;
}


void findpath(vector<vector<int>> &maze, int i, int j, int row, int col, vector<vector<bool>>& visited, string path, vector<string>& ans){
    //base case
    if( i==row-1 && j==col-1){
        ans.push_back(path);
        return;
    }

    for(int k=0; k<4; k++){
        int newx= i+ dx[k];
        int newy= j+ dy[k];
        char move= direction[k];
        
        if(ispossible(maze, newx, newy, row, col, visited)){
            visited[newx][newy]= 1;
            findpath(maze, newx, newy, row, col, visited, path+move, ans);
            //backtracking 
            visited[newx][newy]=0;
        }
    }

}
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
    string path="";
    vector<string> ans;
    int i=0, j=0, row=n, col=n;

    vector<vector<bool>> visited(row, vector<bool> (col, false));
    visited[0][0]=1;

    if(m[0][0]== 0)
        return ans;
    findpath(m, i, j, row, col, visited, path, ans);
    
    return ans;
        
    }
};