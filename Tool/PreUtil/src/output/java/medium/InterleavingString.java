/**https://leetcode.com/problems/interleaving-string/ */
//Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
//An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
//s = s1 + s2 + ... + sn
//t = t1 + t2 + ... + tm
//|n - m| <= 1
//The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
//Note: a + b is the concatenation of strings a and b.


class InterleavingString {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        boolean[][] dp = new boolean[s1.length() + 1][s2.length() + 1];
        dp[0][0] = true;
        for(int i = 1; i <= s1.length(); i++){
            dp[i][0] = dp[i - 1][0] && s1.charAt(i - 1) == s3.charAt(i - 1);
        }
        for(int i = 1; i <= s2.length(); i++){
            dp[0][i] = dp[0][i - 1] && s2.charAt(i - 1) == s3.charAt(i - 1);
        }
        for(int i = 1; i <= s1.length(); i++){
            for(int j = 1; j <= s2.length(); j++){
                dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
            }
        }
        return dp[s1.length()][s2.length()];
        
    }
}

    