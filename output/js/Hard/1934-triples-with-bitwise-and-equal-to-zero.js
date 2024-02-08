/**https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/ */
//Given an integer array nums, return the number of AND triples.
//An AND triple is a triple of indices (i, j, k) such that:
//0 <= i < nums.length
//0 <= j < nums.length
//0 <= k < nums.length
//nums[i] & nums[j] & nums[k] == 0, where & represents the bitwise-AND operator.


/**
 * @param {number[]} nums
 * @return {number}
 */
var countTriplets = function(nums) {
    let res = 0;
    for(let i = 0; i < nums.length; i++){
        for(let j = 0; j < nums.length; j++){
            for(let k = 0; k < nums.length; k++){
                if((nums[i] & nums[j] & nums[k]) === 0){
                    res++;
                }
            }
        }
    }
    return res;
    
};

    