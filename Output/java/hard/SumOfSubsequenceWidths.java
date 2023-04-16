/**https://leetcode.com/problems/sum-of-subsequence-widths/ */
//The width of a sequence is the difference between the maximum and minimum elements in the sequence.
//Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].


class SumOfSubsequenceWidths {
    public int sumSubseqWidths(int[] nums) {
        int n = nums.length;
        int mod = 1000000007;
        Arrays.sort(nums);
        long[] pow = new long[n];
        pow[0] = 1;
        for (int i = 1; i < n; i++) {
            pow[i] = pow[i - 1] * 2 % mod;
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (pow[i] - pow[n - i - 1]) * nums[i]) % mod;
        }
        return (int) res;
        
    }
}
     
    