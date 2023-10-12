/**https://leetcode.com/problems/monotonic-array/ */
//An array is monotonic if it is either monotone increasing or monotone decreasing.
//An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
//Given an integer array nums, return true if the given array is monotonic, or false otherwise.
// 
//Example 1:
//Input: nums = [1,2,2,3]
//Output: true
//Example 2:
//Input: nums = [6,5,4,4]
//Output: true
//Example 3:
//Input: nums = [1,3,2]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean inc = true;
        boolean dec = true;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] > nums[i-1]) dec = false;
            if(nums[i] < nums[i-1]) inc = false;
        }
        return inc || dec;
    }
}