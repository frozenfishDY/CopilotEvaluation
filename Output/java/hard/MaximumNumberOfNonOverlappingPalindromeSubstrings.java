/**https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/ */
//You are given a string s and a positive integer k.
//Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
//The length of each substring is at least k.
//Each substring is a palindrome.
//Return the maximum number of substrings in an optimal selection.
//A substring is a contiguous sequence of characters within a string.


class MaximumNumberOfNonOverlappingPalindromeSubstrings {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        int[] dp = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k - 1) {
                dp[i] = 1;
            }
            if (i >= k) {
                dp[i] += dp[i - k];
            }
            if (i >= k - 1 && isPalindrome(s, i - k + 1, i)) {
                res += dp[i - k + 1];
            }
        }
        return res;
        
        
        
    }
}
     
    