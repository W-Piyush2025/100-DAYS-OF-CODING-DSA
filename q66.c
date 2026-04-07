#include <stdio.h>
#include <stdbool.h>

#define V 5   // number of vertices

// Function to add edge
void addEdge(int graph[V][V], int u, int v) {
    graph[u][v] = 1;
}

// DFS function to detect cycle
bool dfs(int graph[V][V], int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for(int i = 0; i < V; i++) {
        if(graph[node][i]) { // if edge exists
            if(!visited[i] && dfs(graph, i, visited, recStack))
                return true;
            else if(recStack[i])
                return true;
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

// Function to check cycle
bool hasCycle(int graph[V][V]) {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(graph, i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int graph[V][V] = {0};

    // Example edges
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1); // cycle here

    if(hasCycle(graph))
        printf("YES, cycle exists\n");
    else
        printf("NO cycle\n");

    return 0;
}