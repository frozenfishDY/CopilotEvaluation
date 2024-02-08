/**https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/ */
//Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.
//Note that:
//A number greater than 1 is called prime if it is divisible by only 1 and itself.
//An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.


/**
 * @param {number[]} nums
 * @return {number}
 */
var distinctPrimeFactors = function(nums) {
    let n = nums.length;
    let max = 0;
    for(let i = 0; i < n; i++){
        max = Math.max(max, nums[i]);
    }
    let primeFactors = new Array(max + 1).fill(0);
    for(let i = 2; i <= max; i++){
        if(primeFactors[i] == 0){
            for(let j = i; j <= max; j += i){
                primeFactors[j]++;
            }
        }
    }
    let result = 0;
    for(let i = 0; i < n; i++){
        result += primeFactors[nums[i]];
    }
    return result;
    
};

    