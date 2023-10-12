/**https://leetcode.com/problems/count-substrings-that-differ-by-one-character/ */
//Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.
//For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.
//Return the number of substrings that satisfy the condition above.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aba", t = "baba"
//Output: 6
//Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//The underlined portions are the substrings that are chosen from s and t.
//​​Example 2:
//Input: s = "ab", t = "bb"
//Output: 3
//Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
//("ab", "bb")
//("ab", "bb")
//("ab", "bb")
//​​​​The underlined portions are the substrings that are chosen from s and t.
// 
//Constraints:
//	1 <= s.length, t.length <= 100
//	s and t consist of lowercase English letters only.
class Solution {
    public int countSubstrings(String s, String t) {
        int res = 0;
        int m = s.length();
        int n = t.length();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n ; j++) {
                int diff = 0;
                int k = 0;
                while (i + k < m && j + k < n && diff <= 1) {
                    if (s.charAt(i + k) != t.charAt(j + k)) {
                        diff++;
                    }
                    if (diff == 1) {
                        res++;
                    }
                    k++;
                }
            }
        }
        return res;
    }
}