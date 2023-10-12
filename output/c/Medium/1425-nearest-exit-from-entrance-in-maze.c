/**https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/ */
//You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.
//In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
//Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
// 
//Example 1:
//Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
//Output: 1
//Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
//Initially, you are at the entrance cell [1,2].
//- You can reach [1,0] by moving 2 steps left.
//- You can reach [0,2] by moving 1 step up.
//It is impossible to reach [2,3] from the entrance.
//Thus, the nearest exit is [0,2], which is 1 step away.
//Example 2:
//Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
//Output: 2
//Explanation: There is 1 exit in this maze at [1,2].
//[1,0] does not count as an exit since it is the entrance cell.
//Initially, you are at the entrance cell [1,0].
//- You can reach [1,2] by moving 2 steps right.
//Thus, the nearest exit is [1,2], which is 2 steps away.
//Example 3:
//Input: maze = [[".","+"]], entrance = [0,0]
//Output: -1
//Explanation: There are no exits in this maze.
// 
//Constraints:
//	maze.length == m
//	maze[i].length == n
//	1 <= m, n <= 100
//	maze[i][j] is either '.' or '+'.
//	entrance.length == 2
//	0 <= entrancerow < m
//	0 <= entrancecol < n
//	entrance will always be an empty cell.
int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize){
int m=mazeSize;
    int n=*mazeColSize;
    int i,j;
    int row=entrance[0];
    int col=entrance[1];
    int step=0;
    int flag=0;
    int visited[m][n];
    memset(visited,0,sizeof(visited));
    visited[row][col]=1;
    int queue[m*n][2];
    int head=0;
    int tail=0;
    queue[tail][0]=row;
    queue[tail][1]=col;
    tail++;
    while(head<tail){
        int size=tail-head;
        while(size--){
            int row=queue[head][0];
            int col=queue[head][1];
            head++;
            if(row==0||row==m-1||col==0||col==n-1){
                if(!(row==entrance[0]&&col==entrance[1])){
                    return step;
                }
            }
            if(row-1>=0&&maze[row-1][col]=='.'&&visited[row-1][col]==0){
                visited[row-1][col]=1;
                queue[tail][0]=row-1;
                queue[tail][1]=col;
                tail++;
            }
            if(row+1<m&&maze[row+1][col]=='.'&&visited[row+1][col]==0){
                visited[row+1][col]=1;
                queue[tail][0]=row+1;
                queue[tail][1]=col;
                tail++;
            }
            if(col-1>=0&&maze[row][col-1]=='.'&&visited[row][col-1]==0){
                visited[row][col-1]=1;
                queue[tail][0]=row;
                queue[tail][1]=col-1;
                tail++;
            }
            if(col+1<n&&maze[row][col+1]=='.'&&visited[row][col+1]==0){
                visited[row][col+1]=1;
                queue[tail][0]=row;
                queue[tail][1]=col+1;
                tail++;
            }
        }
        step++;
    }
    return -1;
}