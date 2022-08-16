#include "graph.h"
#include <iostream>
#include <queue>
#include <list>

graph::graph(int size){
    if(size<2) n=2;
    else n=size;
    A = new int*[n];
    for(int i=0; i<n; ++i){
        A[i] = new int[n];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            A[i][j] = 0;
        }
    }
}

graph::~graph(){
    for(int i=0; i<n; ++i){
        delete[] A[i];
    }
    delete[] A;
}

bool graph::isConnected(int u, int v){
    return (A[u-1][v-1] == 1);
}

void graph::addEdge(int u, int v){
    A[u-1][v-1] = 1;
}

void graph::BFS(int s){
    std::queue<int> q;
    bool visited[n+1];
    q.push(s);
    visited[s] = true;
    for(int i=1; i<=n; ++i){
        visited[i]=false;
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=1; i<=n; ++i){
            if(isConnected(v,i) && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void graph::visit(int s, bool visited[]){
    visited[s]=true;
    for(int i=1; i<=n; ++i){
        if(isConnected(s,i) && !visited[i]){
            visit(i,visited);
        }
    }
}

void graph::DFS(int s){
    bool visited[n+1];
    for(int i=1; i<=n; ++i){
        visited[i]=false;
    }
    std::cout << s << " ";
    visit(s, visited);
    for(int i=1; i<=n; ++i){
        if(visited[i]){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

void graph::visit(int s, bool visited[], std::list<int> &visitedNodes){
    visited[s]=true;
    for(int i=1; i<=n; ++i){
        if(isConnected(s,i) && !visited[i]){
            visit(i,visited, visitedNodes);
        }
    }
    visitedNodes.push_back(s);
}

void graph::topsort(){
    bool visited[n+1];
    for(int i=1; i<=n; ++i){
        visited[i]=false;
    }
    std::list<int> visitedNodes;
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            visit(i, visited, visitedNodes);
        }        
    }
    for(std::list<int>::reverse_iterator it=visitedNodes.rbegin(); it!=visitedNodes.rend(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}







