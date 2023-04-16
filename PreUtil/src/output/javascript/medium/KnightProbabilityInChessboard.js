/**https://leetcode.com/problems/knight-probability-in-chessboard/ */
//On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
//A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


/**
 * @param {number} n
 * @param {number} k
 * @param {number} row
 * @param {number} column
 * @return {number}
 */
var knightProbability = function(n, k, row, column) {
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    dp[row][column] = 1;
    let moves = [[-2, -1], [-2, 1], [2, -1], [2, 1], [-1, -2], [-1, 2], [1, -2], [1, 2]];
    for(let i = 0; i < k; i++){
        let temp = new Array(n).fill(0).map(() => new Array(n).fill(0));
        for(let j = 0; j < n; j++){
            for(let l = 0; l < n; l++){
                for(let m = 0; m < 8; m++){
                    let x = j + moves[m][0];
                    let y = l + moves[m][1];
                    if(x >= 0 && x < n && y >= 0 && y < n){
                        temp[x][y] += dp[j][l] / 8;
                    }
                }
            }
        }
        dp = temp;
    }
    let result = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            result += dp[i][j];
        }
    }
    return result;
    
};

    