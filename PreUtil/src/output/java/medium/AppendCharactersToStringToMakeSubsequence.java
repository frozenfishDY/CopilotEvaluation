/**https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/ */
//You are given two strings s and t consisting of only lowercase English letters.
//Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


class AppendCharactersToStringToMakeSubsequence {
    public int appendCharacters(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[][] dp = new int[m + 1][n + 1];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s.charAt(i - 1) == t.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return n - dp[m][n];
        
    }
}

    