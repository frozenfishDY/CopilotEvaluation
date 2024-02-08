/**https://leetcode.com/problems/contains-duplicate-ii/ */
//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    let map = new Map();
    for(let i = 0; i < nums.length; i++){
        let num = nums[i];
        if(map.has(num)){
            let index = map.get(num);
            if(i - index <= k){
                return true;
            }
        }
        map.set(num, i);
    }
    return false;
    
};

    