/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].


class NumberOfSquarefulArrays {
    public int numSquarefulPerms(int[] nums) {
        int n = nums.length;
        int[] dp = new int[1 << n];
        dp[0] = 1;
        for (int mask = 1; mask < (1 << n); mask++) {
            int count = Integer.bitCount(mask);
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 1) {
                    for (int j = 0; j < n; j++) {
                        if (((mask >> j) & 1) == 1 && i != j) {
                            if (count == 2 || isSquare(nums[i] + nums[j])) {
                                dp[mask] += dp[mask ^ (1 << i)];
                            }
                        }
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
                
    }
}
     
    