#include <stdio.h>
int G[20][20], visited[20], n; 
void dfs(int v) {
printf("%d ", v);
 visited[v] = 1;
for(int i = 0; i < n; i++) { 
if(G[v][i] && !visited[i]) {
dfs(i);
}}}

int main() {
int edges, u, v, start;
printf("Enter number of vertices and edges: "); 
scanf("%d %d", &n, &edges);
printf("Enter edges (u v):\n"); 
for(int i = 0; i < edges; i++) { 
scanf("%d %d", &u, &v);
G[u][v] = 1;
G[v][u] = 1;
}
printf("Enter start vertex: "); 
scanf("%d", &start);
printf("DFS Traversal: ");
 dfs(start);
return 0;
}
