/**https://leetcode.com/problems/detect-cycles-in-2d-grid/ */
//Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
//A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
//Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
//Return true if any cycle of the same value exists in grid, otherwise, return false.


bool containsCycle(char** grid, int gridSize, int* gridColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int row = gridSize;
    int col = gridColSize[0];
    int* arr = (int*)malloc(sizeof(int) * row * col);
    for(i = 0; i < row * col; i++){
        arr[i] = 0;
    }
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(arr[i * col + j] == 0){
                arr[i * col + j] = 1;
                if(containsCycleHelper(grid, gridSize, gridColSize, i, j, i, j, arr)){
                    return true;
                }
            }
        }
    }
    return false;

}

    