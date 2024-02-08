/**https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/ */
//You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
//Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.


class TakeKOfEachCharacterFromLeftAndRight {
    public int takeCharacters(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n + 1][k + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i - 1][j];
                if(s.charAt(i - 1) == 'a'){
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                if(s.charAt(n - i) == 'a'){
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                if(s.charAt(i - 1) == 'b'){
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                if(s.charAt(n - i) == 'b'){
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                if(s.charAt(i - 1) == 'c'){
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
        
    }
}

    