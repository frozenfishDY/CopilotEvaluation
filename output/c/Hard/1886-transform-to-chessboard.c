/**https://leetcode.com/problems/transform-to-chessboard/ */
//You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.
//Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.
//A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.


int movesToChessboard(int** board, int boardSize, int* boardColSize){
    int n = boardSize;
    int i, j, k, l, r, c, cnt, ans = 0;
    int *row = malloc(n * sizeof(int));
    int *col = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        row[i] = board[0][i];
        col[i] = board[i][0];
    }
    for (i = 0; i < n; i++) {
        if (row[i] != i % 2) {
            for (j = i + 1; j < n; j++) {
                if (row[j] == i % 2) {
                    for (k = 0; k < n; k++) {
                        row[k] ^= 1;
                    }
                    ans++;
                    break;
                }
            }
            if (j == n) {
                return -1;
            }
        }
        if (col[i] != i % 2) {
            for (j = i + 1; j < n; j++) {
                if (col[j] == i % 2) {
                    for (k = 0; k < n; k++) {
                        col[k] ^= 1;
                    }
                    ans++;
                    break;
                }
            }
            if (j == n) {
                return -1;
            }
        }
    }
    cnt = 0;
    for (i = 0; i < n; i++) {
        cnt += row[i];
    }
    if (cnt != n / 2 && cnt != (n + 1) / 2) {
        return -1;
    }
    cnt = 0;
    for (i = 0; i < n; i++) {
        cnt += col[i];
    }
    if (cnt != n / 2 && cnt != (n + 1) / 2) {
        return -1;
    }
    r = c = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && board[i][j] != row[i]) {
                r++;
            }
            if ((i + j) % 2 == 1 && board[i][j]
                != col[j]) {
                c++;
            }

                
    
       


}

    