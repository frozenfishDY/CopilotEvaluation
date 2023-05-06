/**https://leetcode.com/problems/longest-consecutive-sequence/ */
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.


/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let map = {};
    let max = 0;
    for(let i = 0; i < nums.length; i++){
        let num = nums[i];
        if(map[num] == undefined){
            let left = map[num - 1] == undefined ? 0 : map[num - 1];
            let right = map[num + 1] == undefined ? 0 : map[num + 1];
            let sum = left + right + 1;
            map[num] = sum;
            max = Math.max(max, sum);
            map[num - left] = sum;
            map[num + right] = sum;
        }
    }
    return max;
    
};

    