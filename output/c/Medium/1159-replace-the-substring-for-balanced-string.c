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
int balancedString(char * s){
int len = strlen(s);
    int count[26] = {0};
    int avg = len / 4;
    for (int i = 0; i < len; ++i) {
        ++count[s[i] - 'A'];
    }
    int left = 0, right = 0, res = len;
    while (right < len) {
        --count[s[right] - 'A'];
        while (left < len && count['Q' - 'A'] <= avg && count['W' - 'A'] <= avg && count['E' - 'A'] <= avg && count['R' - 'A'] <= avg) {
            res = fmin(res, right - left + 1);
            ++count[s[left++] - 'A'];
        }
        ++right;
    }
    return res;
}