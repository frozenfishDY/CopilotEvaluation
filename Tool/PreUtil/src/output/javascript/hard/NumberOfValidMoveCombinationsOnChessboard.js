/**https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/ */
//There is an 8 x 8 chessboard containing n pieces (rooks, queens, or bishops). You are given a string array pieces of length n, where pieces[i] describes the type (rook, queen, or bishop) of the ith piece. In addition, you are given a 2D integer array positions also of length n, where positions[i] = [ri, ci] indicates that the ith piece is currently at the 1-based coordinate (ri, ci) on the chessboard.
//When making a move for a piece, you choose a destination square that the piece will travel toward and stop on.
//A rook can only travel horizontally or vertically from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), or (r, c-1).
//A queen can only travel horizontally, vertically, or diagonally from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), (r, c-1), (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).
//A bishop can only travel diagonally from (r, c) to the direction of (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).
//You must make a move for every piece on the board simultaneously. A move combination consists of all the moves performed on all the given pieces. Every second, each piece will instantaneously travel one square towards their destination if they are not already at it. All pieces start traveling at the 0th second. A move combination is invalid if, at a given time, two or more pieces occupy the same square.
//Return the number of valid move combinations.
//Notes:
//No two pieces will start in the same square.
//You may choose the square a piece is already on as its destination.
//If two pieces are directly adjacent to each other, it is valid for them to move past each other and swap positions in one second.


/**
 * @param {string[]} pieces
 * @param {number[][]} positions
 * @return {number}
 */
var countCombinations = function(pieces, positions) {
    let mod = 1000000007;
    let dp = new Array(8);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(8).fill(0);
    }
    dp[0][0] = 1;
    for(let i = 1; i < 8; i++){
        dp[i][0] = dp[i - 1][0] * 2 % mod;
        dp[0][i] = dp[0][i - 1] * 2 % mod;
    }
    for(let i = 1; i < 8; i++){
        for(let j = 1; j < 8; j++){
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    let ans = 1;
    for(let i = 0; i < pieces.length; i++){
        let [x, y] = positions[i];
        if(pieces[i] == "Rook"){
            ans = ans * dp[x - 1][y - 1] % mod;
        }else if(pieces[i] == "Queen"){
            ans = ans * dp[7][7] % mod;
        }else{
            ans = ans * (dp[x - 1][y - 1] + dp[7][7] - dp[7][y - 1] - dp[x - 1][7]) % mod;
        }
    }
    return ans;
    
};

    