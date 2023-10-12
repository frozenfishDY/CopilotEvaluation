/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
class Solution {
    public int monotoneIncreasingDigits(int n) {
       char[] ch = String.valueOf(n).toCharArray();
		int i = 1;
		while(i < ch.length && ch[i-1] <= ch[i]) {
			i++;
		}
		if(i < ch.length) {
			while(i > 0 && ch[i-1] > ch[i]) {
				ch[--i]--;
			}
			for(int j=i+1; j<ch.length; j++) {
				ch[j] = '9';
			}
		}
		return Integer.parseInt(String.valueOf(ch));
       
    }
}