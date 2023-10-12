/**https://leetcode.com/problems/delete-characters-to-make-fancy-string/ */
//A fancy string is a string where no three consecutive characters are equal.
//Given a string s, delete the minimum possible number of characters from s to make it fancy.
//Return the final string after the deletion. It can be shown that the answer will always be unique.
// 
//Example 1:
//Input: s = "leeetcode"
//Output: "leetcode"
//Explanation:
//Remove an 'e' from the first group of 'e's to create "leetcode".
//No three consecutive characters are equal, so return "leetcode".
//Example 2:
//Input: s = "aaabaaaa"
//Output: "aabaa"
//Explanation:
//Remove an 'a' from the first group of 'a's to create "aabaaaa".
//Remove two 'a's from the second group of 'a's to create "aabaa".
//No three consecutive characters are equal, so return "aabaa".
//Example 3:
//Input: s = "aab"
//Output: "aab"
//Explanation: No three consecutive characters are equal, so return "aab".
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists only of lowercase English letters.
class Solution {
    public String makeFancyString(String s) {
        int n = s.length();
        if(n <= 2){
            return s;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(s.charAt(0));
        sb.append(s.charAt(1));
        for(int i = 2; i < n; i++){
            if(s.charAt(i) != s.charAt(i - 1) || s.charAt(i) != s.charAt(i - 2)){
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}