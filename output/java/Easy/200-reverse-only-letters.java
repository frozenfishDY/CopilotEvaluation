/**https://leetcode.com/problems/reverse-only-letters/ */
//Given a string s, reverse the string according to the following rules:
//	All the characters that are not English letters remain in the same position.
//	All the English letters (lowercase or uppercase) should be reversed.
//Return s after reversing it.
// 
//Example 1:
//Input: s = "ab-cd"
//Output: "dc-ba"
//Example 2:
//Input: s = "a-bC-dEf-ghIj"
//Output: "j-Ih-gfE-dCba"
//Example 3:
//Input: s = "Test1ng-Leet=code-Q!"
//Output: "Qedo1ct-eeLg=ntse-T!"
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of characters with ASCII values in the range [33, 122].
//	s does not contain '\"' or '\\'.
class Solution {
    public String reverseOnlyLetters(String s) {
        int i = 0, j = s.length() - 1;
        char[] arr = s.toCharArray();
        while (i < j) {
            while (i < j && !Character.isLetter(arr[i])) {
                i++;
            }
            while (i < j && !Character.isLetter(arr[j])) {
                j--;
            }
            char temp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = temp;
        }
        return new String(arr);
    }
}