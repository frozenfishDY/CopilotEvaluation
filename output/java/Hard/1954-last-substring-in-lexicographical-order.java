/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
class Solution {
    public String lastSubstring(String s) {
        int len = s.length();
        if(len <= 1){
            return s;
        }
        int res = len - 1;
        int index = 0;
        int i = 1;
        while(i < len){
            if(s.charAt(i) > s.charAt(index)){
                index = i;
                res = len - 1;
            }else if(s.charAt(i) == s.charAt(index)){
                int j = i + 1;
                int k = index + 1;
                while(j < len && k < i){
                    if(s.charAt(j) > s.charAt(k)){
                        index = i;
                        res = len - 1;
                        break;
                    }else if(s.charAt(j) < s.charAt(k)){
                        break;
                    }
                    j++;
                    k++;
                }
                if(j == len || k == i){
                    res = Math.min(res, index);
                    index = i;
                }
            }
            i++;
        }
        return s.substring(res);
    }
}