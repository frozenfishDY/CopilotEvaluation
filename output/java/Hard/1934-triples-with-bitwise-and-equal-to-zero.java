/**https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/ */
//Given an integer array nums, return the number of AND triples.
//An AND triple is a triple of indices (i, j, k) such that:
//0 <= i < nums.length
//0 <= j < nums.length
//0 <= k < nums.length
//nums[i] & nums[j] & nums[k] == 0, where & represents the bitwise-AND operator.


class TriplesWithBitwiseAndEqualToZero {
    public int countTriplets(int[] nums) {
        int n = nums.length;
        int[] dp = new int[1 << 16];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[nums[i] & nums[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << 16); j++) {
                if ((nums[i] & j) == 0) {
                    res += dp[j];
                }
            }
        }
        return res;
        
    }
}
     
    