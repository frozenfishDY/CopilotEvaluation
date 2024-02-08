/**https://leetcode.com/problems/degree-of-an-array/ */
//Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
//Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.


/**
 * @param {number[]} nums
 * @return {number}
 */
var findShortestSubArray = function(nums) {
    let map = {};
    let max = 0;
    let min = Infinity;
    for(let i = 0; i < nums.length; i++){
        if(map[nums[i]]){
            map[nums[i]].count++;
            map[nums[i]].end = i;
        }else{
            map[nums[i]] = {count: 1, start: i, end: i};
        }
        if(map[nums[i]].count > max){
            max = map[nums[i]].count;
            min = map[nums[i]].end - map[nums[i]].start + 1;
        }else if(map[nums[i]].count == max){
            if(map[nums[i]].end - map[nums[i]].start + 1 < min){
                min = map[nums[i]].end - map[nums[i]].start + 1;
            }
        }
    }
    return min;
    
};

    