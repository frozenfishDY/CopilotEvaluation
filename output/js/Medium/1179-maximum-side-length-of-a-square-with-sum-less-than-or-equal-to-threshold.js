/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.


/**
 * @param {number[][]} mat
 * @param {number} threshold
 * @return {number}
 */
var maxSideLength = function(mat, threshold) {
    let n = mat.length;
    let m = mat[0].length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(m + 1).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    let result = 0;
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            let l = 0;
            let r = Math.min(i, j);
            while(l <= r){
                let mid = Math.floor((l + r) / 2);
                let sum = dp[i][j] - dp[i - mid][j] - dp[i][j - mid] + dp[i - mid][j - mid];
                if(sum <= threshold){
                    result = Math.max(result, mid);
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
    }
    return result;
    
};

    