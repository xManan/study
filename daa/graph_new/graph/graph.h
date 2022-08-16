#ifndef GRAPH_H
#define GRAPH_H

#include <list>

class graph {
    private:
    int size;
    int **A;

    public:
    graph(int s = 2);
    ~graph();
    int getSize();
    void addEdge(int u, int v);
    void addEdge(int u, int v, int w);
    void addEdgeBi(int u, int v);
    void addEdgeBi(int u, int v, int w);
    int weight(int u, int v);
    void printGraph();
    bool isConnected(int u, int v);
    void bfs(int s); // traverse all vertices using breadth first search
    void dfsvisit(int s, bool *visited);
    void dfs(int s);
    void dfsvisit(int s, bool *visited, std::list<int> &visitedNodes);
    void topsort();
    void dijkstra(int s, int e);
    void bellmanFord(int s, int e);
};

#endif
