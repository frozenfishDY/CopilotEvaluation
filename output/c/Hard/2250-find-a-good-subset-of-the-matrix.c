/**https://leetcode.com/problems/find-a-good-subset-of-the-matrix/ */
//You are given a 0-indexed m x n binary matrix grid.
//Let us call a non-empty subset of rows good if the sum of each column of the subset is at most half of the length of the subset.
//More formally, if the length of the chosen subset of rows is k, then the sum of each column should be at most floor(k / 2).
//Return an integer array that contains row indices of a good subset sorted in ascending order.
//If there are multiple good subsets, you can return any of them. If there are no good subsets, return an empty array.
//A subset of rows of the matrix grid is any matrix that can be obtained by deleting some (possibly none or all) rows from grid.
// 
//Example 1:
//Input: grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
//Output: [0,1]
//Explanation: We can choose the 0th and 1st rows to create a good subset of rows.
//The length of the chosen subset is 2.
//- The sum of the 0th column is 0 + 0 = 0, which is at most half of the length of the subset.
//- The sum of the 1st column is 1 + 0 = 1, which is at most half of the length of the subset.
//- The sum of the 2nd column is 1 + 0 = 1, which is at most half of the length of the subset.
//- The sum of the 3rd column is 0 + 1 = 1, which is at most half of the length of the subset.
//Example 2:
//Input: grid = [[0]]
//Output: [0]
//Explanation: We can choose the 0th row to create a good subset of rows.
//The length of the chosen subset is 1.
//- The sum of the 0th column is 0, which is at most half of the length of the subset.
//Example 3:
//Input: grid = [[1,1,1],[1,1,1]]
//Output: []
//Explanation: It is impossible to choose any subset of rows to create a good subset.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m <= 104
//	1 <= n <= 5
//	grid[i][j] is either 0 or 1.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* goodSubsetofBinaryMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize){
int *result = malloc(sizeof(int)*gridSize);
	memset(result, 0, sizeof(int)*gridSize);
	*returnSize = gridSize;
	
	int *queue = malloc(sizeof(int)*gridSize);
	int front = 0, rear = 0;
	int *visited = malloc(sizeof(int)*gridSize);
	memset(visited, 0, sizeof(int)*gridSize);
	int *distance = malloc(sizeof(int)*gridSize);
	memset(distance, 0, sizeof(int)*gridSize);
	
	int i = 0;
	int *bannedVertex = NULL;
	int vertex = 0;
	int result = -1;
	
	queue[rear++] = p;
	visited[p] = 1;
	
	while(front < rear){
		vertex = queue[front++];
		visited[vertex] = 1;
		if(vertex == p){
			result = 0;
		}
		bannedVertex = banned[i++];
		if(visited[bannedVertex] == 0){
			queue[rear++] = bannedVertex;
			distance[bannedVertex] = distance[vertex] + 1;
		} else {
			result = distance[vertex] + distance[bannedVertex] + 1;
			break;
		}
	}
	
	if(result == -1){
		*returnSize = 0;
		return NULL;
	}
	
	result = malloc(sizeof(int)*result);
	memset(result, 0, sizeof(int)*result);
	
	result[--result] = bannedVertex;
	while(result > 0){
		result--;
		vertex = queue[front++];
		if(distance[vertex] == result){
			result[result] = vertex;
		} else {
			result++;
			break;
		}
	}
	
	*returnSize = result;
	return result;
}