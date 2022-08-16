#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> A, int x, int y, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cout << A[x+i][y+j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> add(vector<vector<int>> A, int x1, int y1, vector<vector<int>> B, int x2, int y2, int n){
    vector<vector<int>> C(n, vector<int>(n, 0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            C[i][j] = A[x1+i][y1+j] + B[x2+i][y2+j];
        }
    }
    return C;
}

vector<vector<int>> subtract(vector<vector<int>> A, int x1, int y1, vector<vector<int>> B, int x2, int y2, int n){
    vector<vector<int>> C(n, vector<int>(n, 0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            C[i][j] = A[x1+i][y1+j] - B[x2+i][y2+j];
        }
    }
    return C;
}

vector<vector<int>> multiply(vector<vector<int>> A, int x1, int y1, vector<vector<int>> B, int x2, int y2, int n){
    vector<vector<int>> C(n, vector<int> (n,0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<n; ++k){
                C[i][j]+=A[x1+i][y1+k]*B[x2+k][y2+j];  
            }
        }
    }
    return C;
}

vector<vector<int>> combineMatrix(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C, vector<vector<int>> D, int n){
    vector<vector<int>> V(n*2, vector<int>(n*2,0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            V[i][j] = A[i][j];
            V[i][n+j] = B[i][j];
            V[n+i][j] = C[i][j];
            V[n+i][n+j] = D[i][j];
        }
    }
    return V;
}

vector<vector<int>> strassenMultiply(vector<vector<int>> A, int x1, int y1, vector<vector<int>> B, int x2, int y2, int n){
    if(n <= 2){
        return multiply(A,x1,y1,B,x2,y2,n);
    }
    //vector<vector<int>> ae = strassenMultiply(A, x1, y1, B, x2, y2, n/2);
    //vector<vector<int>> bg = strassenMultiply(A, x1, y1+(n/2), B, x2+(n/2), y2, n/2);
    //vector<vector<int>> af = strassenMultiply(A, x1, y1, B, x2, y2+(n/2), n/2);
    //vector<vector<int>> bh = strassenMultiply(A, x1, y1+(n/2), B, x2+(n/2), y2+(n/2), n/2);
    //vector<vector<int>> ce = strassenMultiply(A, x1+(n/2), y1, B, x2, y2, n/2);
    //vector<vector<int>> dg = strassenMultiply(A, x1+(n/2), y1+(n/2), B, x2+(n/2), y2, n/2);
    //vector<vector<int>> cf = strassenMultiply(A, x1+(n/2), y1, B, x2, y2+(n/2), n/2);
    //vector<vector<int>> dh = strassenMultiply(A, x1+(n/2), y1+(n/2), B, x2+(n/2), y2+(n/2), n/2);
    //vector<vector<int>> aebg = add(ae, 0, 0, bg, 0, 0, n/2);
    //vector<vector<int>> afbh = add(af, 0, 0, bh, 0, 0, n/2);
    //vector<vector<int>> cedg = add(ce, 0, 0, dg, 0, 0, n/2);
    //vector<vector<int>> cfdh = add(cf, 0, 0, dh, 0, 0, n/2);
    //return combineMatrix(aebg, afbh, cedg, cfdh, n/2);
    vector<vector<int>> p1 = strassenMultiply(add(A, x1, y1, A, x1+(n/2), y1+(n/2), n/2), 0, 0, add(B, x2, y2, B, x2+(n/2), y2+(n/2), n/2), 0, 0, n/2);
    vector<vector<int>> p2 = strassenMultiply(A, x1+(n/2), y1+(n/2), subtract(B, x2+(n/2), y2, B, x2, y2, n/2), 0, 0, n/2);
    vector<vector<int>> p3 = strassenMultiply(add(A, x1, y1, A, x1, y1+(n/2), n), 0, 0, B, x2, y2+(n/2), n/2);
    vector<vector<int>> p4 = strassenMultiply(subtract(A, x1, y1+(n/2), B, x2+(n/2), y2, n/2), 0, 0, B, x2+(n/2), y2+(n/2), n/2);
    vector<vector<int>> p5 = strassenMultiply(A, x1, y1, subtract(B, x2, y2+(n/2), B, x2+(n/2), y2+(n/2), n/2), 0, 0, n/2);
    vector<vector<int>> p6 = strassenMultiply(add(A, x1+(n/2), y1, A, x1+(n/2), y1+(n/2), n/2), 0, 0, B, x2, y2, n/2);
    vector<vector<int>> p7 = strassenMultiply(subtract(A, x1, y1, A, x1+(n/2), y1, n/2), 0, 0, add(B, x2, y2, B, x2, y2+(n/2), n/2), 0, 0, n/2);
    vector<vector<int>> c11 = add(add(p1, 0, 0, p2, 0, 0, n/2), 0, 0, subtract(p4, 0, 0, p3, 0, 0, n/2), 0, 0, n/2);
    vector<vector<int>> c12 = add(p5, 0, 0, p3, 0, 0, n/2);
    vector<vector<int>> c21 = add(p6, 0, 0, p2, 0, 0, n/2);
    vector<vector<int>> c22 = subtract(add(p5, 0, 0, p1, 0, 0, n/2), 0, 0, add(p6, 0, 0, p7, 0, 0, n/2), 0, 0, n/2);
    return combineMatrix(c11, c12, c21, c22, n/2);
}

int main(){
    int n=4;
    vector<vector<int>> matrix1(n, vector<int> (n,1)); 
    vector<vector<int>> matrix2(n, vector<int> (n,1)); 
    vector<vector<int>> matrix3(n, vector<int> (n,1)); 
    vector<vector<int>> matrix4(n, vector<int> (n,1)); 

    matrix1[0][0] = 2;
    matrix2[0][1] = 0;
    matrix3[1][1] = 4;
    matrix4[1][0] = 0;

    matrix1[0][0] = 0;
    matrix2[0][1] = 4;
    matrix3[1][0] = 2;
    matrix3[0][1] = 3;
    printMatrix(matrix1, 0, 0, n);
    printMatrix(matrix2, 0, 0, n);
    //printMatrix(matrix3, 0, 0, n);
    //printMatrix(matrix4, 0, 0, n);
    
    vector<vector<int>> matrix5 = multiply(matrix1, 0, 0, matrix2, 0, 0, n);
    vector<vector<int>> matrix6 = strassenMultiply(matrix1, 0, 0, matrix2, 0, 0, n);

    printMatrix(matrix5, 0, 0, n);
    printMatrix(matrix6, 0, 0, n);

}
