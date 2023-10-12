/**https://leetcode.com/problems/permutation-in-string/ */
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
// 
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//Constraints:
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] count = new int[26];
        for (char c : s1.toCharArray()) {
            count[c - 'a']++;
        }
        int left = 0;
        int right = 0;
        int total = s1.length();
        while (right < s2.length()) {
            if (count[s2.charAt(right) - 'a'] > 0) {
                total--;
            }
            count[s2.charAt(right) - 'a']--;
            if (right - left + 1 > s1.length()) {
                if (count[s2.charAt(left) - 'a'] >= 0) {
                    total++;
                }
                count[s2.charAt(left) - 'a']++;
                left++;
            }
            if (total == 0) {
                return true;
            }
            right++;
        }
        return false;
    }
}