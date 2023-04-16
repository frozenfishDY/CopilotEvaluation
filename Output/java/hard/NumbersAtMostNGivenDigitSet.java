/**https://leetcode.com/problems/numbers-at-most-n-given-digit-set/ */
//Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
//Return the number of positive integers that can be generated that are less than or equal to a given integer n.


class NumbersAtMostNGivenDigitSet {
    public int atMostNGivenDigitSet(String[] digits, int n) {
        String s = String.valueOf(n);
        int k = s.length();
        int[] dp = new int[k + 1];
        dp[k] = 1;
        for (int i = k - 1; i >= 0; i--) {
            int si = s.charAt(i) - '0';
            for (String d : digits) {
                if (Integer.parseInt(d) < si) {
                    dp[i] += Math.pow(digits.length, k - i - 1);
                } else if (Integer.parseInt(d) == si) {
                    dp[i] += dp[i + 1];
                }
            }
        }
        for (int i = 1; i < k; i++) {
            dp[0] += Math.pow(digits.length, i);
        }
        return dp[0];
        
    }
}
     
    