/**https://leetcode.com/problems/surrounded-regions/ */
//Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.


void solve(char** board, int boardSize, int* boardColSize){
    int* visited = (int*)calloc(boardSize * *boardColSize, sizeof(int));
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            if(board[i][j] == 'O' && visited[i * *boardColSize + j] == 0){
                int* queue = (int*)malloc(sizeof(int) * boardSize * *boardColSize);
                int front = 0;
                int rear = 0;
                int count = 0;
                int flag = 0;
                queue[rear++] = i * *boardColSize + j;
                visited[i * *boardColSize + j] = 1;
                while(front != rear){
                    int x = queue[front] / *boardColSize;
                    int y = queue[front] % *boardColSize;
                    front++;
                    count++;
                    if(x == 0 || x == boardSize - 1 || y == 0 || y == *boardColSize - 1){
                        flag = 1;
                    }
                    if(x - 1 >= 0 && board[x - 1][y] == 'O' && visited[(x - 1) * *boardColSize + y] == 0){
                        queue[rear++] = (x - 1) * *boardColSize + y;
                        visited[(x - 1) * *boardColSize + y] = 1;
                    }
                    if(x + 1 < boardSize && board[x + 1][y] == 'O' && visited[(x + 1) * *boardColSize + y] == 0){
                        queue[rear++] = (x + 1) * *boardColSize + y;
                        visited[(x + 1) * *boardColSize + y] = 1;
                    }
                    if(y - 1 >= 0 && board[x][y - 1] == 'O' && visited[x * *boardColSize + y - 1] == 0){
                        queue[rear++] = x * *boardColSize + y - 1;
                        visited[x * *boardColSize + y - 1] = 1;
                    }
                    if(y + 1 < *boardColSize && board[x][y + 1] == 'O' && visited[x * *boardColSize + y + 1] == 0){
                        queue[rear++] = x * *boardColSize + y + 1;
                        visited[x * *boardColSize + y + 1] = 1;
                    }
                    

}

    