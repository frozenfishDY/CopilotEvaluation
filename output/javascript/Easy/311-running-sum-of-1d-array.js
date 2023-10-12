/**https://leetcode.com/problems/running-sum-of-1d-array/ */
//Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i])._x000D_
//_x000D_
//Return the running sum of nums._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,2,3,4]_x000D_
//Output: [1,3,6,10]_x000D_
//Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4]._x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,1,1,1,1]_x000D_
//Output: [1,2,3,4,5]_x000D_
//Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1]._x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: nums = [3,1,2,10,1]_x000D_
//Output: [3,4,6,16,17]_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= nums.length <= 1000_x000D_
//	-10^6 <= nums[i] <= 10^6_x000D_
/**_x000D_
 * @param {number[]} nums_x000D_
 * @return {number[]}_x000D_
 */
var runningSum = function(nums) {
    let res = [];
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        res.push(sum);
    }
    return res;
};