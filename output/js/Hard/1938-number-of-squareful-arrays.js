/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].


/**
 * @param {number[]} nums
 * @return {number}
 */
var numSquarefulPerms = function(nums) {
    let dp = [];
    for(let i = 0; i <= nums.length; i++){
        dp.push([]);
        for(let j = 0; j <= nums.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= nums.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= nums.length; i++){
        for(let j = 1; j <= nums.length; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= nums.length; i++){
        ans.push(dp[nums.length][i] - dp[nums.length][i - 1]);
    }
    return ans;
    
};

    