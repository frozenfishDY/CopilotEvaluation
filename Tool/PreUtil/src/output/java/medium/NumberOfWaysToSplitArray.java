/**https://leetcode.com/problems/number-of-ways-to-split-array/ */
//You are given a 0-indexed integer array nums of length n.
//nums contains a valid split at index i if the following are true:
//The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
//There is at least one element to the right of i. That is, 0 <= i < n - 1.
//Return the number of valid splits in nums.


class NumberOfWaysToSplitArray {
    public int waysToSplitArray(int[] nums) {
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        int result = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sum[mid] - sum[i] >= sum[nums.length - 1] - sum[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            int rightIndex = right;
            left = i + 1;
            right = nums.length - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sum[mid] - sum[i] > sum[nums.length - 1] - sum[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            int leftIndex = left;
            if (leftIndex <= rightIndex) {
                result += rightIndex - leftIndex + 1;
            }
        }
        return result;
        
    }
}
     
    