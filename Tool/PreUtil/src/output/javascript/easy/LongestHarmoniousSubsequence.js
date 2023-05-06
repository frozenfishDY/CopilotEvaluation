/**https://leetcode.com/problems/longest-harmonious-subsequence/ */
//We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
//Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
//A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.


/**
 * @param {number[]} nums
 * @return {number}
 */
var findLHS = function(nums) {
    let map = new Map();
    let max = 0;
    for(let i = 0; i < nums.length; i++){
        let num = nums[i];
        if(map.has(num)){
            map.set(num, map.get(num) + 1);
        }else{
            map.set(num, 1);
        }
        if(map.has(num + 1)){
            max = Math.max(max, map.get(num) + map.get(num + 1));
        }
        if(map.has(num - 1)){
            max = Math.max(max, map.get(num) + map.get(num - 1));
        }
    }
    return max;
    
};

    