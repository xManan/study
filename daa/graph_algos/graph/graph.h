#ifndef GRAPH_H
#define GRAPH_H

#include <list>

class graph{
    private:
        int n;
        int **A;
    public:
        graph(int size=2);
        ~graph();
        bool isConnected(int u, int v);
        void addEdge(int u, int v);
        void BFS(int s);
        void visit(int s, bool visited[]);
        void visit(int s, bool visited[], std::list<int> &visitedNodes);
        void DFS(int s);
        void topsort();
};

#endif
