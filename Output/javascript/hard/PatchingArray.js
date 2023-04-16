/**https://leetcode.com/problems/patching-array/ */
//Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
//Return the minimum number of patches required.


/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number}
 */
var minPatches = function(nums, n) {
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

    