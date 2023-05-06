/**https://leetcode.com/problems/total-appeal-of-a-string/ */
//The appeal of a string is the number of distinct characters found in the string.
//For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
//Given a string s, return the total appeal of all of its substrings.
//A substring is a contiguous sequence of characters within a string.


class TotalAppealOfAString {
    public long appealSum(String s) {
        int n = s.length();
        long res = 0;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) == s.charAt(i - 1)) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = 1;
            }
            res += dp[i];
        }
        return res;
        
    }
}
     
    