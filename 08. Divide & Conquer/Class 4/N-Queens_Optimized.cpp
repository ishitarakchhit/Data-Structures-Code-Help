#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//to create a map for row and diagonals
unordered_map<int, bool> rowcheck;
unordered_map<int, bool> upleftdiagonalcheck;
unordered_map<int, bool> bottomleftdiagonalcheck;

//function to print the board
void printBoard(vector<vector<char>> board, int col, int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}

//funtion to check whether we can place the current queen onto the board
bool issafe(vector<vector<char>>& board, int row, int col, int n){
    if(rowcheck[row] == true || upleftdiagonalcheck[n-1 + col-row] == true || bottomleftdiagonalcheck[row+col] == true)
        return false;
    
    return true;
}


void placequeens(vector<vector<char>> board, int col, int n){
    if(col>=n){
        printBoard(board, col, n);
        cout<<endl;
        return;
    }

    for (int row = 0; row < n; row++){
        if(issafe(board, row, col, n)){
            //places the queen
            board[row][col] = 'Q';
            //to map the unsafe places 
            rowcheck[row] = true;
            upleftdiagonalcheck[n-1 + col-row] = true;
            bottomleftdiagonalcheck[row+col] = true;
            //checks for the next column (rc)
            placequeens(board, col+1, n);
            //backtracking
            board[row][col] = '-';
            rowcheck[row] = false;
            upleftdiagonalcheck[n-1 + col-row] = false;
            bottomleftdiagonalcheck[row+col] = false;
    }
        
    }
    
}

//main function
int main(){
    int n;
    cout<<"Enter the size of board: ";
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    placequeens(board, 0, n);
}