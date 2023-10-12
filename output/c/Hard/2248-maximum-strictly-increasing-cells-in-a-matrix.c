/**https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/ */
//Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.
//From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.
//Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.
//Return an integer denoting the maximum number of cells that can be visited.
// 
//Example 1:
//Input: mat = [[3,1],[3,4]]
//Output: 2
//Explanation: The image shows how we can visit 2 cells starting from row 1, column 2. It can be shown that we cannot visit more than 2 cells no matter where we start from, so the answer is 2. 
//Example 2:
//Input: mat = [[1,1],[1,1]]
//Output: 1
//Explanation: Since the cells must be strictly increasing, we can only visit one cell in this example. 
//Example 3:
//Input: mat = [[3,1,6],[-9,5,7]]
//Output: 4
//Explanation: The image above shows how we can visit 4 cells starting from row 2, column 1. It can be shown that we cannot visit more than 4 cells no matter where we start from, so the answer is 4. 
// 
//Constraints:
//	m == mat.length 
//	n == mat[i].length 
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	-105 <= mat[i][j] <= 105
int maxIncreasingCells(int** mat, int matSize, int* matColSize){
int m = matSize;
	int n = matColSize[0];
	int *queue = malloc(sizeof(int)*m*n);
	int front = 0, rear = 0;
	int *visited = malloc(sizeof(int)*m*n);
	memset(visited, 0, sizeof(int)*m*n);
	int *distance = malloc(sizeof(int)*m*n);
	memset(distance, 0, sizeof(int)*m*n);
	
	int i = 0, j = 0;
	int *row = NULL;
	int vertex = 0;
	int result = -1;
	
	queue[rear++] = 0;
	visited[0] = 1;
	
	while(front < rear){
		vertex = queue[front++];
		visited[vertex] = 1;
		i = vertex/n;
		j = vertex%n;
		row = mat[i];
		if(j + row[j] < n){
			if(visited[vertex + row[j]] == 0){
				queue[rear++] = vertex + row[j];
				distance[vertex + row[j]] = distance[vertex] + 1;
			}
		}
		if(i + mat[i][j] < m){
			if(visited[vertex + n*mat[i][j]] == 0){
				queue[rear++] = vertex + n*mat[i][j];
				distance[vertex + n*mat[i][j]] = distance[vertex] + 1;
			}
		}
	}
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(distance[i*n + j] > result){
				result = distance[i*n + j];
			}
		}
	}
	
	return result + 1;
}