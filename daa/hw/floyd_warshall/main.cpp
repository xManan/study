#include <iostream>
#include <climits>

using namespace std;

void displayMatrix(int **A, int V);

class graph{
    int **A;
    int V;
    public:
    graph(int vertices);
    ~graph();
    void display();
    void addEdge(int u, int v, int w);
    bool isConnected(int u, int v);
    int weight(int u, int v);
    void floyd_warshall();
    
};

graph::graph(int vertices){
    V = vertices;
    A = new int*[V];
    for(int i=0; i<V; ++i){
        A[i] = new int[V];
        for(int j=0; j<V; ++j){
            if(i==j) A[i][j] = 0;
            else A[i][j] = INT_MAX;
        }
    }
}

graph::~graph(){
    for(int i=0; i<V; ++i){
        delete[] A[i];
    }    
    delete[] A;
}

void graph::display() {
    cout << "   ";
    for (int i = 0; i < V; ++i) {
        cout.width(2);
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << "   ";
    for (int i = 0; i < V; ++i) {
        cout << "---";
    }
    cout << endl;
    for (int i = 0; i < V; ++i) {
        cout.width(2);
        cout << i + 1 << "|";
        for (int j = 0; j < V; ++j) {
            cout.width(2);
            if(A[i][j] == INT_MAX) cout << " " << " ";      
            else cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void graph::addEdge(int u, int v, int w) {
    A[u-1][v-1] = w;
}

bool graph::isConnected(int u, int v){
    if(A[u-1][v-1] != 0 && A[u-1][v-1] != INT_MAX) return true;
    return false;
}

int graph::weight(int u, int v){
    return A[u-1][v-1];
}

void graph::floyd_warshall(){
    int **dist_arr = new int *[V];
    for(int i=0; i<V; ++i){
        dist_arr[i] = new int [V];
        for(int j=0; j<V; ++j){
            dist_arr[i][j] = A[i][j];
        }
    }
    for(int k=0; k<V; ++k){
        for(int i=0; i<V; ++i){
            for(int j=0; j<V; ++j){
                if(i == j || i == k || j == k) continue;
                if(dist_arr[i][k] == INT_MAX || dist_arr[k][j] == INT_MAX) continue;
                if(dist_arr[i][k] + dist_arr[k][j] < dist_arr[i][j]){
                    dist_arr[i][j] = dist_arr[i][k] + dist_arr[k][j]; 
                }
            }
        }
    }
    displayMatrix(dist_arr, V);
}


void displayMatrix(int **A, int V) {
    cout << "   ";
    for (int i = 0; i < V; ++i) {
        cout.width(2);
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << "   ";
    for (int i = 0; i < V; ++i) {
        cout << "---";
    }
    cout << endl;
    for (int i = 0; i < V; ++i) {
        cout.width(2);
        cout << i + 1 << "|";
        for (int j = 0; j < V; ++j) {
            cout.width(2);
            if(A[i][j] == INT_MAX) cout << " " << " ";      
            else cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    graph g(4);
    g.addEdge(1,3,-2);
    g.addEdge(2,1,4);
    g.addEdge(2,3,3);
    g.addEdge(3,4,2);
    g.addEdge(4,2,-1);
    g.display(); 
    cout << endl;
    g.floyd_warshall();
}
