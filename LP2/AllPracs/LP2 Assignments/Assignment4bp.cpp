#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector <vector<bool>>& board, int row, int col, int n){
    for(int i =0; i<row; i++){
        if(board[i][col]==true){
            return false;
        }
    }
    for(int i =row, j = col; i>=0 && j>=0 ; i--, j--){
        if(board[i][j]==true){
            return false;
        }
    }
    for(int i =row, j = col; i>=0 && j>=0 ; i--, j++){
        if(board[i][j]==true){
            return false;
        }
    }
    return true;
}
bool SolveNQueens(vector <vector<bool>>& board, int row, int n){
    if(row>=n){
        return true;
    }
    for(int i =0; i<n; i++){
        if(isSafe(board, row, i, n)){
            board[row][i]=true;
            if(SolveNQueens(board, row+1, n)){
                return true;
            }
            board[row][i]=false;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter number of queens";
    cin>>n;
    vector <vector<bool>> board (n,vector<bool>(n, false));
    if(SolveNQueens(board, 0, n)){
        for(int i =0; i<n; i++){
            cout<<endl;
            for(int j =0; j<n;j++){
                cout<<"|"<<board[i][j]<<"|";
            }
        }
    }
    else{
        cout<<"\nNo solution present";
    }
    return 0;
}