/**https://leetcode.com/problems/count-of-smaller-numbers-after-self/ */
//Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var countSmaller = function(nums) {
    let n = nums.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(nums[i - 1] > nums[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= n; i++){
        ans.push(dp[n][i] - dp[n][i - 1]);
    }
    return ans;
    
};

    