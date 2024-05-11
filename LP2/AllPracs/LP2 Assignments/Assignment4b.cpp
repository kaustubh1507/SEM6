#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    for(int i = 0; i<row; i++){
        if(board[i][col]==1)
            return false;
    }

    for(int i =row, j= col; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i =row, j= col; i>=0 && j>=0; i--, j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
bool solveNQueensUtil(vector <vector <int>> &board, int row, int n){
    if(row>=n){
        return true;
    }
    
    for(int i =0; i<n;i++){
        if(isSafe(board, row, i, n)){
            board[row][i]=1;
            if(solveNQueensUtil(board, row+1, n))
                return true;

            board[row][i]=0;
        }
    }
    return false;
}
// void solveNQueens(int n){
    
// }
int main(){
    int n;
    cout<<"Enter number of queens :";
    cin>>n;
    // solveNQueens(n);
    vector <vector <int>> board(n, vector<int>(n,0));

    if(solveNQueensUtil(board,0,n)){
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Solution doesn't exist!"<<endl;
    }
    return 0;
}
