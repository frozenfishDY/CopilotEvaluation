/**https://leetcode.com/problems/destroy-sequential-targets/ */
//You are given a 0-indexed array nums consisting of positive integers, representing targets on a number line. You are also given an integer space.
//You have a machine which can destroy targets. Seeding the machine with some nums[i] allows it to destroy all targets with values that can be represented as nums[i] + c * space, where c is any non-negative integer. You want to destroy the maximum number of targets in nums.
//Return the minimum value of nums[i] you can seed the machine with to destroy the maximum number of targets.


/**
 * @param {number[]} nums
 * @param {number} space
 * @return {number}
 */
var destroyTargets = function(nums, space) {
    let n = nums.length;
    let result = 0;
    let set = new Set();
    let left = 0;
    for (let right = 0; right < n; right++) {
        while (set.has(nums[right])) {
            set.delete(nums[left]);
            left++;
        }
        set.add(nums[right]);
        result = Math.max(result, right - left + 1);
    }
    return n - result;
    
    
};

    