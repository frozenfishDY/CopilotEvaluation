/**https://leetcode.com/problems/bricks-falling-when-hit/ */
//You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:
//It is directly connected to the top of the grid, or
//At least one other brick in its four adjacent cells is stable.
//You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).
//Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.
//Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* hitBricks(int** grid, int gridSize, int* gridColSize, int** hits, int hitsSize, int* hitsColSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * hitsSize);
    *returnSize = hitsSize;
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int row = gridSize;
    int col = *gridColSize;
    int hitSize = hitsSize;
    int hitColSize = *hitsColSize;
    int** gridCopy = (int**)malloc(sizeof(int*) * row);
    for(i = 0; i < row; i++){
        gridCopy[i] = (int*)malloc(sizeof(int) * col);
        for(j = 0; j < col; j++){
            gridCopy[i][j] = grid[i][j];
        }
    }
    int* parent = (int*)malloc(sizeof(int) * row * col);
    int* size = (int*)malloc(sizeof(int) * row * col);
    int* rank = (int*)malloc(sizeof(int) * row * col);
    for(i = 0; i < row * col; i++){
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }
    int* dx = (int*)malloc(sizeof(int) * 4);
    int* dy = (int*)malloc(sizeof(int) * 4);
    dx[0] = 0;
    dx[1] = 0;
    dx[2] = 1;
    dx[3] = -1;
    dy[0] = 1;
    dy[1] = -1;
    dy[2] = 0;
    dy[3] = 0;
    for(i = 0; i < hitSize; i++){
        gridCopy[hits[i][0]][hits[i][1]] = 0;
    }
    for(i = 0; i < col; i++){
        if(gridCopy[0][i] == 1){
            unionSet(parent, size, rank, i, -1);
        }
    }
    for(i = 1; i < row; i++){
        for(j = 0; j < col; j++){
            if(gridCopy[i][j] == 1){
                if(gridCopy[i - 1][j] == 1){
                    unionSet(parent ,size, rank, i * col + j, (i - 1) * col + j);

                    

}

    