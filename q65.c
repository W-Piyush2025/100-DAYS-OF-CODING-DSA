#include <stdio.h>
#define MAX 100

int visited[MAX];

int DFS(int adj[MAX][MAX], int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            if (!visited[i]) {
                if (DFS(adj, i, node, n))
                    return 1;
            }
            else if (i != parent) {
                return 1; // Cycle found
            }
        }
    }
    return 0;
}

int hasCycle(int adj[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(adj, i, -1, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (hasCycle(adj, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}