/**https://leetcode.com/problems/count-increasing-quadruplets/ */
//Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.
//A quadruplet (i, j, k, l) is increasing if:
//0 <= i < j < k < l < n, and
//nums[i] < nums[k] < nums[j] < nums[l].


/**
 * @param {number[]} nums
 * @return {number}
 */
var countQuadruplets = function(nums) {

    let n = nums.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= n; k++){
                dp[i][j].push([]);
                for(let l = 0; l <= n; l++){
                    dp[i][j][k].push(0);
                }
            }
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][0][0][0] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            for(let k = 1; k <= n; k++){
                for(let l = 1; l <= n; l++){
                    if(nums[i - 1] > nums[l - 1]){
                        dp[i][j][k][l] = dp[i - 1][j - 1][k - 1][l - 1] + dp[i - 1][j][k][l];
                    }else{
                        dp[i][j][k][l] = dp[i - 1][j][k][l];
                    }
                }
            }
        }
    let ans = [];
    for(let i = 1; i <= n; i++){
        ans.push(dp[n][n][n][i] - dp[n][n][n][i - 1]);
    }
    return ans;
    

    

    
};


    