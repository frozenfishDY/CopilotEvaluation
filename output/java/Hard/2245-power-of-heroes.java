/**https://leetcode.com/problems/power-of-heroes/ */
//You are given a 0-indexed integer array nums representing the strength of some heroes. The power of a group of heroes is defined as follows:
//	Let i0, i1, ... ,ik be the indices of the heroes in a group. Then, the power of this group is max(nums[i0], nums[i1], ... ,nums[ik])2 * min(nums[i0], nums[i1], ... ,nums[ik]).
//Return the sum of the power of all non-empty groups of heroes possible. Since the sum could be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [2,1,4]
//Output: 141
//Explanation: 
//1st group: [2] has power = 22 * 2 = 8.
//2nd group: [1] has power = 12 * 1 = 1. 
//3rd group: [4] has power = 42 * 4 = 64. 
//4th group: [2,1] has power = 22 * 1 = 4. 
//5th group: [2,4] has power = 42 * 2 = 32. 
//6th group: [1,4] has power = 42 * 1 = 16. 
//​​​​​​​7th group: [2,1,4] has power = 42​​​​​​​ * 1 = 16. 
//The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.
//Example 2:
//Input: nums = [1,1,1]
//Output: 7
//Explanation: A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
class Solution {
    public int sumOfPower(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (long)nums[i] * nums[i]) % 1000000007;
        }
        int[] cnt = new int[1000001];
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i]];
        }
        int[] sum = new int[1000001];
        for (int i = 1; i <= 1000000; ++i) {
            sum[i] = sum[i - 1] + cnt[i];
        }
        for (int i = 0; i < n; ++i) {
            int p = nums[i];
            int l = 0, r = p - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (sum[mid] >= i + 1) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (sum[l] < i + 1) {
                ++l;
            }
            int len = p - l;
            long tmp = (long)p * p * len;
            ans = (ans + tmp) % 1000000007;
        }
        return (int)ans;
    }
}