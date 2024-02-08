/**https://leetcode.com/problems/minimum-score-triangulation-of-polygon/ */
//You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
//You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.
//Return the smallest possible total score that you can achieve with some triangulation of the polygon.


/**
 * @param {number[]} values
 * @return {number}
 */
var minScoreTriangulation = function(values) {
    let n = values.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for(let i = 2; i < n; i++){
        for(let j = 0; j < n - i; j++){
            let k = j + i;
            dp[j][k] = Number.MAX_SAFE_INTEGER;
            for(let m = j + 1; m < k; m++){
                dp[j][k] = Math.min(dp[j][k], dp[j][m] + dp[m][k] + values[j] * values[m] * values[k]);
            }
        }
    }
    return dp[0][n - 1];
    
};

    