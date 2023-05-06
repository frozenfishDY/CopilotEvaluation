/**https://leetcode.com/problems/sort-an-array/ */
//Given an array of integers nums, sort the array in ascending order and return it.
//You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    let n = nums.length;
    let result = [];
    let map = {};
    for(let i = 0; i < n; i++){
        let num = nums[i];
        if(map[num] == undefined){
            map[num] = 1;
        }else{
            map[num]++;
        }
    }
    let keys = Object.keys(map);
    keys.sort((a, b) => a - b);
    for(let i = 0; i < keys.length; i++){
        let key = keys[i];
        let count = map[key];
        for(let j = 0; j < count; j++){
            result.push(key);
        }
    }
    return result;
    
};

    