/**https://leetcode.com/problems/modify-graph-edge-weights/ */
//You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.
//Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).
//Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.
//Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.
//Note: You are not allowed to modify the weights of edges with initial positive weights.
// 
//Example 1:
//Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
//Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
//Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
//Example 2:
//Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
//Output: []
//Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
//Example 3:
//Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
//Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
//Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
// 
//Constraints:
//	1 <= n <= 100
//	1 <= edges.length <= n * (n - 1) / 2
//	edges[i].length == 3
//	0 <= ai, bi < n
//	wi = -1 or 1 <= wi <= 107
//	ai != bi
//	0 <= source, destination < n
//	source != destination
//	1 <= target <= 109
//	The graph is connected, and there are no self-loops or repeated edges
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** modifiedGraphEdges(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination, int target, int* returnSize, int** returnColumnSizes){
int** result = malloc(sizeof(int*)*edgesSize);
	*returnSize = 0;
	*returnColumnSizes = malloc(sizeof(int)*edgesSize);
	
	int* queue = malloc(sizeof(int)*edgesSize);
	int front = 0, rear = 0;
	int* visited = malloc(sizeof(int)*edgesSize);
	memset(visited, 0, sizeof(int)*edgesSize);
	int* distance = malloc(sizeof(int)*edgesSize);
	memset(distance, 0, sizeof(int)*edgesSize);
	
	int i = 0;
	int* edge = NULL;
	int vertex = 0;
	int result = -1;
	
	queue[rear++] = source;
	visited[source] = 1;
	
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