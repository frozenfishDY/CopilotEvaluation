/**https://leetcode.com/problems/long-pressed-name/ */
//Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
//You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
// 
//Example 1:
//Input: name = "alex", typed = "aaleex"
//Output: true
//Explanation: 'a' and 'e' in 'alex' were long pressed.
//Example 2:
//Input: name = "saeed", typed = "ssaaedd"
//Output: false
//Explanation: 'e' must have been pressed twice, but it was not in the typed output.
// 
//Constraints:
//	1 <= name.length, typed.length <= 1000
//	name and typed consist of only lowercase English letters.
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i = 0;
        int j = 0;
        int len1 = name.length();
        int len2 = typed.length();
        while (i < len1 && j < len2) {
            if (name.charAt(i) == typed.charAt(j)) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    return false;
                }
                if (typed.charAt(j) == typed.charAt(j - 1)) {
                    j++;
                } else {
                    return false;
                }
            }
        }
        while (j < len2) {
            if (typed.charAt(j) == typed.charAt(j - 1)) {
                j++;
            } else {
                return false;
            }
        }
        return i == len1;
    }
}