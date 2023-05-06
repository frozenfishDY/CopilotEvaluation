/**https://leetcode.com/problems/distribute-repeating-integers/ */
//You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
//The ith customer gets exactly quantity[i] integers,
//The integers the ith customer gets are all equal, and
//Every customer is satisfied.
//Return true if it is possible to distribute nums according to the above conditions.


/**
 * @param {number[]} nums
 * @param {number[]} quantity
 * @return {boolean}
 */
var canDistribute = function(nums, quantity) {
    let n = quantity.length;
    let m = 1 << n;
    let dp = new Array(m).fill(false);
    dp[0] = true;
    let freq = new Map();
    for(let num of nums){
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    let count = Array.from(freq.values());
    for(let i = 0; i < count.length; i++){
        let next = dp.slice();
        for(let j = 0; j < m; j++){
            if(dp[j]){
                let mask = j;
                let sum = 0;
                for(let k = 0; k < n; k++){
                    if((mask & (1 << k)) == 0 && quantity[k] <= count[i]){
                        mask |= 1 << k;
                        sum += quantity[k];
                    }
                }
                if(sum <= count[i]){
                    next[mask] = true;
                }
            }
        }
        dp = next;
    }
    return dp[m - 1];
    
};

    