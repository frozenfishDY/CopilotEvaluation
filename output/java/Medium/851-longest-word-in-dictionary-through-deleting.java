/**https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/ */
//Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
// 
//Example 1:
//Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
//Output: "apple"
//Example 2:
//Input: s = "abpcplea", dictionary = ["a","b","c"]
//Output: "a"
// 
//Constraints:
//	1 <= s.length <= 1000
//	1 <= dictionary.length <= 1000
//	1 <= dictionary[i].length <= 1000
//	s and dictionary[i] consist of lowercase English letters.
class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        String result = "";
        for (String str : dictionary) {
            if (isSubsequence(str, s)) {
                if (str.length() > result.length()) {
                    result = str;
                } else if (str.length() == result.length()) {
                    result = result.compareTo(str) <= 0 ? result : str;
                }
            }
        }
        return result;
    }
    private boolean isSubsequence(String str, String s) {
        int index = 0;
        for (char c : s.toCharArray()) {
            if (c == str.charAt(index)) {
                index++;
            }
            if (index == str.length()) {
                return true;
            }
        }
        return false;
    }
}