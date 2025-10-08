#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int n, int cost[MAX][MAX], int start) {
    int dist[MAX], visited[MAX] = {0};
    for (int i = 0; i < n; i++)
        dist[i] = cost[start][i];
    visited[start] = 1;
    dist[start] = 0;

    for (int count = 1; count < n - 1; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && cost[u][v] + dist[u] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    printf("\nShortest distances from vertex %d:\n", start);
    for (int i = 0; i < n; i++)
        printf("To vertex %d = %d\n", i, dist[i]);
}

int main() {
    int n, cost[MAX][MAX], start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (9999 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dijkstra(n, cost, start);
    return 0;
}

