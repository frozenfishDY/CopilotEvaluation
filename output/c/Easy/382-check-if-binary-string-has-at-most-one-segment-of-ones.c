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
bool checkOnesSegment(char * s){
int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0, len = strlen(s);
    for(i = 0; i < len; i++){
        if(s[i] == '1'){
            if(i != 0 && s[i - 1] == '0'){
                cnt++;
            }
        }
    }
    return (cnt < 2);
}