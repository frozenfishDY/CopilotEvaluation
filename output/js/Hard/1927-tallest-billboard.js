/**https://leetcode.com/problems/tallest-billboard/ */
//You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
//You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
//Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.


/**
 * @param {number[]} rods
 * @return {number}
 */
var tallestBillboard = function(rods) {
    let dp = [];
    for(let i = 0; i <= rods.length; i++){
        dp.push([]);
        for(let j = 0; j <= 10000; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= rods.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= rods.length; i++){
        for(let j = 1; j <= 10000; j++){
            if(j >= rods[i - 1]){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - rods[i - 1]];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = 0;
    for(let i = 0; i <= 10000; i++){
        if(dp[rods.length][i] > 0){
            ans = Math.max(ans, i);
        }
    }
    return ans;
    
};

    