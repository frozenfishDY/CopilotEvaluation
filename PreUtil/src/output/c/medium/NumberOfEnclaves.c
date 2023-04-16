/**https://leetcode.com/problems/number-of-enclaves/ */
//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
//Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


int numEnclaves(int** grid, int gridSize, int* gridColSize){
    int result = 0;
    int* queue = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
    int* visited = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            visited[i * *gridColSize + j] = 0;
        }
    }
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1 && visited[i * *gridColSize + j] == 0){
                int count = 0;
                int head = 0;
                int tail = 0;
                queue[tail++] = i * *gridColSize + j;
                visited[i * *gridColSize + j] = 1;
                while(head < tail){
                    int x = queue[head] / *gridColSize;
                    int y = queue[head] % *gridColSize;
                    head++;
                    count++;
                    if(x > 0 && grid[x - 1][y] == 1 && visited[(x - 1) * *gridColSize + y] == 0){
                        queue[tail++] = (x - 1) * *gridColSize + y;
                        visited[(x - 1) * *gridColSize + y] = 1;
                    }
                    if(x < gridSize - 1 && grid[x + 1][y] == 1 && visited[(x + 1) * *gridColSize + y] == 0){
                        queue[tail++] = (x + 1) * *gridColSize + y;
                        visited[(x + 1) * *gridColSize + y] = 1;
                    }
                    if(y > 0 && grid[x][y - 1] == 1 && visited[x * *gridColSize + y - 1] == 0){
                        queue[tail++] = x * *gridColSize + y - 1;
                        visited[x * *gridColSize + y - 1] = 1;
                    }
                    if(y < *gridColSize - 1 && grid[x][y + 1 ] == 1 && visited[x * *gridColSize + y + 1] == 0){
                        queue[tail++] = x * *gridColSize + y + 1;
                        visited[x * *gridColSize + y + 1] = 1;
                    }
                    

}

    