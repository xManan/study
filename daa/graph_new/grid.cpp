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

    std::queue<coord*> q;
    bool visited[R][C];
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            visited[i][j] = false;
        }
    }
    q.push(new coord(0,0));
    visited[0][0] = true;
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    while(!q.empty()){
        coord *cell = q.front();
        q.pop();
        for(int i=0; i<4; ++i){
            int rr = cell->r+dr[i];
            int cc = cell->c+dc[i];
            //std::cout << cell->r << " " << cell->c << std::endl;
            //return 1;
            if(visited[rr][cc] || rr < 0 || cc < 0 || rr >= R || cc >= C || grid[rr][cc]=='#'){
                continue;
            }
            if(grid[rr][cc] == 'E'){
                std::cout << "END " << rr << " " << cc << std::endl;
                while(cell->parent){
                    std::cout << "(" << cell->r << "," << cell->c << ") ";
                    cell=cell->parent;
                }
                std::cout << std::endl;
                return 1;
            }
            q.push(new coord(rr,cc,cell));
            visited[rr][cc] = true;
            

        }
        
    }

}
