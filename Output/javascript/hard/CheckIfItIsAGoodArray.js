/**https://leetcode.com/problems/check-if-it-is-a-good-array/ */
//Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.
//Return True if the array is good otherwise return False.


/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isGoodArray = function(nums) {
    let gcd = (a, b) => {
        if(a == 0){
            return b;
        }
        return gcd(b % a, a);
    }
    let g = nums[0];
    for(let i = 1; i < nums.length; i++){
        g = gcd(g, nums[i]);
    }
    return g == 1;
    
};

    