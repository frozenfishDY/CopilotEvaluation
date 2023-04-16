/**https://leetcode.com/problems/transform-to-chessboard/ */
//You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.
//Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.
//A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.


/**
 * @param {number[][]} board
 * @return {number}
 */
var movesToChessboard = function(board) {
    let n = board.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push(0);
        }
    }
    dp[0][0] = 1;
    for(let i = 1; i < n; i++){
        if(board[i][0] >= board[i - 1][0]){
            dp[i][0] = dp[i - 1][0];
        }
        if(board[0][i] >= board[0][i - 1]){
            dp[0][i] = dp[0][i - 1];
        }
    }
    for(let i = 1; i < n; i++){
        for(let j = 1; j < n; j++){
            if(board[i][j] >= board[i - 1][j] && board[i][j] >= board[i][j - 1]){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }else if(board[i][j] >= board[i - 1][j]){
                dp[i][j] = dp[i - 1][j];
            }else if(board[i][j] >= board[i][j - 1]){
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][n - 1];
    
};

    