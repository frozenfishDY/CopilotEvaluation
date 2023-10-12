/**https://leetcode.com/problems/largest-palindromic-number/ */
//You are given a string num consisting of digits only.
//Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
//Notes:
//	You do not need to use all the digits of num, but you must use at least one digit.
//	The digits can be reordered.
// 
//Example 1:
//Input: num = "444947137"
//Output: "7449447"
//Explanation: 
//Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
//It can be shown that "7449447" is the largest palindromic integer that can be formed.
//Example 2:
//Input: num = "00009"
//Output: "9"
//Explanation: 
//It can be shown that "9" is the largest palindromic integer that can be formed.
//Note that the integer returned should not contain leading zeroes.
// 
//Constraints:
//	1 <= num.length <= 105
//	num consists of digits.
class Solution {
    public String largestPalindromic(String num) {
        int n = num.length();
        char[] cs = num.toCharArray();
        Arrays.sort(cs);
        int l = 0;
        int r = n - 1;
        int[] count = new int[10];
        for (int i = 0; i < n; i++) {
            count[cs[i] - '0']++;
        }
        StringBuilder res = new StringBuilder();
        for (int i = 9; i >= 0; i--) {
            while (count[i] > 0) {
                count[i]--;
                if (l == r) {
                    res.append(i);
                    break;
                }
                if (cs[l] == i + '0') {
                    res.append(cs[l]);
                    l++;
                    r--;
                } else if (cs[r] == i + '0') {
                    res.append(cs[r]);
                    r--;
                } else {
                    res.append(i);
                    break;
                }
            }
            if (count[i] == 0) {
                break;
            }
        }
        return res.toString();
    }
}