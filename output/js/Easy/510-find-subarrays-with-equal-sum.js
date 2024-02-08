/**https://leetcode.com/problems/find-subarrays-with-equal-sum/ */
//Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
//Return true if these subarrays exist, and false otherwise.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [4,2,4]
//Output: true
//Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
//Example 2:
//Input: nums = [1,2,3,4,5]
//Output: false
//Explanation: No two subarrays of size 2 have the same sum.
//Example 3:
//Input: nums = [0,0,0]
//Output: true
//Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
//Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.
// 
//Constraints:
//	2 <= nums.length <= 1000
//	-109 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var findSubarrays = function(nums) {
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let item = nums[i];
        if (map.has(item)) {
            let count = map.get(item);
            map.set(item, count + 1);
        } else {
            map.set(item, 1);
        }
    }
    let result = false;
    for (let i = 0; i < nums.length; i++) {
        let item = nums[i];
        let tempMap = new Map();
        for (let j = i + 1; j < nums.length; j++) {
            let nextItem = nums[j];
            let count = map.get(item);
            if (count > 1) {
                map.set(item, count - 1);
            } else {
                map.delete(item);
            }
            if (tempMap.has(nextItem)) {
                let count = tempMap.get(nextItem);
                tempMap.set(nextItem, count + 1);
            } else {
                tempMap.set(nextItem, 1);
            }
            let tempSum = 0;
            let tempMap2 = new Map();
            for (let k = j + 1; k < nums.length; k++) {
                let nextItem2 = nums[k];
                if (tempMap2.has(nextItem2)) {
                    let count = tempMap2.get(nextItem2);
                    tempMap2.set(nextItem2, count + 1);
                } else {
                    tempMap2.set(nextItem2, 1);
                }
                tempSum += nextItem2;
                if (tempSum === item) {
                    let isEqual = true;
                    tempMap2.forEach((value, key) => {
                        if (tempMap.has(key)) {
                            let count = tempMap.get(key);
                            if (count !== value) {
                                isEqual = false;
                            }
                        } else {
                            isEqual = false;
                        }
                    });
                    if (isEqual) {
                        result = true;
                        break;
                    }
                }
            }
            if (result) {
                break;
            }
        }
        if (result) {
            break;
        }
    }
    return result;
};