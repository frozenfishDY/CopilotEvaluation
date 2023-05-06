/**https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/ */
//You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
//Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.


int shortestPath(int** grid, int gridSize, int* gridColSize, int k){
    int i,j;
    int** visited = (int**)malloc(sizeof(int*)*gridSize);
    for(i=0;i<gridSize;i++){
        visited[i] = (int*)malloc(sizeof(int)*gridSize);
        for(j=0;j<gridSize;j++){
            visited[i][j] = 0;
        }
    }
    int** queue = (int**)malloc(sizeof(int*)*gridSize*gridSize);
    for(i=0;i<gridSize*gridSize;i++){
        queue[i] = (int*)malloc(sizeof(int)*4);
    }
    int front = 0;
    int rear = 0;
    queue[rear][0] = 0;
    queue[rear][1] = 0;
    queue[rear][2] = 0;
    queue[rear][3] = 0;
    rear++;
    visited[0][0] = 1;
    int count = 0;
    while(front != rear){
        int x = queue[front][0];
        int y = queue[front][1];
        int step = queue[front][2];
        int obs = queue[front][3];
        front++;
        if(x == gridSize-1 && y == gridSize-1){
            return step;
        }
        if(y+1 < gridSize && grid[x][y+1] == 0 && visited[x][y+1] == 0){
            queue[rear][0] = x;
            queue[rear][1] = y+1;
            queue[rear][2] = step+1;
            queue[rear][3] = obs;
            rear++;
            visited[x][y+1] = 1;
        }
        if(x+1 < gridSize && grid[x+1][y] == 0 && visited[x+1][y] == 0){
            queue[rear][0] = x+1;
            queue[rear][1] = y;
            queue[rear][2] = step+1;
            queue[rear][3] = obs;
            rear++;
            visited[x+1][y] = 1;
        }
        if(y-1 >= 0 && grid[x][y-1] == 0 && visited[x][y-1] == 0){
            queue[rear][0] = x;
            queue[rear][1] = y-1;
            queue[rear][2] = step+1;
            queue[rear][3] = obs;
            rear++;
            visited[x][y-1] = 1;

                    

}

    