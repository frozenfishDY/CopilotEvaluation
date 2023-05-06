/**https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/ */
//You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
//The chosen integers have to be in the range [1, n].
//Each integer can be chosen at most once.
//The chosen integers should not be in the array banned.
//The sum of the chosen integers should not exceed maxSum.
//Return the maximum number of integers you can choose following the mentioned rules.


/**
 * @param {number[]} banned
 * @param {number} n
 * @param {number} maxSum
 * @return {number}
 */
var maxCount = function(banned, n, maxSum) {
    let sum = 0;
    let count = 0;
    let i = 0;
    let j = 0;
    while(i < banned.length && j < banned.length){
        if(sum + banned[j] <= maxSum){
            sum += banned[j];
            j++;
        }else{
            sum -= banned[i];
            i++;
        }
        if(sum <= maxSum){
            count = Math.max(count, j - i);
        }
    }
    return count;
    
};

    