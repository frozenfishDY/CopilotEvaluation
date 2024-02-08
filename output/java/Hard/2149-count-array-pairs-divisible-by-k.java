/**https://leetcode.com/problems/count-array-pairs-divisible-by-k/ */
//Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:
//0 <= i < j <= n - 1 and
//nums[i] * nums[j] is divisible by k.


class CountArrayPairsDivisibleByK {
    public long countPairs(int[] nums, int k) {
        int n = nums.length;
        long res = 0;
        for (int i = 0; i < n; i++) {
            int[] count = new int[k];
            for (int j = i + 1; j < n; j++) {
                count[(nums[i] * nums[j]) % k]++;
            }
            for (int j = i + 1; j < n; j++) {
                res += count[(k - (nums[i] * nums[j]) % k) % k];
            }
        }
        return res;
        
    }
}
     
    