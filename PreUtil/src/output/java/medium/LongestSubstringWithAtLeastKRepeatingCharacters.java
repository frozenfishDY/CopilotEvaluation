/**https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/ */
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.


class LongestSubstringWithAtLeastKRepeatingCharacters {
    public int longestSubstring(String s, int k) {
        int n = s.length();
        int[] count = new int[26];
        for(int i = 0; i < n; i++){
            count[s.charAt(i) - 'a']++;
        }
        int res = 0;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0 && count[i] < k){
                for(String t : s.split(String.valueOf((char)('a' + i)))){
                    res = Math.max(res, longestSubstring(t, k));
                }
                return res;
            }
        }
        return n;
                
    }
}

    