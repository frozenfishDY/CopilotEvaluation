/**https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/ */
//In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
//In one move the snake can:
//Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
//Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
//Return the minimum number of moves to reach the target.
//If there is no way to reach the target, return -1.


int minimumMoves(int** grid, int gridSize, int* gridColSize){
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
        int dir = queue[front][2];
        int step = queue[front][3];
        front++;
        if(x == gridSize-1 && y == gridSize-2 && dir == 0){
            return step;
        }
        if(dir == 0){
            if(y+1 < gridSize && grid[x][y+1] == 0 && visited[x][y+1] == 0){
                queue[rear][0] = x;
                queue[rear][1] = y+1;
                queue[rear][2] = 0;
                queue[rear][3] = step+1;
                rear++;
                visited[x][y+1] = 1;
            }
            if(x+1 < gridSize && grid[x+1][y] == 0 && grid[x+1][y+1] == 0 && visited[x+1][y] == 0){
                queue[rear][0] = x+1;
                queue[rear][1] = y;
                queue[rear][2] = 1;
                queue[rear][3] = step+1;
                rear++;
                visited[x+1][y] = 1;
            }
        }
        else{
            if(x+1 < gridSize && grid[x+1][y] == 0 && grid[x+1][y+1] == 0 && visited[x+1][y] == 0){
                queue[rear][0] = x+1;
                queue[rear][1] = y;
                queue[rear][2] = 1;
                queue[rear][3] = step+1;
                rear++;
                visited[x+1][y] = 1;
            }
            if(y+1 < gridSize && grid[x][y+1] == 0 && visited[x][y+1] == 0){
                queue[rear][0] = x;
                queue[rear][1] = y+1;
                queue[rear][2] = 0;
                queue[rear][3] = step+1;
                rear++;
                visited[x][y+1] = 1;
            }
            

}

    