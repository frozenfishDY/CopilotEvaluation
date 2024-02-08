/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.


int largestIsland(int** grid, int gridSize, int* gridColSize){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int** visited = (int**)malloc(sizeof(int*) * gridSize);
    for(i = 0; i < gridSize; i++){
        visited[i] = (int*)malloc(sizeof(int) * gridColSize[0]);
        for(j = 0; j < gridColSize[0]; j++){
            visited[i][j] = 0;
        }
    }
    int** id = (int**)malloc(sizeof(int*) * gridSize);
    for(i = 0; i < gridSize; i++){
        id[i] = (int*)malloc(sizeof(int) * gridColSize[0]);
        for(j = 0; j < gridColSize[0]; j++){
            id[i][j] = -1;
        }
    }
    int* area = (int*)malloc(sizeof(int) * (gridSize * gridColSize[0] + 1));
    for(i = 0; i <= gridSize * gridColSize[0]; i++){
        area[i] = 0;
    }
    int idCount = 0;
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                idCount++;
                int** queue = (int**)malloc(sizeof(int*) * (gridSize * gridColSize[0] + 1));
                for(k = 0; k <= gridSize * gridColSize[0]; k++){
                    queue[k] = (int*)malloc(sizeof(int) * 2);
                }
                int front = 0;
                int rear = 0;
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
                while(front < rear){
                    int x = queue[front][0];
                    int y = queue[front][1];
                    front++;
                    if(visited[x][y] == 1) continue;
                    visited[x][y] = 1;
                    id[x][y] = idCount;
                    area[idCount]++;
                    if(x > 0 && grid[x - 1][y] == 1 && visited [x - 1][y] == 0){
                        queue[rear][0] = x - 1;
                        queue[rear][1] = y;
                        rear++;
                    }
                    if(x < gridSize - 1 && grid[x + 1][y] == 1 && visited [x + 1][y] == 0){
                        queue[rear][0] = x + 1;
                        queue[rear][1] = y;
                        rear++;
                    }
                    if(y > 0 && grid[x][y - 1] == 1 && visited [x][y - 1] == 0){
                        queue[rear][0] = x;
                        queue[rear][1] = y - 1;
                        rear++;
                    }
                    if(y < gridColSize[0] - 1 && grid[x][y + 1] == 1 && visited [x][y + 1] == 0){
                        queue[rear][0] = x;
                        queue[rear][1] = y + 1;
                        rear++;
                    }

             
             

}

    