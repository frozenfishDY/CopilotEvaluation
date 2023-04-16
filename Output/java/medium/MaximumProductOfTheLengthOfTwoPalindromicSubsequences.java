/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/ */
//Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
//Return the maximum possible product of the lengths of the two palindromic subsequences.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.


class MaximumProductOfTheLengthOfTwoPalindromicSubsequences {
    public int maxProduct(String s) {
        int n = s.length();
        int[] dp = new int[1 << n];
        for(int i = 0; i < (1 << n); i++){
            String sub = "";
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0){
                    sub += s.charAt(j);
                }
            }
            if(isPalindrome(sub)){
                dp[i] = sub.length();
            }
        }
        int max = 0;
        for(int i = 0; i < (1 << n); i++){
            for(int j = i + 1; j < (1 << n); j++){
                if((i & j) == 0){
                    max = Math.max(max, dp[i] * dp[j]);
                }
            }
        }
        return max;
        
        
    }
}
     
    