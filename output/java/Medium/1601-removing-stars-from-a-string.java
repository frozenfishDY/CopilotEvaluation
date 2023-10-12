/**https://leetcode.com/problems/removing-stars-from-a-string/ */
//You are given a string s, which contains stars *.
//In one operation, you can:
//	Choose a star in s.
//	Remove the closest non-star character to its left, as well as remove the star itself.
//Return the string after all stars have been removed.
//Note:
//	The input will be generated such that the operation is always possible.
//	It can be shown that the resulting string will always be unique.
// 
//Example 1:
//Input: s = "leet**cod*e"
//Output: "lecoe"
//Explanation: Performing the removals from left to right:
//- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
//- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
//- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
//There are no more stars, so we return "lecoe".
//Example 2:
//Input: s = "erase*****"
//Output: ""
//Explanation: The entire string is removed, so we return an empty string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters and stars *.
//	The operation above can be performed on s.
class Solution {
    public String removeStars(String s) {
        int n = s.length();
        int[] count = new int[n];
        int[] pos = new int[n];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '*') {
                pos[idx++] = i;
            } else {
                count[i] = idx;
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != '*') {
                if (count[i] > 0 && pos[count[i] - 1] == i - 1) {
                    res.setLength(res.length() - 1);
                } else {
                    res.append(s.charAt(i));
                }
            }
        }
        return res.toString();
    }
}