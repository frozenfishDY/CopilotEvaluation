/**https://leetcode.com/problems/shortest-path-in-binary-matrix/ */
//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
//A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//	All the visited cells of the path are 0.
//	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 2
//Example 2:
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
int result = 0;
    if (grid[0][0] == 1) {
        return -1;
    }
    grid[0][0] = 1;
    int queue[2][2500];
    int queueStart = 0;
    int queueEnd = 1;
    queue[0][0] = 0;
    queue[1][0] = 0;
    while (queueStart < queueEnd) {
        int x = queue[0][queueStart];
        int y = queue[1][queueStart];
        queueStart++;
        if (x == gridSize - 1 && y == *gridColSize - 1) {
            result = grid[x][y];
            break;
        }
        if (x > 0 && grid[x - 1][y] == 0) {
            grid[x - 1][y] = grid[x][y] + 1;
            queue[0][queueEnd] = x - 1;
            queue[1][queueEnd] = y;
            queueEnd++;
        }
        if (x < gridSize - 1 && grid[x + 1][y] == 0) {
            grid[x + 1][y] = grid[x][y] + 1;
            queue[0][queueEnd] = x + 1;
            queue[1][queueEnd] = y;
            queueEnd++;
        }
        if (y > 0 && grid[x][y - 1] == 0) {
            grid[x][y - 1] = grid[x][y] + 1;
            queue[0][queueEnd] = x;
            queue[1][queueEnd] = y - 1;
            queueEnd++;
        }
        if (y < *gridColSize - 1 && grid[x][y + 1] == 0) {
            grid[x][y + 1] = grid[x][y] + 1;
            queue[0][queueEnd] = x;
            queue[1][queueEnd] = y + 1;
            queueEnd++;
        }
        if (x > 0 && y > 0 && grid[x - 1][y - 1] == 0) {
            grid[x - 1][y - 1] = grid[x][y] + 1;
            queue[0][queueEnd] = x - 1;
            queue[1][queueEnd] = y - 1;
            queueEnd++;
        }
        if (x > 0 && y < *gridColSize - 1 && grid[x - 1][y + 1] == 0) {
            grid[x - 1][y + 1] = grid[x][y] + 1;
            queue[0][queueEnd] = x - 1;
            queue[1][queueEnd] = y + 1;
            queueEnd++;
        }
        if (x < gridSize - 1 && y > 0 && grid[x + 1][y - 1] == 0) {
            grid[x + 1][y - 1] = grid[x][y] + 1;
            queue[0][queueEnd] = x + 1;
            queue[1][queueEnd] = y - 1;
            queueEnd++;
        }
        if (x < gridSize - 1 && y < *gridColSize - 1 && grid[x + 1][y + 1] == 0) {
            grid[x + 1][y + 1] = grid[x][y] + 1;
            queue[0][queueEnd] = x + 1;
            queue[1][queueEnd] = y + 1;
            queueEnd++;
        }
    }
    return result;
}