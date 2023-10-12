/**https://leetcode.com/problems/shortest-path-with-alternating-colors/ */
//You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
//You are given two arrays redEdges and blueEdges where:
//	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
//	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
//Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
// 
//Example 1:
//Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
//Output: [0,1,-1]
//Example 2:
//Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
//Output: [0,1,-1]
// 
//Constraints:
//	1 <= n <= 100
//	0 <= redEdges.length, blueEdges.length <= 400
//	redEdges[i].length == blueEdges[j].length == 2
//	0 <= ai, bi, uj, vj < n
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestAlternatingPaths(int n, int** redEdges, int redEdgesSize, int* redEdgesColSize, int** blueEdges, int blueEdgesSize, int* blueEdgesColSize, int* returnSize){
int **red = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        red[i] = (int *)malloc(sizeof(int) * n);
        memset(red[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < redEdgesSize; ++i) {
        red[redEdges[i][0]][redEdges[i][1]] = 1;
    }
    int **blue = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        blue[i] = (int *)malloc(sizeof(int) * n);
        memset(blue[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < blueEdgesSize; ++i) {
        blue[blueEdges[i][0]][blueEdges[i][1]] = 1;
    }
    int *res = (int *)malloc(sizeof(int) * n);
    memset(res, -1, sizeof(int) * n);
    res[0] = 0;
    int *queue = (int *)malloc(sizeof(int) * n);
    int queueSize = 0;
    int *visited = (int *)malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    queue[queueSize++] = 0;
    visited[0] = 1;
    while (queueSize) {
        int cur = queue[0];
        for (int i = 0; i < queueSize - 1; ++i) {
            queue[i] = queue[i + 1];
        }
        --queueSize;
        for (int i = 0; i < n; ++i) {
            if (red[cur][i] && !visited[i]) {
                queue[queueSize++] = i;
                visited[i] = 1;
                res[i] = res[cur] + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (blue[cur][i] && !visited[i]) {
                queue[queueSize++] = i;
                visited[i] = 1;
                res[i] = res[cur] + 1;
            }
        }
    }
    *returnSize = n;
    return res;
}