/**https://leetcode.com/problems/longest-substring-of-one-repeating-character/ */
//You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
//The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
//Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.


class LongestSubstringOfOneRepeatingCharacter {
    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int n = s.length();
        int[] dp = new int[n];
        int[] res = new int[queryCharacters.length()];
        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) == s.charAt(i - 1)) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        for (int i = 0; i < queryCharacters.length(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters.charAt(i);
            s = s.substring(0, idx) + c + s.substring(idx + 1);
            if (idx > 0 && s.charAt(idx) == s.charAt(idx - 1)) {
                dp[idx] = dp[idx - 1] + 1;
            } else {
                dp[idx] = 1;
            }
            if (idx < n - 1 && s.charAt(idx) == s.charAt(idx + 1)) {
                dp[idx + 1] = dp[idx] + 1;
            }
            res[i] = dp[idx];
        }
        return res;
        
    }
}
     
    