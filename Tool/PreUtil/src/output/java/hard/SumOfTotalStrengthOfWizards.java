/**https://leetcode.com/problems/sum-of-total-strength-of-wizards/ */
//As the ruler of a kingdom, you have an army of wizards at your command.
//You are given a 0-indexed integer array strength, where strength[i] denotes the strength of the ith wizard. For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), the total strength is defined as the product of the following two values:
//The strength of the weakest wizard in the group.
//The total of all the individual strengths of the wizards in the group.
//Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.


class SumOfTotalStrengthOfWizards {
    public int totalStrength(int[] strength) {
        int n = strength.length;
        int[] dp = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i >= 1) {
                dp[i] = Math.min(dp[i - 1], strength[i]);
            } else {
                dp[i] = strength[i];
            }
            res += dp[i];
        }
        return res;
        
    }
}
     
    