/**https://leetcode.com/problems/maximum-erasure-value/ */
//You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
//Return the maximum score you can get by erasing exactly one subarray.
//An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).


/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
    let n = nums.length;
    let result = 0;
    let sum = 0;
    let set = new Set();
    let left = 0;
    for (let right = 0; right < n; right++) {
        while (set.has(nums[right])) {
            set.delete(nums[left]);
            sum -= nums[left];
            left++;
        }
        set.add(nums[right]);
        sum += nums[right];
        result = Math.max(result, sum);
    }
    return result;
    
};

    