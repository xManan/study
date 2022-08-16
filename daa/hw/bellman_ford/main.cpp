#include <iostream>
#include <climits>

using namespace std;

typedef struct Edge{
    int src;
    int dest;
    int wt;
} Edge;

class Graph{
    Edge **EdgeList;
    int edges;
    int vertices;
    int size;

    public:
    Graph(int v, int e){
        size = 0;
        edges = e;
        vertices = v;
        EdgeList = new Edge*[e];
    }

    int getSize(){
        return size;
    }

    void addEdge(int s, int d, int w){
        EdgeList[size++] = new Edge({s,d,w}); 
    }

    void bellmanFord(int s, int e){
        int dist_arr[vertices+1];
        int parent[vertices+1];
        for(int i=1; i<=vertices; ++i){
            dist_arr[i] = INT_MAX;
            parent[i] = -1;
        }
        dist_arr[s] = 0;
        for(int i=0; i<vertices-1; ++i){
            for(int j=0; j<edges; ++j){
                if(dist_arr[EdgeList[j]->src] == INT_MAX) continue;
                if(dist_arr[EdgeList[j]->src]+EdgeList[j]->wt < dist_arr[EdgeList[j]->dest]){
                    dist_arr[EdgeList[j]->dest] = dist_arr[EdgeList[j]->src]+EdgeList[j]->wt; 
                    parent[EdgeList[j]->dest] =  EdgeList[j]->src;
                }
            }
        }
        for(int i=1; i<=vertices; ++i){
            cout << dist_arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    // Graph g(5,9);
    // g.addEdge(1,2,4);
    // g.addEdge(1,3,2);
    // g.addEdge(2,4,2);
    // g.addEdge(2,5,4);
    // g.addEdge(2,3,3);
    // g.addEdge(3,2,1);
    // g.addEdge(3,4,3);
    // g.addEdge(3,5,5);
    // g.addEdge(5,4,-5);
    // cout << g.getSize() << endl; 
    // g.bellmanFord(1,5);
    int v,e;
    cout << "Enter number of vertices: " << endl; 
    cin >> v;
    cout << "Enter number of edges: " << endl; 
    cin >> e;
    Graph g(v,e);
    
    for(int i=0; i<e; ++i){
        int s,d,w;
        cin >> s >> d >> w;
        g.addEdge(s,d,w);
    }
    int start,end;
    cout << "Enter source and destination: ";
    cin >> start >> end;
    g.bellmanFord(start,end);

    return 0;
}
