/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//The character '.' represents the floor which means a free cell to walk.
//The character '#' represents the wall which means an obstacle (impossible to walk there).
//There is only one box 'B' and one target cell 'T' in the grid.
//The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.


int minPushBox(char** grid, int gridSize, int* gridColSize){
    int i,j;
    int** visited = (int**)malloc(sizeof(int*)*gridSize);
    for(i=0;i<gridSize;i++){
        visited[i] = (int*)malloc(sizeof(int)*gridColSize[0]);
        for(j=0;j<gridColSize[0];j++){
            visited[i][j] = 0;
        }
    }
    int** queue = (int**)malloc(sizeof(int*)*gridSize*gridColSize[0]);
    for(i=0;i<gridSize*gridColSize[0];i++){
        queue[i] = (int*)malloc(sizeof(int)*4);
    }
    int front = 0;
    int rear = 0;
    int bx = 0;
    int by = 0;
    int tx = 0;
    int ty = 0;
    int sx = 0;
    int sy = 0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            if(grid[i][j] == 'B'){
                bx = i;
                by = j;
            }
            if(grid[i][j] == 'T'){
                tx = i;
                ty = j;
            }
            if(grid[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    queue[rear][0] = bx;
    queue[rear][1] = by;
    queue[rear][2] = sx;
    queue[rear][3] = sy;
    rear++;
    visited[bx][by] = 1;
    int count = 0;
    while(front != rear){
        int x = queue[front][0];
        int y = queue[front][1];
        int sx = queue[front][2];
        int sy = queue[front][3];
        front++;
        if(x == tx && y == ty){
            return count;
        }
        if(x+1 < gridSize && grid[x+1][y] != '#' && visited[x+1][y] == 0){
            if(sx == x+1 && sy == y){
                queue[rear][0] = x+1;
                queue[rear][1] = y;
                queue[rear][2] = x;
                queue[rear][3] = y

}

    