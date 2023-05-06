/**https://leetcode.com/problems/maximize-score-after-n-operations/ */
//You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
//In the ith operation (1-indexed), you will:
//Choose two elements, x and y.
//Receive a score of i * gcd(x, y).
//Remove x and y from nums.
//Return the maximum score you can receive after performing n operations.
//The function gcd(x, y) is the greatest common divisor of x and y.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxScore = function(nums) {
    let n = nums.length;
    let dp = new Array(1 << n).fill(0);
    for(let i = 1; i < (1 << n); i++){
        let count = 0;
        for(let j = 0; j < n; j++){
            if(i & (1 << j)){
                count++;
            }
        }
        if(count % 2 == 1){
            continue;
        }
        for(let j = 0; j < n; j++){
            if(i & (1 << j)){
                for(let k = j + 1; k < n; k++){
                    if(i & (1 << k)){
                        dp[i] = Math.max(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + (count / 2) * gcd(nums[j], nums[k]));
                    }
                }
            }
        }
    }
    return dp[(1 << n) - 1];
    
    
};

    