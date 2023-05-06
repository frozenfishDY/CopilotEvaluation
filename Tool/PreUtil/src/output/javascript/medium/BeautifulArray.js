/**https://leetcode.com/problems/beautiful-array/ */
//An array nums of length n is beautiful if:
//nums is a permutation of the integers in the range [1, n].
//For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.


/**
 * @param {number} n
 * @return {number[]}
 */
var beautifulArray = function(n) {
    let result = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        result[i] = i + 1;
    }
    return helper(result);
    
    
};

    