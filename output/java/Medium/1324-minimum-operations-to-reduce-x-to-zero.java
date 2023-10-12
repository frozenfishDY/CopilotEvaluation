/**https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/ */
//You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
//Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
// 
//Example 1:
//Input: nums = [1,1,4,2,3], x = 5
//Output: 2
//Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
//Example 2:
//Input: nums = [5,6,7,8,9], x = 4
//Output: -1
//Example 3:
//Input: nums = [3,2,20,1,1,3], x = 10
//Output: 5
//Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 104
//	1 <= x <= 109
class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int target = sum - x;
        if (target == 0) {
            return n;
        }
        int left = 0;
        int right = 0;
        int cur = 0;
        int res = -1;
        while (right < n) {
            cur += nums[right];
            while (cur > target && left <= right) {
                cur -= nums[left++];
            }
            if (cur == target) {
                res = Math.max(res, right - left + 1);
            }
            right++;
        }
        return res == -1 ? -1 : n - res;
    }
}