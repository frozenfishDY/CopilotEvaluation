/**https://leetcode.com/problems/non-decreasing-array/ */
//Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
//We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
// 
//Example 1:
//Input: nums = [4,2,3]
//Output: true
//Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
//Example 2:
//Input: nums = [4,2,1]
//Output: false
//Explanation: You cannot get a non-decreasing array by modifying at most one element.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 104
//	-105 <= nums[i] <= 105
class Solution {
    public boolean checkPossibility(int[] nums) {
        int n = nums.length;
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int num1 = nums[i], num2 = nums[i + 1];
            if (num1 > num2) {
                count++;
                if (count > 1) {
                    return false;
                }
                if (i - 1 >= 0 && num2 < nums[i - 1]) {
                    nums[i + 1] = num1;
                }
            }
        }
        return true;
    }
}