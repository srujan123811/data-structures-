#include <stdio.h>
#define INF 9999
#define MAX 10

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int i, j, ne = 1, min, a, b, u, v, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (9999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    while (ne < n) {
        min = INF;
        for (i = 0; i < n; i++)
            if (visited[i])
                for (j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }

        visited[v] = 1;
        printf("Edge %d: (%d -> %d) cost: %d\n", ne++, a, b, min);
        total += min;
    }

    printf("\nMinimum Cost = %d\n", total);
    return 0;
}

