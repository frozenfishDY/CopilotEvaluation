/**https://leetcode.com/problems/find-array-given-subset-sums/ */
//You are given an integer n representing the length of an unknown array that you are trying to recover. You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).
//Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.
//An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.
//Note: Test cases are generated such that there will always be at least one correct answer.


/**
 * @param {number} n
 * @param {number[]} sums
 * @return {number[]}
 */
var recoverArray = function(n, sums) {
    let result = [];
    let map = new Map();
    for (let i = 0; i < sums.length; i++) {
        let sum = sums[i];
        if (map.has(sum)) {
            map.set(sum, map.get(sum) + 1);
        } else {
            map.set(sum, 1);
        }
    }
    let max = 0;
    let maxSum = 0;
    for (let [key, value] of map) {
        if (value > max) {
            max = value;
            maxSum = key;
        }
    }
    result.push(maxSum);
    let index = 0;
    while (result.length < n) {
        let sum = sums[index];
        if (sum != maxSum) {
            result.push(sum - maxSum);
        }
        index++;
    }
    return result;
    
};

    