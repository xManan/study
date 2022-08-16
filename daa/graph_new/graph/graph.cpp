#include "graph.h"
#include <functional>
#include <iostream>
#include <limits.h>
#include <list>
#include <queue>
#include <vector>

graph::graph(int s) {
    if (s < 2) size = 2;
    else size = s;
    A = new int *[size];
    for (int i = 0; i < size; ++i){
        A[i] = new int[size];
        for (int j = 0; j < size; ++j){
            A[i][j] = 0;
        }
    }
}

graph::~graph() {
    for (int i = 0; i < size; ++i) {
        delete[] A[i];
    }
    delete[] A;
}

int graph::getSize() { return size; }

void graph::addEdge(int u, int v) { A[u - 1][v - 1] = 1; }

void graph::addEdge(int u, int v, int w) { A[u - 1][v - 1] = w; }

void graph::addEdgeBi(int u, int v) { A[u - 1][v - 1] = A[v - 1][u - 1] = 1; }

void graph::addEdgeBi(int u, int v, int w) { A[u - 1][v - 1] = A[v - 1][u - 1] = w; }

void graph::printGraph() {
    std::cout << "   ";
    for (int i = 0; i < size; ++i) {
        std::cout.width(2);
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    std::cout << "   ";
    for (int i = 0; i < size; ++i) {
        std::cout << "---";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout.width(2);
        std::cout << i + 1 << "|";
        for (int j = 0; j < size; ++j) {
          std::cout.width(2);
          std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool graph::isConnected(int u, int v) { return A[u - 1][v - 1] != 0; }

int graph::weight(int u, int v) { return A[u - 1][v - 1]; }

void graph::bfs(int s) {
    std::queue<int> q;
    bool visited[size + 1];
    for (int i = 1; i <= size; ++i) {
        visited[i] = false;
    }
    q.push(s);
    std::cout << s << " ";
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= size; ++i) {
            if (isConnected(u, i) && !visited[i]) {
                q.push(i);
                std::cout << i << " ";
                visited[i] = true;
            }
        }
    }
    std::cout << std::endl;
}

void graph::dfsvisit(int s, bool *visited) {
    for (int i = 1; i <= size; ++i) {
        if (isConnected(s, i) && !visited[i]) {
            std::cout << i << " ";
            visited[i] = true;
            dfsvisit(i, visited);
        }
    }
}

void graph::dfs(int s) {
    bool visited[size + 1];
    for (int i = 1; i <= size; ++i) {
        visited[i] = false;
    }
    std::cout << s << " ";
    dfsvisit(s, visited);
    std::cout << std::endl;
}

void graph::dfsvisit(int s, bool *visited, std::list<int> &visitedNodes) {
    for (int i = 1; i <= size; ++i) {
        if (isConnected(s, i) && !visited[i]) {
            visited[i] = true;
            dfsvisit(i, visited, visitedNodes);
            // std::cout << i << " ";
            visitedNodes.push_back(i);
        }
    }
}

void graph::topsort() {
    bool visited[size + 1];
    std::list<int> visitedNodes;
    for (int i = 1; i <= size; ++i) {
        visited[i] = false;
    }
    for (int i = 1; i <= size; ++i) {
        if (!visited[i]) {
            dfsvisit(i, visited, visitedNodes);
            // std::cout << i << " ";
            visitedNodes.push_back(i);
      }
    }
    for (std::list<int>::reverse_iterator rit = visitedNodes.rbegin(); rit != visitedNodes.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << '\n';
}

void graph::dijkstra(int s, int e) {
    std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> pq;
    int prev[size + 1];
    bool visited[size + 1];
    for (int i = 1; i <= size; ++i) {
        prev[i] = -1;
        visited[i] = false;
    }
    pq.push(std::make_pair(0, s));
    while (!pq.empty()) {
        int u = pq.top().second;
        if (u == e) {
            for (int i = 1; i <= size; ++i) {
                std::cout << prev[i] << ' ';
            }
            std::cout << std::endl;
            return;
        }
        pq.pop();
        visited[u] = true;
        for (int i = 1; i <= size; ++i) {
            if (isConnected(u, i) && !visited[i]) {
                pq.push(std::make_pair(weight(u, i), i));
                prev[i] = u;
            }
        }
    }
}

void graph::bellmanFord(int s, int e) {
    int relax = size - 1;
    int distances[size + 1];
    int oldDistances[size + 1];
    int parent[size+1];
    for (int i = 1; i <= size; ++i) {
        distances[i] = INT_MAX;
        oldDistances[i] = INT_MAX;
        parent[i] = -1;
    }

    distances[s] = 0;
    oldDistances[s] = 0;
    for (int i = 0; i < relax; ++i) {
        for (int j = s; j <= size; ++j) {
            for (int k = 1; k <= size; ++k) {
                if (isConnected(j, k)) {
                    if (oldDistances[j] == INT_MAX) {
                        continue;
                    }
                    if (oldDistances[j] + weight(j, k) < oldDistances[k]) {
                        distances[k] = weight(j, k) + oldDistances[j];
                        oldDistances[k] = weight(j, k) + oldDistances[j];
                        parent[k] = j;
                    }
                }
            }
        }
        for (int j = 1; j < s; ++j) {
            for (int k = 1; k <= size; ++k) {
                if (isConnected(j, k)) {
                    if (oldDistances[j] == INT_MAX) {
                        continue;
                    }
                    if (oldDistances[j] + weight(j, k) < oldDistances[k]) {
                        distances[k] = weight(j, k) + oldDistances[j];
                        oldDistances[k] = weight(j, k) + oldDistances[j];
                        parent[k] = j;
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    for (int i = 1; i < size + 1; ++i) {
        std::cout << distances[i] << " ";
    }
    std::cout << std::endl;
    int tmp = e;
    std::cout << e <<  " ";
    while(parent[tmp] != -1){
        std::cout << parent[tmp] <<  " ";
        tmp = parent[tmp];
    }
    std::cout << std::endl;
}
