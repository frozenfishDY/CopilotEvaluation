/**https://leetcode.com/problems/pacific-atlantic-water-flow/ */
//There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
//The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
//The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
//Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * heightsSize * (*heightsColSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * heightsSize * (*heightsColSize));
    int resultSize = 0;
    for(int i = 0; i < heightsSize; i++){
        for(int j = 0; j < *heightsColSize; j++){
            if(isPacificAtlantic(heights, heightsSize, *heightsColSize, i, j)){
                result[resultSize] = (int*)malloc(sizeof(int) * 2);
                (*returnColumnSizes)[resultSize] = 2;
                result[resultSize][0] = i;
                result[resultSize][1] = j;
                resultSize++;
            }
        }
    }
    *returnSize = resultSize;
    return result;

}

    