/**https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/ */
//You are given an integer array nums. The value of this array is defined as the sum of |nums[i] - nums[i + 1]| for all 0 <= i < nums.length - 1.
//You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.
//Find maximum possible value of the final array.


class ReverseSubarrayToMaximizeArrayValue {
    public int maxValueAfterReverse(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int maxDiff = 0;
        for (int i = 0; i < n - 1; i++) {
            int diff = Math.abs(nums[i] - nums[i + 1]);
            sum += diff;
            maxDiff = Math.max(maxDiff, Math.max(Math.abs(nums[0] - nums[i + 1]) - diff, Math.abs(nums[n - 1] - nums[i]) - diff));
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                maxDiff = Math.max(maxDiff, Math.abs(nums[i] - nums[j]) - Math.abs(nums[i + 1] - nums[j - 1]));
            }
        }
        return sum + maxDiff;
        
    }
}
     
    