/**https://leetcode.com/problems/string-compression-ii/ */
//Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".
//Notice that in this problem, we are not adding '1' after single characters.
//Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.
//Find the minimum length of the run-length encoded version of s after deleting at most k characters.


class StringCompressionIi {
    public int getLengthOfOptimalCompression(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n + 1][k + 1];
        for(int i = 0; i <= n; i++){
            Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = dp[i - 1][j];
                int cnt = 0;
                int diff = 0;
                for(int l = i; l >= 1; l--){
                    if(s.charAt(l - 1) == s.charAt(i - 1)){
                        cnt++;
                    }else{
                        diff++;
                    }
                    if(j >= diff && dp[l - 1][j - diff] != Integer.MAX_VALUE / 2){
                        dp[i][j] = Math.min(dp[i][j], dp[l - 1][j - diff] + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1 : 0));
                    }
                }
            }
        }
        return dp[n][k];
        
    }
}
     
    