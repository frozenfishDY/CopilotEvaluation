/**https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/ */
//You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).
//You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).
//Return true if it is possible to make the matrix disconnect or false otherwise.
//Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.


bool isPossibleToCutPath(int** grid, int gridSize, int* gridColSize){
    int* visited = (int*)calloc(gridSize * *gridColSize, sizeof(int));
    int* queue = (int*)malloc(sizeof(int) * gridSize * *gridColSize);
    int front = 0;
    int rear = 0;
    queue[rear++] = 0;
    visited[0] = 1;
    while(front != rear){
        int x = queue[front] / *gridColSize;
        int y = queue[front] % *gridColSize;
        front++;
        if(x == gridSize - 1 && y == *gridColSize - 1){
            return false;
        }
        if(x + 1 < gridSize && grid[x + 1][y] == 1 && visited[(x + 1) * *gridColSize + y] == 0){
            queue[rear++] = (x + 1) * *gridColSize + y;
            visited[(x + 1) * *gridColSize + y] = 1;
        }
        if(y + 1 < *gridColSize && grid[x][y + 1] == 1 && visited[x * *gridColSize + y + 1] == 0){
            queue[rear++] = x * *gridColSize + y + 1;
            visited[x * *gridColSize + y + 1] = 1;
        }
    }
    return true;

}

    