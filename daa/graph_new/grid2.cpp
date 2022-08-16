#include <iostream>
#include <queue>

class coord{
    public:
    int r;
    int c;
    coord *parent;
    coord(int x, int y){
        r=x;
        c=y;
        parent=NULL;
    }
    coord(int x, int y, coord *cell){
        r=x;
        c=y;
        parent=cell;
    }
};
int *coord(int r, int c){
    int *arr = new int[2];
    arr[0]=r;
    arr[1]=c;
    return arr;
}
int main(){
    int R=5;
    int C=7;
    char grid[R][C] = {
        {'S','.','.','#','.','.','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','.','.','.','.','.'},
        {'.','.','#','#','.','.','.'},
        {'#','.','#','E','.','#','.'},
    };

    std::queue<int> r;
    std::queue<int> c;
    bool visited[R][C];
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            visited[i][j] = false;
        }
    }
    r.push(0);
    c.push(0);
    visited[0][0] = true;
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    int *path[R][C];
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            path[i][j] = NULL;
        }
    }
    std::cout << "START 0 0" << '\n';
    while(!r.empty()){
        int *cell = new int[2];
        cell[0] = r.front();
        cell[1] = c.front();
        r.pop();
        c.pop();
        for(int i=0; i<4; ++i){
            int rr = cell[0]+dr[i];
            int cc = cell[1]+dc[i];
            //std::cout << cell->r << " " << cell->c << std::endl;
            //return 1;
            if(visited[rr][cc] || rr < 0 || cc < 0 || rr >= R || cc >= C || grid[rr][cc]=='#'){
                continue;
            }
            if(grid[rr][cc] == 'E'){
                std::cout << "END " << rr << " " << cc << std::endl;
                int rindex = cell[0];
                int cindex = cell[1];
            //    std::cout << rindex << " " << cindex << '\n';
             //   std::cout << path[cell[0]][cell[1]][0] << " " << path[cell[0]][cell[1]][1] << '\n';
              //  return 0;
                while(path[rindex][cindex] != NULL){
                    std::cout << "(" << rindex << "," << cindex << ") "; 
                    rindex=path[rindex][cindex][0];
                    cindex=path[rindex][cindex][1];
                }
                std::cout << std::endl;
                return 0;
            }
            r.push(rr);
            c.push(cc);
            visited[rr][cc] = true;
            path[rr][cc] = cell;
            //std::cout << "index: " << rr << " " << cc << '\n';
            //std::cout << "path : " << path[rr][cc][0] << " " << path[rr][cc][1] << '\n';
        }
    }
}

