/**https://leetcode.com/problems/escape-a-large-maze/ */
//There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
//We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
//Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
//Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.


bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize){
    int i,j;
    int** grid = (int**)malloc(sizeof(int*)*1000000);
    for(i=0;i<1000000;i++){
        grid[i] = (int*)malloc(sizeof(int)*1000000);
        for(j=0;j<1000000;j++){
            grid[i][j] = 0;
        }
    }
    for(i=0;i<blockedSize;i++){
        grid[blocked[i][0]][blocked[i][1]] = 1;
    }
    int** visited = (int**)malloc(sizeof(int*)*1000000);
    for(i=0;i<1000000;i++){
        visited[i] = (int*)malloc(sizeof(int)*1000000);
        for(j=0;j<1000000;j++){
            visited[i][j] = 0;
        }
    }
    int** queue = (int**)malloc(sizeof(int*)*1000000);
    for(i=0;i<1000000;i++){
        queue[i] = (int*)malloc(sizeof(int)*2);
    }
    int front = 0;
    int rear = 0;
    queue[rear][0] = source[0];
    queue[rear][1] = source[1];
    rear++;
    visited[source[0]][source[1]] = 1;
    int count = 0;
    while(front != rear){
        int x = queue[front][0];
        int y = queue[front][1];
        front++;
        count++;
        if(count > 20000){
            return true;
        }
        if(x == target[0] && y == target[1]){
            return true;
        }
        if(x+1 < 1000000 && grid[x+1][y] == 0 && visited[x+1][y] == 0){
            queue[rear][0] = x+1;
            queue[rear][1] = y;
            rear++;
            visited[x+1][y] = 1;
        }
        if(x-1 >= 0 && grid[x-1][y] == 0 && visited[x-1][y] == 0){
            queue[rear][0] = x-1;
            queue[rear][1] = y;
            rear++;
            visited[x-1][y] = 1;
        }
        if(y+1 < 1000000 && grid[x][y+1] == 0 && visited[x][y+1] == 0){
            queue[rear][0] = x;
            queue[rear][1] = y+1;
            rear++;
            visited[x][y+1] = 1;
        }
        if(y-1 >= 0 && grid[x][y-1] == 0 && visited[x][y-1] == 0){
            queue[rear][0] = x;
            queue[rear][1] = y-1;
            rear++;
            visited[x][y-1] = 1;
        }

        

}

    