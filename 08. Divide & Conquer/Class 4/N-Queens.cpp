#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



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
    int i = row, j= col;
    //check left side of row 
    while(j>=0){
        if(board[i][j]=='Q')
            return false;
        j--;
    }

    i=row;
    j=col;
    //check upper left diagnol
    while(j>=0 && i>=0){
        if(board[i][j]=='Q')
            return false;
        j--;
        i--;
    }

    i = row;
    j= col;
    //check lower left diagnol
    while(j>=0 && i<n){
        if(board[i][j]=='Q')
            return false;
        j--;
        i++;
    }

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
            //checks for the next column (rc)
            placequeens(board, col+1, n);
            //backtracking
            board[row][col] = '-';
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