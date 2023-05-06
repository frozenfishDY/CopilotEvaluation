/**https://leetcode.com/problems/minimum-falling-path-sum/ */
//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    let dp = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        dp[i] = matrix[0][i];
    }
    for(let i = 1; i < n; i++){
        let temp = new Array(n).fill(0);
        for(let j = 0; j < n; j++){
            temp[j] = dp[j] + matrix[i][j];
            if(j > 0){
                temp[j] = Math.min(temp[j], dp[j - 1] + matrix[i][j]);
            }
            if(j < n - 1){
                temp[j] = Math.min(temp[j], dp[j + 1] + matrix[i][j]);
            }
        }
        dp = temp;
    }
    let result = dp[0];
    for(let i = 1; i < n; i++){
        result = Math.min(result, dp[i]);
    }
    return result;
    
};

    