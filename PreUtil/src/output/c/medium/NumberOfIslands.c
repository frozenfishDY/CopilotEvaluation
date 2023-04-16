/**https://leetcode.com/problems/number-of-islands/ */
//Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


int numIslands(char** grid, int gridSize, int* gridColSize){
    int* visited = (int*)calloc(gridSize * *gridColSize, sizeof(int));
    int count = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == '1' && visited[i * *gridColSize + j] == 0){
                count++;
                int* queue = (int*)malloc(sizeof(int) * gridSize * *gridColSize);
                int front = 0;
                int rear = 0;
                queue[rear++] = i * *gridColSize + j;
                visited[i * *gridColSize + j] = 1;
                while(front != rear){
                    int x = queue[front] / *gridColSize;
                    int y = queue[front] % *gridColSize;
                    front++;
                    if(x + 1 < gridSize && grid[x + 1][y] == '1' && visited[(x + 1) * *gridColSize + y] == 0){
                        queue[rear++] = (x + 1) * *gridColSize + y;
                        visited[(x + 1) * *gridColSize + y] = 1;
                    }
                    if(y + 1 < *gridColSize && grid[x][y + 1] == '1' && visited[x * *gridColSize + y + 1] == 0){
                        queue[rear++] = x * *gridColSize + y + 1;
                        visited[x * *gridColSize + y + 1] = 1;
                    }
                    if(x - 1 >= 0 && grid[x - 1][y] == '1' && visited[(x - 1) * *gridColSize + y] == 0){
                        queue[rear++] = (x - 1) * *gridColSize + y;
                        visited[(x - 1) * *gridColSize + y] = 1;
                    }
                    if(y - 1 >= 0 && grid[x][y - 1] == '1' && visited[x * *gridColSize + y - 1] == 0){
                        queue[rear++] = x * *gridColSize + y - 1;
                        visited[x * *grid ColSize + y - 1] = 1;
                        

}

    