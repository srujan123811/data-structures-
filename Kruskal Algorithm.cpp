#include <stdio.h>

#define MAX 30

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, cost[MAX][MAX];
    int i, j, k = 1, a, b, u, v, min, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (999 for no edge):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    while (k < n) {
        min = 999;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("Edge %d: (%d -> %d) cost: %d\n", k++, a, b, min);
            total += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum Cost = %d\n", total);
    return 0;
}

