/**https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/ */
//Given a string s and an array of strings words, determine whether s is a prefix string of words.
//A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.
//Return true if s is a prefix string of words, or false otherwise.
// 
//Example 1:
//Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
//Output: true
//Explanation:
//s can be made by concatenating "i", "love", and "leetcode" together.
//Example 2:
//Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
//Output: false
//Explanation:
//It is impossible to make s using a prefix of arr.
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 20
//	1 <= s.length <= 1000
//	words[i] and s consist of only lowercase English letters.
class Solution {
    public boolean isPrefixString(String s, String[] words) {
        int n = s.length();
        int index = 0;
        for(int i = 0; i < words.length; i++){
            for(int j = 0; j < words[i].length(); j++){
                if(index == n){
                    return true;
                }
                if(s.charAt(index) != words[i].charAt(j)){
                    return false;
                }
                index++;
            }
        }
        return index == n;
    }
}