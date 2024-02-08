/**https://leetcode.com/problems/sum-of-scores-of-built-strings/ */
//You are building a string s of length n one character at a time, prepending each new character to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.
//For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
//The score of si is the length of the longest common prefix between si and sn (Note that s == sn).
//Given the final string s, return the sum of the score of every si.


class SumOfScoresOfBuiltStrings {
    public long sumScores(String s) {
        int n = s.length();
        long res = 0;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) == s.charAt(i - 1)) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
            res += dp[i];
        }
        return res;
        
    }
}
     
    