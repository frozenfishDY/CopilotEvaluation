/**https://leetcode.com/problems/extra-characters-in-a-string/ */
//You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.
//Return the minimum number of extra characters left over if you break up s optimally.
// 
//Example 1:
//Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
//Output: 1
//Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.
//Example 2:
//Input: s = "sayhelloworld", dictionary = ["hello","world"]
//Output: 3
//Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
// 
//Constraints:
//	1 <= s.length <= 50
//	1 <= dictionary.length <= 50
//	1 <= dictionary[i].length <= 50
//	dictionary[i] and s consists of only lowercase English letters
//	dictionary contains distinct words
class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        int m = dictionary.length;
        int max = 0;
        for (String word : dictionary) {
            max = Math.max(max, word.length());
        }
        int[][] dp = new int[n][max + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        int ans = minExtraChar(s, 0, 0, max, dictionary, dp);
        return ans;
    }
    private int minExtraChar(String s, int index, int len, int max, String[] dictionary, int[][] dp) {
        int n = s.length();
        if (index == n) {
            return 0;
        }
        if (dp[index][len] != -1) {
            return dp[index][len];
        }
        int ans = n - index;
        for (int i = index; i < n; i++) {
            String word = s.substring(index, i + 1);
            boolean found = false;
            for (String target : dictionary) {
                if (target.equals(word)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans = Math.min(ans, minExtraChar(s, i + 1, 0, max, dictionary, dp));
            } else if (len < max) {
                ans = Math.min(ans, 1 + minExtraChar(s, i + 1, len + 1, max, dictionary, dp));
            } else {
                break;
            }
        }
        dp[index][len] = ans;
        return ans;
    }
}