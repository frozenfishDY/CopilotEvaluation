/**https://leetcode.com/problems/replace-the-substring-for-balanced-string/ */
//You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
//A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
//Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
// 
//Example 1:
//Input: s = "QWER"
//Output: 0
//Explanation: s is already balanced.
//Example 2:
//Input: s = "QQWE"
//Output: 1
//Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
//Example 3:
//Input: s = "QQQW"
//Output: 2
//Explanation: We can replace the first "QQ" to "ER". 
// 
//Constraints:
//	n == s.length
//	4 <= n <= 105
//	n is a multiple of 4.
//	s contains only 'Q', 'W', 'E', and 'R'.
class Solution {
    public int balancedString(String s) {
        int ans = s.length();
        Map<Character, Integer> map = new HashMap<>();
        for(char c: s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0)+1);
        }
        int i = 0;
        for(int j = 0; j < s.length(); j++) {
            map.put(s.charAt(j), map.get(s.charAt(j))-1);
            while(i < s.length() && map.get('Q') <= s.length()/4 && map.get('W') <= s.length()/4 && map.get('E') <= s.length()/4 && map.get('R') <= s.length()/4) {
                ans = Math.min(ans, j-i+1);
                map.put(s.charAt(i), map.get(s.charAt(i))+1);
                i++;
            }
        }
        return ans;
    }
}