/**https://leetcode.com/problems/count-anagrams/ */
//You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.
//A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
//For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
//Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 10^9 + 7.


class CountAnagrams {
    public int countAnagrams(String s) {
        int n = s.length();
        int mod = 1000000007;
        int[][] dp = new int[n + 1][n + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = -1;
            }
        }
        return dfs(s, 0, 0, dp) % mod;
        
    }
}
     
    