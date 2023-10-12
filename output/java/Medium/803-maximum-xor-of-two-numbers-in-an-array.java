/**https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/ */
//Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
// 
//Example 1:
//Input: nums = [3,10,5,25,2,8]
//Output: 28
//Explanation: The maximum result is 5 XOR 25 = 28.
//Example 2:
//Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
//Output: 127
// 
//Constraints:
//	1 <= nums.length <= 2 * 105
//	0 <= nums[i] <= 231 - 1
class Solution {
    public int findMaximumXOR(int[] nums) {
        int result = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            Set<Integer> set = new HashSet<>();
            for (int num : nums) {
                set.add(num & mask);
            }
            int tmp = result | (1 << i);
            for (int num : set) {
                if (set.contains(num ^ tmp)) {
                    result = tmp;
                    break;
                }
            }
        }
        return result;
    }
}