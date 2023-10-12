/**https://leetcode.com/problems/critical-connections-in-a-network/ */
//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
//Return all critical connections in the network in any order.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
//Output: [[1,3]]
//Explanation: [[3,1]] is also accepted.
//Example 2:
//Input: n = 2, connections = [[0,1]]
//Output: [[0,1]]
// 
//Constraints:
//	2 <= n <= 105
//	n - 1 <= connections.length <= 105
//	0 <= ai, bi <= n - 1
//	ai != bi
//	There are no repeated connections.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes){
int i, j, k, l, m, n;
    int **ans = (int **)calloc(n, sizeof(int *));
    int *ansColSize = (int *)calloc(n, sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));
    int *dfn = (int *)calloc(n, sizeof(int));
    int *low = (int *)calloc(n, sizeof(int));
    int *parent = (int *)calloc(n, sizeof(int));
    int time = 0;
    int **graph = (int **)calloc(n, sizeof(int *));
    int *graphColSize = (int *)calloc(n, sizeof(int));
    int *graphColCapacity = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        graphColCapacity[i] = 1;
        graphColSize[i] = 0;
        graph[i] = (int *)calloc(graphColCapacity[i], sizeof(int));
    }
    for (i = 0; i < connectionsSize; i++) {
        int a = connections[i][0], b = connections[i][1];
        graph[a][graphColSize[a]++] = b;
        if (graphColSize[a] == graphColCapacity[a]) {
            graphColCapacity[a] <<= 1;
            graph[a] = (int *)realloc(graph[a], graphColCapacity[a] * sizeof(int));
        }
        graph[b][graphColSize[b]++] = a;
        if (graphColSize[b] == graphColCapacity[b]) {
            graphColCapacity[b] <<= 1;
            graph[b] = (int *)realloc(graph[b], graphColCapacity[b] * sizeof(int));
        }
    }
    *returnSize = 0;
    dfs(0, -1, graph, graphColSize, visited, dfn, low, parent, &time, ans, ansColSize, returnSize);
    *returnColumnSizes = ansColSize;
    return ans;
}
void dfs(int u, int pre, int **graph, int *graphColSize, int *visited, int *dfn, int *low, int *parent, int *time, int **ans, int *ansColSize, int *returnSize) {
    visited[u] = 1;
    dfn[u] = low[u] = (*time)++;
    for (int i = 0; i < graphColSize[u]; i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            parent[v] = u;
            dfs(v, u, graph, graphColSize, visited, dfn, low, parent, time, ans, ansColSize, returnSize);
            low[u] = low[u] < low[v] ? low[u] : low[v];
            if (low[v] > dfn[u]) {
                ans[*returnSize] = (int *)calloc(2, sizeof(int));
                ans[*returnSize][0] = u;
                ans[*returnSize][1] = v;
                (*ansColSize)++;
                (*returnSize)++;
            }
        } else if (v != pre) {
            low[u] = low[u] < dfn[v] ? low[u] : dfn[v];
        }
    }
}