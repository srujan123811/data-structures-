#include <stdio.h>
#define MAX 20

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

void bfs(int adj[MAX][MAX], int n, int start) {
    int i;
    for (i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int v = dequeue();
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, adj[MAX][MAX], i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    bfs(adj, n, start);
    return 0;
}

