/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.


class ShortestPalindrome {
    public String shortestPalindrome(String s) {
        int n = s.length();
        int[] dp = new int[n];
        for (int i = 1; i < n; i++) {
            int j = dp[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = dp[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                j++;
            }
            dp[i] = j;
        }
        int j = dp[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = dp[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                j++;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = n - 1; i >= j; i--) {
            sb.append(s.charAt(i));
        }
        sb.append(s);
        return sb.toString();
        
    }
}
     
    