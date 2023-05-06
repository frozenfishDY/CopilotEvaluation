/**https://leetcode.com/problems/sliding-window-maximum/ */
//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    let n = nums.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= k; j++){
            dp[i].push(0);
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= k; j++){
            if(i - j >= 0){
                dp[i][j] = Math.max(dp[i - 1][j], nums[i - 1]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = k; i <= n; i++){
        ans.push(dp[i][k]);
    }
    return ans;
    
};

    