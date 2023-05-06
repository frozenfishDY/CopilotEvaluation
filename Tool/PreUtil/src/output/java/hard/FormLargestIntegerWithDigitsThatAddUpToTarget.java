/**https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/ */
//Given an array of integers cost and an integer target, return the maximum integer you can paint under the following rules:
//The cost of painting a digit (i + 1) is given by cost[i] (0-indexed).
//The total cost used must be equal to target.
//The integer does not have 0 digits.
//Since the answer may be very large, return it as a string. If there is no way to paint any integer given the condition, return "0".


class FormLargestIntegerWithDigitsThatAddUpToTarget {
    public String largestNumber(int[] cost, int target) {
        int[] dp = new int[target + 1];
        Arrays.fill(dp, Integer.MIN_VALUE);
        dp[0] = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = cost[i]; j <= target; j++) {
                dp[j] = Math.max(dp[j], dp[j - cost[i]] + 1);
            }
        }
        if (dp[target] < 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 8, j = target; i >= 0; i--) {
            while (j >= cost[i] && dp[j] == dp[j - cost[i]] + 1) {
                sb.append(i + 1);
                j -= cost[i];
            }
        }
        return sb.toString();
        
    }
}
     
    