/**https://leetcode.com/problems/max-area-of-island/ */
//You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//The area of an island is the number of cells with a value 1 in the island.
//Return the maximum area of an island in grid. If there is no island, return 0.
// 
//Example 1:
//Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//Output: 6
//Explanation: The answer is not 11, because the island must be connected 4-directionally.
//Example 2:
//Input: grid = [[0,0,0,0,0,0,0,0]]
//Output: 0
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	grid[i][j] is either 0 or 1.
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
int maxArea = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                int area = 0;
                grid[i][j] = 0;
                int queue[2][2500];
                int queueStart = 0;
                int queueEnd = 1;
                queue[0][0] = i;
                queue[1][0] = j;
                while (queueStart < queueEnd) {
                    int x = queue[0][queueStart];
                    int y = queue[1][queueStart];
                    queueStart++;
                    area++;
                    if (x > 0 && grid[x - 1][y] == 1) {
                        grid[x - 1][y] = 0;
                        queue[0][queueEnd] = x - 1;
                        queue[1][queueEnd] = y;
                        queueEnd++;
                    }
                    if (x < gridSize - 1 && grid[x + 1][y] == 1) {
                        grid[x + 1][y] = 0;
                        queue[0][queueEnd] = x + 1;
                        queue[1][queueEnd] = y;
                        queueEnd++;
                    }
                    if (y > 0 && grid[x][y - 1] == 1) {
                        grid[x][y - 1] = 0;
                        queue[0][queueEnd] = x;
                        queue[1][queueEnd] = y - 1;
                        queueEnd++;
                    }
                    if (y < *gridColSize - 1 && grid[x][y + 1] == 1) {
                        grid[x][y + 1] = 0;
                        queue[0][queueEnd] = x;
                        queue[1][queueEnd] = y + 1;
                        queueEnd++;
                    }
                }
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    return maxArea;
}