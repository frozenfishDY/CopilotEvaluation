/**https://leetcode.com/problems/beautiful-arrangement/ */
//Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
//	perm[i] is divisible by i.
//	i is divisible by perm[i].
//Given an integer n, return the number of the beautiful arrangements that you can construct.
// 
//Example 1:
//Input: n = 2
//Output: 2
//Explanation: 
//The first beautiful arrangement is [1,2]:
//    - perm[1] = 1 is divisible by i = 1
//    - perm[2] = 2 is divisible by i = 2
//The second beautiful arrangement is [2,1]:
//    - perm[1] = 2 is divisible by i = 1
//    - i = 2 is divisible by perm[2] = 1
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 15
class Solution {
    public int countArrangement(int n) {
        public int countArrangement(int n) {
        int[] result = new int[1];
        int[] nums = new int[n];
        for (int i = 1; i <= n; i++) {
            nums[i - 1] = i;
        }
        helper(nums, 0, result);
        return result[0];
    }
    public void helper(int[] nums, int index, int[] result) {
        if (index == nums.length) {
            result[0]++;
            return;
        }
        for (int i = index; i < nums.length; i++) {
            if (nums[i] % (index + 1) == 0 || (index + 1) % nums[i] == 0) {
                swap(nums, i, index);
                helper(nums, index + 1, result);
                swap(nums, i, index);
            }
        }
    }
    public void swap(int[] nums, int i, int j) {
        if (i == j) return;
        int val = nums[i];
        nums[i] = nums[j];
        nums[j] = val;
    }
}