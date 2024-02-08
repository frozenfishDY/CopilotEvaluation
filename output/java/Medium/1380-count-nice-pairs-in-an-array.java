/**https://leetcode.com/problems/count-nice-pairs-in-an-array/ */
//You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:
//0 <= i < j < nums.length
//nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
//Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.


class CountNicePairsInAnArray {
    public int countNicePairs(int[] nums) {
        int mod = 1000000007;
        Map<Integer, Integer> map = new HashMap<>();
        int res = 0;
        for (int num : nums) {
            int rev = reverse(num);
            int diff = num - rev;
            int count = map.getOrDefault(diff, 0);
            res = (res + count) % mod;
            map.put(diff, count + 1);
        }
        return res;
        
    }
}
     
    