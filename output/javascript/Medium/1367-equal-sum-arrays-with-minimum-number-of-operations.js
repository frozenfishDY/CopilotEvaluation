/**https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/ */
//You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in the arrays are between 1 and 6, inclusive.
//In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.
//Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.
// 
//Example 1:
//Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
//Output: 3
//Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
//- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
//- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
//- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
//Example 2:
//Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
//Output: -1
//Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
//Example 3:
//Input: nums1 = [6,6], nums2 = [1]
//Output: 3
//Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
//- Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
//- Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
//- Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 105
//	1 <= nums1[i], nums2[i] <= 6
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minOperations = function(nums1, nums2) {
    let sum1 = nums1.reduce((a, b) => a + b);
    let sum2 = nums2.reduce((a, b) => a + b);
    if (sum1 === sum2) return 0;
    if (sum1 > sum2) {
        let temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        let tempSum = sum1;
        sum1 = sum2;
        sum2 = tempSum;
    }
    let diff = sum2 - sum1;
    let map = new Map();
    for (let num of nums1) {
        map.set(num, (map.get(num) || 0) + 1);
    }
    for (let num of nums2) {
        map.set(num, (map.get(num) || 0) - 1);
    }
    let res = 0;
    for (let i = 5; i >= 1; i--) {
        while (map.get(i) > 0 && diff > 0) {
            res++;
            diff -= i - 1;
            map.set(i, map.get(i) - 1);
        }
    }
    if (diff > 0) return -1;
    return res;
};