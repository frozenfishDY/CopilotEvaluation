/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
char * lastSubstring(char * s){
int len = strlen(s);
	int left = 0, right = 1, offset = 0;
	while (left + offset < len && right + offset < len) {
		if (s[left + offset] == s[right + offset]) {
			offset++;
		} else {
			if (s[left + offset] < s[right + offset]) {
				left = right;
				right = left + 1;
			} else {
				right = right + offset + 1;
			}
			offset = 0;
		}
	}
	return s + left;
}