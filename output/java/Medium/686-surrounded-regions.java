/**https://leetcode.com/problems/surrounded-regions/ */
//Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.


class SurroundedRegions {
    public void solve(char[][] board) {
        if(board == null || board.length == 0 || board[0].length == 0){
            return;
        }
        int m = board.length;
        int n = board[0].length;
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][n - 1] == 'O'){
                dfs(board, i, n - 1);
            }
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                dfs(board, 0, j);
            }
            if(board[m - 1][j] == 'O'){
                dfs(board, m - 1, j);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
}

    