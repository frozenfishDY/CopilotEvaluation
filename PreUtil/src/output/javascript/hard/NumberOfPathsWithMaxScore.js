/**https://leetcode.com/problems/number-of-paths-with-max-score/ */
//You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.
//You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.
//Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.
//In case there is no path, return [0, 0].


/**
 * @param {string[]} board
 * @return {number[]}
 */
var pathsWithMaxScore = function(board) {
    let n = board.length;
    let dp = new Array(n);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n).fill(0);
    }
    let mod = 1000000007;
    let paths = new Array(n);
    for(let i = 0; i < paths.length; i++){
        paths[i] = new Array(n).fill(0);
    }
    paths[n - 1][n - 1] = 1;
    for(let i = n - 1; i >= 0; i--){
        for(let j = n - 1; j >= 0; j--){
            if(board[i][j] == 'X'){
                continue;
            }
            if(i == n - 1 && j == n - 1){
                continue;
            }
            let max = 0;
            let count = 0;
            if(i + 1 < n && j + 1 < n){
                if(dp[i + 1][j + 1] > max){
                    max = dp[i + 1][j + 1];
                    count = paths[i + 1][j + 1];
                }
                else if(dp[i + 1][j + 1] == max){
                    count = (count + paths[i + 1][j + 1]) % mod;
                }
            }
            if(i + 1 < n){
                if(dp[i + 1][j] > max){
                    max = dp[i + 1][j];
                    count = paths[i + 1][j];
                }
                else if(dp[i + 1][j] == max){
                    count = (count + paths[i + 1][j]) % mod;
                }
            }
            if(j + 1 < n){
                if(dp[i][j + 1] > max){
                    max = dp[i][j + 1];
                    count = paths[i][j + 1];
                }
                else if(dp[i][j + 1] == max){
                    count = (count + paths[i][j + 1]) % mod;
                }
            }
            dp[i][j] = max + (board[i][j] == 'E' ? 0 : board[i][j].charCodeAt(0) - 48);
            paths[i ][j] = count;
        }
    }
    
};

    