#include <iostream>
#include "graph/graph.h"

int main(){
    graph g(10);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(6,7);
    g.addEdge(7,3);
    g.addEdge(8,9);
    g.addEdge(9,10);
    g.addEdge(10,5);
    g.topsort();
    return 0;
}
