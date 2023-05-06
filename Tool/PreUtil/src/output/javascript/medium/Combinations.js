/**https://leetcode.com/problems/combinations/ */
//Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
//You may return the answer in any order.


/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    let result = [];
    if(n == 0){
        return result;
    }
    let current = [];
    helper(n, k, 1, current, result);
    return result;
    
    
    
};

    