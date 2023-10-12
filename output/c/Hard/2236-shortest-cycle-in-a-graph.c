/**https://leetcode.com/problems/shortest-cycle-in-a-graph/ */
//There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
//Return the length of the shortest cycle in the graph. If no cycle exists, return -1.
//A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
//Output: 3
//Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
//Example 2:
//Input: n = 4, edges = [[0,1],[0,2]]
//Output: -1
//Explanation: There are no cycles in this graph.
// 
//Constraints:
//	2 <= n <= 1000
//	1 <= edges.length <= 1000
//	edges[i].length == 2
//	0 <= ui, vi < n
//	ui != vi
//	There are no repeated edges.
int findShortestCycle(int n, int** edges, int edgesSize, int* edgesColSize){
int *queue = malloc(sizeof(int)*n);
	int front = 0, rear = 0;
	int *visited = malloc(sizeof(int)*n);
	memset(visited, 0, sizeof(int)*n);
	int *distance = malloc(sizeof(int)*n);
	memset(distance, 0, sizeof(int)*n);
	
	int i = 0;
	int *edge = NULL;
	int vertex = 0;
	int result = -1;
	
	queue[rear++] = 0;
	visited[0] = 1;
	
	while(front < rear){
		vertex = queue[front++];
		visited[vertex] = 1;
		edge = edges[i++];
		if(edge[0] == vertex){
			if(visited[edge[1]] == 0){
				queue[rear++] = edge[1];
				distance[edge[1]] = distance[vertex] + 1;
			} else {
				result = distance[vertex] + distance[edge[1]] + 1;
				break;
			}
		} else {
			if(visited[edge[0]] == 0){
				queue[rear++] = edge[0];
				distance[edge[0]] = distance[vertex] + 1;
			} else {
				result = distance[vertex] + distance[edge[0]] + 1;
				break;
			}
		}
	}
	return result;
}