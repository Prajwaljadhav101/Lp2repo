#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int size, vector<vector<int>> &board){

    int x = row;
    int y = col;

    while(y >= 0){
        if(board[x][y] == 1) return false;
        y--;
    }

    x = row;
    y = col;

    while(x >= 0 && y >= 0){
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }

    x = row;
    y = col;
    
    while(x < size && y >= 0){
        if(board[x][y] == 1) return false;
        x++;
        y--;
    }

    return true;
}

void print(vector<vector<int>> &board, int n){
    
    static int count = 1;
    cout << count << "th Solution : " << "\n";
    count++;

    for(auto i : board){
        for(auto j : i){
            if(j == 1) cout << 'Q' << " ";
            else cout << "." << " ";
        }
        cout << "\n";
    }


}

void solve(int col, int n, vector<vector<int>> &board){
    
    if(col == n){

        print(board,n);
        cout << "\n";
        return;
    }

    for(int row = 0; row < n; row++){

        if( isSafe(row, col, n, board) ){
            board[row][col] = 1;
            solve(col + 1, n, board);
            board[row][col] = 0;
        }
    }
}

int main(){

    int n;
    cout << "Enter the number of queens : ";
    cin >> n;

    vector<vector<int>> board(n, vector<int> (n,0));

    int col = 0;

    solve(col, n, board);


    return 0;
}