/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
class Solution {
    public String originalDigits(String s) {
          int[] count = new int[26];
        int[] digit = new int[10];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        digit[0] = count['z' - 'a'];
        digit[2] = count['w' - 'a'];
        digit[4] = count['u' - 'a'];
        digit[6] = count['x' - 'a'];
        digit[8] = count['g' - 'a'];
        digit[3] = count['h' - 'a'] - digit[8];
        digit[5] = count['f' - 'a'] - digit[4];
        digit[7] = count['v' - 'a'] - digit[5];
        digit[9] = count['i' - 'a'] - digit[5] - digit[6] - digit[8];
        digit[1] = count['n' - 'a'] - digit[7] - 2 * digit[9];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < digit[i]; j++) {
                sb.append(i);
            }
        }
        return sb.toString();   
    }
}