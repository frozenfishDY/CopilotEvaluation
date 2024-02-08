/**https://leetcode.com/problems/longest-subsequence-repeated-k-times/ */
//You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
//For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
//Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.


class LongestSubsequenceRepeatedKTimes {
    public String longestSubsequenceRepeatedK(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s.charAt(i - 1) == s.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int len = dp[n][n];
        char[] res = new char[len];
        int i = n, j = n;
        while(i > 0 && j > 0){
            if(s.charAt(i - 1) == s.charAt(j - 1)){
                res[len - 1] = s.charAt(i - 1);
                i--;
                j--;
                len--;
            }else if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }else{
                j--;
            }
        }
        String str = new String(res);
        int count = 0;
        for(i = 0; i < n; i++){
            if(s.startsWith(str, i)){
                count++;
            }
        }
        return count == k ? str : "";
        
    }
}
     
    