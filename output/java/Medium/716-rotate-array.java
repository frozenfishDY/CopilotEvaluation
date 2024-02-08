/**https://leetcode.com/problems/rotate-array/ */
//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


class RotateArray {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
        
        
    }
}

    