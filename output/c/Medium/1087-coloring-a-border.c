/**https://leetcode.com/problems/coloring-a-border/ */
//You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
//Two squares belong to the same connected component if they have the same color and are next to each other in any of the 4 directions.
//The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).
//You should color the border of the connected component that contains the square grid[row][col] with color.
//Return the final grid.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * gridSize);
    int* stack = (int*)malloc(sizeof(int) * 10000);
    int top = -1;
    int i = 0;
    int j = 0;
    int temp = 0;
    int temp2 = 0;
    int temp3 = 0;
    int temp4 = 0;
    int temp5 = 0;
    int temp6 = 0;
    int temp7 = 0;
    int temp8 = 0;
    int temp9 = 0;
    int temp10 = 0;
    int temp11 = 0;
    int temp12 = 0;
    int temp13 = 0;
    int temp14 = 0;
    int temp15 = 0;
    int temp16 = 0;
    int temp17 = 0;
    int temp18 = 0;
    int temp19 = 0;
    int temp20 = 0;
    int temp21 = 0;
    int temp22 = 0;
    int temp23 = 0;
    int temp24 = 0;
    int temp25 = 0;
    int temp26 = 0;
    int temp27 = 0;
    int temp28 = 0;
    int temp29 = 0;
    int temp30 = 0;
    int temp31 = 0;
    int temp32 = 0;
    int temp33 = 0;
    int temp34 = 0;
    int temp35 = 0;
    int temp36 = 0;
    int temp37 = 0;
    int temp38 = 0;
    int temp39 = 0;
    int temp40 = 0;
    int temp41 = 0;
    int temp42 = 0;
    int temp43 = 0;
    int temp44 = 0;
    int temp45 = 0;
    int temp46 = 0;
    int temp47 = 0;
    int temp48 = 0;
    int temp49 = 0;
    int temp50 = 0;
    int temp51 = 0;
    int temp52 = 0;
    int temp53 = 0;
    int temp54 = 0;
    int temp55 = 0;
    int temp56 = 0;

}

    