#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

// DFS function to detect cycle
int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return 1;
            }
            else if (i != parent) {
                return 1; // cycle detected
            }
        }
    }
    return 0;
}

int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}