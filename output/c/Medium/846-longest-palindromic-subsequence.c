/**https://leetcode.com/problems/longest-palindromic-subsequence/ */
//Given a string s, find the longest palindromic subsequence's length in s.
//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: s = "bbbab"
//Output: 4
//Explanation: One possible longest palindromic subsequence is "bbbb".
//Example 2:
//Input: s = "cbbd"
//Output: 2
//Explanation: One possible longest palindromic subsequence is "bb".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists only of lowercase English letters.
int longestPalindromeSubseq(char * s){
int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    int len = strlen(s);
    int** dp = (int**)malloc(sizeof(int*) * len);
    for (i = 0; i < len; i++) {
        dp[i] = (int*)malloc(sizeof(int) * len);
        memset(dp[i], 0, sizeof(int) * len);
    }
    for (i = len - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = dp[i][j - 1] > dp[i + 1][j] ? dp[i][j - 1] : dp[i + 1][j];
            }
        }
    }
    return dp[0][len - 1];
}