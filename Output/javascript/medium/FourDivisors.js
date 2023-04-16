/**https://leetcode.com/problems/four-divisors/ */
//Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.


/**
 * @param {number[]} nums
 * @return {number}
 */
var sumFourDivisors = function(nums) {
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        let count = 0;
        let divisors = [];
        for (let j = 1; j <= Math.sqrt(nums[i]); j++) {
            if (nums[i] % j === 0) {
                if (nums[i] / j === j) {
                    count++;
                    divisors.push(j);
                } else {
                    count += 2;
                    divisors.push(j);
                    divisors.push(nums[i] / j);
                }
            }
        }
        if (count === 4) {
            sum += divisors.reduce((a, b) => a + b);
        }
    }
    return sum;
    
};

    