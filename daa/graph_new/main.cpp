#include "graph/graph.h"
#include <iostream>

using namespace std;

int main() {
    graph g(5);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 2);
    g.addEdge(2, 5, 7);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 5, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(5, 4, -5);
    g.printGraph();
    // g.topsort();
    // g.dijkstra(1,6);
    g.bellmanFord(1, 5);

    return 0;
}
