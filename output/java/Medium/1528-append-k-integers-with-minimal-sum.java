/**https://leetcode.com/problems/append-k-integers-with-minimal-sum/ */
//You are given an integer array nums and an integer k. Append k unique positive integers that do not appear in nums to nums such that the resulting total sum is minimum.
//Return the sum of the k integers appended to nums.
// 
//Example 1:
//Input: nums = [1,4,25,10,25], k = 2
//Output: 5
//Explanation: The two unique positive integers that do not appear in nums which we append are 2 and 3.
//The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
//The sum of the two integers appended is 2 + 3 = 5, so we return 5.
//Example 2:
//Input: nums = [5,6], k = 6
//Output: 25
//Explanation: The six unique positive integers that do not appear in nums which we append are 1, 2, 3, 4, 7, and 8.
//The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which is the minimum. 
//The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so we return 25.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
//	1 <= k <= 108
class Solution {
    public long minimalKSum(int[] nums, int k) {
        int n = nums.length;
        int[] pre = new int[n + 1];
        long res = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1];
            if (nums[i - 1] > nums[i - 2]) {
                pre[i]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (nums[mid] < nums[i - 1]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (nums[l] < nums[i - 1]) {
                res += pre[i - 1] - pre[l];
            } else {
                res += pre[i - 1] - pre[l] - 1;
            }
        }
        return res;
    }
}