/**https://leetcode.com/problems/number-of-arithmetic-triplets/ */
//You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
//	i < j < k,
//	nums[j] - nums[i] == diff, and
//	nums[k] - nums[j] == diff.
//Return the number of unique arithmetic triplets.
// 
//Example 1:
//Input: nums = [0,1,4,6,7,10], diff = 3
//Output: 2
//Explanation:
//(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
//(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
//Example 2:
//Input: nums = [4,5,6,7,8,9], diff = 2
//Output: 2
//Explanation:
//(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
//(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
// 
//Constraints:
//	3 <= nums.length <= 200
//	0 <= nums[i] <= 200
//	1 <= diff <= 50
//	nums is strictly increasing.
/**
 * @param {number[]} nums
 * @param {number} diff
 * @return {number}
 */
var arithmeticTriplets = function(nums, diff) {
    let result = 0;
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
    for (let i = 0; i < nums.length; i++) {
        let item = nums[i];
        let first = item - diff;
        let second = item + diff;
        if (map.has(first) && map.has(second)) {
            if (diff === 0) {
                let count = map.get(item);
                if (count >= 3) {
                    result += count * (count - 1) * (count - 2) / 6;
                }
            } else {
                result++;
            }
        }
    }
    return result;
};