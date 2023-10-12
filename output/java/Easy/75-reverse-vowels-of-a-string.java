/**https://leetcode.com/problems/reverse-vowels-of-a-string/ */
//Given a string s, reverse only all the vowels in the string and return it.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// 
//Example 1:
//Input: s = "hello"
//Output: "holle"
//Example 2:
//Input: s = "leetcode"
//Output: "leotcede"
// 
//Constraints:
//	1 <= s.length <= 3 * 105
//	s consist of printable ASCII characters.
class Solution {
    public String reverseVowels(String s) {
        char[] chars = s.toCharArray();
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (!isVowel(chars[i])) {
                ++i;
                continue;
            }
            if (!isVowel(chars[j])) {
                --j;
                continue;
            }
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
            ++i;
            --j;
        }
        return new String(chars);
    }
    private boolean isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || 
            c == 'o' || c == 'u' || c == 'A' || 
            c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }
}