/**https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/ */
//A split of an integer array is good if:
//	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
//	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
//Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [1,1,1]
//Output: 1
//Explanation: The only good way to split nums is [1] [1] [1].
//Example 2:
//Input: nums = [1,2,2,2,5,0]
//Output: 3
//Explanation: There are three good ways of splitting nums:
//[1] [2] [2,2,5,0]
//[1] [2,2] [2,5,0]
//[1,2] [2,2] [5,0]
//Example 3:
//Input: nums = [3,2,1]
//Output: 0
//Explanation: There is no good way to split nums.
// 
//Constraints:
//	3 <= nums.length <= 105
//	0 <= nums[i] <= 104
class Solution {
    public int waysToSplit(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = 0;
        int mod = (int)1e9 + 7;
        for (int i = 1; i < n; i++) {
            int left = prefix[i];
            int right = prefix[n] - prefix[i];
            int leftIndex = binarySearch(prefix, i + 1, n, left * 2);
            int rightIndex = binarySearch(prefix, i + 1, n, (left + right) / 2);
            if (leftIndex != -1 && rightIndex != -1) {
                res = (res + Math.max(0, rightIndex - leftIndex + 1)) % mod;
            }
        }
        return res;
    }
    private int binarySearch(int[] prefix, int start, int end, int target) {
        int res = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (prefix[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
                res = mid;
            }
        }
        return res;
    }

}