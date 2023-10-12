/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
    public String smallestSubsequence(String s) {
        int[] cnt = new int[26];
		boolean[] used = new boolean[26];
		for(char c: s.toCharArray()) {
			cnt[c - 'a']++;
		}
		Stack<Character> stack = new Stack<>();
		for(char c: s.toCharArray()) {
			cnt[c - 'a']--;
			if(used[c - 'a']) {
				continue;
			}
			while(!stack.isEmpty() && stack.peek() > c && cnt[stack.peek() - 'a'] > 0) {
				used[stack.pop() - 'a'] = false;
			}
			stack.push(c);
			used[c - 'a'] = true;
		}
		StringBuilder sb = new StringBuilder();
		while(!stack.isEmpty()) {
			sb.append(stack.pop());
		}
		return sb.reverse().toString();
    }
}