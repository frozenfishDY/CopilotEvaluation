/**https://leetcode.com/problems/pizza-with-3n-slices/ */
//There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
//You will pick any pizza slice.
//Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
//Your friend Bob will pick the next slice in the clockwise direction of your pick.
//Repeat until there are no more slices of pizzas.
//Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.


/**
 * @param {number[]} slices
 * @return {number}
 */
var maxSizeSlices = function(slices) {
    let n = slices.length;
    let k = Math.floor(n / 3);
    let dp = new Array(k + 1);
    for(let i = 0; i <= k; i++){
        dp[i] = new Array(n).fill(0);
    }
    for(let i = 1; i <= k; i++){
        for(let j = i - 1; j < n; j++){
            dp[i][j] = Math.max(dp[i][j - 1], (j >= 2 ? dp[i - 1][j - 2] : 0) + slices[j]);
        }
    }
    let ans = dp[k][n - 1];
    for(let i = 1; i <= k; i++){
        for(let j = i; j < n; j++){
            dp[i][j] = Math.max(dp[i][j - 1], (j >= 2 ? dp[i - 1][j - 2] : 0) + slices[j]);
        }
    }
    return Math.max(ans, dp[k][n - 2]);
    
    
};

    