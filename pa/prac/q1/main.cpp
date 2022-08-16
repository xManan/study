#include <iostream>

using namespace std;

int main(){
    int n=2,m=2;
    int matrix[n][m];
    matrix[0][0] = 102;
    matrix[0][1] = 50;
    matrix[1][0] = 100;
    matrix[1][1] = 50;
    int totalSum = 0;
    for(int i=0; i<n; ++i){
        int rowSum = 0;
        for(int j=0; j<m; ++j){
            // matrix[i][j] = (i*j)/10;
            rowSum += matrix[i][j];
        }
        if(!(rowSum % 3 == 0 && rowSum % 5 == 0)){
            cout << rowSum << '\n';
            cout << "row sum not div by 3 and 5\n";
            return 1;
        }
        totalSum += rowSum;
    }
    if(totalSum < 300){
        cout << "row sum not div by 3 and 5\n";
        return 1;
    }
    return 0;
    // int matrix[2][3];
    // matrix[0][0] = 1;
}
