#include <iostream>

using namespace std;

void printGrid(int **grid, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **grid, int n, int row, int col){
    for(int i=0; i<n; ++i) if(i != col && grid[row][i] == 1) return false;
    for(int i=0; i<n; ++i) if(i != row && grid[i][col] == 1) return false;
    if(row > col){
        for(int i=0; i<n-row+col; ++i) if(i != col && grid[row-col+i][i] == 1) return false;
    }
    else{
        for(int i=0; i<n-col+row; ++i) if(i != row && grid[i][col-row+i] == 1) return false;
    }
    if(row > n-col-1){
        for(int i=0; i<n-row+n-col-1; ++i) if(i != n-row-1 && grid[n-1-i][col-n+row+1+i] == 1) return false;
    }
    else{
        for(int i=0; i<row+col+1; ++i) if(i != col && grid[row+col-i][i] == 1) return false;
    }
    return true;
}

bool solve_row(int **grid, int n, int row){
    if(row > n-1) return true;
    for(int i=0; i<n; ++i){
        if(isSafe(grid, n, row, i)){
            grid[row][i] = 1;
            if(solve_row(grid, n, row+1)){
                return true;
            }
            grid[row][i] = 0;
        }
    }
    return false;
}

int main(){
    int n = 16;
    int **grid = new int*[n];
    for(int i=0; i<n; ++i){
        grid[i] = new int[n];
        for(int j=0; j<n; ++j){
            grid[i][j] = 0;
        }
    }
    solve_row(grid, n, 0);
    printGrid(grid, n);
    return 0;
}
