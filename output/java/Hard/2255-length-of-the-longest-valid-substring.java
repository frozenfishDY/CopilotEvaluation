/**https://leetcode.com/problems/length-of-the-longest-valid-substring/ */
//You are given a string word and an array of strings forbidden.
//A string is called valid if none of its substrings are present in forbidden.
//Return the length of the longest valid substring of the string word.
//A substring is a contiguous sequence of characters in a string, possibly empty.
// 
//Example 1:
//Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
//Output: 4
//Explanation: There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc"and "aabc". The length of the longest valid substring is 4. 
//It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 
//Example 2:
//Input: word = "leetcode", forbidden = ["de","le","e"]
//Output: 4
//Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
//It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
// 
//Constraints:
//	1 <= word.length <= 105
//	word consists only of lowercase English letters.
//	1 <= forbidden.length <= 105
//	1 <= forbidden[i].length <= 10
//	forbidden[i] consists only of lowercase English letters.
class Solution {
    public int longestValidSubstring(String word, List<String> forbidden) {
        int m = word.length();
        int[][] dp = new int[m][2];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = Math.max(ans, dfs(i, 0, word, forbidden, dp));
        }
        return ans;
    }
    private int dfs(int i, int j, String word, List<String> forbidden, int[][] dp) {
        int m = word.length();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 1;
        for (int k = i - 1; k <= i + 1; ++k) {
            if (k < 0 || k >= m) {
                continue;
            }
            for (int l = j - 1; l <= j + 1; ++l) {
                if (l < 0 || l >= m || k == i && l == j) {
                    continue;
                }
                if (word.charAt(k) >= word.charAt(i) && word.charAt(l) >= word.charAt(j)) {
                    ans = Math.max(ans, 1 + dfs(k, l, word, forbidden, dp));
                }
            }
        }
        return dp[i][j] = ans;
    }
}