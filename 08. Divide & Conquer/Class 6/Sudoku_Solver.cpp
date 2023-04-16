/*
https://leetcode.com/problems/sudoku-solver/description/
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/



class Solution {
public:
bool isCheck(vector<vector<char>>& sudoku, int n, int row, int col, char num){
    for(int i = 0; i<n; i++){
        if(sudoku[row][i] == num){
            return false;
        }
        if(sudoku[i][col] == num){
            return false;
        }
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == num)
            return false;
    }
    return true;
}


bool solve(vector<vector<char>>& sudoku, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(sudoku[i][j]=='.'){
                for (char k = '1'; k <= '9'; k++)
                {
                if(isCheck(sudoku, n, i, j, k)){
                    sudoku[i][j] = k;
                    bool nextsolve = solve(sudoku, n);
                    if(nextsolve){
                        return true;
                    }
                    else{
                        //backtracking
                        sudoku[i][j] = '.';
                    }
                }
                    
                }
                return false;
            }
        }
        
    }
    return true;
    

    
}
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board, n);
    }
};