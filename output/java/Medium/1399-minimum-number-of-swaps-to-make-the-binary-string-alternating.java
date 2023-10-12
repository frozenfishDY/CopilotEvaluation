/**https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/ */
//Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
//The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
//Any two characters may be swapped, even if they are not adjacent.
// 
//Example 1:
//Input: s = "111000"
//Output: 1
//Explanation: Swap positions 1 and 4: "111000" -> "101010"
//The string is now alternating.
//Example 2:
//Input: s = "010"
//Output: 0
//Explanation: The string is already alternating, no swaps are needed.
//Example 3:
//Input: s = "1110"
//Output: -1
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
class Solution {
    public int minSwaps(String s) {
        int n = s.length();
        int[] ones = new int[n + 1];
        int[] zeros = new int[n + 1];
        for (int i = 0; i < n; i++) {
            ones[i + 1] = ones[i] + (s.charAt(i) == '1' ? 1 : 0);
            zeros[i + 1] = zeros[i] + (s.charAt(i) == '0' ? 1 : 0);
        }
        if (Math.abs(ones[n] - zeros[n]) > 1) {
            return -1;
        }
        if (ones[n] == zeros[n]) {
            int res = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0 && s.charAt(i) == '1' || i % 2 == 1 && s.charAt(i) == '0') {
                    res = Math.min(res, ones[i + 1] + zeros[n] - zeros[i + 1]);
                }
            }
            return res;
        } else if (ones[n] > zeros[n]) {
            int res = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0 && s.charAt(i) == '0' || i % 2 == 1 && s.charAt(i) == '1') {
                    res = Math.min(res, ones[i + 1] + zeros[n] - zeros[i + 1]);
                }
            }
            return res;
        } else {
            int res = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0 && s.charAt(i) == '1' || i % 2 == 1 && s.charAt(i) == '0') {
                    res = Math.min(res, ones[i + 1] + zeros[n] - zeros[i + 1]);
                }
            }
            return res;
    }
}