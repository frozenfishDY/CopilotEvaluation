/**https://leetcode.com/problems/thousand-separator/ */
//Given an integer n, add a dot (".") as the thousands separator and return it in string format.
// 
//Example 1:
//Input: n = 987
//Output: "987"
//Example 2:
//Input: n = 1234
//Output: "1.234"
// 
//Constraints:
//	0 <= n <= 231 - 1
class Solution {
    public String thousandSeparator(int n) {
        String s = Integer.toString(n);
        StringBuilder res = new StringBuilder();
        int count = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(count == 3){
                res.append('.');
                count = 0;
            }
            res.append(s.charAt(i));
            count++;
        }
        return res.reverse().toString();
    }
}