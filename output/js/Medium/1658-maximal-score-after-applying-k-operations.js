/**https://leetcode.com/problems/maximal-score-after-applying-k-operations/ */
//You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
//In one operation:
//choose an index i such that 0 <= i < nums.length,
//increase your score by nums[i], and
//replace nums[i] with ceil(nums[i] / 3).
//Return the maximum possible score you can attain after applying exactly k operations.
//The ceiling function ceil(val) is the least integer greater than or equal to val.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxKelements = function(nums, k) {
    let n = nums.length;
    let result = 0;
    for(let i = 0; i <= k; i++){
        let j = k - i;
        if(i > n || j > n){
            continue;
        }
        let max1 = getMax(nums, i);
        let max2 = getMax(nums, j);
        result = Math.max(result, max1 + max2);
    }
    return result;
    
    
    
};

    