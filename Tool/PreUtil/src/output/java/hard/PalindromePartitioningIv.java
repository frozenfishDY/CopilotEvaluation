/**https://leetcode.com/problems/palindrome-partitioning-iv/ */
//Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.
//A string is said to be palindrome if it the same string when reversed.


class PalindromePartitioningIv {
    public boolean checkPartitioning(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int i = 0; i < n - 1; i++){
            dp[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j - 1] && s.charAt(i) == s.charAt(j);
            }
        }
        for(int i = 0; i < n - 2; i++){
            if(dp[0][i]){
                for(int j = i + 1; j < n - 1; j++){
                    if(dp[i + 1][j] && dp[j + 1][n - 1]){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
}
     
    