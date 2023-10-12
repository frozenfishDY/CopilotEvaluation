/**https://leetcode.com/problems/frequency-of-the-most-frequent-element/ */
//The frequency of an element is the number of times it occurs in an array.
//You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
//Return the maximum possible frequency of an element after performing at most k operations.
// 
//Example 1:
//Input: nums = [1,2,4], k = 5
//Output: 3
//Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
//4 has a frequency of 3.
//Example 2:
//Input: nums = [1,4,8,13], k = 5
//Output: 2
//Explanation: There are multiple optimal solutions:
//- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
//- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
//- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
//Example 3:
//Input: nums = [3,9,6], k = 2
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
//	1 <= k <= 105
class Solution {
    public int maxFrequency(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        long[] prefixSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = i;
            while (left < right) {
                int mid = left + (right - left) / 2;
                long cur = prefixSum[i + 1] - prefixSum[mid];
                long target = (long) nums[i] * (i - mid + 1);
                if (cur + k >= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res = Math.max(res, i - left + 1);
        }
        return res;
    }
}