/**https://leetcode.com/problems/path-with-maximum-probability/ */
//You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
//Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
//If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
// 
//Example 1:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
//Output: 0.25000
//Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
//Example 2:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
//Output: 0.30000
//Example 3:
//Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
//Output: 0.00000
//Explanation: There is no path between 0 and 2.
// 
//Constraints:
//	2 <= n <= 10^4
//	0 <= start, end < n
//	start != end
//	0 <= a, b < n
//	a != b
//	0 <= succProb.length == edges.length <= 2*10^4
//	0 <= succProb[i] <= 1
//	There is at most one edge between every two nodes.
double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start_node, int end_node){
double *dist = calloc(n, sizeof(double));
    bool *visited = calloc(n, sizeof(bool));
    int **graph = calloc(n, sizeof(int *));
    int *graphSize = calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        graph[edges[i][0]] = realloc(graph[edges[i][0]], (graphSize[edges[i][0]] + 1) * sizeof(int));
        graph[edges[i][1]] = realloc(graph[edges[i][1]], (graphSize[edges[i][1]] + 1) * sizeof(int));
        graph[edges[i][0]][graphSize[edges[i][0]]] = edges[i][1];
        graph[edges[i][1]][graphSize[edges[i][1]]] = edges[i][0];
        graphSize[edges[i][0]]++;
        graphSize[edges[i][1]]++;
    }
    dist[start_node] = 1;
    for (int i = 0; i < n; i++) {
        int min = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && (min == -1 || dist[j] > dist[min])) {
                min = j;
            }
        }
        visited[min] = true;
        for (int j = 0; j < graphSize[min]; j++) {
            if (visited[graph[min][j]] == false) {
                if (dist[min] * succProb[graph[min][j]] > dist[graph[min][j]]) {
                    dist[graph[min][j]] = dist[min] * succProb[graph[min][j]];
                }
            }
        }
    }
    return dist[end_node];
}