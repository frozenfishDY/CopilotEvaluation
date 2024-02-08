/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.


int shortestBridge(int** grid, int gridSize, int* gridColSize){
    int* queue = (int*)malloc(sizeof(int) * gridSize * gridSize * 2);
    int queueSize = 0;
    int* visited = (int*)malloc(sizeof(int) * gridSize * gridSize);
    for(int i = 0; i < gridSize * gridSize; i++){
        visited[i] = 0;
    }
    int* direction = (int*)malloc(sizeof(int) * 4);
    direction[0] = 1;
    direction[1] = -1;
    direction[2] = gridSize;
    direction[3] = -gridSize;
    int result = 0;
    int found = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
            if(grid[i][j] == 1){
                queue[queueSize] = i * gridSize + j;
                queueSize++;
                visited[i * gridSize + j] = 1;
                found = 1;
                break;
            }
        }
        if(found == 1){
            break;
        }
    }
    while(queueSize != 0){
        int* temp = (int*)malloc(sizeof(int) * queueSize * 2);
        int tempSize = 0;
        for(int i = 0; i < queueSize; i++){
            int x = queue[i] / gridSize;
            int y = queue[i] % gridSize;
            for(int j = 0; j < 4; j++){
                int newX = x + direction[j];
                int newY = y + direction[j ^ 1];
                if(newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize && visited[newX * gridSize + newY] == 0){
                    if(grid[newX][newY] == 1){
                        return result;
                    }else{
                        temp[tempSize] = newX * gridSize + newY;
                        tempSize++;
                        visited[newX * gridSize + newY] = 1;
                    }
                }
            }
        }
        free(queue);
        queue = temp;
        queueSize = tempSize;
        result++;
    }
    return result;

}

    