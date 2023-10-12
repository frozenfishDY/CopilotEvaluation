/**https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/ */
//Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.
// 
//Example 1:
//Input: s = "1001"
//Output: false
//Explanation: The ones do not form a contiguous segment.
//Example 2:
//Input: s = "110"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 100
//	s[i]​​​​ is either '0' or '1'.
//	s[0] is '1'.
class Solution {
    public boolean checkOnesSegment(String s) {
        boolean zero = false;
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) == '0'){
                zero = true;
            }else if(s.charAt(i) == '1' && zero){
                return false;
            }
        }
        return true;
    }
}