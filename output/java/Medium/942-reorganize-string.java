/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
class Solution {
    public String reorganizeString(String s) {
        int n = s.length();
        int[] cnt = new int[26];
        for(char c: s.toCharArray()) {
            cnt[c-'a']++;
        }
        PriorityQueue<Character> pq = new PriorityQueue<>((a,b) -> cnt[b-'a'] - cnt[a-'a']);
        for(int i=0; i<26; i++) {
            if(cnt[i] > 0) {
                pq.add((char)('a' + i));
            }
        }
        StringBuilder sb = new StringBuilder();
        while(pq.size() >= 2) {
            char c1 = pq.remove();
            char c2 = pq.remove();
            sb.append(c1);
            sb.append(c2);
            if(--cnt[c1-'a'] > 0) {
                pq.add(c1);
            }
            if(--cnt[c2-'a'] > 0) {
                pq.add(c2);
            }
        }
        if(pq.size() > 0) {
            char c = pq.remove();
            if(cnt[c-'a'] > 1) {
                return "";
            }
            sb.append(c);
        }
        return sb.toString();
    }
}